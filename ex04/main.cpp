/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:04:42 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/18 15:04:30 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>

int main(int ac, char **av) {
  if (ac != 4) return 1;
  std::ifstream ifs;
  ifs.open(av[1]);
  if (!ifs.is_open()) return 1;
  std::ofstream ofs;
  ofs.open(std::string(av[1]) + ".replace");
  if (!ofs.is_open()) return 1;
  std::string s1(av[2]);
  std::string s2(av[3]);
  std::string line;
  while (std::getline(ifs, line)) {
    size_t pos;
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