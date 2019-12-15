#include <pigpio.h>

enum class MotorPosition {RIGHT_MOTOR, LEFT_MOTOR};

class TB6612Driver
{
private:

public:
    TB6612Driver(MotorPosition motor_position);
    void rotate(float v);
    ~TB6612Driver();
};
