#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

class LinkedList
{
    Node *head;
    int len = 0;

public:
    LinkedList()
    {
        head = NULL;
    }
    void insertNode(int d);
    void deleteNode(int index);
    void printList();
};

void LinkedList::printList()
{
    Node *selector = this->head;
    if (this->head == NULL)
    {
        cout << "The List is Empty" << endl;
        return;
    }
    while (selector->next != NULL)
    {
        cout << selector->data << "\n";
        selector = selector->next;
    }
    cout << selector->data << "\n";
}

void LinkedList::insertNode(int d)
{
    Node *selector = this->head;
    Node *newNode = new Node(d);
    if (this->head == NULL)
    {
        this->head = newNode;
        this->len++;
        return;
    }

    while (selector->next != NULL)
    {
        selector = selector->next;
    }
    selector->next = newNode;
    this->len += 1;
    // cout << this->len << " is the current length" << endl;
}
void LinkedList::deleteNode(int index)
{
    if (index + 1 > this->len || this->len == 0)
    {
        cout << "Invalid index " << index << ". List Length " << this->len << endl;
        return;
    }
    Node *prev_selector = this->head;
    Node *selector = prev_selector->next;

    // Handling the deletion of head
    if (index == 0)
    {
        delete this->head;
        this->head = selector;
        return;
    }
    for (int i = 2; i <= index; i++)
    {
        prev_selector = prev_selector->next;
        selector = selector->next;
    }
    prev_selector->next = selector->next;
    delete selector;
    this->len--;
}

int main()
{
    LinkedList *ll = new LinkedList();
    // ll->insertNode(0);
    // ll->insertNode(1);
    // ll->insertNode(2);
    // ll->insertNode(3);
    // ll->insertNode(4);
    ll->printList();
    cout << "-----------" << endl;
    ll->deleteNode(10);
    ll->printList();
    return 0;
}