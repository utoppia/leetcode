/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 18:45:53
 * filename    : 142-linked-list-cycle-ii.cpp
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
  ListNode *detectCycle(ListNode *head) {

    ListNode *r = head;
    ListNode *t = head;

    while (r != nullptr) {
      r = r->next;
      if (r != nullptr)
        r = r->next;
      t = t->next;
      if (t == r)
        break;
    }

    if (r == nullptr)
      return nullptr;

    r = head;
    while (r != t) {
      r = r->next;
      t = t->next;
    }
    return t;
  }
};
