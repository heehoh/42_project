/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:34:36 by hujeong           #+#    #+#             */
/*   Updated: 2023/12/04 01:55:46 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc == 1) std::cout << "사용법: ./PmergeMe 인자" << std::endl;
  if (argc < 3) std::cout << "인자는 두 개 이상 넣어주세요" << std::endl;
  std::vector<std::string> arguments(&argv[1], &argv[argc]);
  try {
    PmergeMe pm(arguments);
    std::cout << "---- 정렬 전 ----" << std::endl;
    pm.printVector();
    pm.isSort();
    pm.sortVector();
    std::cout << "---- 정렬 후 ----" << std::endl;
    pm.printVector();
    pm.isSort();

    std::cout << "---- 덱 정렬 전 ----" << std::endl;
    pm.printDeque();
    pm.isDequeSort();
    pm.sortDeque();
    std::cout << "---- 덱 정렬 후 ----" << std::endl;
    pm.printDeque();
    pm.isDequeSort();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}