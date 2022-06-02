#pragma once
#include "user.h"

using namespace std;

class Signup;
class UserRepository;

class SignupUI
{
public:
	Signup *signupControl;
	string ID;
	string PW;
	string name;
	int SID;

	SignupUI(Signup *);
	void completeSignup();
};

class Signup
{
private:
	SignupUI *suUI;
	UserRepository *userlist;

	// 파일 입출력 객체 포인터 선언
	ifstream *fin;
	ofstream *fout;

public:
	// main 함수의 진입점 함수에서 파일 스트림 객체를 매개변수로 받아서 멤버로 초기화
	Signup(UserRepository *, ifstream *, ofstream *);
	User *createNewUser();

	// 파일스트림 객체의 getter
	ifstream *getFin() { return this->fin; }
	ofstream *getFout() { return this->fout; }
};
