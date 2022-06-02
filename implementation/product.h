#pragma once

#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string name;
	string manufacturer;
	int price;
	int quantity;
	double avgRating;
	string sellerID;
	ProductCollection* productCollection;

public:
	Product(string name, string manufacturer, int price, int qty, string sellerID, ProductCollection* productList);
	void dedeuctStock(int quantity);
	void getProductDetail();
	string getName();
	string getSellerID();
	string getManufactuerer();
	int getPrice();
	int getQty();
};

class ProductCollection {
private:
	Product* ownedProduct[100];
	int cnt;

public:
	ProductCollection();

	int getCnt() { return this->cnt; }
	bool validateProduct(string name);
	Product* getProductByName(string name);
	Product* getSoldoutProduct();
	Product* getProducts();
	Product createProduct(string name, string manufacturer, int price, int quantity);
};