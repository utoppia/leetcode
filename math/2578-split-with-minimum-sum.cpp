/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-19 00:18:08
 * filename    : 2578-split-with-minimum-sum.cpp
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
  int splitNum(int num) {
    vector<int> c;
    while (num)
      c.pb(num % 10), num /= 10;
    vector<int> ans(2);
    sort(vall(c));
    for (int i = 0; i < c.size(); ++i) {
      ans[i & 1] = ans[i & 1] * 10 + c[i];
    }
    return ans[0] + ans[1];
  }
};
