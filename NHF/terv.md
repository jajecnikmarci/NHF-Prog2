# MVM
**<h1 align="center">Házi Feladat </h1>**

<h2 align = "center">Specifikáció</h2>
<h2 align = "center">Jajecnik Marcell- DMB3AD</h3>
<h2 align = "center">2023. 04. 24.</h2>

<h3>Feladat leírás</h3>
Tervezze meg a Meseországi Villamos Művek (MVM) nyilvántartási rendszerének egyszerűsített objektummodelljét, majd valósítsa azt meg! A rendszerrel minimum a következő műveleteket kívánjuk elvégezni:

- ügyfél adatinak felvétele
- szolgáltatási szerződés kötése
- szolgáltatási díj előírása (számlázás)
- szolgáltatási díj befizetése
- egyenleg lekérdezése
- fogyasztás bejelentése

A rendszer lehet bővebb funkcionalitású, ezért nagyon fontos, hogy jól határozza meg az objektumokat és azok felelősségét.
Demonstrálja a működést külön modulként fordított tesztprogrammal! A megoldáshoz ne használjon STL tárolót!

<h3>Bemenetek</h3>

#### Forras.txt fájl ami tartalmazza az ügyfél adatait a következő sorrendben
- ügyfél neve
- ügyfél típus
- szerződéstípus (enum)
- szerződött időszak
- tarifa
- egyenleg

#### Adatfelvitel parancssorból, egy információ, 1 sor
- ügyfél neve
- ügyfél típus
- szerződéstípus (enum)
- szerződéshossz
- tarifa
- egyenleg

#### Parancssoros adatkezelés
- egyenleglekérdezés
- számlakészítés
- befizetés
- fogyasztás bejelentése

#### Tesztesetek futtatása fájlból
- egyenleglekérdezés
- számlakészítés
- befizetés
- fogyasztás bejelentése

<h3>Kimenetek</h3>

#### Számlakészítés fájlba
- Kinek a számlája
- Milyen időszakról
- Mekkora összeg

#### Számlakészítés parancssorba
- Kinek a számlája
- Milyen időszakról
- Mekkora összeg

#### Egyenleglekérdezés
- Függvényvisszaadja a jelenlegi egyenleget

#### Teszt tesztesetekkel tesztfájlal
#
#
#
#
#
#
#
#
#
#
#
#
#

# MVM
**<h1 align="center">Házi Feladat </h1>**

<h2 align = "center">Terv</h2>
<h2 align = "center">Jajecnik Marcell- DMB3AD</h3>
<h2 align = "center">2023. 05. 03.</h2>

# A program struktúrája

*A program osztálydiagramja, a fontosabb adattagokkal és függvényekkel*

@startuml
!theme black-knight

MyVektor -- MVM::clients
Client -- MVM::clients
class "MVM" as MVM {
    - MyVektor<Client*> clients - tárolja az ügyfelek adatait
    - static Company MVM_company = Company("Meseorszagi Villamos Muvek ZRT.", "10760798244") - Az MVM adatai
    - static int save_version = 0 - legutóbbi mentés verziószáma

    + MVM() - Default konstruktor
    + static Company adatok - az MVM adatai a számla kiállításához, mivel nem változik így statikus
    + void addContract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, int invo_in_year, int invo_in_month, int invo_in_day, double tariff_in = 0.0, double balance_in = 0.0, double consumption_in = 0.0) - hozzáad egy szerződést
    + void addClient(Client* client_in) - hozzáad egy ügyfelet
    + Client* getClient(const std::string name_in,const std::string somekindofID) - Kikeresi a meglévő ügyfelek közül a keresettet
    + const std::string getCompanyDetails() - Az MVM adatait adja vissza
    + void deleteClient (const std::string name_in, const std::string somekindofID) - töröl egy ügyfelet
    + void save() - biztonsági mentést készít
    + void load_from_save (int version_id_in) - Beolvassa a ügyfeleket és a szerzo ̋déseiket egy fájlból.
    + void load_from_console () - Belvas egy contractet a console-ról.
    + ~MVM() - Destruktor ami felszabadítja a tárolt ügyfeleket
}

MyVektor -- Client::mycontracts
Contract -- Client::mycontracts
class "Client" as Client{
    - std::string name - a ügyfél neve
    - MyVector<Contract> mycontracts - az ügyfélhez tartozó szerződések
    - size_t SumOfAll_contract - Azt tárolja hogy a kliens megléte alatt összesen hány szerződést kötött (A szerződés azonosítására használ a felhasználó számára)
    + Client(const std::string name_in):name(std::string(name_in)) - Konstruktor
    + size_t getSumOfAll_Contract() - Visszaadja a kliens által eddig kötött szerződések számát
    + std::string getName() const - Visszaadja a kliens nevét
    + void addContract(Contract& contract_in) - szerződést ad hozzá
    + virtual std::string getsub_Client_info() - Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben
    + void save_invoice(size_t contract_index, const Date& date) - Számlát állít ki fájlba
    + Contract& getContract(size_t contract_ID) - Visszaadja azt a szerződést aminek az azonosítóját megadtuk
    + virtual ~Client() - virtuális destruktor
}

Person <|-Client
class "Person" as Person{
    - std::string ID - személyazonosító szám

    + Person(const std::string name_in="", std::string ID_in="") - Alapértékes konstruktor
    + std::string getID() const - visszaadja a személyazonosító számot
    + void setID(std::string ID_in) - beállítja a személyazonosító számot
    + std::string getsub_Client_info() - Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben
    + ~Person - Destruktor
}

Company <|-Client
class "Company" as Company{
    - std::string Tax_ID - adóazonosító szám
    + std::string getID() const - visszaadja az adóazonosító számot
    + Company (std::string name_in="", std::string ID_in="") - Alapértékes konstruktor
    + void setID(std::string ID-in) - beállítja az adóazonosító számot
    + std::string getsub_Client_info() - Visszaadja a gyermek osztály személyes adatait kiíráshoz egy string-ben
    + ~Company() - Destruktor
}

Client -- Contract::client
ContractType -- Contract::contract_type
Contract_date -- Contract::contract_time
Date -- Contract::last_invoicing
class "Contract" as Contract {
    - Client* client - ügyfél adatai
    - int contract_ID - A szerződés azonosítószáma
    - ContractType contract_type - szerződés típusa
    - Contract_date contract_time - szerződés itőtartama eleje és vég megadásával
    - Date last_invoicing - legutóbbi számlázás ideje
    - double tariff - kilowattóránkénti ár forintban megadva
    - double balance - jelenlegi egyenleg
    - double consumption - fogyasztás a legutóbbi számlázás óta

    + Client() - Default konstruktor
    + Contract(Client* client_in, ContractType ctype_in, int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end, int invo_in_year, int invo_in_month, int invo_in_day, size_t ContractID_in ,double tariff_in=0.0, double balance_in=0.0, double consumption_in=0.0) - Alapértékes konstruktor
    + Client* getClient() const - visszaad egy Client-et ami tartalmazza a szerződéskötő adatait
    + ClientType getCtype() const - visszaadja a szerződés típusát
    + double getTariff() const - visszaadja a tarifát ami megadja a KWh óránkénti árat
    + double getBalance() const - visszaadja a jelenlegi egyenleget
    + double getConsumption() - visszaadja a jelenlegi fogyasztást a legutóbbi számlázás óta
    + Contract_date getCtime() const - visszaadja a szerződés hosszát
    + size_t getContractID() const - Visszaadja a szerződés azonosítóját
    + const std::string Ctype_toString() const - A szerződés típusát adja vissza stringként
    + Date getLast_invoicing() const - Visszaadja a legutótóbbi számla kiállításának az időpontját
    + void addConsumption(double con_in) - növeli a fogyasztás értékét a legutóbbi számlázás óta
    + void setCtype(ContractType ctype_in) - beállítja a szerződés típusát
    + void setTariff(double tariff_in) - beállítja a tarifát ami megadja a KWh óránkénti árat
    + void setBalance(double balance_in) - beállítja a jelenlegi egyenleget
    + void setCtime(Contract_date ctime_in) - beállítja a szerződés hosszát
    + void setLast_invoicing(Date last_in) - beálllítja a legutóbbi számlázás idejét
    + void pay(double amount) - befizetés
    + void invoice (const Date &today) - számla készítése a legutóbbi számlakiállítás óta
    + const std::string Ctype_toString () const - Ctype-ot alakít string formátumba
    + ~Client() - destruktor
}

enum "ContractType" as ContractType {}

class "Date" as Date {
    - std::chrono::system_clock::time_point tp - tárolt dátum

    + Date(int year, int month, int day) - Konstruktor
    + std::chrono::system_clock::time_point into_date(int year, int month, int day) - Időponttá alakít egy dátumot
    + void print_date() const - Kiírja az időpontot
    + bool operator==(const Date& in) const - == operátor egyenlősség vizsgálathoz
    + bool operator<(const Date& in) const - < operátor összehasonlításhoz
    + bool operator>(const Date& in) const - > operátor összehasonlításhoz
    + bool operator<=(const Date& in) const - <= operátor összehasonlításhoz
    + bool operator>=(const Date& in) const - >= operátor összehasonlításhoz
    + std::string toString() const - Visszaadja a dátumot string formátumban
    std::ostream& operator<<(std::ostream os, const Date& date) - classon kívüli függvény kiíráshoz
}



Date -- Contract_date::begin
Date -- Contract_date::end
class "Contract_date" as Contract_date {
    - Date begin - szerződés kezdete
    - Date end - szerződés vége

    + Contract_date() - Default konstruktor
    + Contract_date(Date begin_date, Date end_date) - Konstruktor 2 dátumból
    + Contract_date(int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end) - konstruktor intekkel megadott paraméterekből
    + Date getBegin() - visszaadja a szerződés kezdetét
    + Date getEnd() - visszaadja a szerződés végét
    + void setBegin(Date beg_in) - beállítja a szerződés kezdetét Date-ből
    + void setBegin(int year, int month, int day) - beállítja a szerződés kezdetét intekből
    + void setEnd(Date end_in) - bállítja a szerződés végét Date-ből
    + void setEnd(int year, int month, int day) - beállítja a szerződés végét intekből
    + bool contains(const Date& date_in) const - eldönti hogy a kapott dátum benne van-e a szerződés időtartamában
    + Contract_date& operator=(const Contract_date& contractDate_in) - = operátor értékadáshoz
}

class "MyVektor<T>" as MyVektor {
    - T* m_buffer
    - size_t m_capacity - maximális szám ami még belefér a foglalt memóriába
    - size_t m_size - jelenleg tárolt adatok száma
    - void reserve() - helyet foglal - privát függvény

    + MyVektor() - alapértékes konstruktor
    + void push_back(T value) - belerak egy új adatot ha még nincs tele, ha tele van újat foglal
    + T* begin() - iterátor a tömb elejére
    + T* end() - iterátor a tömb végére
    + size_t size() - visszaadja a jelenleg tárolt adatok számát
    + size_t capacity() - visszaadja a jelenleg foglalt méretet
    + void erase(size_t pos) - kitöröl egy tárolt adatot egy bizonyos helyről
    + void pop_back() - kitörli a legutóbbi elemet
    + T& operator[](size_t i) - [] operátor az indexelhetőséghez
    + const T& operator[](size_t i) const -[] operátor az indexelhetőséghez constans formában is
    + ~MyVektor() - destruktor


}
    
@enduml

- A person és a company osztályok publikus módon öröklődnek a client-ből
- A myvektor generikus osztály az indexelhetőséghez
- A myvektor amennyiben betelik az eddigi méretének dupláját foglalja
- Egy emberhez több szerződés is kapcsolódhat