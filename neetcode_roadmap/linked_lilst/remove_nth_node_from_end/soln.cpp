#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector_elements(vector<T> &v)
{
    for (T &e : v)
    {
        cout << e << " ";
    }
    cout << "\n";
}

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/**
 * Definition for singly-linked list.
 **/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> listNode;
        ListNode *current = head;
        while (current != NULL)
        {
            listNode.push_back(current);
            current = current->next;
        }
        if (n >= listNode.size())
        {
            return head->next;
        }
        if (n >= 1)
        {
            listNode[listNode.size() - n - 1]->next = listNode[listNode.size() - n]->next;
        }
        return head;
    }
};

ListNode *createLinkedList(const std::vector<int> &nums)
{
    ListNode dummy;
    ListNode *tail = &dummy;
    for (int num : nums)
    {
        tail->next = new ListNode(num);
        tail = tail->next;
    }
    return dummy.next;
}

// Function to print a linked list
void printLinkedList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

int main()
{
    Solution s;

    // Test case 1
    ListNode *head1 = createLinkedList({1, 2, 3, 4, 5});
    ListNode *result1 = s.removeNthFromEnd(head1, 2);
    printLinkedList(result1); // Expected output: 1 2 3 5

    // Test case 2
    ListNode *head2 = createLinkedList({1});
    ListNode *result2 = s.removeNthFromEnd(head2, 1);
    printLinkedList(result2); // Expected output: (empty)

    // Test case 3
    ListNode *head3 = createLinkedList({1, 2});
    ListNode *result3 = s.removeNthFromEnd(head3, 1);
    printLinkedList(result3); // Expected output: 1

    return 0;
}
