/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:08:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/10 13:06:38 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>

const std::string ShrubberyCreationForm::asciiArt =
    "                   o000000oo\n"
    "                  00000000000o\n"
    "                 00000000000000\n"
    "              oooooo  00000000  o88o\n"
    "           ooOOOOOOOoo  ```''  888888\n"
    "         OOOOOOOOOOOO'.qQQQQq. `8888'\n"
    "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
    "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
    "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
    "           OOOOOOOOO `QQQQQQ/ /QQ'\n"
    "             OO:F_P:O `QQQ/  /Q'\n"
    "                \\ \\. \\ |  // |\n"
    "                d\\ \\\\\\|_////\n"
    "                qP| \\\\ _' `|Ob\n"
    "                   \\  / \\  \\Op\n"
    "                   |  | O| |\n"
    "           _       /\\. \\_/ /\\\n"
    "            `---__/|_\\\\   //|  __\n"
    "                  `-'  `-'`-'-'\n";

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target_("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm("ShrubberyCreationForm", 145, 137), target_(other.target_) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this == &other) return *this;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string& ShrubberyCreationForm::getTarget() const { return target_; }

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  AForm::execute(executor);
  std::ofstream ofs(target_ + "_shrubbery");
  if (!ofs.is_open()) {
    std::cout << "파일 오픈 에러: " << target_ << "_shrubbery" << std::endl;
    return;
  }
  ofs << asciiArt;
  ofs.close();
  std::cout << target_ << "_shrubbery 파일이 생성되었습니다." << std::endl;
}
