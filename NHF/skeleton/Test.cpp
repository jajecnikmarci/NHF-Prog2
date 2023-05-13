#include <iostream>

#include "gtest_lite.h"
#include "memtrace.h"
#include "MVM.h"

/**@brief Teszt makro vezerli a vegrehajtando tesztesetek szamat.
 * TST 1: MyVektor
 * TST 2: Date
 * TST 3: Contract_date
 * TST 4: Client
 * TST 5: Person
 * TST 6: Company
 * TST 7: Contract
 * TST 8: MVM
 * TST 9: Számlakészítés
 * TST 10: Beolvasás Fájlból
 */
#define TST 10



#define MEMTRACE_H
int main() {

#if TST > 0
    TEST(MyVector, tesztek) {
        MyVector<int> int_test;
        MyVector<double> double_test;
        EXPECT_EQ(10, int_test.capacity()); // Alapertelmezett ertek
        EXPECT_EQ(0, int_test.size());
        int_test.push_back(1);
        EXPECT_EQ(1, int_test.size());
        int_test.pop_back();
        EXPECT_EQ(0, int_test.size());
        int_test.pop_back(); //Torles ha nincs semmi bajt okoz-e?

        for(size_t i = 0; i < 11; ++i) {
            int_test.push_back(i);
            double_test.push_back(i);
        }
        EXPECT_EQ(20, int_test.capacity());
        EXPECT_EQ(11, int_test.size());

        for(size_t i = 0; i < 11; ++i) {
            int_test.erase(0);
            double_test.pop_back();
        }

        EXPECT_EQ(0, int_test.size());
        EXPECT_EQ(0, double_test.size());

        for (size_t i = 0; i < 5; ++i) {
            int_test.push_back(i);
        }
        for (size_t i = 0; i < 5; i++)
        {
            EXPECT_EQ(i, int_test[i]);
        }
        EXPECT_THROW(int_test[-1], std::range_error);
        EXPECT_THROW(int_test[5], std::range_error);

    } END
#endif
#if TST > 1
    TEST(Date, tesztek) {
        
    }END
#endif
#if TST > 2
    TEST(Contract_date, tesztek) {

    }END
#endif
#if TST > 3
    TEST(Client, tesztek) {

    }END
#endif
#if TST > 4
    TEST(Person, tesztek) {

    }END
#endif
#if TST > 5
    TEST(Company, tesztek) {

    }END
#endif
#if TST > 6
    TEST(Contract, tesztek) {

    }END
#endif
#if TST > 7
    TEST(MVM, tesztek) {

    }END
#endif
#if TST > 8
    TEST(Szamlakeszites, tesztek) {

    }END
#endif
#if TST > 9
    TEST(Beolvasas_fajlbol, tesztek) {

    }END
#endif
    return 0;
}
