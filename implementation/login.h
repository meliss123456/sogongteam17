#pragma once

#include "user.h"
#include <string>

class Login;
class UserRepository;

class LoginUI {
private:
	string ID, PW;
	Login* loginControl;

public:
	LoginUI(Login*);
	void completeLogin();
};

class Login {
private:
	LoginUI* lgiUI;
	UserRepository* userlist;

public:
	Login(UserRepository*);
	bool login(string ID, string PW);

};