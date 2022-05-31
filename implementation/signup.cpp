#pragma once

#include "signup.h"
#include "user.h"
#include <stdio.h>

using namespace std;

Signup::Signup(UserRepository* userlist) {
	this->userlist = userlist;

	SignupUI *UI = new SignupUI();
	this->suUI = UI;
}

User Signup::createNewUser() {
	string id, pw, name;
	int SID = 0;

	scanf("%s %s %s %d", &id, &pw, &name, &SID);

	User *newUser = new User(id, pw, name, SID);
	userlist->addUser(newUser);

	printf("\n");
}