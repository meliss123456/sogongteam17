#pragma once

#include "statistics.h"
#include <iostream>

using namespace std;

//boundary
ReadStatisticsUI::ReadStatisticsUI(ReadStatistics* control){
	this->readStatisticsControl = control;
}

void ReadStatisticsUI::readStatistics(){
	cout << "> " << this->readStatisticsControl->readStatistics() << endl;
	
}

ReadStatistics::ReadStatistics(ProductCollection* productList){

}

Product* showOrderItem::