#include "attributes.h"

using namespace std;

attributes::attributes(){}

attributes::attributes(const int32_t v) {
    this->label = INT;
    this->i = v;
}

attributes::attributes(const bool v) {
    this->label = BOOL;
    this->b = v;
}

attributes::attributes(const float v) {
    this->label = FLOAT;
    this->f = v;
}

attributes::attributes(const char* v) {
    this->label = STR;
    this->s = v;
}

attributes::type attributes::get_type() {
    return label;
}
int32_t attributes::get_int() {
    return i;
}
bool attributes::get_bool() {
    return b;
}
float attributes::get_float() {
    return f;
}
string attributes::get_string() {
    return s;
}