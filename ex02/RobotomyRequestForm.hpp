/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:10:30 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/09 00:48:56 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>

#include "AForm.hpp"

class RobotomyRequest : public AForm {
 private:
  const std::string target_;
  RobotomyRequest();
  RobotomyRequest(const RobotomyRequest& other);
  RobotomyRequest& operator=(const RobotomyRequest& other);

 public:
  RobotomyRequest(const std::string& target);
  virtual ~RobotomyRequest();
  const std::string& getTarget() const;
  virtual void execute(Bureaucrat const& executor) const;
};

#endif