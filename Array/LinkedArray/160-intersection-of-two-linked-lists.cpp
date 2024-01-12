/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 18:28:25
 * filename    : 160-intersection-of-two-linked-lists.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_set>
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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> hs;

    while (headA != NULL) {
      hs.insert(headA);
      headA = headA->next;
    }

    while (headB != NULL) {
      if (hs.count(headB))
        return headB;
      headB = headB->next;
    }

    return NULL;
  }
};
