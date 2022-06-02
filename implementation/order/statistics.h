#pragma once

#include "product.h"
#include <string>

using namespace std;

class ReadStatistics;

class ReadStatisticsUI{
private:
	string name;
	string manufacturer;
	int price;
	int quantity;
	ReadStatistics* readStatisticsControl;

public:
	CreateProductUI(CreateProduct*);
	void completeCreateProduct();
};

class CreateProduct{
private:
	CreateProductUI* cpUI;
	ProductCollection* productList;

public:
	CreateProduct(ProductCollection*);
	void createNewProduct(string name, string manu, int price, int qty);

};