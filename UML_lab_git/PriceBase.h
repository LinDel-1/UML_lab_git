#pragma once
#include "Product.h"

//Singleton
class PriceBase { //Database of products
public:
	PriceBase(const PriceBase&) = delete;
	PriceBase& operator = (const PriceBase&) = delete;
	static PriceBase& Instance() {
		static PriceBase instance;
		return instance;
	}

	WeightProduct get_product_weight_price(const std::string name) {
		auto it = m_products_weight_price.find(name);
		if (it == m_products_weight_price.end())
			throw("This name can't be found");
		return it->second;
	}

	AmmountProduct get_product_ammount_price(const std::string name) {
		auto it = m_products_ammount_price.find(name);
		if (it == m_products_ammount_price.end())
			throw("This name can't be found");
		return it->second;
	}

protected:
	PriceBase() {
		m_products_info = {
			 { "Apple", ProductInfo("Green sweet apple") },
			 { "Nuts", ProductInfo("Macadamia nut") },
			 { "Pencil", ProductInfo("Red pensile with rubber") },
			 { "Chair", ProductInfo("Wooden chair with armrests") },
		};
		m_products_weight_price = {
			{ "Apple", WeightProduct(m_products_info.at("Apple"), 11.3) },
			{ "Nuts", WeightProduct(m_products_info.at("Nuts"), 34.2) },
		};
		m_products_ammount_price = {
			{ "Pencil", AmmountProduct(m_products_info.at("Pencil"), 5.7) },
			{ "Chair", AmmountProduct(m_products_info.at("Chair"), 75) },
		};
	}
private:
	std::map<std::string, ProductInfo> m_products_info;
	std::map<std::string, WeightProduct> m_products_weight_price;
	std::map<std::string, AmmountProduct> m_products_ammount_price;
};

