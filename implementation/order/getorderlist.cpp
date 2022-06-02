#pragma once

#include "getorderlist.h"
#include <iostream>

using namespace std;

ReadOrderHistoryUI::ReadOrderHistoryUI(ReadOrderHistory* control){
	this->logoutControl = control;
}

void ReadOrderHistoryUI::readOrderHistory(){
	cout << "> " << this->readOrderHistoryControl->readOrderHistory() << endl;
	
}