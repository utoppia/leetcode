/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 16:22:22
 * filename    : 438-find-all-anagrams-in-a-string.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
#include <set>
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
private:
  bool check(vector<int> cnt) {
    for (int &v : cnt)
      if (v != 0)
        return false;
    return true;
  }

public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> cnt(26, 0);
    vector<bool> vis(26, false);
    for (char c : p) {
      vis[c - 'a'] = true;
      cnt[c - 'a']--;
    }
    int n = s.length();
    for (int i = 0; i < min(n, (int)p.length()); ++i)
      if (vis[s[i] - 'a']) {
        cnt[s[i] - 'a']++;
      }

    int i = 0, j = p.length() - 1;
    vector<int> ans;
    while (j < n) {
      if (check(cnt))
        ans.eb(i);
      if (vis[s[i] - 'a'])
        cnt[s[i] - 'a']--;
      i++;
      j++;
      if (j < n && vis[s[j] - 'a'])
        cnt[s[j] - 'a']++;
    }
    return ans;
  }
};
