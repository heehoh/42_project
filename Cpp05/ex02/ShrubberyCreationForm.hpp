/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:08:19 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 00:50:59 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 private:
  const std::string target_;
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  static const std::string asciiArt;

 public:
  ShrubberyCreationForm(const std::string& target);
  virtual ~ShrubberyCreationForm();
  const std::string& getTarget() const;
  virtual void execute(Bureaucrat const& executor) const;
};

#endif