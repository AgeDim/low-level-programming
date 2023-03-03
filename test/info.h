#ifndef LAB1_STRESS_TEST_H
#define LAB1_STRESS_TEST_H
#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>
#include <cassert>

#include "../src/db/attributes.h"
#include "../src/db/m_data.h"
#include "../src/db/node.h"
#include "../src/db/database.h"
#include "../src/db/ld.h"

using namespace std;

struct info {
    string file = "../file.db";
    string big = "../big.db";

    static void load(database *db, const string& name, size_t n);
    void empty_load_test() const;
    void big_load_test() const;

    void insert_time() const;
    void select_time() const;
    void update_time() const;
    void delete_time() const;
};


#endif
