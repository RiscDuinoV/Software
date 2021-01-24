#include <dev/io.h>         // IO PERIPHERIALS
#include <dev/sio.h>        // UART
#include "FreeRTOS.h"
#include "task.h"
#include <riscv/mtime.h>    // delay

TaskHandle_t Task1_Handler;
TaskHandle_t Task2_Handler;

void Task1( void *pvParameters )
{
    for( ;; )
    {
        sio_puts(UART_USB_BASE, "Hello from Task1\n\r");
        delay(1000);
        vTaskResume(Task2_Handler);
        vTaskSuspend(NULL);
    }
}
void Task2( void *pvParameters )
{
    for( ;; )
    {
        sio_puts(UART_USB_BASE, "Hello from Task2\n\r");   
        delay(1000);
        vTaskResume(Task1_Handler);
        vTaskSuspend(NULL);
    }
}

int main(void)
{
    uint8_t start = 1;
    BaseType_t ret = xTaskCreate(
        Task1,
        "Task1",
        256,
        NULL,
        2,
        &Task1_Handler
    );
    if (ret == -1)
    {
        start = 0;
    }
    sio_puts(UART_USB_BASE, "ret1 = ");
    sio_printNumber(UART_USB_BASE, ret, 16);
    sio_puts(UART_USB_BASE, "\n");
    ret = xTaskCreate(
        Task2,
        "Task2",
        256,
        NULL,
        2,
        &Task2_Handler
    );
    if (ret == -1)
    {
        start = 0;
    }
    else
    {
        vTaskSuspend(Task2_Handler);
    }
    
    sio_puts(UART_USB_BASE, "ret2 = ");
    sio_printNumber(UART_USB_BASE, ret, 16);
    sio_puts(UART_USB_BASE, "\n");
    if (start == 1)
        vTaskStartScheduler();
    while (1)
    {
        for (int i = 0; i < 8; i++)
        { 
            OUTB(IO_LED, (1 << i));
            delay(100);
        }
        for (int i = 0; i < 8; i++)
        {
            OUTB(IO_LED, (0x80 >> i));
            delay(100);
        }
    }
    return 0;
}
