#pragma once

#include <string>
#include <vector>
#include "product.h"

using namespace std;

class OrderUI
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

class Purchase
{
public:
	void createOrder(string userId, string sellerId, string productName, ProductCollection *pc, OrderCollection *oc);
};


class Order
{
private:
	string buyer;	//해당 부분은 userRef선언으로 대체 가능하지 않은가 의문 -> 일단 addOrder 파라미터는 string으로 user(buyer) 정보 받는 것으로 함
	string product; //해당 부분은 productRef로 대체 가능한듯
	string company;
	int price;
	int rate = 0;
	OrderCollection *ownedProductCollection;
	Product *productRef;

	ifstream *fin;
	ofstream *fout;

public:
	Order(ifstream *, ofstream *){};
	Order(string buyer, string userId, OrderCollection *ownedProductCollection, Product *productRef);
	void getOrderItemDetails();
	void rateOrderItem(string product, int rate);

	ifstream *getFin() { return this->fin; }
	ofstream *getFout() { return this->fout; }
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
	string getStatistics();

	//getTotalPrice,getTotalRate,calculateTotalPrice,calculateTotalRate()를 하나로 묶음
// => getStatistics()
};
