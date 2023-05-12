//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_CLIENTS_H
#define SKELETON_CLIENTS_H

#include "date.h"
#include "myvektor.hpp"
#include "contracts.h"
#include <string>

class Contract;
/**@brief Ügyfél adatait tárolja
 * @param name Az ügyfél neve
 * @param mycontracts Az ügyfél szerződéseit tároló tömb
 */
class Client{
private:
    std::string name;
    MyVector<Contract *> mycontracts;
    size_t SumOfAll_contract;
public:
    /**@brief Alapértékes kontruktor
     *
     * @param name_in Ügyfél neve
     * @param sumofContracts A kliens által eddig kötött szerződések száma (nem jelenlegi)
     */
    Client(const std::string name_in, size_t sumofContracts):name(std::string(name_in)), SumOfAll_contract(sumofContracts){}

    size_t getSumOfAll_Contract();

    std::string getName() const;

    /**@brief Szerződés hozzáadása a mycontracts hez
     *
     * @param contract_in a hozzáadandó szerződésre mutató pointer.
     */
    void addContract(Contract* contract_in);

    /**
     * @brief Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben.
     * 
     * \return gyermek osztály személyes adatai kiíráshoz egy string-ben
     */
    virtual std::string getsub_Client_info();

    /**
     * @brief Számlát állít ki fájlba.
     * 
     * \param contract_index A szerződés sorszáma a tárolt szerződések között
     */
    void save_invoice(size_t contract_index );

    /**@brief Virtuális destruktor
     *
     */
    virtual ~Client(){};
};

/**@brief Magánszemély adatait tárolja
 * @param ID A személy személyazonosító száma
*/
class Person: public Client{
private:
    long ID;
public:
    /**@brief Alapértékes konstruktor
     * @param name_in Bejövő magánszemély neve
     * @param ID_in Bejövő magánszemély személyigazolványszáma
     * @param SumOfAll_contract A kliens által eddig kötött szerződések száma (nem jelenlegi)
    */
    Person(const std::string name_in="", long ID_in=0, size_t SumOfAll_contract=0)
    : Client(std::string(name_in),SumOfAll_contract), ID(ID_in)
    {}

    /**@brief Személyigazolvány beállítása
     *
     * @param ID_in Beérkező személyigazolványszám
     */
    void setID(long ID_in);

    /**@brief Magánszemély személyigazolványszámát adja vissza
     *
     * @return Magánszemély személyigazolványszáma
     */
    long getID() const;

    /**
     * @brief Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben.
     *
     * \return gyermek osztály személyes adatai kiíráshoz egy string-ben
     */
    std::string getsub_Client_info();

    /**@brief Destruktor
     *
     */
    ~Person();
};

/**@brief Egy cég adatait tárolja
 *@param Tax_ID A cég adóazonosító száma
 */
class Company: public Client{
private:
    long Tax_ID;
public:

    /**@brief Alapértékes kontruktor
     *
     * @param name_in Bejövő Cégnév
     * @param ID_in Bejövő Cég adószám
     * @param SumOfAllContract A kliens által eddig kötött szerződések száma (nem jelenlegi)
     */
    Company(std::string name_in="", long ID_in=0, size_t SumOfAllContract=0)
    : Client(name_in, SumOfAllContract), Tax_ID(ID_in)
    {}

    /**@brief Cég adószámának állítása
     *
     * @param ID_in Bejövő Cég adószám
     */
    void setID(long ID_in);

    /**@brief Cég adószámát adja vissza
     *
     * @return Cég adószáma
     */
    long getID() const;

    /**
     * @brief Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben.
     *
     * \return gyermek osztály személyes adatai kiíráshoz egy string-ben
     */
    std::string getsub_Client_info();

    /**@brief Destruktor
     *
     */
    ~Company();
};

#endif //SKELETON_CLIENTS_H