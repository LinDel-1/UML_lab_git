#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <string>

class ProductInfo { //Информация о продукте - Этикетка
public:
	explicit ProductInfo(const std::string& info) : m_info(info) {} //Принимаем инфо о продукте
	std::string& get_info() { return m_info; } //Что написано на этикетке?
private:
	std::string m_info; //Инофрмация с этикетки
};

class Product {
public:
	explicit Product(ProductInfo& product_info) : m_product_info(product_info) {} //Прилепили этикетку к продукту
	virtual std::string get_info() const = 0;
	virtual double get_cost() const = 0; //Определим интерфейс
protected:
	ProductInfo& m_product_info; //Будем хранить этикетку по ссылке(агрегация, можем прилепить и к др. объекту)
};

class WeightProduct : public Product {
public:
	WeightProduct(ProductInfo& product_info, double cost) //Продукт на развес
		: Product(product_info), m_cost_per_kg(cost) {}
	std::string get_info() const override { //Покупатель читает этикетку
		return m_product_info.get_info() + " : "
			+ std::to_string(m_cost_per_kg) + " per kg\n";
	}
	double get_cost() const override { //Сколько стоит один килограмм?
		return m_cost_per_kg;
	}
private:
	double m_cost_per_kg;
};

class AmmountProduct : public Product {
public:
	AmmountProduct(ProductInfo& product_info, double cost) //Штучный продукт
		: Product(product_info), m_cost_per_one(cost) {}
	std::string get_info() const override { //Покупатель читает этикетку
		return m_product_info.get_info() + " : "
			+ std::to_string(m_cost_per_one) + " per one\n";
	}
	double get_cost() const override { //Сколько стоит одна штука?
		return m_cost_per_one;
	}
private:
	double m_cost_per_one;
};