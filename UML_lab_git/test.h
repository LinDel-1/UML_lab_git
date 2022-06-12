#pragma once

#include "PriceBase.h"
#include "Client.h"

// Initial test from technical task
void test_1() {
    auto& base = PriceBase::Instance();
    Order ord1;
    std::cout << std::boolalpha << "Order is empty?  " << ord1.empty() << std::endl;

    try {
        auto pos1 = WeightPosition(std::make_unique<WeightProduct>(base.get_product_weight_price("Apple")), 0.5);
        ord1.add_position(std::make_unique<WeightPosition>(std::move(pos1)));
        ord1.get_info();
        std::cout << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        auto ap1 = base.get_product_ammount_price("Pencil");
        auto pos2 = AmmountPosition(std::make_unique<AmmountProduct>(ap1), 2);
        ord1.add_position(std::make_unique<AmmountPosition>(std::move(pos2)));
        ord1.get_info();
        std::cout << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        auto pos3 = WeightPosition(std::make_unique<WeightProduct>(base.get_product_weight_price("Apple")), 3);
        ord1.add_position(std::make_unique<WeightPosition>(std::move(pos3)));
        ord1.get_info();
        std::cout << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    Client Ivan;
    Ivan.pay_and_recieve_order(ord1);
    Ivan.earn_money(10000);
    std::cout << "Ivan: I got some money!" << std::endl;
    Ivan.pay_and_recieve_order(ord1);
    ord1.get_info();
}
