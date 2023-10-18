/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 13:13:41
 * filename    : 1925-count-square-sum-triples.cpp
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
  int countTriples(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; ++j) {
        for (int k = j + 1; k <= n; ++k) {
          if (i * i + j * j == k * k) {
            ans++;
            if (i != j)
              ans++;
          }
        }
      }
    }
    return ans;
  }
};
