/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 21:03:08
 * filename    : 2960-count-tested-devices-after-test-operations.cpp
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
  int countTestedDevices(vector<int> &batteryPercentages) {
    int add = 0;
    int ans = 0;
    for (int val : batteryPercentages) {
      if (val - add > 0) {
        ans++;
        add++;
      }
    }
    return ans;
  }
};
