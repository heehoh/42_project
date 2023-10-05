/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:57:24 by hujeong           #+#    #+#             */
/*   Updated: 2023/10/05 11:22:54 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int& gradeToSign, int& gradeToExec)
    : name_(name),
      signed_(false),
      gradeToSign_(gradeToSign),
      gradeToExec_(gradeToExec) {}

Form::~Form() {}

const std::string& Form::getName() const { return name_; }
const bool& Form::getSigned() const { return signed_; }