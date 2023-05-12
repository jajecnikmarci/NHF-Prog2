//
// Created by Jajecnik Marcell on 2023. 05. 04..
//

#ifndef SKELETON_DATE_H
#define SKELETON_DATE_H

#include <iostream>
#include <chrono>
#include "sstream"
#include "iomanip"

/**@brief Egy dátumot tárol time_point formátumba
 * @param tp tárolt dátum
 */
class Date {
private:
    std::chrono::system_clock::time_point tp;

public:
    /**@Konstruktor
     *
     * @param year Beállítandó év
     * @param month Beállítandó hónap
     * @param day Beállítandó nap
     */
    Date(int year, int month, int day): tp(into_date(year,month,day)) {}

    /**@brief Időponttá alakít egy dátumot
     *
     * @param year Bejövő év
     * @param month Bejövő hónap
     * @param day Bejövő nap
     * @return időponttá alakított dátum
     */
    std::chrono::system_clock::time_point into_date(int year, int month, int day);

    /**@brief Kiírja az időpontot
     */
    void print_date() const;

    /**@brief == operátor összehasonlításhoz
     *
     * @param in Összehasonlítandó dátum
     * @return Egyenlőek
     */
    bool operator==(const Date& in) const;

    /**@brief < operátor összehasonlításhoz
     *
     * @param in Összehasonlítandó dátum
     * @return Kisebb?
     */
    bool operator<(const Date& in) const;

    /**@brief > operátor összehasonlításhoz
     *
     * @param in Összehasonlítandó dátum
     * @return Nagyobb?
     */
    bool operator>(const Date& in) const;

    /**@brief <= operátor összehasonlításhoz
     *
     * @param in Összehasonlítandó dátum
     * @return Kisebb vagy egyenlő?
     */
    bool operator<=(const Date& in) const;

    /**@brief >= operátor összehasonlításhoz
     *
     * @param in Összehasonlítandó dátum
     * @return Nagyobb vagy egyenlő?
     */
    bool operator>=(const Date& in) const;

    std::string toString() const;
};

/**@brief << operátor Kiíráshoz
 *
 * @param os ostream a kiíráshoz
 * @param date kiírandó dátum
 * @return Kiírja a dátumot majd visszaadja az ostream-et
 */
std::ostream& operator<<(std::ostream os, const Date& date);



/**@brief Egy időpárt tárol
 * @param beging Az kezdeti időpont
 * @param end A végső időpont
 */
class Contract_date {
private:
    Date begin;
    Date end;

    
public:

    /**@brief Konstruktor
     *
     * @param year_begin Bejövő kezdeti év
     * @param month_begin Bejövő kezdeti hónap
     * @param day_begin Bejövő kezdeti nap
     * @param year_end Bejövő végzeti év
     * @param month_end Bejövő végzeti hónap
     * @param day_end Bejövő végzeti nap
     */
    Contract_date(int year_begin, int month_begin, int day_begin, int year_end, int month_end, int day_end)
        : begin(Date(year_begin, month_begin, day_begin)), end(Date(year_end, month_end, day_end))
    {}

    /**@brief Visszaadja a kezdeti időpontot
     *
     * @return kezdeti időpont
     */
    Date getBegin() const;

    /**@brief Visszaadja a végső időpontot
     *
     * @return Végső időpont
     */
    Date getEnd() const;

    /**@brief Beállítja a kezdeti időpontot
     *
     * @param year Beállítandó év
     * @param month Beállítandó hónap
     * @param day Beállítandó nap
     */
    void setBegin(int year, int month, int day);

    /**@brief Beállítja a végső időpontot
     *
     * @param year Beállítandó év
     * @param month Beállítandó hónap
     * @param day Beállítandó nap
     */
    void setEnd(int year, int month, int day);

    /**@brief Ellenőrzi hogy a paraméterként kapott dátum a dátumpár között van-e
     *
     * @param date paraméterként kapott dátum
     * @return A dátumpár között van?
     */
    bool contains(const Date& date_in) const;


    /**@brief = operátor az = jel helyes működéséhez
     *
     * @param contractDate_in Bejövő contractDate
     * @return Visszaadandó contractDate
     */
    Contract_date& operator=( Contract_date& contractDate_in);
};


#endif //SKELETON_DATE_H
