/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 13:43:48
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
    vector<int> bits(n);

    for (int i = 0; i < n; ++i) {
      for (char c : words[i]) {
        bits[i] |= 1 << (c - 'a');
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        if ((bits[i] & bits[j]) == 0 &&
            words[i].length() * words[j].length() > ans) {
          ans = words[i].length() * words[j].length();
        }
      }
    return ans;
  }
};
