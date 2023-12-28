/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:54:14
 * filename    : 2418-sort-the-people.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
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
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    int n = names.size();
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);

    sort(vall(pos),
         [heights](int i, int j) { return heights[i] > heights[j]; });
    vector<string> ret;
    for (int i : pos)
      ret.pb(names[i]);
    return ret;
  }
};
