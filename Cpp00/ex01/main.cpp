/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:20:57 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/10 18:03:05 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "PhoneBook.hpp"

void showCommand(void) {
  std::cout << "----------------------------------------------------"
            << "\n\n"
            << "            ☎ My PhoneBook 커맨드 입력 ☎            "
            << "\n\n"
            << "----------------------------------------------------"
            << "\n"
            << "ADD(정보 저장)"
            << " SEARCH(정보 검색)"
            << " EXIT(프로그램 종료)" << std::endl;
}

int main(void) {
  PhoneBook phonebook;
  std::string input;

  showCommand();
  while (true) {
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::clearerr(stdin);
      std::cin.clear();
      std::cout << "\n";
      std::cout << "잘못된 명령어 입니다. 다시 입력해주세요" << std::endl;
    } else if (input == "ADD") {
      phonebook.add();
      showCommand();
    } else if (input == "SEARCH") {
      phonebook.search();
      showCommand();
    } else if (input == "EXIT")
      return 0;
    else
      std::cout << "잘못된 명령어 입니다. 다시 입력해주세요" << std::endl;
  }
  return 0;
}