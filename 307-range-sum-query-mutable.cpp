/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 18:42:43
 * filename    : 307-range-sum-query-mutable.cpp
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

class NumArray {
private:
  vector<int> c;
  vector<int> vals;
  int n;
  int lowbit(int x) { return x & -x; }
  int getSum(int index) {
    int ans = 0;
    while (index > 0) {
      ans += c[index];
      index -= lowbit(index);
    }
    return ans;
  }
  void add(int index, int val) {
    while (index <= n) {
      c[index] += val;
      index += lowbit(index);
    }
  }

public:
  NumArray(vector<int> &nums) : vals(nums) {
    n = nums.size();
    c.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      add(i, nums[i - 1]);
    }
  }

  void update(int index, int val) {
    add(index + 1, val - vals[index]);
    vals[index] = val;
  }

  int sumRange(int left, int right) { return getSum(right + 1) - getSum(left); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
