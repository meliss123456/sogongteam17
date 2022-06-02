#pragma once

#include <string>
#include <vector>
#include "order.h"

using namespace std;

class ProductUI
{
	ProductCollection *productCollection;
	OrderCollection *orderCollection;

public:
	ProductUI(){};
	ProductUI(ProductCollection *p, OrderCollection *o)
	{
		this->productCollection = p;
		this->orderCollection = o;
	}
	void startInterface();
	void showProduct();
	void purchaseProduct();
};

class SearchProduct
{
public:
	SearchProduct(){};
	void searchProductByName(ProductCollection *pc, string name);
};

class Product
{
private:
	string name;
	string manufacturer;
	int price;
	int quantity;
	double avgRating;
	string sellerID;
	ProductCollection *productCollection;

public:
	Product(string name, string manufacturer, int price, int qty, string sellerID, ProductCollection *productList);
	void dedeuctStock(int quantity);
	void getProductDetail();
	string getName();
	string getSellerID();
	string getManufacturer();
	int getPrice();
	int getQty();
};

class ProductCollection
{
private:
	Product *ownedProduct[100];
	int cnt;

public:
	ProductCollection();

	int getCnt() { return this->cnt; }
	bool validateProduct(string name);
	Product *getProductByName(string name);
	Product *getProductByNameAndSellerID(string sellerId, string name); // 해당 메소드 추가함 -> 구매시, 상품명과 상품파매자 아이디 입력받음
	Product *getSoldoutProduct();
	Product *getProducts();
	Product createProduct(string name, string manufacturer, int price, int quantity);
};