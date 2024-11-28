/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-14 03:17:24
 * filename    : 83-remove-duplicates-from-sorted-list.cpp
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *p, *q;
    p = head;
    if (p == nullptr)
      return p;
    while (p != nullptr) {
      q = p->next;
      while (q != nullptr && p->val == q->val)
        q = q->next;
      p->next = q;
      p = q;
    }
    return head;
  }
};
