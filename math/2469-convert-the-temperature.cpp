/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:36:33
 * filename    : 2469-convert-the-temperature.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  vector<double> convertTemperature(double celsius) {
    vector<double> ans(2);
    ans[0] = celsius + 273.15;
    ans[1] = celsius * 1.8 + 32;
    return ans;
  }
};
