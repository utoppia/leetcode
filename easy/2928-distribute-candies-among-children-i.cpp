/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 20:53:23
 * filename    : 2928-distribute-candies-among-children-i.cpp
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
  int distributeCandies(int n, int limit) {
    int ans = 0;
    for (int i = 0; i <= limit; ++i) {
      for (int j = 0; j <= limit; ++j) {
        int k = n - i - j;
        if (k >= 0 && k <= limit)
          ans++;
      }
    }
    return ans;
  }
};
