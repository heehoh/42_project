/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/31 14:10:34 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &) {
  return *this;
}
BitcoinExchange::~BitcoinExchange() {}

void checkDate(std::string &date) {
  if (date.length() != 10)
    throw std::runtime_error("Error: 날짜 형식이 잘못되었습니다.");
  if (date[4] != '-' || date[7] != '-')
    throw std::runtime_error("Error: 날짜 형식이 잘못되었습니다.");
  for (int i = 0; i < 10; i++) {
    if (i == 4 || i == 7) continue;
    if (date[i] < '0' || date[i] > '9')
      throw std::runtime_error("Error: 날짜 형식이 잘못되었습니다.");
  }
}

void checkPrice(std::string &exchangeRate) {
  int dot = 0;
  if (exchangeRate[0] == '-')
    throw std::runtime_error("Error: 가격 형식이 잘못되었습니다.");
  for (int i = 0; i < exchangeRate.length(); ++i) {
    if (exchangeRate[i] == '.') {
      if (i == 0)
        throw std::runtime_error("Error: 가격 형식이 잘못되었습니다.");
      ++dot;
      if (dot > 1)
        throw std::runtime_error("Error: 가격 형식이 잘못되었습니다.");
      continue;
    }
    if (exchangeRate[i] < '0' || exchangeRate[i] > '9')
      throw std::runtime_error("Error: 가격 형식이 잘못되었습니다.");
  }
}

void checkInput(std::string &input) {}

BitcoinExchange::BitcoinExchange(std::string database) {
  std::ifstream ifs(database);
  std::string line;
  std::string key;
  double value;

  if (!ifs.is_open())
    throw std::runtime_error("Error: 데이터 베이스 파일을 열 수 없습니다.");
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    std::stringstream ss(line);
    std::getline(ss, key, ',');
    ss >> value;
    exchange_[key] = value;
  }
}

void BitcoinExchange::printExchange() {
  std::map<std::string, double>::iterator it = exchange_.begin();
  while (it != exchange_.end()) {
    std::cout << it->first << ": " << std::fixed << std::setprecision(2)
              << it->second << std::endl;
    it++;
  }
}