/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:31:43
 * filename    : 2351-first-letter-to-appear-twice.cpp
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
  char repeatedCharacter(string s) {
    vector<int> vis(26);
    for (char c : s) {
      if (vis[c - 'a'] == 1)
        return c;
      else
        vis[c - 'a'] = 1;
    }
    return 0;
  }
};
