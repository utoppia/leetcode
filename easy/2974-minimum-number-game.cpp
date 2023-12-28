/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 21:05:18
 * filename    : 2974-minimum-number-game.cpp
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
  vector<int> numberGame(vector<int> &nums) {
    sort(vall(nums));
    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n; i += 2) {
      ans.pb(nums[i + 1]);
      ans.pb(nums[i]);
    }
    return ans;
  }
};
