/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 00:05:52
 * filename    : 2659-make-array-empt.cpp
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

class BIT {
private:
  vector<int> c;
  int size;

public:
  BIT(int _size) : size(_size), c(_size + 1) {}

  static constexpr int lowbit(int x) { return x & -x; }

  void add(int index, int val) {
    while (index <= size) {
      c[index] += val;
      index += lowbit(index);
    }
  }

  int getSum(int index) {
    int ret = 0;
    while (index > 0) {
      ret += c[index];
      index -= lowbit(index);
    }
    return ret;
  }

  void make_tree(vector<int> nums) {
    size = nums.size();
    c.resize(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
      add(i, nums[i - 1]);
    }
  }
};

class Solution {
public:
  long long countOperationsToEmptyArray(vector<int> &nums) {
    vector<pir> pos;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      pos.pb(make_pair(nums[i], i + 1));
    }
    sort(all(pos));

    BIT b(n);
    for (int i = 1; i <= n; ++i)
      b.add(i, 1);
    int cur = 0;
    ll ans = 0ll;
    for (int i = 0, nxt; i < n; ++i) {
      nxt = pos[i].snd;
      if (nxt > cur) {
        ans += b.getSum(nxt) - b.getSum(cur);
      } else {
        ans += b.getSum(n) - b.getSum(cur) + b.getSum(nxt);
      }
      cur = nxt;
      b.add(cur, -1);
    }
    return ans;
  }
};
