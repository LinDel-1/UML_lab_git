#pragma once
#include "Product.h"

class Position { //Position assosiating with one type of product
public: //Interface class
	Position() = default;
	explicit Position(std::unique_ptr<Product>&& ptr_product)
		:m_ptr_product(std::move(ptr_product)) {};
	std::unique_ptr<Product>& get_ptr_product() { return m_ptr_product; }
	virtual double get_cost() const = 0; 
	virtual double get_quantity() const = 0;
protected:
	std::unique_ptr<Product> m_ptr_product; //agregation
};

class AmmountPosition : public Position {
public:
	AmmountPosition(std::unique_ptr<AmmountProduct> ptr_product, size_t ammount)
		:Position(std::move(ptr_product)), m_ammount(ammount) {};
	double get_quantity() const override { return m_ammount; }
	double get_cost() const override { //total cost for this type of product
		return (m_ammount * m_ptr_product->get_cost());
	}

private:
	size_t m_ammount;
};

class WeightPosition : public Position {
public:
	WeightPosition(std::unique_ptr<WeightProduct> ptr_product, double weight) 
		:Position(std::move(ptr_product)), m_weight(weight) {};

	double get_quantity() const override { return m_weight; }
	double get_cost() const override { //total cost for this type of product
		return (m_weight * m_ptr_product->get_cost());
	}

private:
	double m_weight;
};

