/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:34:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/11/29 16:58:50 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc == 1) std::cout << "사용법: ./PmergeMe 인자" << std::endl;
  if (argc < 3) std::cout << "인자는 두 개 이상 넣어주세요" << std::endl;
  std::vector<std::string> arguments(&argv[1], &argv[argc]);
  try {
    PmergeMe pm(arguments);
    pm.printVector();
    pm.sortVector();
    pm.printVector();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}