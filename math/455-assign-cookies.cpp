/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-18 21:20:52
 * filename    : 455-assign-cookies.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define vall(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int ans = 0;
    auto j = g.begin();
    for (auto i = s.begin(); i != s.end(); ++i) {
      while (j != g.end() && *i < *j) {
        j++;
      }
      if (j == g.end())
        break;
      ans++;
      j++;
    }
    return ans;
  }
};
