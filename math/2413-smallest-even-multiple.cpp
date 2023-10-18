/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 23:33:26
 * filename    : 2413-smallest-even-multiple.cpp
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
  int smallestEvenMultiple(int n) { return (n & 1) ? 2 * n : n; }
};
