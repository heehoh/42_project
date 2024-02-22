/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:11:11 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/02 10:42:32 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  void add(void);
  void search(void);
  void showInfo(std::string tmp);
  void showPhoneBook(int idx);
  void showDetailInfo(void);

 private:
  Contact _contact[8];
  int _contact_idx;
};

#endif