#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}


void	Account::_displayTimestamp( void ) {
	time_t	now = time(0);
	tm *ltm = localtime(&now);

	std::cout << '[' << 1900 + ltm->tm_year;
	std::cout <<  "0" <<  1 + ltm->tm_mon;
	std::cout << ltm->tm_mday << '_';
	std::cout << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << ']';
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _nbAccounts << ";"; 
	_nbAccounts++;
	std::cout << "amount:" << checkAmount() << ";" << "created" << std::endl;
	_totalAmount += _amount;
}

void	Account::displayStatus( void ) const {
		_displayTimestamp();
		std::cout << " index:" << this->_accountIndex << ";";
		std::cout << "amount:" << checkAmount() << ";";
		std::cout << "deposits:" << _nbDeposits << ";";
		std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << checkAmount() + deposit << ';';
	std::cout << "nb_deposits:" << _nbDeposits + 1<< std::endl;
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	if (withdrawal > _amount) {
		std::cout << "withdrawal:refused" << std::endl; 
		return (0);
	}
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << _amount - withdrawal << ';';
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

Account::~Account ( void ) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "closed" << std::endl;
}