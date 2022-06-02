#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

class OrderCollection {
private:
	Order* ownedProduct;

public:
	void addOrder(string product);
	void removeOrder(string product);
	Order* findFirst();
	Order* getNext();
	string getOrderItem(string product);
	int getTotalPrice(Product*);
	int getTotalRate(Product*);
	int calculateTotalPrice();
	double calculateTotalRate();
};

class Order {
private:
	string buyer;
	string product;
	string company;
	int price;
	int rate;
	int totalPrice;
	int totalRate;
	OrderCollection* ownedProductCollection;
	Product* productRef;

public:
	void getOrderItemDetails();
	void rateOrderItem(string product, int rate);
};