/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:44:07 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/26 16:58:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Date.hpp"

Date::Date() {}
Date::Date(const Date& copy) {
  year_ = copy.year_;
  month_ = copy.month_;
  day_ = copy.day_;
}
Date& Date::operator=(const Date&) { return *this; }
Date::~Date() {}

bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {
  std::stringstream ss;
  ss << year_ << "-" << month_ << "-" << day_;
  if (year_ < 0)
    throw std::runtime_error(
        std::string("Error: 연도가 유효하지 않습니다. => ") + ss.str());
  if (month_ < 1 || month_ > 12)
    throw std::runtime_error(std::string("Error: 유효한 월수가 아닙니다. => ") +
                             ss.str());
  int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month == 2 && isLeapYear(year_)) daysInMonth[2] = 29;
  if (day_ < 1 || day_ > daysInMonth[month_])
    throw std::runtime_error(std::string("Error: 유효한 일수가 아닙니다. => ") +
                             ss.str());
};

bool Date::operator<(const Date& other) const {
  return year_ < other.year_ ||
         (year_ == other.year_ && month_ < other.month_) ||
         (year_ == other.year_ && month_ == other.month_ && day_ < other.day_);
}

int Date::getYear() const { return year_; }
int Date::getMonth() const { return month_; }
int Date::getDay() const { return day_; }

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << std::setw(4) << std::setfill('0') << date.getYear() << "-"
     << std::setw(2) << std::setfill('0') << date.getMonth() << "-"
     << std::setw(2) << std::setfill('0') << date.getDay();
  return os;
}