#include <pigpio.h>

enum class MotorPosition {RIGHT_MOTOR, LEFT_MOTOR};

class TB6612Driver
{
private:
    unsigned int in1;
    unsigned int in2;
    unsigned int pwm;
    unsigned int stby;
public:
    TB6612Driver(MotorPosition motor_position);
    void rotate(float v);
    ~TB6612Driver();
};
