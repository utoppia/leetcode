/******************************************
 * author      : utoppia
 * description : solution for leetcoode
 * updated at  : 2024-01-13 00:45:54
 * filename    : 295-find-median-from-data-stream.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class MedianFinder {
private:
  vector<int> left, right;
  int n;

public:
  MedianFinder() {
    left.clear();
    right.clear();
    n = 0;
  }

  void addNum(int num) {
    if (n == 0) {
      left.eb(num);
      push_heap(vall(left));
      n++;
      return;
    }

    if (num <= left[0]) {
      right.eb(-left[0]);
      push_heap(vall(right));
      pop_heap(vall(left));
      left.pop_back();
      left.eb(num);
      push_heap(vall(left));
    } else {
      right.eb(-num);
      push_heap(vall(right));
    }

    if (right.sz() > left.sz()) {
      left.eb(-right[0]);
      push_heap(vall(left));
      pop_heap(vall(right));
      right.pop_back();
    }

    n++;
  }

  double findMedian() {
    if (n % 2 == 1)
      return left[0];
    else
      return (double)(left[0] - right[0]) / 2.0;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
