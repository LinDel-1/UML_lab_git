#pragma once
#include "Product.h"

class Position {
public:
	Position() = default;
	explicit Position(std::unique_ptr<Product> ptr_product)//Принимаем по указателю с каким продуктом будем работать 
		:m_ptr_product(std::move(ptr_product)) {};
	std::unique_ptr<Product>& get_ptr_product() { return m_ptr_product; }
	virtual double get_cost() const = 0; //Интерфейс
	virtual double get_quantity() const = 0;
protected:
	std::unique_ptr<Product> m_ptr_product;
};

class AmmountPosition : public Position {
public:
	AmmountPosition(std::unique_ptr<AmmountProduct> ptr_product, size_t ammount)
		:Position(std::move(ptr_product)), m_ammount(ammount) {};
	double get_quantity() const override { return m_ammount; } //Сколько в корзине у покупателя такого продукта?
	double get_cost() const override { //Общая стоимость за вид этого товара
		return (m_ammount * m_ptr_product->get_cost());
	}

private:
	size_t m_ammount;
};

class WeightPosition : public Position {
public:
	WeightPosition(std::unique_ptr<WeightProduct> ptr_product, double weight) //Развесной товар
		:Position(std::move(ptr_product)), m_weight(weight) {};

	double get_quantity() const override { return m_weight; } //Сколько кило в корзине у покупателя такого продукта?
	double get_cost() const override { //Общая стоимость за вид этого товара
		return (m_weight * m_ptr_product->get_cost());
	}

private:
	double m_weight;
};

