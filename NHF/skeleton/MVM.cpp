//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "MVM.h"

Company MVM::MVM_company = Company("MVM ZRT.", 10760798244);

void MVM::addClient(Client* client_in) {
    clients.push_back(client_in);
}


void MVM::addContract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, int invo_in_year, int invo_in_month, int invo_in_day, double tariff_in, double balance_in, double consumption_in) {
    Contract* new_contract = new Contract(client_in, ctype_in, year_begin, month_begin, day_begin, year_end, month_end, day_end, invo_in_year, invo_in_month, invo_in_day, (client_in->getSumOfAll_Contract() + 1), tariff_in, balance_in, consumption_in);
    client_in->addContract(new_contract);
}

Client *MVM::getClient(const std::string name_in) {
    for (size_t i = 0; i < clients.size(); ++i) {
        if (name_in==clients[i]->getName()) return clients[i];
    }
    return nullptr;
}

const std::string MVM::getCompanyDetails() {
    return "Company name: " + MVM_company.getName() + ", Tax ID: " + std::to_string(MVM_company.getID());
}

MVM::~MVM(){
    //felszabadítani
}
