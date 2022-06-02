#pragma once

#include "product.h"

class GetProductList;
class ProductCollection;

class GetProductListUI{
private:
	GetProductList* getProductListControl;

public:
	GetProductListUI(GetProductList*);
	void getMyProductList();
};

class GetProductList {
private:
	GetProductListUI* gplUI;
	ProductCollection* productList;

public:
	GetProductList(ProductCollection*);
	ProductCollection* getProductCollection() { return this->productList; }
	Product* getMyProductList();

};