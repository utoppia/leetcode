/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-12 17:42:15
 * filename    : 896-monotonic-array.cpp
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
  bool isMonotonic(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return true;

    vector<int> diff(n - 1);
    bool flag = true;
    for (int i = 1; i < n; ++i) {
      diff[i - 1] = nums[i] - nums[i - 1];
    }

    if (all_of(vall(diff), [](int x) { return x >= 0; }))
      return true;
    if (all_of(vall(diff), [](int x) { return x <= 0; }))
      return true;
    return false;
  }
};
