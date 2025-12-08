#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0; /// ????????????????????????????

// GETERS
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::_displayTimestamp()
{
    std::time_t timestamp = std::time(nullptr);
    std::tm *tm = std::localtime(&timestamp); // ????????
    std::cout << "[" 
              << tm->tm_year + 1900
              << std::setw(2) << std::setfill('0') << tm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << tm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << tm->tm_mday
              << "_"
              << std::setw(2) << std::setfill('0') << tm->tm_hour
              << std::setw(2) << std::setfill('0') << tm->tm_min
              << std::setw(2) << std::setfill('0') << tm->tm_sec
              << "] ";
}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";deposits:" << _nbDeposits 
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = checkAmount();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit; 
	_displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << _amount 
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = checkAmount();
	if (withdrawal > p_amount)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex 
                  << ";p_amount:" << _amount 
                  << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
              << ";p_amount:" << p_amount 
              << ";withdrawal:" << withdrawal 
              << ";amount:" << _amount 
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::displayAccountsInfos()
{
	std::cout << "accounts:" << _nbAccounts 
              << ";total:" << _totalAmount 
              << ";deposits:" << _totalNbDeposits 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
