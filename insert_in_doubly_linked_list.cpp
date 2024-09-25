#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtHead(node *&head, node *&tail, int d)
{
    node *newnode = new node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insertAttail(node *&head, node *&tail, int d)
{
    node *newnode = new node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insertAtPosition(node *&head, node *&tail, int d, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    int cnt = 1;
    node *temp = head;
    while (temp != NULL && cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == NULL)
    {
        cout << "Poisition Out of range." << endl;
        return;
    }

    if (temp->next == NULL)
    {
        insertAttail(head, tail, d);
        return;
    }

    node *newnode = new node(d);

    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printreverse(node *tail)
{
    node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *tail = NULL;

    insertAtHead(head, tail, 3);
    insertAttail(head, tail, 4);
    insertAttail(head, tail, 5);
    insertAttail(head, tail, 6);
    insertAttail(head, tail, 8);

    insertAtPosition(head, tail, 7, 5);

    print(head);
    printreverse(tail);
}