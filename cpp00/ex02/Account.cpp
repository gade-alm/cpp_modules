#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp( void )
{
	time_t	now = time(0);
	tm *ltm = localtime(&now);

	std::cout << '[' << 1900 + ltm->tm_year;
	std::cout <<  "0" <<  1 + ltm->tm_mon;
	std::cout << ltm->tm_mday << '_';
	std::cout << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << ']';
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _nbAccounts << ";"; 
	std::cout << "amount:" << initial_deposit << ";created" << std::endl;
	this->_totalAmount += initial_deposit;
	Account::_nbAccounts ++;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
}
