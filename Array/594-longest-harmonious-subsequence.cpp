/******************************************
 * author      : utoppia
 * description : soltion for leetcode
 * updated at  : 2023-11-10 13:50:14
 * filename    : 594-longest-harmonious-subsequence.cpp
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
  int findLHS(vector<int> &nums) {
    map<int, int> s;
    for (int val : nums) {
      s[val]++;
    }

    int ans = 0;
    for (auto x : s) {
      if (s.count(x.fi + 1)) {
        ans = max(ans, x.snd + s[x.fi + 1]);
      }
    }
    return ans;
  }
};
