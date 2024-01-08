/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-09 01:04:36
 * filename    : 1578-minimum-time-to-make-rope-colorful.cpp
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
  int minCost(string colors, vector<int> &neededTime) {
    int n = colors.size();
    int ans = 0;

    int l = 0, r, flag;
    while (l < n) {
      r = l;
      flag = neededTime[l];
      while (r < n && colors[l] == colors[r]) {
        flag = max(flag, neededTime[r]);
        ans += neededTime[r];
        r++;
      }
      ans -= flag;
      l = r;
    }
    return ans;
  }
};
