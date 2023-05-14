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

class Client;
class Company;
enum class ContractType;

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

    /**@brief paraméter nélkül hívható konstruktor
     *
     */
    MVM() {}

    /**@brief Hozzáad egy új klienst
     * @details Eltárolja a klienst, amit előre létre kell hozni, de a felszabadítást az MVM osztály végzi
     * @param client_in Szerződést kötő ügyfél
     */
    void addClient(Client* client_in);

    /**@briefHozzáad egy szerződést
     *
     * @param client_in Szerződést kötő ügyfél
     * @param ctype_in Szerződés típusa
     * @param year_begin Szerződéskötés kezdeti éve
     * @param month_begin Szerződéskötés kezdeti hónapja
     * @param day_begin Szerződéskötés kezdeti napja
     * @param year_end Szerződéskötés végső éve
     * @param month_end Szerződéskötés végső hónapja
     * @param day_end Szerződéskötés végső napja
     * @param invo_in_year Legutóbbi számlázás éve
     * @param invo_in_month Legutóbbi számlázás hónapja
     * @param invo_in_day Legutóbbi számlázás napja
     * @param tariff_in KWh-kénti ár
     * @param balance_in Bejövő egyenleg
     * @param consumption_in Bejövő fogyasztás
     */
    void addContract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, int invo_in_year, int invo_in_month, int invo_in_day, double tariff_in = 0.0, double balance_in = 0.0, double consumption_in = 0.0);

    /**@brief Visszaadja a keresett ügyfelet a neve alapján
     *
     * @param name_in Keresett ügyfél neve
     * @return Keresett ügyfél
     */
    Client* getClient(const std::string name_in,const std::string somekindofID);

    /**
     * @brief Az MVM adatait adja vissza
     * @return MVM adatai
     */
    const std::string getCompanyDetails();

    /**@brief Kitöröl egy ügyfelet a neve alapján
     *
     * @param name_in Törlendő ügyfél neve
     */
    void deleteClient(const std::string name_in, const std::string somekindofID);

    /**@brief Destruktor
     *
     */
    ~MVM();
};

#endif //SKELETON_MVM_H
