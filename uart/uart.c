#include "uart.h"
#include "lib.h"

// Write data
void write_char(unsigned char c)
{
    while (in_word(UART0_FR) & (1 << 5)) { }
    out_word(UART0_DR, c);
}

// Read data
unsigned char read_char(void)
{
    while (in_word(UART0_FR) & (1 << 4)) { }
    return in_word(UART0_DR);
}

// To print string into console
void write_string(const char *string)
{
    for(int i = 0; string[i] != '\0'; i++){
        write_char(string[i]);
    }
}

// Writing control register
// Initialize Buad rate divisor
// defining line control register
// Interrupt mask
void init_uart(void)
{
    out_word(UART0_CR, 0);
    out_word(UART0_IBRD, 26);
    out_word(UART0_FBRD, 0);
    out_word(UART0_LCRH, (1 << 4) | (1 << 5) | (1 << 6));
    out_word(UART0_IMSC, 0);
    out_word(UART0_CR, (1 << 0) | (1 << 8) | (1 << 9));
}