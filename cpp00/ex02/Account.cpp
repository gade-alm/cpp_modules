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

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ';';
	this->_nbAccounts++;
	std::cout << "amount:" << _amount << ';';
	this->_totalAmount += this->_amount;
	std::cout << "created" << std::endl;
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

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::displayStatus( void ) const
{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "amount:" << this->_amount << ';';
		std::cout << "deposits:" << this->_nbDeposits << ';';
		std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	this->_amount += deposit;
	this->_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ';';
	this->_nbDeposits++;
	this->_totalNbDeposits ++;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->_amount << ';';
	std::cout << "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	std::cout << withdrawal << ';';
	std::cout << "amount:" << this->_amount - withdrawal << ';';
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (1);
}
