/******************************************
 * author      : utoppia
 * description : solution for leecode
 * updated at  : 2023-12-28 23:21:36
 * filename    : 2828-check-if-a-string-is-an-acronym-of-words.cpp
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
  bool isAcronym(vector<string> &words, string s) {
    string t = "";
    for (string word : words) {
      t += word[0];
    }
    return t == s;
  }
};
