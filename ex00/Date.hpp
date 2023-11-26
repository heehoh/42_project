/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:43:57 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/26 16:39:50 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATE_HPP
#define DATE_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

class Date {
 private:
  int year_;
  int month_;
  int day_;
  Date();
  Date& operator=(const Date&);

 public:
  Date(const Date&);
  Date(int year, int month, int day);
  ~Date();
  bool operator<(const Date& date) const;
  int getYear() const;
  int getMonth() const;
  int getDay() const;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

#endif