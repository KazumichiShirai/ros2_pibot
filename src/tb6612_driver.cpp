#include <iostream>
#include <thread>
#include <mutex>
#include <math.h>
#include "tb6612_driver.hpp"


TB6612Driver::TB6612Driver(MotorPosition motor_position)
{
    static std::once_flag flag;
    std::call_once(flag, gpioInitialise);
    if(motor_position == MotorPosition::RIGHT_MOTOR){
        in1 = 14;
        in2 = 15;
        pwm = 18;
        stby = 23;
    }else{
        in1 = 2;
        in2 = 3;
        pwm = 4;
        stby = 17;
    }
    gpioSetMode(in1, PI_OUTPUT);
    gpioSetMode(in2, PI_OUTPUT);
    gpioSetMode(stby, PI_OUTPUT);
    gpioSetMode(pwm, PI_ALT5);

}

void TB6612Driver::rotate(float v){
    if(v > 0){ //CW
        gpioWrite(in1, 1);
        gpioWrite(in2, 0);
        gpioWrite(stby, 1);
    }else if(v < 0){//CCW
        gpioWrite(in1, 0);
        gpioWrite(in2, 1);
        gpioWrite(stby, 1);
    }else if(v == 0){
        gpioWrite(in1, 0);
        gpioWrite(in2, 0);
        gpioWrite(stby, 1);
    }else{
        gpioWrite(stby, 0);
    }

    if(fabs(v) > 1.0){
        //debug print
        return;
    }

    unsigned dutycycle; //range:[0:255]
    dutycycle = (unsigned)(fabs(v) * 255.0);
    gpioPWM(pwm, dutycycle);
}

TB6612Driver::~TB6612Driver(void)
{
    gpioWrite(stby, 0);
    gpioWrite(in1, 0);
    gpioWrite(in2, 0);
    gpioPWM(pwm, 0);
    gpioTerminate();
    gpioInitialise();
}
