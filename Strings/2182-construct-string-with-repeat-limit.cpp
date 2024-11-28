/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 18:52:42
 * filename    : 2182-construct-string-with-repeat-limit.cpp
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
  string repeatLimitedString(string s, int repeatLimit) {
    vector<int> cnt(26, 0);
    for (char c : s)
      cnt[c - 'a']++;

    string ans = "";
    for (int i = 25; i >= 0; --i)
      if (cnt[i]) {
        bool flag = true;
        while (cnt[i]) {
          if (cnt[i] > repeatLimit) {
            for (int j = 0; j < repeatLimit; ++j) {
              ans += (char)('a' + i);
            }
            cnt[i] -= repeatLimit;
            flag = false;
            for (int j = i - 1; j >= 0; j--)
              if (cnt[j]) {
                ans += (char)('a' + j);
                cnt[j]--;
                flag = true;
                break;
              }
            if (not flag) {
              break;
            }
          } else {
            for (int j = 0; j < cnt[i]; ++j) {
              ans += (char)('a' + i);
            }
            cnt[i] = 0;
          }
        }
        if (not flag)
          break;
      }
    return ans;
  }
};
