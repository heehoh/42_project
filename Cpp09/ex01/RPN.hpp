/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:24:56 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/26 18:25:48 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>

class RPN {
 private:
  std::stack<double> stack_;
  RPN(const RPN &);
  const RPN &operator=(const RPN &);

 public:
  RPN();
  ~RPN();
  void calculate(const std::string &input);
  void showResult();
};

#endif