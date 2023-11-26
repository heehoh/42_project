/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/26 15:12:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str) {
  std::size_t first = str.find_first_not_of(" \t\n\r");
  std::size_t last = str.find_last_not_of(" \t\n\r");
  if (first == std::string::npos || last == std::string::npos) return "";
  return str.substr(first, last - first + 1);
}

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange&) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange&) {
  return *this;
}
BitcoinExchange::~BitcoinExchange() {
  dataBase_.close();
  input_.close();
}

BitcoinExchange::BitcoinExchange(const std::string& input)
    : dataBase_(DATA_BASE), input_(input) {
  if (!dataBase_.is_open()) {
    throw std::runtime_error("Error: data.csv가 열리지 않습니다.");
  }
  if (!input_.is_open()) {
    dataBase_.close();
    throw std::runtime_error("Error: input 파일이 열리지 않습니다.");
  }
  parseDB();
}

int convertDate(const std::string& date, int start, int end) {
  std::stringstream ss;
  int time;

  for (int i = start; i < end; ++i) {
    if (date[i] < '0' || date[i] > '9')
      throw std::runtime_error("Error: 날짜 형식이 올바르지 않습니다.");
  }
  ss << date.substr(start, end);
  ss >> time;
  return time;
}

Date parseDate(const std::string& date) {
  std::size_t pos1 = 0;
  std::size_t pos2;

  pos1 = date.find("-", pos1);
  if (pos1 == std::string::npos)
    throw std::runtime_error("Error: 날짜 형식이 올바르지 않습니다.");

  pos2 = date.find("-", pos1 + 1);
  if (pos2 == std::string::npos)
    throw std::runtime_error("Error: 날짜 형식이 올바르지 않습니다.");

  int year = convertDate(date, 0, pos1);
  int month = convertDate(date, pos1 + 1, pos2);
  int day = convertDate(date, pos2 + 1, date.length());

  return Date(year, month, day);
}

float parseVal(const std::string& val) {
  std::stringstream ss;
  float value;

  ss << val;
  ss >> value;

  ss << value;
  if (val != ss.str())
    throw std::runtime_error("Error: 값 형식이 올바르지 않습니다");
  if (value < 0) throw std::runtime_error("Error: 값은 양수여야 합니다.");
  return value;
}

void checkFirstLine(const std::string& line, const std::string& del,
                    const std::string& key, const std::string& value) {
  std::size_t pos = 0;
  pos = line.find(del, pos);
  if (pos == std::string::npos)
    throw std::runtime_error("Error: 구분자 형식이 올바르지 않습니다.");
  if (trim(line.substr(0, pos)) != key) {
    throw std::runtime_error("Error: 유효하지 않은 Key 명칭입니다.");
  }
  if (trim(line.substr(pos + 1)) != value)
    throw std::runtime_error("Error: 유효하지 않은 value 명칭입니다.");
}

void BitcoinExchange::parseDBLine(const std::string& line,
                                  const std::string& del) {
  std::size_t pos = 0;
  pos = line.find(del, pos);
  if (pos == std::string::npos)
    throw std::runtime_error("Error: 구분자 형식이 올바르지 않습니다.");
  exchange_[parseDate(trim(line.substr(0, pos)))] =
      parseVal(trim(line.substr(pos + 1)));
}

void BitcoinExchange::parseDB() {
  std::string line;

  std::getline(dataBase_, line);
  checkFirstLine(line, ",", DATE, EXCHANGE);
  while (std::getline(dataBase_, line)) parseDBLine(line, ",");
}

void BitcoinExchange::parseInputLine(const std::string& line,
                                     const std::string& del) {
  std::size_t pos = 0;
  pos = line.find(del, pos);
  if (pos == std::string::npos)
    throw std::runtime_error("Error: 구분자 형식이 올바르지 않습니다.");
  const Date& date = parseDate(trim(line.substr(0, pos)));
  const float value = parseVal(trim(line.substr(pos + 1)));

  if (value > 1000)
    throw std::runtime_error("Error: 너무 큰 숫자가 들어왔습니다.");
  std::map<Date, float>::iterator it = exchange_.lower_bound(date);
  if (it == exchange_.end())
    throw std::runtime_error(
        "Error: 데이터베이스 안에 해당하는 날짜의 비트코인 환율정보가 존재하지 "
        "않습니다.");
  std::cout << date << " => " << value << " = " << value * it->second
            << std::endl;
}

void BitcoinExchange::parseInput() {
  std::string line;

  std::getline(input_, line);
  checkFirstLine(line, "|", DATE, VALUE);
  while (std::getline(input_, line)) {
    try {
      parseInputLine(line, "|");
    } catch (std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}