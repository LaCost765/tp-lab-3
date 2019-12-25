//
// Created by egor on 13.11.2019.
//
#include <iostream>
#include "Circle.h"

double calcDelta()
{
    auto* circleRow = new Circle(6378.1);

    circleRow->setFerence(circleRow->getFerence() + 1);

    std::cout << "Gap = " << circleRow->getRadius() - 6378.1 << std::endl;

    return circleRow->getRadius() - 6378.1;
}

double calcCost()
{
    const int concretePrice = 1000;
    const int boundPrice = 2000;
    const int roadWidth = 1;

    double totalCost = 0;

    auto* pool = new Circle(3);

    auto* poolWithRoad = new Circle(pool->getRadius() + roadWidth);

    totalCost += (poolWithRoad->getArea() - pool->getArea()) * concretePrice;

    totalCost+= poolWithRoad->getFerence() * boundPrice;

    std::cout << "Total cost = " << totalCost << std::endl;

    return totalCost;
}
