/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:39:19
 * filename    : 347-top-k-frequent-elements.cpp
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
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> hs;
    for (int val : nums)
      hs[val]++;

    vector<vector<int>> h;
    for (auto it = begin(hs); it != end(hs); it++) {
      h.pb({it->second, it->first});
    }

    make_heap(vall(h));

    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.eb(h[0][1]);

      pop_heap(vall(h));
      h.pop_back();
    }

    return ans;
  }
};
