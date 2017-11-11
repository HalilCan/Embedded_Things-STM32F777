#include <cmsis_os.h>
#include <Uart.hpp>
#include <DigitalOut.hpp>
#include <Pins.hpp>


Uart uart(PD9, PD8, 128, 128, 115200);

DigitalOut led0Out(PA1);
DigitalOut led1Out(PA2);
DigitalOut led2Out(PA3);
DigitalOut led4Out(PA4);

DigitalOut ledOuts[4] = { led0Out, led1Out, led2Out, led3Out };

int counter = 0;

static void LED_Thread1(void const *)
{
	//Define a buffer to hold the message
	/*char message[50];
	char name[50];
	char response[50];
	*/

	while (true)
	{
		//Fill the message with data
		//int length = snprintf(message, sizeof_array(message), "Hello World! \r\n");

		//Ask for user's name
		/*
		int length = snprintf(message, sizeof_array(message), "What is your name? \r\n");
		*/

		//Write the message
		/*
		uart.Transmit(reinterpret_cast<uint8_t*>(message), length);
		*/

		//Get the name, and where it ends
		/*
		int nameBytes = uart.TryReceive(reinterpret_cast<uint8_t*>(name), sizeof_array(name) - 1);
		*/

		//Add a newline character for where the name ends, transmit name, print name
		/*
		if (name[nameBytes - 1] == '\n' || name[nameBytes - 1] == '\r') {
			snprintf(response, sizeof_array(response), "Hello %s !", name);
			uart.Transmit(reinterpret_cast<uint8_t*>(response), sizeof_array(response)+1);
		}
		*/

		int originalCount = counter;
		if (counter >= 16) {
			counter -= counter % 16;
			led0Out.Set(true);
		}


		//Sleep 10000ms for name
		//osDelay(10000);
		//Sleep 1000ms for single LED blink
		osDelay(1000);
	}
}

//===================== DO NOT MODIFY BELOW HERE =======================

osThreadId LEDThread1Handle;
int main()
{

	/* Thread 1 definition */
	osThreadDef(LED1, LED_Thread1, osPriorityNormal, 0, 2048);

	/* Start thread 1 */
	LEDThread1Handle = osThreadCreate(osThread(LED1), nullptr);

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */
	while (true)
		BREAKPOINT;
}