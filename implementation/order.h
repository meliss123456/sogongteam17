#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

class Purchase
{
public:
	void createOrder(string userId, string sellerId, string productName, ProductCollection *pc, OrderCollection *oc);
};

class OrderCollection
{
private:
	Order *ownedProduct[100]; //배열 초기화 시킴
	int cnt = 0;			  //cnt도 추가함

public:
	void addOrder(Product *p, string buyer, string userId);
	void removeOrder(string product);
	Order *findFirst();
	Order *getNext();
	string getOrderItem(string product);
	int getTotalPrice(Product *);
	int getTotalRate(Product *);
	int calculateTotalPrice();
	double calculateTotalRate();
};

class Order
{
private:
	string buyer;	//해당 부분은 userRef선언으로 대체 가능하지 않은가 의문 -> 일단 addOrder 파라미터는 string으로 user(buyer) 정보 받는 것으로 함
	string product; //해당 부분은 productRef로 대체 가능한듯
	string company;
	int price;
	int rate = 0;
	int totalPrice;
	int totalRate = 0;
	OrderCollection *ownedProductCollection;
	Product *productRef;

public:
	Order(){};
	Order(string buyer, string userId, OrderCollection *ownedProductCollection, Product *productRef);
	void getOrderItemDetails();
	void rateOrderItem(string product, int rate);
};