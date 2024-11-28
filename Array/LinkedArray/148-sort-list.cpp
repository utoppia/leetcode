/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 02:42:14
 * filename    : 148-sort-list.cpp
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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr)
      return head;

    vector<ListNode *> tmp;

    ListNode *pt = head;
    while (pt != nullptr) {
      tmp.pb(pt);
      pt = pt->next;
    }

    sort(begin(tmp), end(tmp),
         [](const ListNode *i, const ListNode *j) { return i->val < j->val; });

    for (int i = 1; i < tmp.sz(); ++i)
      tmp[i - 1]->next = tmp[i];
    tmp[tmp.sz() - 1]->next = nullptr;

    return tmp[0];
  }
};
