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

	User getCurrentUser();
	void setCurrentUser(User user);
	bool validateUser();
	static User createUser(string ID, string PW, string name, int SID);
	static void deleteUser();
};

class UserRepository {
private:
	vector<User*> userlist;
public:
	void addUser(User*);
	void deleteUser(string userID);
};