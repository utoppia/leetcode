/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 02:18:11
 * filename    : 2739-total-distance-traveled.cpp
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
  int distanceTraveled(int mainTank, int additionalTank) {
    int ans = 0;
    while (mainTank) {
      if (mainTank >= 5) {
        ans += 50;
        mainTank -= 5;
        if (additionalTank) {
          mainTank++;
          additionalTank--;
        }
      } else {
        ans += mainTank * 10;
        mainTank = 0;
      }
    }
    return ans;
  }
};
