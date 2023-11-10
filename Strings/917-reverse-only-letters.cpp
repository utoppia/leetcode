/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 12:15:20
 * filename    : 917-reverse-only-letters.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
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
  string reverseOnlyLetters(string s) {
    vector<char> tmp;
    int n = 0;
    for (char c : s) {
      if (isalpha(c)) {
        tmp.pb(c);
        n++;
      }
    }

    n--;
    string ret = s;
    for (int i = 0; i < ret.length(); ++i) {
      if (isalpha(ret[i])) {
        ret[i] = tmp[n];
        n--;
      }
    }
    return ret;
  }
};
