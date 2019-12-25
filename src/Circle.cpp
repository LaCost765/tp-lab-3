//
// Created by egor on 13.11.2019.
//

#include "Circle.h"

void Circle::setRadius(double radius)
{
    this->radius = radius;
    this->ference = 2 * pi * radius;
    this->area = pi * radius * radius;
}

void Circle::setFerence(double ference)
{
    this->ference = ference;
    this->radius = ference / (2 * pi);
    this->area = pi * this->radius * this->radius;
}

void Circle::setArea(double area)
{
    this->area = area;
    this->radius = sqrt(area / pi);
    this->ference = 2 * pi * this->radius;
}

double Circle::getRadius()
{
    return this->radius;
}

double Circle::getFerence()
{
    return this->ference;
}

double Circle::getArea()
{
    return this->area;
}

