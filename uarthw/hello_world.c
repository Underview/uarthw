/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "system.h"
#include "sys/alt_timestamp.h"
#include "altera_avalon_pio_regs.h"
#include "sys/alt_irq.h"
#define PROJECT1


#ifdef PROJECT1

int main()
{
  int *uart_ba = (int *) UART_0_BASE;
  int rxdataoffs = 0;
  int txdataoffs = 1;
  int statusoffs = 2;
  int ctrloffs = 3;
  int divisoroffs = 4;

  printf("Base address: 0x%08x (%d)\n", (int) uart_ba,(int) uart_ba);
  printf("RXDATA address = 0x%08x (%d) - ", (int) (uart_ba+rxdataoffs), (int)(uart_ba+rxdataoffs));
  printf("value = %d\n", *(uart_ba + rxdataoffs));

  printf("TXDATA address = 0x%08x (%d) - ", (int) (uart_ba+txdataoffs), (int)(uart_ba+txdataoffs));
  printf("value = %d\n", *(uart_ba + txdataoffs));

  printf("STATUS address = 0x%08x (%d) - ", (int) (uart_ba+statusoffs), (int)(uart_ba+statusoffs));
  printf("value = %d\n", *(uart_ba + statusoffs));

  printf("CONTROLL address = 0x%08x (%d) - ", (int) (uart_ba+ctrloffs), (int)(uart_ba+ctrloffs));
  printf("value = %d\n", *(uart_ba + ctrloffs));

  printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
  printf("value = %d\n", *(uart_ba + divisoroffs));
  return 0;
}

#endif
