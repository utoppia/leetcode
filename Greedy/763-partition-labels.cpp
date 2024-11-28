/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 13:17:39
 * filename    : 763-partition-labels.cpp
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
  vector<int> partitionLabels(string s) {
    vector<int> next(26);
    int n = s.length();
    for (int i = 0; i < n; ++i)
      next[s[i] - 'a'] = i;

    int i = 0;
    vector<int> ans;

    while (i < n) {
      int j = i, right = next[s[i] - 'a'];
      while (j <= right) {
        right = max(right, next[s[j] - 'a']);
        j++;
      }
      ans.pb(j - i);
      i = j;
    }

    return ans;
  }
};
