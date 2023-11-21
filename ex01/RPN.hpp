/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:24:56 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/21 22:12:00 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
 private:
  std::stack<int> _s;
  RPN(const RPN &);
  const RPN &operator=(const RPN &);

 public:
  RPN();
  ~RPN();
  void parseParam(std::string param);
  void addParam(const std::string &param);
  void showResult();
};

#endif