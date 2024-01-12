/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:14:22
 * filename    : 19-remove-nth-node-from-end-of-list.cpp
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    vector<ListNode *> nodes;
    ListNode *p = head;
    while (p != nullptr) {
      nodes.pb(p);
      p = p->next;
    }

    int m = nodes.sz();
    if (m == 0)
      return nullptr;

    n = (n - 1) % m;
    n = m - 1 - n;
    if (n == 0)
      return nodes[0]->next;
    if (n == m - 1) {
      nodes[m - 2]->next = nullptr;
      return nodes[0];
    }
    nodes[n - 1]->next = nodes[n + 1];
    return nodes[0];
  }
};
