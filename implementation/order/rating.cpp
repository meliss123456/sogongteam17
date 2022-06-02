#pragma once

#include "rating.h"
#include <iostream>

using namespace std;

//boundary
RatingUI::RatingUI(Rating* control){
	this->ratingControl = control;
}

void RatingUI::rating(){
	cout << "> " << this->ratingControl->rating() << endl;
	
}