#include <iostream>
#include "order.h"
#include "product.h"

using namespace std;

void Purchase::createOrder(string userId, string sellerId, string productName, ProductCollection* pc, OrderCollection* oc) {
	Product* product = pc->getProductByNameAndSellerID(sellerId, productName);

	oc->addOrder(product, sellerId, userId);
}

void OrderCollection::addOrder(Product* p, string buyer, string userId) {
	this->ownedProduct[this->cnt] = new Order(buyer, userId, this, p);
	this->cnt++;
}

Order::Order(string buyer, string userId, OrderCollection* ownedProductCollection, Product* productRef) {
	this->buyer = buyer;//해당 부분은 userRef선언으로 대체 가능하지 않은가 의문 -> 일단 addOrder 파라미터는 string으로 user(buyer) 정보 받는 것으로 함
	this->product = productRef->getName();
	this->company = productRef->getManufacturer();
	this->price = productRef->getPrice();
	this->totalPrice = productRef->getPrice();
	this->ownedProductCollection = ownedProductCollection;
	this->productRef = productRef;
}
