/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:11:45 by hujeong           #+#    #+#             */
/*   Updated: 2023/09/09 16:05:18 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
 private:
  const std::string name;
  int grade;

 public:
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();

  Bureaucrat& operator=(const Bureaucrat& other);

  const std::string& getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };
};

#endif