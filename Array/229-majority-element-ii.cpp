/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 13:35:06
 * filename    : 229-majority-element-ii.cpp
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
  vector<int> majorityElement(vector<int> &nums) {
    unordered_map<int, int> m;
    for (int v : nums)
      m[v]++;
    int n = nums.size();
    vector<int> ans;
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second > n / 3)
        ans.pb(it->first);
    }
    return ans;
  }
};
