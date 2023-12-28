/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:41:09
 * filename    : 2395-find-subarrays-with-equal-sum.cpp
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
  bool findSubarrays(vector<int> &nums) {
    set<int> S;
    int n = nums.size();
    for (int i = 1, s; i < n; ++i) {
      s = nums[i] + nums[i - 1];
      if (S.count(s))
        return true;
      S.insert(s);
    }
    return false;
  }
};
