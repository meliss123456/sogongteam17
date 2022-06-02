#include <iostream>
#include "order.h"
#include "product.h"

using namespace std;

void Purchase::createOrder(string userId, string sellerId, string productName, ProductCollection* pc, OrderCollection* oc) {
	Product* product = pc->getProductByNameAndSellerID(sellerId, productName);

	oc->addOrder(product, sellerId, userId);
}


Order::Order(string buyer, string userId, OrderCollection* ownedProductCollection, Product* productRef) {
	this->buyer = buyer;//�ش� �κ��� userRef�������� ��ü �������� ������ �ǹ� -> �ϴ� addOrder �Ķ���ʹ� string���� user(buyer) ���� �޴� ������ ��
	this->product = productRef->getName();
	this->company = productRef->getManufacturer();
	this->price = productRef->getPrice();
	this->rate = productRef->getAvgRating();
	this->ownedProductCollection = ownedProductCollection;
	this->productRef = productRef;
}

void OrderCollection::addOrder(Product* p, string buyer, string userId) {
	this->ownedProduct[this->cnt] = new Order(buyer, userId, this, p);
	this->cnt++;
}

void OrderCollection::removeOrder(){}

void OrderCollection::findFirst(){}

void OrderCollection::getNext(){}

void OrderCollection::getOrderItem(){
	
}

//getTotalPrice,getTotalRate,calculateTotalPrice,calculateTotalRate()를 하나로 묶음
// => getStatistics()

string OrderCollection::getStatistics(){
	string s;
	for (int i = 0; i < this->cnt; i++)
	{
		int sum=0;
		int avgRating=0;
		string name=ownedProduct[i]->getName();
		avgRating=ownedProduct[i]->getAvgRating();
		int price=ownedProduct[i]->getPrice();
		int quantity=ownedProduct[i] ->getQty();
		sum += price*quantity;
		s+=(name + ' ' + to_string(sum) + ' ' + to_string(avgRating) + '\n');
	}
	return s;
}




void Order::getOrderItemsDetail(){

}

void rateOrderItem(string product,int rate){
	
}
