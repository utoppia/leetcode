/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-19 00:15:40
 * filename    : 2549-count-distinct-numbers-on-board.cpp
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
  int distinctIntegers(int n) { return (n == 1) ? 1 : n - 1; }
};
