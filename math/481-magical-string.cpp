/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 16:39:20
 * filename    : 481-magical-string.cpp
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
  int magicalString(int n) {
    vector<int> s(max(3, n));
    s[0] = 1;
    s[1] = 2;
    s[2] = 2;
    int p = 2, q = 3, v;
    while (q < n) {
      if (s[q] == 0) {
        v = s[q - 1] == 1 ? 2 : 1;
      }
      for (int i = 0; i < s[p] && q < n; ++i) {
        s[q] = v;
        q++;
      }
      p++;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
      ans += (s[i] == 1);
    return ans;
  }
};
