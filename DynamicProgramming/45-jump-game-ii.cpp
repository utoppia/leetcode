/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:23:15
 * filename    : 45-jump-game-ii.cpp
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
  int jump(vector<int> &nums) {
    int n = nums.sz();
    int ans = 0, pos = 0;

    while (pos < n - 1) {
      int cur = -1, nxt;
      for (int j = pos; j <= nums[pos] + pos; ++j) {
        if (j >= n)
          continue;

        if (j + nums[j] > cur) {
          nxt = j;
          cur = j + nums[j];
        }
      }

      ans++;
      if (nums[pos] + pos >= n - 1)
        return ans;
      pos = nxt;
    }

    return ans;
  }
};
