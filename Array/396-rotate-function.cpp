/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:02:27
 * filename    : 396-rotate-function.cpp
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
  int maxRotateFunction(vector<int> &nums) {
    int n = nums.size();
    int cur = 0, ans;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      cur += i * nums[i];
      sum += nums[i];
    }
    ans = cur;
    for (int i = n - 1; i > 0; --i) {
      cur = cur + sum - n * nums[i];
      ans = max(ans, cur);
    }
    return ans;
  }
};
