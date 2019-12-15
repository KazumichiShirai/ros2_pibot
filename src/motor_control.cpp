#include <stdio.h>
#include <iostream>
#include <math.h>
#include "motor_control.hpp"
#include "tb6612_driver.hpp"

TB6612Driver tb6612_right(MotorPosition::RIGHT_MOTOR);
TB6612Driver tb6612_left(MotorPosition::LEFT_MOTOR);

MotorControl::MotorControl(int pin1)
{
    std::cout << pin1;
}

MotorVelocity MotorControl::joy2vel_(float x, float y)
{
    double th = atan2(y, x);
    double v = hypot(x, y);
    MotorVelocity mv;
    mv.v_l = v * cos(th - M_PI / 4.0);
    mv.v_r = v * sin(th - M_PI / 4.0);

    return mv;
}

void MotorControl::drive(float x, float y)
{
    MotorVelocity mv;
    mv = joy2vel_(x, y);
    tb6612_right.rotate(mv.v_r);
    tb6612_right.rotate(mv.v_l);
}