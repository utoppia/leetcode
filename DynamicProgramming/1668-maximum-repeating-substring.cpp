/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-28 23:43:21
 * filename    : 1668-maximum-repeating-substring.cpp
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
  int maxRepeating(string sequence, string word) {
    int n = sequence.length();
    int m = word.length();

    vector<int> dp(n + 1, 0);

    for (int i = n - m; i >= 0; i--) {
      if (word == sequence.substr(i, m))
        dp[i] = dp[i + m] + 1;
    }

    return *max_element(dp.begin(), dp.end());
  }
};
