/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 19:05:47
 * filename    : 821-shortest-distance-to-a-character.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  vector<int> shortestToChar(string s, char c) {
    int n = s.length();
    vector<int> ans(n);
    ans.assign(n, n);
    int i = 0, dis = 0;
    while (i < n && s[i] != c)
      i++;
    while (i < n) {
      if (s[i] == c) {
        dis = 0;
      } else {
        dis++;
      }
      if (ans[i] > dis)
        ans[i] = dis;
      i++;
    }
    i = n - 1;
    while (i >= 0 && s[i] != c)
      i--;
    while (i >= 0) {
      if (s[i] == c) {
        dis = 0;
      } else {
        dis++;
      }
      if (ans[i] > dis)
        ans[i] = dis;
      i--;
    }
    return ans;
  }
};
