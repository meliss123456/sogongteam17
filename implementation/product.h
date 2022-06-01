#pragma once

#include <string>
#include <vector>
#include "order.h"

using namespace std;

class ProductUI {
	ProductCollection* productCollection;
	OrderCollection* orderCollection;
public:
	ProductUI() {};
	ProductUI(ProductCollection* p, OrderCollection* o) {
		this->productCollection = p;
		this->orderCollection = o;
	}
	void startInterface();
	void showProduct();
	void purchaseProduct();
};

class SearchProduct {
public:
	SearchProduct() {};
	void searchProductByName(ProductCollection * pc, string name);
};

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
	string getName(); // 해당 메소드 추가함 -> 검색시 private 꺼내와야함
	string getSellerId(); //해당 메소드 추가함 -> 검색시 private 꺼내와야함
	string getManufacturer();//해당 메소드 추가함 -> 검색시 private 꺼내와야함
	int getPrice();//해당 메소드 추가함 -> 검색시 private 꺼내와야함
};

class ProductCollection {
private:
	Product* ownedProduct[100]; //배열로 초기화 시킴
	int cnt; // 해당 부분 추가함 -> 검색 시, iteration돌기 어려움 따라사 상품 등록시 해당 cnt 올리기!!!!

public:
	ProductCollection();
	bool validateProduct(string name);
	Product* getProductByName(string name);
	Product* getProductByNameAndSellerID(string sellerId, string name); // 해당 메소드 추가함 -> 구매시, 상품명과 상품파매자 아이디 입력받음
	Product* getSoldoutProduct();
	Product* getProducts();
	Product createProduct(string name, string manufacturer, int price, int quantity, string sellerID);
};