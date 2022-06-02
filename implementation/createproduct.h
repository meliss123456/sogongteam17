#pragma once

#include "product.h"
#include <string>

using namespace std;

class CreateProduct;

class CreateProductUI{
private:
	string name;
	string manufacturer;
	int price;
	int quantity;
	CreateProduct* createProductControl;

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