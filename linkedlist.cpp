#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class llist
{
    public:
    Node* head;
    llist()
    {
        head = NULL;
    }
    void insertNode(int data)
    {
        Node* temp = new Node(data);
        if(head == NULL)
        {
            head = temp;
            return;
        }
        Node* temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
    }
    void deletenode(int n)
    {
        Node* temp = head;
        Node* temp1 = temp;
        int len = 0;
        while(temp!= NULL)
        {
            temp = temp->next;
            len++;
        }
        temp = head;
        if(len<n)
        {
            cout<<"Invalid"<<endl;
            return;
        }
        if(n==1)
        {
            head = head->next;
            delete temp;
            return;
        }
        while(n-- > 1)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = temp->next;
        delete temp;
    }
    void print()
    {
        Node* temp = head;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
    int main()
    {
        llist l;
        l.insertNode(1);
        l.insertNode(2);
        l.insertNode(3);
        l.insertNode(4);
        l.print();
        l.deletenode(5);
        cout<<endl;
        l.print();
        return 0;
    }
