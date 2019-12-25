//
// Created by egor on 13.11.2019.
//

#include <iostream>
#include "DateTime.h"
using namespace std;

int main()
{

    auto* date1 = new DateTime(22,12,2019);
    auto* date2 = new DateTime();

    cout << "date1 and date2 - pointers to objects of DateTime class" << endl;
    cout << "date1->getToday() = " << date1->getToday() << endl;
    cout << "date1->getYesterday() = " << date1->getYesterday() << endl;
    cout << "date1->getTomorrow() = " << date1->getTomorrow() << endl;

    return 0;
}