#include "test.h"

using namespace std;

void test::all_tests() {
    add_test();
    del_test();
    child_test();
    update_test();
}

void test::add_test() {
    cout << "ADD TEST STARTED" << endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 1234);
    n.add("bool", false);
    n.add("float", 12345.54321f);
    n.add("string", "ITMO GOOD!");
    n.add("string2", "passed the lab!");

    db.add_node(vector<string> {"root"}, n);

    auto p = vector<string> {"root", "test"};
    node nn = db.find_node(p);
    assert(nn.attribute["int"].get_int() == 1234);
    assert(nn.attribute["bool"].get_bool() == false);
    assert(nn.attribute["float"].get_float() == 12345.54321f);
    assert(nn.attribute["string"].get_string() == "ITMO GOOD!");
    assert(nn.attribute["string2"].get_string() == "passed the lab!");

    assert(db.meta_data.count == 1);
    assert(db.meta_data.child.find(nn.id) != db.meta_data.child.end());
    assert(db.meta_data.path.find(nn.id) != db.meta_data.path.end());
    assert(db.meta_data.pos.find(path(p)) != db.meta_data.pos.end());

    cout << "ADD TEST SUCCEEDED" << endl;
}

void test::del_test() {
    cout << "DEL TEST STARTED" << endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 1234);
    n.add("bool", false);
    n.add("float", 12345.54321f);
    n.add("string", "ITMO GOOD!");
    n.add("string2", "passed the lab!");

    db.add_node(vector<string> {"root"}, n);
    auto p = vector<string> {"root", "test"};
    node nn = db.find_node(p);
    db.delete_node(p);

    assert(db.meta_data.count == 0);
    assert(db.meta_data.child.find(nn.id) == db.meta_data.child.end());
    assert(db.meta_data.path.find(nn.id) == db.meta_data.path.end());
    assert(db.meta_data.pos.find(path(p)) == db.meta_data.pos.end());
    assert(db.meta_data.free[0] == nn.id);

    cout << "DEL TEST SUCCEEDED" << endl;
}

void test::child_test() {
    cout << "CHILD ADD TEST STARTED" << endl;

    database db(file);
    db.create();

    node n1("n1");
    node n2("n2");
    node n3("n3");
    node n4("n4");
    node n5("n5");

    db.add_node(vector<string> {"root"}, n1);
    db.add_node(vector<string> {"root", "n1"}, n2);
    db.add_node(vector<string> {"root", "n1"}, n3);
    db.add_node(vector<string> {"root", "n1", "n3"}, n4);
    db.add_node(vector<string> {"root"}, n5);

    node nn1 = db.find_node(vector<string> {"root", "n1"});
    node nn2 = db.find_node(vector<string> {"root", "n1", "n2"});
    node nn3 = db.find_node(vector<string> {"root", "n1", "n3"});
    node nn4 = db.find_node(vector<string> {"root", "n1", "n3", "n4"});
    node nn5 = db.find_node(vector<string> {"root", "n5"});

    assert(db.meta_data.count == 5);
    assert(db.meta_data.child[0].find(nn1.id) != db.meta_data.child[0].end());
    assert(db.meta_data.child[nn1.id].find(nn2.id) != db.meta_data.child[nn1.id].end());
    assert(db.meta_data.child[nn1.id].find(nn3.id) != db.meta_data.child[nn1.id].end());
    assert(db.meta_data.child[nn3.id].find(nn4.id) != db.meta_data.child[nn3.id].end());
    assert(db.meta_data.child[0].find(nn5.id) != db.meta_data.child[0].end());

    db.delete_node(vector<string>{"root", "n1"});
    auto free = db.meta_data.free;
    assert(free[0] == nn1.id);
    assert(free[1] == nn2.id);
    assert(free[2] == nn3.id);
    assert(free[3] == nn4.id);
    assert(db.meta_data.path.size() == 2);
    assert(db.meta_data.pos.size() == 2);

    cout << "CHILD ADD TEST SUCCEEDED" << endl;
}

void test::update_test() {
    cout << "UPDATE TEST STARTED" << endl;

    database db(file);
    db.create();

    node n("test");
    n.add("int", 1234);
    n.add("bool", false);
    n.add("float", 12345.54321f);
    n.add("string", "ITMO GOOD!");
    n.add("string2", "passed the lab!");

    db.add_node(vector<string> {"root"}, n);

    node nn("minecraft");
    nn.add("int", "one");
    nn.add("bool", 12);
    nn.add("float", true);
    nn.add("string", "new string");

    auto p = vector<string> {"root", "test"};
    db.update_node(p, nn);

    auto pp = vector<string> {"root", "minecraft"};
    node nnn = db.find_node(pp);

    assert(nnn.attribute["int"].get_type() == attributes::STR);
    assert(nnn.attribute["bool"].get_type() == attributes::INT);
    assert(nnn.attribute["float"].get_type() == attributes::BOOL);
    assert(nnn.attribute["string"].get_type() == attributes::STR);
    assert(nnn.attribute.find("string2") == nnn.attribute.end());

    assert(nnn.attribute["int"].get_string() == "one");
    assert(nnn.attribute["bool"].get_int() == 12);
    assert(nnn.attribute["float"].get_bool() == true);
    assert(nnn.attribute["string"].get_string() == "new string");

    cout << "UPDATE TEST SUCCEEDED" << endl;
}