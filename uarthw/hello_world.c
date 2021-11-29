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
/*define as global variable*/
  int *uart_ba = (int *) UART_0_BASE; /*0x8001060 - 0x0800107f*/
  int rxdataoffs = 0;
  int txdataoffs = 1;
  int statusoffs = 2;
  int ctrloffs = 3;
  int divisoroffs = 4;






#define PROJECT3


#ifdef PROJECT1

int main()
{


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


#ifdef PROJECT2
int main()
{
	//with a baudrate of 115200 we obtain 433
	//with a baudrate of 2400 we obtain 20832(0x00005160)
	*( uart_ba + divisoroffs) = 0x5160;
	 printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
	 printf("value = %d\n", *(uart_ba + divisoroffs));




}
#endif


#ifdef PROJECT31
int main()
{
	char str ='c'; //modify this parameter to send one-two-three characters
	int i;
	//with a baudrate of 115200 we obtain 433
	//with a baudrate of 2400 we obtain 20832(0x00005160)
	*( uart_ba + divisoroffs) = 0x00005160;
	 printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
	 printf("value = %d\n", *(uart_ba + divisoroffs));

	 	 //sending 1 char

		 printf("value = %d\n", *(uart_ba + statusoffs));//before transmission
		 *( uart_ba + txdataoffs ) = (int)str; //writing the register
		 printf("value = %d\n", *(uart_ba + statusoffs));




}
#endif

#ifdef PROJECT32
int main()
{
	char str[i] ="ci"; //modify this parameter to send one-two-three characters
	int i;
	//with a baudrate of 115200 we obtain 433
	//with a baudrate of 2400 we obtain 20832(0x00005160)
	*( uart_ba + divisoroffs) = 0x00005160;
	 printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
	 printf("value = %d\n", *(uart_ba + divisoroffs));

	 	 //sending 2 char

		 printf("value = %d\n", *(uart_ba + statusoffs));//before transmission
		 *( uart_ba + txdataoffs ) = (int)str[0]; //writing the register
		 *( uart_ba + txdataoffs ) = (int)str[1];
		 printf("value = %d\n", *(uart_ba + statusoffs));




}
#endif

#ifdef PROJECT32
int main()
{
	char str[i] ="cia"; //modify this parameter to send one-two-three characters
	int i;
	//with a baudrate of 115200 we obtain 433
	//with a baudrate of 2400 we obtain 20832(0x00005160)
	*( uart_ba + divisoroffs) = 0x00005160;
	 printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
	 printf("value = %d\n", *(uart_ba + divisoroffs));

	 //sending three char

		 printf("value = %d\n", *(uart_ba + statusoffs));//before transmission
		 *( uart_ba + txdataoffs ) = (int)str[0]; //writing the register
		 *( uart_ba + txdataoffs ) = (int)str[1];
		 *( uart_ba + txdataoffs ) = (int)str[2];
		 //check tmt=1, if  true shift register is empty
		 //tmt = (*( uart_ba + statusoffs)
		 printf("value = %d\n", *(uart_ba + statusoffs));


		 return 0;

}
#endif


#ifdef PROJECT4

int main()
{
	char str[i] ="My name is Abda"; //modify this parameter to send one-two-three characters
	int i;
	//with a baudrate of 115200 we obtain 433
	//with a baudrate of 2400 we obtain 20832(0x00005160)
	*( uart_ba + divisoroffs) = 0x00005160;
	 printf("DIVISOR address = 0x%08x (%d) - ", (int) (uart_ba+divisoroffs), (int)(uart_ba+divisoroffs));
	 printf("value = %d\n", *(uart_ba + divisoroffs));


	 for(i=0;str[i]!='\0';i++)
	 {
		 while(((*( uart_ba + statusoffs))>>6 && 0x01)!=0); //checking that TRDY if it is empty
		 *( uart_ba + txdataoffs ) = (int)str[i];
	 }

	 return 0;

	// ((*( uart_ba + statusoffs))>>6 && 0x01);
}

#endif PROJECT4


#ifdef PROJECT51
int main()
{
	//disable interrupts
	*( uart_ba + ctrloffs) = 0x0;
	//polling

	while(1)
	{
	while(((*( uart_ba + statusoffs))>>7 && 0x01)!=0); //i am checking RRDY until data is available
	fprintf(stdout,"%c",(char)*(uart_ba + txdataoffs); //printing character
	}
	return 0;
}





#endif PROJECT51



#ifdef PROJECT52
int main()
{
	//removed polling to see what will happen

	//disable interrupts
	*( uart_ba + ctrloffs) = 0x0;
	//polling

	while(1)
	{
	printf("value = %d\n", *(uart_ba + statusoffs));//before transmission
	fprintf(stdout,"%c",(char)*(uart_ba + txdataoffs); //printing character
	printf("value = %d\n", *(uart_ba + statusoffs));
	}
	return 0;
}





#endif PROJECT52
