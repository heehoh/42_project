/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:28:55 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 00:47:43 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 private:
  const std::string target_;
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

 public:
  PresidentialPardonForm(const std::string& target);
  virtual ~PresidentialPardonForm();
  const std::string& getTarget() const;
  virtual void execute(Bureaucrat const& executor) const;
};

#endif