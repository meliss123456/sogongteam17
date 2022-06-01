#include "product.h"
#include <iostream>

using namespace std;

void SearchProduct::searchProductByName(ProductCollection* pc, string name) {
	Product* product = pc->getProductByName(name);
	product->getProductDetail();
}


void Product::dedeuctStock(int quantity) {
	this->quantity -= quantity;
}

void Product::getProductDetail() {
	
	cout << this->sellerID << this->name << " " << this->manufacturer << " " << this->price << " " << this->quantity << " " << this->avgRating << endl;
}

string Product::getName() {
	return this->name;
}

string Product::getSellerId() {
	return this->sellerID;
}

string Product::getManufacturer(){
	return this->manufacturer;
}

int Product::getPrice() {
	return this->price;
}

Product* ProductCollection::getProductByName(string name) {
	
	for (int i = 0; i < this->cnt; i++) {
		if (this->ownedProduct[i]->getName() == name) {
			return this->ownedProduct[i];
		}
	}

}

Product* ProductCollection::getProductByNameAndSellerID(string sellerId, string name) {
	for (int i = 0; i < this->cnt; i++) {
		if (this->ownedProduct[i]->getName() == name && this->ownedProduct[i]->getSellerId() == sellerId) {
			return this->ownedProduct[i];
		}
	}
}