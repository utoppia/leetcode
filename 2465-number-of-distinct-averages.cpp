/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 14:00:30
 * filename    : 2465_number-of-distinct-averages.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  int distinctAverages(vector<int> &nums) {
    if (nums.empty())
      return 0;
    vector<bool> vis(300);
    sort(nums.begin(), nums.end());
    int be = 0, ed = nums.size() - 1;
    while (be < ed) {
      vis[nums[be] + nums[ed]] = true;
      ++be;
      --ed;
    }
    int ans = 0;
    for (auto c : vis) {
      ans += c;
    }
    return ans;
  }
};
