/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 16:44:07
 * filename    : 560-subarray-sum-equals-k.cpp
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
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> preffix(n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur += nums[i];
      preffix[i] = cur;
    }

    int ans = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;

    for (int val : preffix) {
      ans += hash[val - k];
      hash[val]++;
    }

    return ans;
  }
};
