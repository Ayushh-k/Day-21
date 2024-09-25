#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }

    ~node()
    {
        int value = this->data;
        if (this->next != nullptr)
        {
            delete next;
            next = nullptr;
        }
        cout << "Delete node is: " << value << endl;
    }
};

void insertAtHead(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&head, node *&tail, int data)
{
    if (tail == NULL)
    {
        node *temp = new node(data);
        head = temp;
        tail = temp;
    }
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

void deleteByValue(node *&head, node *&Tail, int value)
{
    if (head == NULL)
    {
        return;
    }

    if (value == head->data)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        node *prev = NULL;
        node *curr = head;

        while (curr != NULL && curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL)
        {
            cout << "Value not found." << endl;
            return;
        }

        prev->next = curr->next;
        if (curr->next == NULL)
        {
            Tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head, node *&tail)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool floydLoopDetection(node *&head, node *&tail)
{
    if (head == NULL)
    {
        return false;
    }

    node *slow = head;
    node *fast = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    node *first = new node(5);
    node *head = first;
    node *tail = first;
    insertAtHead(head, tail, 6);
    insertAtHead(head, tail, 8);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 7);

    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);

    tail->next = head;

    bool loop = floydLoopDetection(head, tail);
    if (loop)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}