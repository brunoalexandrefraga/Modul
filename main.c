#include <stdio.h>

#include "system.h"
#include "uart1.h"


int main(void)
{
    SYSTEM_Initialize();

    while(1) {
        uint8_t var = UART1_Read();
        
        printf("%c", var);
    }
}
