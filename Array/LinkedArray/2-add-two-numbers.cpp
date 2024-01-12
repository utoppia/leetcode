/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:12:27
 * filename    : 2-add-two-numbers.cpp
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head, *p;
    int add = 0, first = 1, k;
    while (l1 != NULL || l2 != NULL || add != 0) {
      k = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + add;
      add = k / 10;
      k = k % 10;
      ListNode *newNode = new ListNode(k);
      if (first) {
        head = newNode;
        p = head;
        first = 0;
      } else {
        p->next = newNode;
        p = p->next;
      }
      if (l1 != NULL)
        l1 = l1->next;
      if (l2 != NULL)
        l2 = l2->next;
    }
    return head;
  }
};
