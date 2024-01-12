/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 17:41:17
 * filename    : 238-product-of-array-except-self.cpp
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
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.sz();
    vector<int> ans(n, 1);
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i - 1] * nums[i - 1];
    }

    int p = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      ans[i] *= p;
      p *= nums[i];
    }
    return ans;
  }
};
