/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:43:13 by hujeong           #+#    #+#             */
/*   Updated: 2023/07/04 13:22:06 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp";

#include <iostream>

int Account::getNbAccounts(void) {}
int Account::getTotalAmount(void) {}
int Account::getNbDeposits(void) {}
int Account::getNbWithdrawals(void) {}
void Account::displayAccountsInfos(void) {}

Account::Account(int initial_deposit) {
  std::cout << "[19920104_091532] " << _accountIndex;
}

Account::~Account() {}

void Account::makeDeposit(int deposit) {}
bool Account::makeWithdrawal(int withdrawal) {}
int Account::checkAmount(void) const {}
void Account::displayStatus(void) const {}
void Account::_displayTimestamp(void) {}