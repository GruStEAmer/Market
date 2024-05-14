#pragma once
#include<string>
#include<iostream>
#include<vector>

using std::string;
//-----------------------------------
class Goods
{
	friend class Stock;
	friend class Receipt;

	int id,
		count,
		sale;
	double price;
	string name;

public:
	Goods(int id = 0, string name = "", double price = 0, int count = 0, int sale = 0) :
		id(id), name(name), price(price), count(count), sale(sale)
	{}

	void print() const;

	void operator=(const Goods& g);

};
//-----------------------------------
class Stock
{
	friend class Receipt;


	std::vector<Goods> goods_v;

public:
	void Add(const Goods& g);
	void print();

};
//-----------------------------------
class Receipt
{	
	Stock* st;
	std::vector<Goods> check_list;

public:
	Receipt(Stock* st):st(st){}

	void print() const;
	void Add(const int id, const int count);
	void Add(string name, const int count);
	void del(const int id);
	void del(const string name);
};





