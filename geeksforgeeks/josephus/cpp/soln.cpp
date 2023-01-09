
// Problem: geeksforgeeks
// Link: https://practice.geeksforgeeks.org/problems/josephus-problem/1
// Date: 09-01-2023
// Author: Nazib Abrar

#include <bits/stdc++.h>
using namespace std;

#define _DEBUG 1

struct LLnode
{
    int val;
    LLnode *previous, *next;
    LLnode(int v)
    {
        val = v;
        previous = next = NULL;
    }
    void deleteNode(LLnode *node)
    {
        LLnode *prev = node->previous;
        LLnode *nxt = node->next;
        delete node;
        prev->next = nxt;
        nxt->previous = prev;
    }
};

int josephus(int n, int k)
{
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    LLnode firstNode = LLnode(1);
    LLnode commonNode = firstNode;
    for (int i = 2; i < 10; i++)
    {
        commonNode->next = LLnode(i);
        commonNode = commonNode.next;
    }

    return 0;
}