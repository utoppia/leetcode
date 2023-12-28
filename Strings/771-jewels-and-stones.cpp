/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-12 17:33:55
 * filename    : 771-jewels-and-stones.cpp
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
  int numJewelsInStones(string jewels, string stones) {
    vector<bool> is_jewels(500);
    for (char c : jewels)
      is_jewels[c] = true;

    int ans = 0;
    for (char c : stones)
      if (is_jewels[c])
        ans++;
    return ans;
  }
};
