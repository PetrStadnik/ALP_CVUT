#include "mbed.h"

DigitalOut myled(LED1);
Serial serial(SERIAL_TX, SERIAL_RX);
Ticker heartBeat;

void handleHeartBeat()
{
    serial.putc('a');
}

int main()
{
    serial.baud(115200);
    serial.putc('i');
    
    heartBeat.attach(&handleHeartBeat, 0.5);

    while (true) {
    }
}
