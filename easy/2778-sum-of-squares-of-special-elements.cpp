/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 21:14:32
 * filename    : 2778-sum-of-squares-of-special-elements.cpp
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
  int sumOfSquares(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (n % (i + 1) == 0) {
        ans += nums[i] * nums[i];
      }
    }
    return ans;
  }
};
