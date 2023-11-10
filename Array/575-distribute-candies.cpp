/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-10 13:47:24
 * filename    : 575-distribute-candies.cpp
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
  int distributeCandies(vector<int> &candyType) {
    set<int> s(candyType.begin(), candyType.end());
    return min(s.size(), candyType.size() / 2);
  }
};
