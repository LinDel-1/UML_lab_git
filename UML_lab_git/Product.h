#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <string>

class ProductInfo { //���������� � �������� - ��������
public:
	explicit ProductInfo(const std::string& info) : m_info(info) {} //��������� ���� � ��������
	std::string& get_info() { return m_info; } //��� �������� �� ��������?
private:
	std::string m_info; //���������� � ��������
};

class Product {
public:
	explicit Product(ProductInfo& product_info) : m_product_info(product_info) {} //��������� �������� � ��������
	virtual std::string get_info() const = 0;
	virtual double get_cost() const = 0; //��������� ���������
protected:
	ProductInfo& m_product_info; //����� ������� �������� �� ������(���������, ����� ��������� � � ��. �������)
};

class WeightProduct : public Product {
public:
	WeightProduct(ProductInfo& product_info, double cost) //������� �� ������
		: Product(product_info), m_cost_per_kg(cost) {}
	std::string get_info() const override { //���������� ������ ��������
		return m_product_info.get_info() + " : "
			+ std::to_string(m_cost_per_kg) + " per kg\n";
	}
	double get_cost() const override { //������� ����� ���� ���������?
		return m_cost_per_kg;
	}
private:
	double m_cost_per_kg;
};

class AmmountProduct : public Product {
public:
	AmmountProduct(ProductInfo& product_info, double cost) //������� �������
		: Product(product_info), m_cost_per_one(cost) {}
	std::string get_info() const override { //���������� ������ ��������
		return m_product_info.get_info() + " : "
			+ std::to_string(m_cost_per_one) + " per one\n";
	}
	double get_cost() const override { //������� ����� ���� �����?
		return m_cost_per_one;
	}
private:
	double m_cost_per_one;
};