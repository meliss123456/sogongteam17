#pragma once

#include "logout.h"
#include <iostream>

using namespace std;

LogoutUI::LogoutUI(Logout* control){
	this->logoutControl = control;
}

void LogoutUI::logout(){
	cout << "> " << this->logoutControl->logout() << endl;
	
}

Logout::Logout(UserRepository* userlist){
	this->lgoUI = new LogoutUI(this);
	this->userlist = userlist;

	this->lgoUI->logout();
}

string Logout::logout(){
	if (User::getCurrentUser) {
		string logoutUser = User::getCurrentUser()->getID();
		User::setCurrentUser(nullptr);

		return logoutUser;
	}

	return "";
}
