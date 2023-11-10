/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-10 14:04:22
 * filename    : 645-set-mismatch.cpp
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
  vector<int> findErrorNums(vector<int> &nums) {
    vector<int> ans;
    vector<int> vis(nums.size() + 1);

    for (int val : nums) {
      if (vis[val] == 1)
        ans.pb(val);
      vis[val] = 1;
    }

    for (int i = 1; i <= nums.size(); ++i)
      if (vis[i] == 0)
        ans.pb(i);
    return ans;
  }
};
