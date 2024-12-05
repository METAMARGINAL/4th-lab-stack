#pragma once
#include "stack.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

using namespace std;



int main() {
    string text = "";//À+(45-F()*(B-C))
    cout << "enter the text" << endl;
    cin >> text;
    find_bracket_pairs(text);
    return 0;
}
