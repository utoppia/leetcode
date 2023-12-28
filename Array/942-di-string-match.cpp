/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-15 01:03:11
 * filename    : 942-di-string-match.cpp
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
  vector<int> diStringMatch(string s) {
    int n = s.length();

    vector<int> perm(n + 1);

    int l = 0, r = n;
    if (s[0] == 'I')
      perm[0] = 0, l++;
    else
      perm[0] = n, r--;

    int i = 0;
    while (i < n) {
      int j = i;
      while (j < n && s[i] == s[j])
        j++;

      if (s[i] == 'I') {
        for (int k = j; k > i; k--) {
          perm[k] = r;
          r--;
        }
      } else {
        for (int k = j; k > i; k--) {
          perm[k] = l;
          l++;
        }
      }

      i = j;
    }
    return perm;
  }
};
