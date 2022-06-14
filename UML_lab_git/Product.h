#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <string>

class ProductInfo { 
public:
	explicit ProductInfo(const std::string& info) : m_info(info) {} //put some info about
	std::string& get_info() noexcept { return m_info; } //get unique info about product
private:
	std::string m_info; 
};

class Product { //Interface class
public:
	explicit Product(ProductInfo& product_info) : m_product_info(product_info) {} //put info on product
	virtual std::string get_info() const = 0;
	virtual double get_cost() const = 0; 
protected:
	ProductInfo& m_product_info; //agregation
};

class WeightProduct : public Product { //Weight product 
public:
	WeightProduct(ProductInfo& product_info, double cost)
		: Product(product_info), m_cost_per_kg(cost) {}
	std::string get_info() const override { 
		return m_product_info.get_info() + 
			": " + std::to_string(m_cost_per_kg) + " per kg\n";
	}
	double get_cost() const override { //How much money per one kg
		return m_cost_per_kg;
	}
private:
	double m_cost_per_kg;
};

class AmmountProduct : public Product { //Ammount product
public:
	AmmountProduct(ProductInfo& product_info, double cost) 
		: Product(product_info), m_cost_per_one(cost) {}
	std::string get_info() const override { 
		return m_product_info.get_info() +
			": " + std::to_string(m_cost_per_one) + " per kg\n";
	}
	double get_cost() const override { //How much money per one
		return m_cost_per_one;
	}
private:
	double m_cost_per_one;
};