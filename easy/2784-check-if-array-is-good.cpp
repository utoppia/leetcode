/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 21:18:14
 * filename    : 2784-check-if-array-is-good.cpp
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
  bool isGood(vector<int> &nums) {
    int n = nums.size() - 1;

    vector<int> vis(n + 1);
    for (int val : nums) {
      if (val < 1 || val > n)
        return false;
      vis[val]++;
      if (val == n && vis[val] > 2)
        return false;
      if (val < n && vis[val] > 1)
        return false;
    }
    return true;
  }
};
