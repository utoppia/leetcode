/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:14:05
 * filename    : 128-longest-consecutive-sequence.cpp
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
  int longestConsecutive(vector<int> &num) {
    unordered_set<int> hash;
    for (int val : num)
      hash.insert(val);

    int ans = 0;
    for (const int &val : hash) {
      if (!hash.count(val - 1)) {
        int cur = val;
        int cnt = 0;

        while (hash.count(cur)) {
          cnt++;
          cur++;
        }
        ans = max(ans, cnt);
      }
    }
    return ans;
  }
};
