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

std::string Person::getsub_Client_info() {
    return "Person name: " + getName() + ", ID: " + std::to_string(ID);
}

long Person::getID() const {
    return ID;
}

void Person::setID(long ID_in) {
    ID=ID_in;
}

Person::~Person() {

}

long Company::getID() const {
    return Tax_ID;
}

void Company::setID(long ID_in) {
    Tax_ID=ID_in;
}

std::string Company::getsub_Client_info() {
    return "Company name: " + getName() + ", Tax ID: " + std::to_string(Tax_ID);
}


Company::~Company() {

}