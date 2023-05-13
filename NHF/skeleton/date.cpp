//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "date.h"

std::chrono::system_clock::time_point Date::into_date(int year, int month, int day) {
    std::tm tm = { 0, 0, 0, day, month - 1, year - 1900 }; // Month is 0-based, year is 1900-based
    std::time_t tt = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(tt);
}

void Date::print_date() const{
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);
    char buffer[11];
    std::strftime(buffer, 11, "%Y-%m-%d", std::localtime(&tt));
    std::cout << "Date entered: " << buffer;
}

bool Date::operator==(const Date& in) const {
    return  tp == in.tp;
}

bool Date::operator<(const Date& in) const {
    return tp < in.tp;
}

bool Date::operator>(const Date& in) const {
    return tp > in.tp;
}

bool Date::operator<=(const Date& in) const {
    return tp <= in.tp;
}

bool Date::operator>=(const Date& in) const {
    return tp >= in.tp;
}

std::string Date::toString() const {
    // Convert the time_point to a time_t
    std::time_t tt = std::chrono::system_clock::to_time_t(tp);

    // Convert the time_t to a struct tm
    std::tm tm = *std::localtime(&tt);

    // Format the date as a string
    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d");
    return ss.str();
}


std::ostream& operator<<(std::ostream os, const Date& date) {
    date.print_date();
    return os;
}

Date Contract_date::getBegin() const {
    return begin;
}

Date Contract_date::getEnd() const {
    return end;
}

void Contract_date::setBegin(int year, int month, int day) {
    begin = Date(year, month, day);

}

void Contract_date::setEnd(int year, int month, int day) {
    end = Date(year, month, day);;
}

bool Contract_date::contains(const Date& date_in) const {
    return (date_in >= begin && date_in <= end);
}

Contract_date &Contract_date::operator=(const Contract_date &contractDate_in) {
    if (!(this->begin==contractDate_in.begin && this->end==contractDate_in.end)) {
        this->begin = contractDate_in.begin;
        this->end = contractDate_in.end;
    }
    return *this;
}
