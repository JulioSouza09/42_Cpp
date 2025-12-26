#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts++;
	this->makeDeposit(initial_deposit);
}

Account::~Account(void) {
	;
}

void Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > this->_amount) {
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	return (true);
}

int Account::checkAmount() const {
	return (this->_amount);
}

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}
