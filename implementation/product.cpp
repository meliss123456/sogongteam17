#include "product.h"
#include "user.h"
#include <iostream>
#include <vector>

using namespace std;

Product::Product(string name, string manufacturer, int price, int qty, string sellerID, ProductCollection* productList) {
	this->name = name;
	this->manufacturer = manufacturer;
	this->price = price;
	this->quantity = qty;
	this->avgRating = 0.0;
	this->sellerID = sellerID;
	this->productCollection = productList;
}


ProductCollection::ProductCollection(){
	this->cnt = 0;
}

bool ProductCollection::validateProduct(string name){
	for (int i = 0; i < this->cnt; i++) {
		if (this->ownedProduct[i]->getName() == name) {
			return true;
		}

		return false;
	}
}


Product* ProductCollection::getProducts() {
	vector<Product*> productList;

	for (int i = 0; i < this->cnt; i++) {
		if (this->ownedProduct[i]->getSellerID() == User::getCurrentUser()->getID()) {
			productList.push_back(this->ownedProduct[i]);
		}
	}

	return &*productList[0];
}

Product* ProductCollection::getSoldoutProduct() {
	vector<Product*> productList;

	for (int i = 0; i < this->cnt; i++) {
		if (this->ownedProduct[i]->getSellerID() == User::getCurrentUser()->getID() && this->ownedProduct[i]->getQty() == 0) {
			productList.push_back(this->ownedProduct[i]);
		}
	}

	return &*productList[0];
}

Product ProductCollection::createProduct(string name, string manufacturer, int price, int quantity) {
	string sellerID = User::getCurrentUser()->getID();

	this->ownedProduct[++this->cnt] = new Product(name, manufacturer, price, quantity, sellerID, this);
}