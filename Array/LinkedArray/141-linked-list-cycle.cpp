/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 18:41:46
 * filename    : 141-linked-list-cycle.cpp
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr)
      return false;

    ListNode *r = head->next;
    ListNode *t = head;

    while (t != nullptr && r != nullptr && r != t) {
      r = r->next;
      if (r != nullptr)
        r = r->next;
      t = t->next;
    }

    if (r == nullptr)
      return false;
    return true;
  }
};
