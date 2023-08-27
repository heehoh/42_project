/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:04:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/08/22 00:29:26 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

int main(int ac, char **av) {
  if (ac != 4) {
    std::cout << "사용법: ./a.out <파일 이름> <바꿀 문자열> <새로운 문자열>"
              << std::endl;
    return 1;
  }
  std::ifstream ifs;
  ifs.open(av[1]);
  if (!ifs.is_open()) {
    std::cout << "파일 열기 실패" << std::endl;
    return 1;
  }
  std::ofstream ofs;
  ofs.open(std::string(av[1]) + ".replace");
  if (!ofs.is_open()) {
    std::cout << "파일 생성 실패" << std::endl;
    return 1;
  }
  std::string s1(av[2]);
  std::string s2(av[3]);
  std::string line;
  while (std::getline(ifs, line)) {
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos) {
      line.erase(pos, s1.size());
      line.insert(pos, s2);
    }
    ofs << line << std::endl;
  }
  ifs.close();
  ofs.close();
  return 0;
}