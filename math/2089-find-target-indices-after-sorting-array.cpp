/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 01:06:40
 * filename    : 2089-find-target-indices-after-sorting-array.cpp
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
  vector<int> targetIndices(vector<int> &nums, int target) {
    vector<int> cnt(101);
    for (int c : nums)
      cnt[c]++;
    vector<int> ans;
    if (cnt[target] == 0)
      return ans;
    int begin = 0;
    for (int i = 0; i < target; ++i)
      begin += cnt[i];
    int end = begin + cnt[target];
    for (int i = begin; i < end; ++i)
      ans.pb(i);
    return ans;
  }
};
