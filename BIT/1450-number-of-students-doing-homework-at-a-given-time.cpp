/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 10:32:06
 * filename    : 1450-number-of-students-doing-homework-at-a-given-time.cpp
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

// class Solution {
// public:
//   int busyStudent(vector<int> &startTime, vector<int> &endTime, int
//   queryTime) {
//     BIT b(1001);
//     int n = startTime.size();
//     for (int i = 0; i < n; ++i) {
//       b.add(startTime[i], 1);
//       b.add(endTime[i] + 1, -1);
//     }
//     return b.getSum(queryTime);
//   }
// };

class Solution {
public:
  int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime) {
    int ans = 0;
    int n = startTime.size();
    for (int i = 0; i < n; ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i])
        ans++;
    }
    return ans;
  }
};
