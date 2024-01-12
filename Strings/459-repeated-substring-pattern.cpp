/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:18:49
 * filename    : 459-repeated-substring-pattern.cpp
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
  bool repeatedSubstringPattern(string s) {
    int n = s.length();
    for (int i = 1; i < n; ++i) {
      if (n % i == 0) {
        string base = "";
        for (int j = 0; j < i; ++j)
          base += s[j];
        string tmp = "";
        for (int j = 0; j < n / i; ++j)
          tmp += base;
        if (tmp == s)
          return true;
      }
    }
    return false;
  }
};
