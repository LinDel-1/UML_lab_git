#pragma once
#include "Position.h"


class Order {
public:
	friend class Client;
	Order() {}
	void add_position(std::unique_ptr<Position> ptr_pos) {
		//Find if products in positions are equal
		auto equal_prod = [](const Product& prod_1, const Product& prod_2) {
			return prod_1.get_info() == prod_2.get_info();
		};
		//Find if Positions are equal
		auto equal_pos = [&ptr_pos, equal_prod](std::unique_ptr<Position>& ptr_pos_resource) {
			return equal_prod(*(ptr_pos_resource->get_ptr_product()), *(ptr_pos->get_ptr_product()));
		};
		//If find equal positions - replace old to new position
		auto found_pos = std::find_if(m_ptr_positions.begin(), m_ptr_positions.end(), std::move(equal_pos));
		if (found_pos != m_ptr_positions.end()) {
			*found_pos = std::move(ptr_pos);
			return;
		}
		//If not find - add position
		m_ptr_positions.push_back(std::move(ptr_pos));
	}
	double get_cost() { //Total cost of Order (consist of positions)
		double final_cost = 0;
		for (const auto& pos : m_ptr_positions)
			final_cost += pos->get_cost(); 
		return final_cost;
	}
	void get_info() { //Print summary info about order
		if (empty()) {
			std::cout << "Order is empty" << std::endl;
			return;
		}
		std::cout << "Your order:" << std::endl;
		for (const auto& el : m_ptr_positions) {
			std::cout << el->get_ptr_product()->get_info() << std::endl;
			std::cout << "\tAmount: " << el->get_quantity() << std::endl;
			std::cout << "\tCost: " << el->get_cost() << std::endl << std::endl;
		}
		std::cout << "Total cost: " << get_cost() << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
	}
	bool empty() { return m_ptr_positions.empty(); }

private:
	void clear() { //Private method (used in class Client)
		m_ptr_positions.clear();
	}

private:
	std::vector<std::unique_ptr<Position>> m_ptr_positions;
};
