/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-07 20:38:28
 * filename    : 781-rabbits-in-forest.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
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
  int numRabbits(vector<int> &answers) {
    map<int, int> m;
    for (int num : answers) {
      m[num]++;
    }
    int ans = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
      int t = it->second / (it->first + 1);
      if (it->second % (it->first + 1) != 0)
        t++;
      ans += (it->first + 1) * t;
    }
    return ans;
  }
};
