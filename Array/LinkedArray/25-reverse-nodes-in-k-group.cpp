/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 02:13:42
 * filename    : 25-reverse-nodes-in-k-group.cpp
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    vector<ListNode *> tmp;
    ListNode *pt = head;
    while (pt != nullptr) {
      tmp.pb(pt);
      pt = pt->next;
    }

    int n = tmp.size();
    for (int i = 0; i < n; i += k) {
      if (i + k - 1 < n)
        reverse(begin(tmp) + i, begin(tmp) + i + k);
    }
    for (int i = 0; i < n - 1; i++) {
      tmp[i]->next = tmp[i + 1];
    }
    tmp[n - 1]->next = nullptr;
    return tmp[0];
  }
};
