#include "m_data.h"

using namespace std;

m_data::m_data() {
    this->count = 0;
    this->child = unordered_map<int32_t, unordered_set<int32_t>>();
    this->free = vector<int32_t>();
    this->pos = unordered_map<string, int32_t>();
    this->path = unordered_map<int32_t, string>();
    child[0] = unordered_set<int32_t>();
    path[0] = "/root";
    pos["/root"] = 0;
}