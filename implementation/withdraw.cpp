#pragma once

#include "withdraw.h"
#include "user.h"
#include <iostream>

using namespace std;

void WithdrawAccountUI::withdrawAccount(){
	cin >> this->ID;

	this->withdrawControl->withdrawUserAccount();
	cout << ID << endl;
}

WithdrawAccount::WithdrawAccount(UserRepository* userlist, WithdrawAccount* control){
	this->userlist = userlist;
	this->waUI = new WithdrawAccountUI();

	this->waUI->withdrawControl = control;

	this->waUI->withdrawAccount();

}

void WithdrawAccount::withdrawUserAccount(){
	this->userlist->deleteUser(this->waUI->ID);
}
