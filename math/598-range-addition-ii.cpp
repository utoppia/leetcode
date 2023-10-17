/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 00:41:57
 * filename    : 598-range-addition-ii.cpp
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
  int maxCount(int m, int n, vector<vector<int>> &ops) {
    for (vector<int> c : ops) {
      m = min(m, c[0]);
      n = min(n, c[1]);
    }
    return m * n;
  }
};
