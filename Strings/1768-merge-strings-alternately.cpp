/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 12:35:27
 * filename    : 1768-merge-strings-alternately.cpp
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
  string mergeAlternately(string word1, string word2) {
    int m = min(word1.length(), word2.length());

    string ret = "";
    for (int i = 0; i < m; ++i) {
      ret += word1[i];
      ret += word2[i];
    }

    if (word1.length() > m) {
      for (int i = m; i < word1.length(); ++i)
        ret += word1[i];
    }
    if (word2.length() > m) {
      for (int i = m; i < word2.length(); ++i)
        ret += word2[i];
    }
    return ret;
  }
};
