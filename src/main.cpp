#include <iostream>

#include "../test/test.h"
#include "../test/info.h"

using namespace std;

int main() {

    test test;
    info info;
    //main test
    test.all_tests();
    cout << endl;

    info.insert_time();
    cout << endl;
    info.select_time();
    cout << endl;
    info.update_time();
    cout << endl;
    info.delete_time();
    cout << endl;
    info.empty_load_test();
    cout << endl;
    info.big_load_test();
    cout << endl;

    return 0;
}