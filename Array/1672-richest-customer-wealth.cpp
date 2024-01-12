/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:43:29
 * filename    : 1672-richest-customer-wealth.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#define vall(v) v.begin(), v.end()
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
  int maximumWealth(vector<vector<int>> &accounts) {
    vector<int> maxValues;
    for (vector<int> &a : accounts) {
      maxValues.pb(accumulate(vall(a), 0));
    }
    return *max_element(vall(maxValues));
  }
};
