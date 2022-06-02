#pragma once

#include "signup.h"
#include <iostream>

using namespace std;

Signup::Signup(UserRepository *userlist, ifstream *fin, ofstream *fout)
{
	// collection class 및 file stream 객체 초기화
	this->userlist = userlist;
	this->fin = fin;
	this->fout = fout;

	SignupUI *UI = new SignupUI(this);
	this->suUI = UI;

	UI->completeSignup();
}

User *Signup::createNewUser()
{
	User *newUser = new User(this->suUI->ID, this->suUI->PW, this->suUI->name, this->suUI->SID);
	userlist->addUser(newUser);

	return newUser;
}

SignupUI::SignupUI(Signup *control)
{
	this->SID = 0;
	this->signupControl = control;
}

void SignupUI::completeSignup()
{
	this->signupControl->getFin() >> this->name >> this->SID >> this->ID >> this->PW;

	this->signupControl->createNewUser();
	this->signupControl->getFout() << "> " << this->name << this->SID << this->ID << this->PW << endl;
}
