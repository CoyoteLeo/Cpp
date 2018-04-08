#include <string>
#include <cmath>

class Robot
{
   public:
    Robot();
    Robot(double x);
    Robot(double x, double y);
    Robot(double x, double y, double power);
    double getX();
    double getY();
    double getPower();
    void move(double x, double y);
    std::string speak(std::string content);
    void charge(double p);

   private:
    double x;
    double y;
    double power;
};

Robot::Robot()
{
    this->x = 0;
    this->y = 0;
    this->power = 100;
}
Robot::Robot(double x)
{
    this->x = x;
    this->y = 0;
    this->power = 100;
}
Robot::Robot(double x, double y)
{
    this->x = x;
    this->y = y;
    this->power = 100;
}
Robot::Robot(double x, double y, double power)
{
    this->x = x;
    this->y = y;
    this->power = (power > 0 ? power : 0);
}
double Robot::getX()
{
    return x;
}
double Robot::getY()
{
    return y;
}
double Robot::getPower()
{
    return power;
}
void Robot::move(double x, double y)
{
    if (power > 0)
    {
        double consume = sqrt(x * x + y * y);
        if (power > consume)
        {
            this->x += x;
            this->y += y;
            power -= consume;
        }
        else
        {
            this->x += x * power / consume;
            this->y += y * power / consume;
            power = 0;
        }
    }
}
std::string Robot::speak(std::string content)
{
    std::string result = "";
    int now;
    for (unsigned int i = 0; i < content.length(); i++)
    {
        now = (int)content[i];
        if (now > 64 && now < 91)  // upper
        {
            if (power < 2)
                break;
            power -= 2;
            result += (char)(now + 32);
        }
        else if (now > 96 && now < 123)  // lower
        {
            if (power < 1)
                break;
            power -= 1;
            result += (char)(now - 32);
        }
        else  // other
        {
            if (power < 0.5)
                break;
            power -= 0.5;
            result += content[i];
        }
    }
    return result;
}
void Robot::charge(double p)
{
    power += p;
    power = (power > 0 ? power : 0);
}