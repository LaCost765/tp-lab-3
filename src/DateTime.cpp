//
// Created by egor on 13.11.2019.
//
#include "DateTime.h"

const char* months[] = {"january", "february", "march",
                       "april", "may", "june",
                       "july","august", "september",
                       "october", "november", "december"};

const char* daysOfWeek[] = {"sunday", "monday", "tuesday", "wednesday",
                            "thursday", "friday", "saturday"};

DateTime::DateTime(int day, int month, int year)
{
    _timeInfo = new tm();

    _timeInfo->tm_mday = day;
    _timeInfo->tm_mon = month - 1;
    _timeInfo->tm_year = year - 1900;

    mktime(_timeInfo);
}

DateTime::DateTime()
{
    time_t rawtime;
    time(&rawtime);
    this->_timeInfo = localtime(&rawtime);
}

DateTime::DateTime(const DateTime* other)
{
    _timeInfo = new tm();
    *_timeInfo = *(other->_timeInfo);
}

std::string DateTime::getToday()
{
    std::string result = "";

    if (_timeInfo->tm_mday < 10)
        result += "0";

    result += std::to_string(_timeInfo->tm_mday) + " ";
    result += months[_timeInfo->tm_mon];
    result += " " + std::to_string(_timeInfo->tm_year + 1900) + ", ";
    result += daysOfWeek[_timeInfo->tm_wday];

    return result;
}

std::string DateTime::getYesterday()
{
    tm temp = *(this->_timeInfo);

    auto* yesterday = new DateTime(this);

    time_t yesterdayTime = mktime(yesterday->_timeInfo) - 24 * 3600;

    *(yesterday->_timeInfo) = *(localtime(&yesterdayTime));

    std::string result = yesterday->getToday();

    *(this->_timeInfo) = temp;
    return result;
}

std::string DateTime::getTomorrow()
{
    tm temp = *(this->_timeInfo);

    auto* yesterday = new DateTime(this);

    time_t yesterdayTime = mktime(yesterday->_timeInfo) + 24 * 3600;

    *(yesterday->_timeInfo) = *(localtime(&yesterdayTime));

    std::string result = yesterday->getToday();

    *(this->_timeInfo) = temp;
    return result;
}

std::string DateTime::getFuture(unsigned int N)
{
    tm temp = *(this->_timeInfo);

    auto* copy = new DateTime(this);
    time_t currentTime = mktime(copy->_timeInfo);

    currentTime += 24 * 3600 * N;

    auto* future = new DateTime();
    future->_timeInfo = localtime(&currentTime);

    std::string result = future->getToday();

    *(this->_timeInfo) = temp;
    return result;
}

std::string DateTime::getPast(unsigned int N)
{
    tm temp = *(this->_timeInfo);

    auto* copy = new DateTime(this);
    time_t currentTime = mktime(copy->_timeInfo);

    currentTime -= 24 * 3600 * N;

    auto* past = new DateTime();
    past->_timeInfo = localtime(&currentTime);

    std::string result = past->getToday();

    *(this->_timeInfo) = temp;
    return result;
}

int DateTime::getDifference(DateTime & other)
{
    tm temp = *(this->_timeInfo);

    auto* copy = new DateTime(this);
    time_t time1 = mktime(copy->_timeInfo);
    time_t time2 = mktime(other._timeInfo);

    time_t diff = (time1 > time2) ? time1 - time2 : time2 - time1;

    *(this->_timeInfo) = temp;
    return diff / (3600 * 24);
}
