/*
 * Change.cpp
 */

#include "Change.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool sortVec(vector<int> v1, vector<int> v2){
    return v1.size() < v2.size();
}


string calcChange(int m, int numCoins, int *coinValues) {
    string result = "";
    vector<vector<int>> comb;
    vector<int> temp;
    int m1 = m;
    for (int x = numCoins - 1; x >= 0; x--) {
        m1 = m;
        for (int i = x; i >= 0; --i) {
            if (m1 / coinValues[i] > 0) {
                while (m1 / coinValues[i] > 0) {
                    temp.push_back(coinValues[i]);
                    m1 = m1 - coinValues[i];
                }
            }
        }
        comb.push_back(temp);
        temp.clear();
    }
    sort(comb.begin(), comb.end(), sortVec);
    if (comb[0].empty() && m > 0) return "-";
    for (auto x: comb[0])
        result += to_string(x) + ";";
    return result;
}


