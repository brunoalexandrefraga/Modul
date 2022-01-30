#include <stdio.h>

#include "system.h"
#include "uart1.h"
#include "timer_1ms.h"

static void ButtonDebounce(void);

int main(void)
{
    SYSTEM_Initialize();

    TIMER_SetConfiguration(TIMER_CONFIGURATION_1MS);
    TIMER_RequestTick(&ButtonDebounce, 1000 * 10);
    
    while(1);
}


static void ButtonDebounce(void)
{
    printf("Hello dear!");
}