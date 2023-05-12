//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_MVM_H
#define SKELETON_MVM_H

#include "clients.h"
#include "myvektor.hpp"
#include "date.h"
#include "contracts.h"
#include <iostream>
#include <chrono>



/**
 * @brief Ügyfeleket tároló class.
 */
class MVM {
private:
    /**
     * Kliensek heterogén kollekciója.
     */
    MyVector<Client *> clients;

    
public:
    /**
     * Az MVM adatai
     */
    static Company MVM_company;

    MVM() {}
    void addClient(Client* client_in);

    /**
     * @brief
     * @param contract_in
     */
    void addContract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, int invo_in_year, int invo_in_month, int invo_in_day, double tariff_in = 0.0, double balance_in = 0.0, double consumption_in = 0.0);

    Client* getClient(const std::string name_in);

    /**
     * @brief
     * @return Az MVM adatait adja vissza.
     */
    const std::string getCompanyDetails();

    ~MVM();
};

#endif //SKELETON_MVM_H
