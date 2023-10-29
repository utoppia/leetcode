/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 16:12:54
 * filename    : 457-circular-array-loop.cpp
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
private:
  int next(int pos, int step, int n) {
    pos += step;
    pos %= n;
    pos += n;
    pos %= n;
    return pos;
  }

public:
  bool circularArrayLoop(vector<int> &nums) {
    int n = nums.size();
    vector<bool> vis(n);

    auto check = [&](int i) {
      int p = i, q = i;
      vis[p] = true;
      do {
        p = next(p, nums[p], n);
        q = next(q, nums[q], n);
        q = next(q, nums[q], n);
        vis[p] = true;
        vis[q] = true;
      } while (p != q);

      p = i;
      while (p != q) {
        p = next(p, nums[p], n);
        q = next(q, nums[q], n);
      }

      q = next(p, nums[p], n);
      int l = 1;
      bool positive = nums[p] > 0;
      while (p != q) {
        if ((nums[q] > 0) != positive)
          return false;
        q = next(q, nums[q], n);
        l++;
      }
      return l > 1;
    };

    for (int i = 0; i < n; ++i)
      if (!vis[i]) {
        if (check(i))
          return true;
      }
    return false;
  }
};
