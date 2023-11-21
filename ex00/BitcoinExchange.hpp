/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/21 21:22:42 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
 private:
  std::map<std::string, double> exchange_;
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange&);
  BitcoinExchange& operator=(const BitcoinExchange&);

  // 데이터 베이스 파싱
  // 데이터 베이스 라인 체크
  // 데이터 베이스 날짜 체크
  // 데이터 베이스 값 체크(double)

  // Input 파일 파싱
  // Input 파일 line 체크
  // Input 파일 날짜 체크
  // Input 파일 값체크(int 값)

 public:
  BitcoinExchange(std::string database);
  void printExchange();
  ~BitcoinExchange();
};

#endif