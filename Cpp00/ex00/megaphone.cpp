/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:05:59 by hujeong           #+#    #+#             */
/*   Updated: 2023/06/30 20:48:39 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }
  for (int i = 1; i < argc; i++) {
    for (int j = 0; argv[i][j]; j++)
      argv[i][j] = static_cast<char>(std::toupper(argv[i][j]));
    std::cout << argv[i];
  }
  std::cout << std::endl;
  return 0;
}
