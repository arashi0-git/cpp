/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:55:38 by aryamamo          #+#    #+#             */
/*   Updated: 2025/04/19 19:49:24 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp() {
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);

    std::cout << "[" << (ltm->tm_year + 1900)
            << std::setw(2) << std::setfill('0') << (ltm->tm_mon + 1)
            << std::setw(2) << std::setfill('0') << ltm->tm_mday
            << "_"
            << std::setw(2) << std::setfill('0') << ltm->tm_hour
            << std::setw(2) << std::setfill('0') << ltm->tm_min
            << std::setw(2) << std::setfill('0') << ltm->tm_sec
            << "]";
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" <<std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";closed" << std::endl;
}

int Account::checkAmount( void ) const {
    return _amount;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits()
                << ";withdrawals:" << getNbWithdrawals()
                << std::endl;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}

void Account::makeDeposit( int deposit ){
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";p_amount:" << _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";deposit:" << deposit
                << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";p_amount:" << _amount;
    if(_amount >= withdrawal) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;
        std::cout << ";withdrawal:" << withdrawal
                    << ";amount:" << _amount
                    << ";nb_withdrawals:" << _nbWithdrawals
                    << std::endl;
        return true;
    }
    else {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
}
