/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:25:55
 * filename    : 24-swap-nodes-in-pairs.cpp
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
  ListNode *swapPairs(ListNode *head) {
    if (head == NULL)
      return NULL;
    vector<ListNode *> temp;
    while (head != NULL) {
      temp.push_back(head);
      head = head->next;
    }
    for (int i = 0; i + 1 < temp.size(); i += 2)
      swap(temp[i], temp[i + 1]);
    for (int i = 0; i < temp.size() - 1; ++i)
      temp[i]->next = temp[i + 1];
    temp[temp.size() - 1]->next = NULL;
    return temp[0];
  }
};
