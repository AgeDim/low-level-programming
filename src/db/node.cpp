#include "node.h"

using namespace std;

node::node() {}

node::node(const string& name) {
    this->name = name;
}

void node::add(const string& key, const attributes& value) {
    this->attribute[key] = value;
}

void node::serialize(const string& file, int32_t position) {
    ofstream fout(file, BOI);
    fout.seekp(META + (KB4 * position));
    cereal::BinaryOutputArchive boa(fout);

    size_t start = fout.tellp();
    boa(id);
    boa(name);
    boa(attribute);
    size_t end = fout.tellp();

    assert(end - start <= KB4);

    fout.close();
}

void node::deserialize(const string& file, int32_t position) {
    ifstream fin(file, BOI);
    fin.seekg(META + (KB4 * position));
    cereal::BinaryInputArchive bia(fin);

    size_t start = fin.tellg();
    bia(id);
    bia(name);
    bia(attribute);
    size_t end = fin.tellg();

    assert(end - start <= KB4);

    fin.close();
}
