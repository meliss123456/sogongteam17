#pragma once
#include "user.h"

using namespace std;

class Signup;
class UserRepository;

class SignupUI{
public:
	Signup* signupControl;
	string ID;
	string PW;
	string name;
	int SID;

	SignupUI(Signup*);
	void completeSignup();
};

class Signup{
private:
	SignupUI* suUI;
	UserRepository *userlist;

public:
	Signup(UserRepository*);
	User* createNewUser();
};

