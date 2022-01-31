#include <stdio.h>

#include "system.h"
#include "uart1.h"
#include "timer_1ms.h"

static void ButtonDebounce(void);

int main(void)
{
    SYSTEM_Initialize();

    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    TIMER_RequestTick(&ButtonDebounce, 1000 * 2);
    
    while(1);
}


static void ButtonDebounce(void)
{
    if(!UART1_ReceiveBufferIsEmpty()) {
        uint8_t buffer[UART1_CONFIG_RX_BYTEQ_LENGTH];

        UART1_ReadBuffer(buffer, UART1_CONFIG_RX_BYTEQ_LENGTH);
        printf(buffer);
    }
}