#include "login.h"
#include <iostream>

using namespace std;

LoginUI::LoginUI(Login* control) {
	this->loginControl = control;
}

void LoginUI::completeLogin(){
	cin >> this->ID >> this->PW;

	bool islogined = this->loginControl->login(this->ID, this->PW);
	
	if (islogined) cout << this->ID << this->PW << endl;
	else cout << "invalid user info!\n";
}

Login::Login(UserRepository* userlist){
	this->lgiUI = new LoginUI(this);
	this->userlist = userlist;

	this->lgiUI->completeLogin();
}

bool Login::login(string ID, string PW){
	if (!this->userlist->validateUser(ID)){
		User* user = this->userlist->findUser(ID);

		if (user->getPW() == PW) {
			User::setCurrentUser(user);
			return true;
		}

		else {
			return false;
		}
	}
}
