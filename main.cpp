#include "mbed.h"

#define DEBOUNCE_TIME  0.2 // [s]

#define LONG_PRESS 200 // [ms]

#define NUMBER_OF_PERIODS 7
float periods[] = {1.0, 0.5, 0.4, 0.3, 0.2, 0.1, 0.05}; //periods [s]

int period = 0;
int countBtn;

Ticker debounceTimer;
bool pressIgnore = false;

DigitalOut led(LED1);

InterruptIn button(USER_BUTTON);
DigitalIn btnPress(USER_BUTTON);

Ticker btnPressTicker;
Ticker ledTicker;

void flipState();
void clearIgnore();
void pressed();
void controlBtn();


void flipState()
{
    led = !led;
}



void clearIgnore()
{
    pressIgnore = false;
    countBtn = 0;
    debounceTimer.detach();
    btnPressTicker.attach(&controlBtn, 0.01);
}


void pressed()
{
    if (!pressIgnore) {
        //if (fastPeriod) {
        if (period < NUMBER_OF_PERIODS) {
            ledTicker.attach(&flipState, periods[period]/2);
            period++;
        } else {
            ledTicker.detach();
            led = true;
        }
        debounceTimer.attach(&clearIgnore, DEBOUNCE_TIME);
        pressIgnore = true;
    }
}

void controlBtn()
{
    if (btnPress == 1) {
        btnPressTicker.detach();
    }
    countBtn++;
    if (countBtn == LONG_PRESS/10) {
        period = 0;
        btnPressTicker.detach();
        pressed();

    }
}

int main()
{
    button.fall(&pressed);
    pressed();
}
