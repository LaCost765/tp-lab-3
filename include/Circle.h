//
// Created by egor on 13.11.2019.
//

#ifndef TASK1_CIRCLE_H
#define TASK1_CIRCLE_H

#include <cmath>

const double pi = 3.14;

class Circle
{
public:

    Circle(double radius)
    {
        setRadius(radius);
    }

    void setRadius(double radius);

    void setFerence(double ference);

    void setArea(double area);

    double getRadius();

    double getFerence();

    double getArea()
    ;

private:
    double radius{};
    double ference{};
    double area{};
};
#endif //TASK1_CIRCLE_H
