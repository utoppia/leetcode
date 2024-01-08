/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-09 00:48:22
 * filename    : 1558-minimum-numbers-of-function-calls-to-make-target-array.cpp
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
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    vector<int> ops(n), oqs(n);

    for (int i = 0, v; i < n; ++i) {
      v = nums[i];
      while (v) {
        if (v > 1)
          ops[i]++;
        if (v % 2 == 1)
          oqs[i]++;
        v >>= 1;
      }
    }

    int ans = *max_element(vall(ops));

    for (int v : oqs) {
      ans += v;
    }

    return ans;
  }
};
