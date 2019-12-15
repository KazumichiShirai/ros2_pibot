#include <math.h>
#include "tb6612_driver.hpp"

unsigned int in1;
unsigned int in2;
unsigned int pwm;
unsigned int stby;

TB6612Driver::TB6612Driver(MotorPosition motor_position)
{
    if(motor_position == MotorPosition::RIGHT_MOTOR){
        in1 = 2;
        in2 = 3;
        pwm = 4;
        stby = 17;
    }else{
        in1 = 14;
        in2 = 15;
        pwm = 18;
        stby = 23;
    }

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
    dutycycle = (unsigned)(v * 255.0);
    gpioPWM(pwm, dutycycle);
}

TB6612Driver::~TB6612Driver(void)
{
    gpioWrite(stby, 0);
    gpioWrite(in1, 0);
    gpioWrite(in2, 0);
    gpioPWM(pwm, 0);
}
