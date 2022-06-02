#pragma once

#include "user.h"

class WithdrawAccount;
class UserRepository;

class WithdrawAccountUI {
public:
	string ID;
	WithdrawAccount* withdrawControl;

	void withdrawAccount();
};

class WithdrawAccount {
private:
	WithdrawAccountUI* waUI;
	UserRepository* userlist;

public:
	WithdrawAccount(UserRepository*, WithdrawAccount*);
	void withdrawUserAccount();
};