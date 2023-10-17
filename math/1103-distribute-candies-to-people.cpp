/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 01:04:35
 * filename    : 1103-distribute-candies-to-people.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
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
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ans(num_people);
    int cur = 1;
    int cnt = 0;
    int i = 0;
    while (cnt <= candies) {
      if (cnt + cur < candies) {
        cnt += cur;
        ans[i % num_people] += cur;
      } else {
        ans[i % num_people] += candies - cnt;
        break;
      }
      i++;
      cur++;
    }
    return ans;
  }
};
