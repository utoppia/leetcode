/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-06 12:43:19
 * filename    : 318-maximum-product-of-word-lengths.cpp
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
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int maxProduct(vector<string> &words) {
    int n = words.size();
    vector<int> l(n);
    for (int i = 0; i < n; ++i)
      l[i] = words[i].length();

    vector<int> pos[26];

    for (int i = 0; i < n; ++i) {
      for (char c : words[i]) {
        pos[c - 'a'].pb(i);
      }
    }

    vector<bool> vis(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
    }
  }
};
