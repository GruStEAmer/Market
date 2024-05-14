#include "Market.h"

//Receipt
void Receipt::print() const {
	std::cout << "My check_list\n";
	for (auto i : check_list) i.print();
}
void Receipt::Add(const int id, const int count) {
	
	Goods res;

	for (auto i = st->goods_v.begin(); i != st->goods_v.end(); i++) {
		if ((id == i->id) && (i->count - count >= 0)) {
			i->count -= count;
			res = Goods(i->id,i->name,i->price,count,i->sale);
		}
	}

	if(res.id != 0){
		for (auto i = check_list.begin(); i != check_list.end(); i++) {
			if (i->id == res.id) {
				i->count += res.count;
				std::cout << "------------------------" << "\n";
				return;
			}
		}
		check_list.push_back(res);
	}
	else {
		std::cout << "No more!\n";
	}
	std::cout << "------------------------" << "\n";
}
void Receipt::Add(string name, const int count){
	Goods res;

	for (auto i = st->goods_v.begin(); i != st->goods_v.end(); i++) {
		if ((name == i->name) && (i->count - count >= 0)) {
			i->count -= count;
			res = Goods(i->id, i->name, i->price, count, i->sale);
		}
	}

	if (res.name != "") {
		for (auto i = check_list.begin(); i != check_list.end(); i++) {
			if (i->id == res.id) {
				i->count += res.count;
				std::cout << "------------------------" << "\n";
				return;
			}
		}
		check_list.push_back(res);
	}
	else {
		std::cout << "No more!\n";
	}
	std::cout << "------------------------" << "\n";
}
void Receipt::del(const int id) {
	for (auto i = check_list.begin(); i != check_list.end(); i++) {
		if (i->id == id) {
			check_list.erase(i);
			return;
		}
	}
	std::cout << "Error:ID is not in Receint\n";
	std::cout << "------------------------" << "\n";
	return;
}
void Receipt::del(const string name) {
	for (auto i = check_list.begin(); i != check_list.end(); i++) {
		if (i->name == name) {
			check_list.erase(i);
			return;
		}
	}
	std::cout << "Error:ID is not in Receint\n";
	std::cout << "------------------------" << "\n";
	return;
}
//

//Stock
void Stock::Add(const Goods& g) {
	for (auto i = goods_v.begin(); i != goods_v.end();i++) {
		if (i->id == g.id) {
			i->count += g.count;
			return;
		}
	}
	goods_v.push_back(g);
	std::cout << "------------------------" << "\n";
}
void Stock::print() {
	for (auto i : goods_v) i.print();
}
//

//Goods
void Goods::print() const {
	std::cout << "id:" << id << "\n" <<
		"name:" << name << "\n" <<
		"price:" << price << "\n" <<
		"count:" << count << "\n" <<
		"sale:" << sale << "\n" <<
		"------------------------" << "\n";
}
void Goods::operator=(const Goods& g) {
	id = g.id;
	name = g.name;
	count = g.count;
	sale = g.sale;
	price = g.price;
}
//





