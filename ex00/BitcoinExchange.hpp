/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:11:29 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/28 00:45:40 by hujeong          ###   ########.fr       */
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

 public:
  BitcoinExchange(std::string database);
  void printExchange();
  ~BitcoinExchange();
};

#endif