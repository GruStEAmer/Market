#include"Market.h"

int main() {
	Stock st;
	Receipt re(&st);
	Goods goods;

	int input;

	//for switch
	int id, count, sale;
	double price;
	string name;

	while (true) {
		std::cin >> input;
		switch (input) {
		//Create goods
		case 1:
			std::cout << "Write ID,NAME,PRICE,COUNT,SALE\n";
			std::cin >> id >> name >> price >> count >> sale;
			goods = Goods(id, name, price, count, sale);
			break;
		//Add to Stock
		case 2:
			st.Add(goods);
			break;
		//Print Stock
		case 3:
			st.print();
			break;
		//Add to Receipt with ID
		case 4:
			std::cout << "Write ID and COUNT\n";
			std::cin >> id >> count;
			re.Add(id, count);
			break;
		// Add to Receipt with NAME
		case 5:
			std::cout << "Write NAME and COUNT\n";
			std::cin >> name >> count;
			re.Add(name, count);
			break;
		//Print Receipt
		case 6:
			re.print();
			break;
		//Delete element in Recept
		case 7:
			std::cout << "Write ID to delete\n";
			std::cin >> id;
			re.del(id);
			break;
		case 8:
			std::cout << "Write NAME to delete\n";
			std::cin >> name;
			re.del(name);
			break;
		case -1:
			return 0;
		}
	}
}