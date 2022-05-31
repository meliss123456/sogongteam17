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
	void dedeuctStock(int quantity);
	void getProductDetail();
};

class ProductCollection {
private:
	Product* ownedProduct;

public:
	bool validateProduct(string name);
	Product* getProductByName(string name);
	Product* getSoldoutProduct();
	Product* getProducts();
	Product createProduct(string name, string manufacturer, int price, int quantity, string sellerID);
};