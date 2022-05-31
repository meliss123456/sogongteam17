#pragma once
#include <string>
#include "user.h"

using namespace std;

class SignupUI {
public:
	void completeSignup();
};

class Signup {
private:
	SignupUI* suUI;
	UserRepository *userlist;

public:
	Signup(UserRepository*);
	User createNewUser();
};

