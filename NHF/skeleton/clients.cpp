//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#include "clients.h"

std::string Client::getName() const{
    return name;
}

void Client::addContract(Contract& contract_in) {
    SumOfAll_contract++;
    mycontracts.push_back(contract_in);
}

size_t Client::getSumOfAll_Contract() {
    return SumOfAll_contract;
}

std::string Client::getsub_Client_info() {
    return "Client name: " + getName();
}

void Client::save_invoice(size_t contract_index, const Date& date) {
    getContract(contract_index).invoice(date);
}

Contract &Client::getContract(size_t contract_index) {
    if (contract_index<=0 || contract_index>getSumOfAll_Contract()) throw std::range_error("Nem létező contract");
    for (size_t i = 0; i < mycontracts.size(); ++i) {
        if (mycontracts[i].getContractID()==contract_index) return mycontracts[i];
    }
}

std::string Person::getsub_Client_info() {
    return "Person name: " + getName() + ", ID: " + ID;
}

std::string Person::getID() const {
    return ID;
}

void Person::setID(std::string ID_in) {
    ID=ID_in;
}

Person::~Person() {

}

std::string Company::getID() const {
    return Tax_ID;
}

void Company::setID(std::string ID_in) {
    Tax_ID=ID_in;
}

std::string Company::getsub_Client_info() {
    return "Company name: " + getName() + ", Tax ID: " + Tax_ID;
}

Company::~Company() {

}