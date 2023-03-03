#include "info.h"

using namespace std;
void info::load(database *db, const string& name, size_t n) {
    node node("");
    for (int i = 0; i < n; i++) {
        node.name = name + to_string(i);
        db->add_node(vector<string> {"root"}, node);
    }
}

void info::empty_load_test() const {
    database db(file);
    db.create();

    time_t begin, end;
    time(&begin);
    load(&db, "node", 100000);
    time(&end);

    db.save();

    cout << "Empty db add 100000 nodes time " << end - begin << "s" << endl;
}

void info::big_load_test() const {
    quick_ld(file, 1000000);
    database db(file);
    db.open();

    time_t begin, end;
    time(&begin);
    load(&db, "node", 100000);
    time(&end);

    db.save();

    cout << "Big db add 100000 nodes time " << end - begin << "s"<< endl;
}

void info::insert_time() const {
    cout << "insert time" << endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = chrono::high_resolution_clock::now();

        load(&db, "test", 1000);

        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        cout << 1000 * i << ";" << time/chrono::milliseconds(1) << ";" << endl;
    }
}

void info::select_time() const {
    cout << "select time" << endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            auto path = vector<string> {"root", "node" + to_string(j)};
            node n = db.find_node(path);
        }

        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        cout << 1000 * i << ";" << time/chrono::milliseconds(1) << ";" << endl;
    }
}

void info::update_time() const {
    cout << "update time" << endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            node n("test" + to_string(j));
            auto path = vector<string> {"root", "node" + to_string(j)};
            db.update_node(path, n);
        }

        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        cout << 1000 * i << ";" << time/chrono::milliseconds(1) << ";" << endl;
    }
}

void info::delete_time() const {
    cout << "delete time" << endl;
    for (int i = 1; i < 21; i++) {
        database db(file);
        db.create();

        load(&db, "node", 1000 * i);
        db.save();

        auto start_time = chrono::high_resolution_clock::now();

        for (int j = 0; j < 1000; j++) {
            auto path = vector<string> {"root", "node" + to_string(j)};
            db.delete_node(path);
        }

        auto end_time = chrono::high_resolution_clock::now();
        auto time = end_time - start_time;


        cout << 1000 * i << ";" << time/chrono::milliseconds(1) << ";" << endl;
    }
}