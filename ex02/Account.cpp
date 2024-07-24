#include "Account.hpp"
#include <exception>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayStatus() const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
				<< "total:" << Account::_totalAmount << ";"
				<< "deposits:" << Account::_totalNbDeposits << ";"
				<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp() { 
	char ts[16];

	std::time_t t = std::time(NULL);
	if (std::strftime(ts, sizeof ts, "%Y%m%d_%H%M%S", std::localtime(&t)))
		std::cout << "[" << ts << "] ";
}

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_nbDeposits = 0; // Do we actually need to initialize these to 0?
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
}

Account::Account() {
	this->_accountIndex = _nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0; // Do we actually need to initialize these to 0?
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;

	Account::_displayTimestamp() ;
	std::cout << "index:" << this->_accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;
	Account::_displayTimestamp();

	if (this->_amount - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex << ";"
					<< "p_amount:" << p_amount << ";"
					<< "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;

	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << p_amount << ";"
		<< "withdrawal:" << withdrawal << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount() const {
	return this->_amount;
}
