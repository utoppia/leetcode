/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:43:23
 * filename    : 11-container-with-most-water.cpp
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
#define eb emplace_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int i = 0, j = height.size() - 1;
    int ans = 0;

    while (i != j) {
      ans = max(ans, min(height[i], height[j]) * (j - i));
      if (height[i] < height[j])
        i++;
      else
        j--;
    }

    return ans;
  }
};
