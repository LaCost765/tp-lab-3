//
// Created by egor on 13.11.2019.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H

#include <ctime>
#include <string>

class DateTime
{
public:
    DateTime(int day, int month, int year);
    DateTime();
    DateTime(const DateTime* other);

    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int N);
    std::string getPast(unsigned int N);
    int getDifference(DateTime&);

//private:
    tm* _timeInfo;
};

#endif //TASK1_DATETIME_H
