#pragma once

#include "user.h"

class Logout;
class UserRepository;

class LogoutUI{
private:
	Logout* logoutControl;

public:
	LogoutUI(Logout*);
	void logout();
};

class Logout{
private:
	LogoutUI* lgoUI;
	UserRepository* userlist;

public:
	Logout(UserRepository*);
	string logout();
};