/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/22 18:56:51 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

#define DATA_BASE "data.csv"
class BitcoinExchange {
 private:
  std::map<std::string, float> exchange_;
  std::map<std::string, float> value_;
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  void checkDate(std::string date);  // 데이터베이스와 인풋 파일 둘다 검증
  void checkValue(float value);  // 인풋파일만 검증하면 됨

  void parseDB();
  void parseInput();

 public:
  BitcoinExchange();
  void printExchange();
  ~BitcoinExchange();
};

#endif