/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/25 19:44:24 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>

#include "Date.hpp"

#define DATA_BASE "data.csv"
#define DATE "date"
#define EXCHANGE "exchange_rate"
#define VALUE "value"
class BitcoinExchange {
 private:
  std::map<Date, float> exchange_;
  std::ifstream dataBase_;
  std::ifstream input_;
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);
  void parseDBLine(const std::string& line, const std::string& del);
  void parseInputLine(const std::string& line, const std::string& del);

 public:
  BitcoinExchange(const std::string& input);
  ~BitcoinExchange();
  void parseDB();
  void parseInput();
};

#endif