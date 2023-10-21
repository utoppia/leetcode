/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 01:58:34
 * filename    : 2614-prime-in-diagonal.cpp
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
#define nMax 4000005

#define MOD 998244353
using namespace std;

class Solution {

public:
  bool isPrime(int n) {
    for (int p = 2; p * p <= n; p++)
      if (n % p == 0)
        return false;
    return n != 1;
  }
  int diagonalPrime(vector<vector<int>> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (isPrime(nums[i][i]))
        ans = max(ans, nums[i][i]);
      if (isPrime(nums[i][n - 1 - i]))
        ans = max(ans, nums[i][n - 1 - i]);
    }
    return ans;
  }
};
