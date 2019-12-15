#include <stdio.h>
#include <float.h>

struct MotorVelocity
{
    float v_r;
    float v_l;
};

class MotorControl
{
private:
    MotorVelocity joy2vel_(float x, float y);
public:
    MotorControl(void);

    void drive(float x, float y);
};