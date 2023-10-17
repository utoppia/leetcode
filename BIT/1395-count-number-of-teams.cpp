/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 22:00:39
 * filename    : 1395-count-number-of-teams.cpp
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
#define nMax 100005

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

  void clear() { c.assign(size, 0); }
};

class Solution {
public:
  int numTeams(vector<int> &rating) {

    BIT b(nMax);
    int n = rating.size();
    vector<int> pref(n);
    for (int i = 0; i < n; ++i) {
      pref[i] = b.getSum(rating[i] - 1);
      b.add(rating[i], 1);
    }
    b.clear();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += b.getSum(rating[i] - 1);
      b.add(rating[i], pref[i]);
    }
    pref.assign(n, 0);
    b.clear();
    for (int i = n - 1; i >= 0; --i) {
      pref[i] = b.getSum(rating[i] - 1);
      b.add(rating[i], 1);
    }
    b.clear();
    for (int i = n - 1; i >= 0; --i) {
      ans += b.getSum(rating[i] - 1);
      b.add(rating[i], pref[i]);
    }
    return ans;
  }
};
