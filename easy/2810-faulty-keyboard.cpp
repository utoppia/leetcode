/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:14:58
 * filename    : 2810-faulty-keyboard.cpp
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
  string finalString(string s) {
    string ans = "";

    for (char c : s) {
      if (c == 'i')
        reverse(ans.begin(), ans.end());
      else
        ans += c;
    }
    return ans;
  }
};
