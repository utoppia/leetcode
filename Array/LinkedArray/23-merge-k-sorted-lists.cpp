/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:28:36
 * filename    : 23-merge-k-sorted-lists.cpp
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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *head = new ListNode(0);
    ListNode *p = head;
    vector<int> temp;
    temp.clear();
    for (int i = 0; i < lists.size(); ++i) {
      while (lists[i] != NULL) {
        temp.push_back(lists[i]->val);
        lists[i] = lists[i]->next;
      }
    }
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i) {
      p->next = new ListNode(temp[i]);
      p = p->next;
    }
    return head->next;
  }
};
