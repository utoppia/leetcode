/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:10:10
 * filename    : 1-two-sum.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
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
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    int n = nums.size();
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (hash.count(target - nums[i]) != 0) {
        ans.pb(i);
        ans.pb(hash[target - nums[i]]);
        return ans;
      }
      hash[nums[i]] = i;
    }
    return ans;
  }
};
