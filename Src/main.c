#include "system_stm32f4xx.h"
#include "time.h"
#include "eventman.h"
#include "led.h"
#include "melody.h"
#include "eventbutton.h"
#include "button.h"
#include "string.h"
#include "stdint.h"
#include "Ucglib.h"
#include "stdio.h"
#include "flash.h"
#include <stdbool.h>

// Định nghĩa các kiểu sự kiện
typedef enum {
    EVENT_EMPTY,
    EVENT_APP_INIT,
    EVENT_APP_FLUSHMEM_READY
} event_api_t, *event_api_p;

typedef enum {
    STATE_APP_STARTUP,
    STATE_APP_IDLE,
    STATE_APP_RESET,
} state_app_t;

// Biến toàn cục
state_app_t eCurrentState;
uint8_t idTimer;
uint8_t time_current;
uint8_t event;
uint8_t buttoncount = 0;
uint8_t time_initial;
uint8_t time_total;
uint8_t reset = 0;
uint8_t IdTimerCancle;

// Biến để xác định chế độ đổi font
uint8_t Mode = 0;  // Chế độ mặc định
uint8_t i;          // Số thứ tự font
uint8_t needReinitialize = 0;
uint8_t currentFontIndex = 1;

p_UserData_t g_pReadWriteData;
uint8_t g_loadFont;
bool status = true;

// Mảng các font
const ucg_fntpgm_uint8_t *Font[] = {
    ucg_font_timR08_hf,
    ucg_font_ncenB10_tf,
    ucg_font_profont12_8f,
    ucg_font_helvR14_hr,
    ucg_font_helvB12_hr,
    ucg_font_helvB18_hf,
    ucg_font_ncenB08_hf,
    ucg_font_ncenB10_tr,
    ucg_font_ncenB12_hf,
    ucg_font_helvR08_tf,
    ucg_font_profont17_mf,
    ucg_font_ncenB14_hr,
    ucg_font_ncenB12_tf,
    ucg_font_profont15_8f,
    ucg_font_profont22_8r,
    ucg_font_ncenB14_tf,
    ucg_font_ncenB18_hf,
    ucg_font_timR14_tf,
    ucg_font_profont10_8r,
    ucg_font_ncenB18_tf
};

static ucg_t ucg;
static char src1[50];
static uint32_t lastUpdateTime;
static uint32_t updateInterval = 2000;  // Millisecond

// Khai báo các hàm
static void SetStateApp(state_app_t state);
static state_app_t GetStateApp(void);
void LoadConfiguration(void);
static void DeviceStateMachine(uint8_t);
static void Task_Screen_Update(void);
static void AppStateManager(uint8_t event);
static void Screen_Scan(void);
void delay_ms(uint32_t ms);
void setup(void);
static void parameteInit(void);
static void SaveFontToFlash(uint8_t byFont);

// Hàm tính toán thời gian
uint32_t CalculatorTime(uint32_t dwTimeInit, uint32_t dwTimeCurrent) {
    uint32_t dwTimeTotal;
    if (dwTimeCurrent >= dwTimeInit) {
        dwTimeTotal = dwTimeCurrent - dwTimeInit;
    } else {
        dwTimeTotal = 0xFFFFFFFFU + dwTimeCurrent - dwTimeInit;
    }
    return dwTimeTotal;
}

// Hàm khởi tạo ứng dụng
static void AppInitCommon(void) {
    SystemCoreClockUpdate();
    TimerInit();
    EventSchedulerInit(AppStateManager);
    EventButton_Init();
    LedControl_Init();
    FLASH_Init();
    parameteInit();

    Ucglib4WireSWSPI_begin(&ucg, UCG_FONT_MODE_SOLID);
    ucg_ClearScreen(&ucg);
    ucg_SetRotate180(&ucg);
    time_initial = GetMilSecTick();
    i = currentFontIndex = 0;
}

// Hàm load cấu hình
void LoadConfiguration(void) {
    ucg_SetColor(&ucg, 0, 225, 225, 225);
    ucg_SetColor(&ucg, 1, 0, 0, 0);
    ucg_SetFont(&ucg, Font[currentFontIndex]);

    ucg_DrawString(&ucg, 0, 50, 0, "Hello ");
    ucg_DrawString(&ucg, 0, 70, 0, "IOT Programming");
    needReinitialize = 1;
    setup();
}

// Hàm đặt font và đánh dấu đã cài đặt
void SetFontAndMarkInstalled(ucg_t *ucg, uint8_t fontIndex) {
    ucg_SetFont(ucg, Font[fontIndex]);
    status = false;  // Đánh dấu rằng font đã được cài đặt
    currentFontIndex = fontIndex; // Cập nhật chỉ số font hiện tại
}

// Quản lý trạng thái ứng dụng
void AppStateManager(uint8_t event) {
    switch (GetStateApp()) {
        case STATE_APP_STARTUP:
            if (event == EVENT_APP_INIT) {
                LoadConfiguration();
                SetStateApp(STATE_APP_IDLE);
            }
            break;
        case STATE_APP_IDLE:
            DeviceStateMachine(event);
            if (needReinitialize == 1) {
                SetStateApp(STATE_APP_STARTUP);
                EventSchedulerAdd(EVENT_APP_INIT);
                needReinitialize = 0;
            }
            break;
        case STATE_APP_RESET:
            break;
        default:
            break;
    }
}

// Hàm đặt trạng thái ứng dụng
static void SetStateApp(state_app_t state) {
    eCurrentState = state;
}

// Hàm lấy trạng thái ứng dụng
static state_app_t GetStateApp(void) {
    return eCurrentState;
}

// Quản lý trạng thái của thiết bị
void DeviceStateMachine(uint8_t event) {
    switch (event) {
        case EVENT_OF_BUTTON_3_PRESS_LOGIC:
            if (buttoncount == 0) {
                ucg_SetColor(&ucg, 0, 0, 0, 225);
                ucg_SetColor(&ucg, 1, 0, 0, 0);
                BuzzerControl_SetMelody(pbeep);
                buttoncount = 1;
                Mode = 1;
                LedControl_BlinkStart(LED_ALL_ID, BLINK_RED, 4, 200, LED_COLOR_BLACK);
                BuzzerControl_SetMelody(pbeep);
            } else {
                ucg_SetColor(&ucg, 0, 225, 225, 225); // Chuyển màu chữ về trắng
                ucg_SetColor(&ucg, 1, 0, 0, 0);
                BuzzerControl_SetMelody(pbeep);
                buttoncount = 0;
                Mode = 0; // Thoát chế độ đổi font
                LedControl_BlinkStart(LED_ALL_ID, BLINK_GREEN, 4, 200, LED_COLOR_BLACK);
                BuzzerControl_SetMelody(p2beep);
                status = true;
                currentFontIndex = i; // Cập nhật giá trị của biến `currentFontIndex`

                // Lưu font hiện tại vào flash khi thoát khỏi chế độ đổi font
                if (Mode == 0) {
                    SaveFontToFlash(currentFontIndex);
                }
            }
            break;

        case EVENT_OF_BUTTON_1_PRESS_LOGIC:
            if (Mode == 1 && i <= 18) {
                i++;
                currentFontIndex = i;
                ucg_ClearScreen(&ucg);
                ucg_SetColor(&ucg, 0, 0, 0, 225);
                ucg_SetFont(&ucg, Font[i]);
                buttoncount = 1;
                BuzzerControl_SetMelody(pbeep);

                // Lưu font hiện tại vào flash khi thoát khỏi chế độ đổi font
                if (Mode == 0) {
                    SaveFontToFlash(currentFontIndex);
                }
            }
            break;

        case EVENT_OF_BUTTON_5_PRESS_LOGIC:
            if (Mode == 1 && i >= 1) {
                i--;
                currentFontIndex = i;
                ucg_ClearScreen(&ucg);
                ucg_SetColor(&ucg, 0, 0, 0, 225);
                ucg_SetFont(&ucg, Font[i]);
                buttoncount = 1;
                BuzzerControl_SetMelody(pbeep);

                // Lưu font hiện tại vào flash khi thoát khỏi chế độ đổi font
                if (Mode == 0) {
                    SaveFontToFlash(currentFontIndex);
                }
            }
            break;

        default:
            break;
    }
}

// Hàm lưu font hiện tại vào flash
static void SaveFontToFlash(uint8_t byFont) {
    p_UserData_t pReadWriteData;
    pReadWriteData = FLASH_GetUserData();
    pReadWriteData->Font = byFont;
    pReadWriteData->Used = FLASH_USERDATA_VALID;
    FLASH_RamToFlash();
}

// Hàm khởi tạo tham số
static void parameteInit() {
    g_pReadWriteData = FLASH_GetUserData();
    g_loadFont = g_pReadWriteData->Font;
}

// Hàm cập nhật màn hình
static void Task_Screen_Update(void) {
    if (reset == 0) {
        ucg_ClearScreen(&ucg);
        reset = 1;
    }
    memset(src1, 0, sizeof(src1));
    sprintf(src1, "Font%3d             ", currentFontIndex + 1);
    ucg_DrawString(&ucg, 40, 15, 0, src1);
}

// Hàm main
int main(void) {
    AppInitCommon();
    SetStateApp(STATE_APP_STARTUP);
    EventSchedulerAdd(EVENT_APP_INIT);

    while (1) {
        processTimerScheduler();
        processEventScheduler();
        DeviceStateMachine(event);
        Screen_Scan();
    }
}

// Hàm hủy bỏ timer
void cancleTimer(void *data) {
    if (IdTimerCancle != NO_TIMER) {
        TimerStop(IdTimerCancle);
    }
}

// Hàm quét màn hình
void Screen_Scan() {
    uint32_t currentTime = GetMilSecTick();
    if (currentTime - lastUpdateTime >= updateInterval) {
        lastUpdateTime = currentTime;
        Task_Screen_Update();
        IdTimerCancle = TimerStart("delay", 5000, TIMER_REPEAT_FOREVER, (void *)Task_Screen_Update, NULL);
    }
}

// Hàm setup (cài đặt ban đầu)
void setup() {
    // Vẽ hình 1 ngôi nhà
    ucg_DrawLine(&ucg, 2, 126, 41, 126);
    ucg_DrawLine(&ucg, 2, 101, 2, 126);
    ucg_DrawLine(&ucg, 2, 101, 41, 101);
    ucg_DrawLine(&ucg, 41, 101, 41, 126);
    ucg_DrawTriangle(&ucg, 2, 101, 22, 90, 41, 101);
    ucg_DrawLine(&ucg, 27, 125, 35, 125);
    ucg_DrawLine(&ucg, 27, 125, 27, 112);
    ucg_DrawLine(&ucg, 27, 112, 35, 112);
    ucg_DrawLine(&ucg, 35, 125, 35, 112);
    ucg_DrawCircle(&ucg, 12, 110, 5, UCG_DRAW_ALL);

    // Vẽ hình 1 xe tải
    ucg_DrawFrame(&ucg, 50, 108, 30, 15);
    ucg_DrawLine(&ucg, 50, 121, 79, 121);
    ucg_DrawLine(&ucg, 50, 106, 79, 106);
    ucg_DrawLine(&ucg, 80, 122, 92, 122);
    ucg_DrawLine(&ucg, 92, 121, 92, 118);
    ucg_DrawLine(&ucg, 86, 112, 92, 118);
    ucg_DrawLine(&ucg, 80, 112, 85, 112);
    ucg_DrawCircle(&ucg, 55, 125, 2, UCG_DRAW_ALL);
    ucg_DrawCircle(&ucg, 75, 125, 2, UCG_DRAW_ALL);
    ucg_DrawCircle(&ucg, 87, 125, 2, UCG_DRAW_ALL);
}

