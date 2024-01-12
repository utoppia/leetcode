/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 16:16:28
 * filename    : 3-longest-substring-without-repeating-characters.cpp
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

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    unordered_map<int, int> hash;
    int p = -1;
    for (int i = 0; i < s.length(); ++i) {
      if (hash.find(s[i]) == hash.end())
        ans = max(ans, i - p);
      else {
        ans = max(ans, min(i - hash[s[i]], i - p));
        p = max(p, hash[s[i]]);
      }
      hash[s[i]] = i;
    }
    return ans;
  }
};
