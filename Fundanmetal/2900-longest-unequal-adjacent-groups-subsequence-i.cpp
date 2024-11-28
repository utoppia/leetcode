/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-28 23:57:56
 * filename    : 2900-longest-unequal-adjacent-groups-subsequence-i.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
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
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    vector<string> ans;
    ans.push_back(words[0]);
    int cur = 0;
    for (size_t i = 1; i < groups.size(); ++i) {
      if (groups[cur] != groups[i]) {
        cur = i;
        ans.push_back(words[i]);
      }
    }
    return ans;
  }
};
