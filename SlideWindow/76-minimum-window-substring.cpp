/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 13:29:40
 * filename    : 76-minimum-window-substring.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
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
  string minWindow(string s, string t) {
    unordered_map<char, int> hs;
    unordered_set<char> S;
    for (char c : t) {
      hs[c]++;
      S.insert(c);
    }

    int l = 0, n = s.length(), r = 0;
    for (auto it = begin(hs); it != end(hs); ++it) {
      while (it->second > 0 && r < n) {
        if (S.count(s[r]))
          hs[s[r]]--;
        r++;
      }
      if (it->second > 0)
        return "";
    }

    string ans = "";
    while (l < n) {
      while (l < n) {
        if (S.count(s[l])) {
          hs[s[l]]++;
          if (hs[s[l]] > 0) {
            if (ans == "" || ans.length() > r - l) {
              ans = string(begin(s) + l, begin(s) + r);
            }
            break;
          }
        }
        l++;
      }

      if (l >= n)
        break;

      while (r < n && s[r] != s[l]) {
        if (S.count(s[r]))
          hs[s[r]]--;
        r++;
      }
      if (r >= n)
        break;
      hs[s[r]]--;
      r++;
      l++;
    }

    return ans;
  }
};
