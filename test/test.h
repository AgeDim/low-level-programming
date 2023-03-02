#ifndef LAB1_TEST_H
#define LAB1_TEST_H
#include <iostream>
#include <cassert>

#include "../src/db/attributes.h"
#include "../src/db/m_data.h"
#include "../src/db/node.h"
#include "../src/db/database.h"

using namespace std;

struct test {

    string file = "../file.db";

    void all_tests();
    void add_test();
    void del_test();
    void child_test();
    void update_test();

};


#endif
