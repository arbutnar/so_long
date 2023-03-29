#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	timeStamp( void )
{
	time_t		current_time;
	struct tm	*local_time;

	time(&current_time);
	local_time = localtime(&current_time);
	std::cout << '[' << 1900 + local_time->tm_year;
	if (local_time->tm_mon < 9)
		std::cout << '0';
	std::cout << 1 + local_time->tm_mon;
	if (local_time->tm_mday < 10)
		std::cout << '0';
	std::cout << local_time->tm_mday << '_';
	if (local_time->tm_hour < 10)
		std::cout << '0';
	std::cout << local_time->tm_hour;
	if (local_time->tm_min < 10)
		std::cout << '0';
	std::cout << local_time->tm_min;
	if (local_time->tm_sec < 10)
		std::cout << '0';
	std::cout << local_time->tm_sec << ']';
	
}

Account::Account( int initial_deposit )
	: _accountIndex {_nbAccounts}, _amount {initial_deposit} {
		timeStamp( );
		std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
		_totalAmount += _amount;
		_nbAccounts += 1;
}

Account::~Account( ) {
	timeStamp( );
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	timeStamp( );
	std::cout << "account:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawal:" << _totalNbWithdrawals <<  std::endl;
}

void	Account::makeDeposit( int deposit )
{
	timeStamp( );
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposits:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	timeStamp( );
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		checkAmount( );
		return (0);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (1);
}

int		Account::checkAmount( void ) const
{
	timeStamp( );
	std::cout << "refused" << std::endl;
	return (0);
}

void	Account::displayStatus( void ) const
{
	timeStamp( );
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
