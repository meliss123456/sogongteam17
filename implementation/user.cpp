#pragma once

#include "user.h"
#include <algorithm>
#include <vector>

using namespace std;

User::User(string ID, string PW, string name, int SID){
	this->ID = ID;
	this->password = PW;
	this->name = name;
	this->SID = SID;
}

User::~User(){}

User* User::currentUser = nullptr;

User* User::getCurrentUser(){
	return User::currentUser;
}

void User::setCurrentUser(User* user){
	User::currentUser = user;
}

User User::createUser(string ID, string PW, string name, int SID){
	return User(ID, PW, name, SID);
}

void User::deleteUser(){
	this->~User();
}

void UserRepository::addUser(User* newUser){
	this->userlist.push_back(newUser);
}

void UserRepository::deleteUser(string userID){
	this->userlist.erase(remove_if(this->userlist.begin(), this->userlist.end(), [&](User* x) -> bool { return x->getID() == userID; }), this->userlist.end());
}

User* UserRepository::findUser(string ID) {
	return *find_if(this->userlist.begin(), this->userlist.end(), [&](User* x)->bool {return x->getID() == ID; });
}

bool UserRepository::validateUser(string ID){
	 return this->findUser(ID) == *this->userlist.end();
}
