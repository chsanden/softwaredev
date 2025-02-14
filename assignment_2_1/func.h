//
// Created by thebe on 14/02/2025.
//

#ifndef FUNC_H
#define FUNC_H
#include "rapidcsv.h"
#include <unordered_map>



rapidcsv::Document customers("customers.csv");
std::vector<int> custID = customers.GetColumn<int>("id");
std::vector<std::string> custname = customers.GetColumn<std::string>("name");
std::vector<std::string> custaddress = customers.GetColumn<std::string>("address");
std::vector<int> totalSpent(custID.size(), 0);

rapidcsv::Document products("products.csv");
std::vector<std::string> prodname = products.GetColumn<std::string>("name");
std::vector<int> prodprice = products.GetColumn<int>("price");
std::vector<int> prodID = products.GetColumn<int>("id");

rapidcsv::Document orders("orders.csv");
std::vector<int> orderID = orders.GetColumn<int>("id");
std::vector<int> orderProdID = orders.GetColumn<int>("productid");
std::vector<int> amount = orders.GetColumn<int>("amount");
std::vector<int> orderCustID = orders.GetColumn<int>("customerid");
std::vector<int> totalIncome(prodID.size(), 0);
std::vector<int> totalAmount(prodID.size(), 0);

class Display {
public:
    void Customer() {
        for (int i = 0; i < custname.size(); i++)
            std::cout << "Customer: " << custname[i] << ", " << custaddress[i]  << std::endl;
    }

    void Product() {
        for (int i = 0; i < prodname.size(); i++)
            std::cout << "Product: " << prodname[i] << ", " << prodprice[i] << std::endl;
    }

    void Order() {
    for (int i = 0; i < prodID.size(); i++)
    {
        totalAmount[i] = 0;
    }
    for (int i = 0; i < prodID.size(); i++)
    {
        for (int j = 0; j < orderID.size(); j++)
        {
            if (orderProdID[j] == prodID[i])
            {
                totalAmount[i] += amount[j];
            }
        }
    }
        for (int i = 0; i < prodID.size(); i++)
    {
        std::cout << prodname[i] << " amount: " << totalAmount[i] << std::endl;
    }
}

    void GrossIncome() {
        for (int i = 0; i < prodID.size(); i++)
        {
            totalIncome[i] = 0;
        }

        for (int i = 0; i < prodID.size(); i++)
        {
            for (int j = 0; j < orderProdID.size(); j++)
            {
                if (prodID[i] == orderProdID[j])
                {
                    totalIncome[i] += prodprice[i] * amount[j];
                }
            }
        }
        for (int i = 0; i < prodID.size(); i++)
        {
            std::cout << prodname[i] << " gross income: " << totalIncome[i] << std::endl;
        }
    }


    void CustomerSpent()
    {
        for (int c = 0; c < custID.size(); c++) {
            totalSpent[c] = 0;
        }

        for (int c = 0; c < custID.size(); c++)
        {
            for (int o = 0; o < orderID.size(); o++)
            {
                if (orderCustID[o] == custID[c])
                {
                    int prodIdInOrder = orderProdID[o];
                    for (int p = 0; p < prodID.size(); p++)
                    {
                        if (prodID[p] == prodIdInOrder)
                        {
                            totalSpent[c] += prodprice[p] * amount[o];
                            break;
                        }
                    }
                }
            }
        }
        for (int c = 0; c < custID.size(); c++)
        {
            std::cout << custname[c] << " money spent: " << totalSpent[c] << std::endl;
        }
    }

};













#endif //FUNC_H
