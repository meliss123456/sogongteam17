#pragma once
#include <string>
#include <vector>

using namespace std;

class User {
private:
	string ID;
	string password;
	string name;
	int SID;

public:
	static User* currentUser;

	User(string ID, string PW, string name, int SID);
	~User();

	static User* getCurrentUser();
	static void setCurrentUser(User* user);
	static User createUser(string ID, string PW, string name, int SID);
	string getID() { return this->ID; }
	string getPW() { return this->password; }
	void deleteUser();
};

class UserRepository {
private:
	vector<User*> userlist;
public:
	void addUser(User*);
	void deleteUser(string ID);
	User* findUser(string ID);
	bool validateUser(string ID);
};