/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-19 00:45:49
 * filename    : 131-palindrome-partitioning.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <string>
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
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    int l = s.length();
    if (l == 1) {
      vector<string> t;
      t.pb(s);
      ans.pb(t);
      return ans;
    }

    if (is_partition(s)) {
      vector<string> t;
      t.pb(s);
      ans.pb(t);
    }
    for (int i = 1; i < l; ++i)
      if (is_partition(s.substr(0, i))) {
        vector<vector<string>> right = partition(s.substr(i));
        if (right.size() == 0)
          continue;
        for (auto b : right) {
          b.insert(b.begin(), s.substr(0, i));
          ans.pb(b);
        }
      }
    return ans;
  }

private:
  bool is_partition(string s) {
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] != s[s.length() - 1 - i])
        return false;
    }
    return true;
  }
};
