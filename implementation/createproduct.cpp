#pragma once

#include "createproduct.h"
#include <iostream>
#include <string>

using namespace std;

CreateProductUI::CreateProductUI(CreateProduct* control){
	this->createProductControl = control;
}

void CreateProductUI::completeCreateProduct(){
	cin >> this->name >> this->manufacturer >> this->price >> this->quantity;

	this->createProductControl->createNewProduct(this->name, this->manufacturer, this->price, this->quantity);
	cout << "> " << this->name << this->manufacturer << this->price << this->quantity;
}

CreateProduct::CreateProduct(ProductCollection* productList){
	this->productList = productList;
	this->cpUI = new CreateProductUI(this);

	this->cpUI->completeCreateProduct();
}

void CreateProduct::createNewProduct(string name, string manu, int price, int qty){
	this->productList->createProduct(name, manu, price, qty);
}
