/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 01:22:54
 * filename    : 1402-reducing-dishes.cpp
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
  int maxSatisfaction(vector<int> &satisfaction) {
    vector<int> a, b;
    for (int val : satisfaction)
      if (val >= 0)
        a.pb(val);
      else
        b.pb(-val);
    sort(vall(a));
    sort(vall(b));
    int ans = 0, s = 0;
    for (int i = 0; i < a.size(); ++i) {
      ans += (i + 1) * a[i];
      s += a[i];
    }
    int cur = 0, add = 0, p = 0;
    for (int i = 0; i < b.size(); ++i) {
      cur += s - b[i] - p;
      p += b[i];
      if (cur > add)
        add = cur;
    }
    return ans + add;
  }
};
