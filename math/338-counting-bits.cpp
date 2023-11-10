/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-10 13:34:50
 * filename    : 338-counting-bits.cpp
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
  vector<int> countBits(int n) {
    vector<int> ans(n + 1);
    for (int val = 0; val <= n; ++val) {
      int x = val;
      ans[val] = 0;
      while (x) {
        if (x & 1)
          ans[val]++;
        x >>= 1;
      }
    }
    return ans;
  }
};
