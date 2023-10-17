/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 21:27:33
 * filename    : 327-count-of-range-sum.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <map>
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

struct BIT {
  vector<int> c;
  int size;

  BIT(int _size) : size(_size), c(_size + 1) {}

  inline int lowbit(int x) { return x & -x; }

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
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    set<ll> S;
    ll pre = 0ll;
    S.insert(pre);
    for (auto c : nums) {
      pre += c;
      S.insert(pre);
      S.insert(pre - lower);
      S.insert(pre - upper);
    }
    int n = 0;
    map<ll, int> dic;
    for (auto it : S) {
      dic[it] = ++n;
    }
    BIT b(n);
    b.add(dic[0ll], 1);
    pre = 0ll;
    int ans = 0;
    for (auto c : nums) {
      pre += c;
      ans += b.getSum(dic[pre - lower]) - b.getSum(dic[pre - upper] - 1);
      b.add(dic[pre], 1);
    }
    return ans;
  }
};
