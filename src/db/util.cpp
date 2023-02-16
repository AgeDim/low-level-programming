#include "util.h"

using namespace std;

string path(const vector<string>& path) {
    string ret;
    for (const string& s : path) {
        ret += "/";
        ret += s;
    }
    return ret;
}