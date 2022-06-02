#pragma once

#include "signup.h"
#include <iostream>

using namespace std;

Signup::Signup(UserRepository* userlist) {
	this->userlist = userlist;

	SignupUI *UI = new SignupUI(this);
	this->suUI = UI;

	UI->completeSignup();
}

User* Signup::createNewUser() {
	User *newUser = new User(this->suUI->ID, this->suUI->PW, this->suUI->name, this->suUI->SID);
	userlist->addUser(newUser);

	return newUser;
}


SignupUI::SignupUI(Signup* control){
	this->SID = 0;
	this->signupControl = control;
}

void SignupUI::completeSignup(){
	cin >> this->name >> this->SID >> this->ID >> this->PW;

	this->signupControl->createNewUser();
	cout << "> " << this->name << this->SID << this->ID << this->PW << endl;

}
