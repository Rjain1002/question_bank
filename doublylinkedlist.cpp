#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node*prev;
    Node*next;

    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node()
    {
        int value = this -> data;

        //memory free kar rahe he;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
            this -> prev = NULL;
        }
        cout<<"memory is deleted for data value  "<<value<<endl;
    }
};

void insertathead(Node* &head,int d)
{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    //head -> next = NULL;
    //temp -> prev = NULL;
    head = temp;
}

void insertattail(Node* &tail,int d)
{
    Node*temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    temp = tail;
}

void insertatmid(Node* &tail, Node* &head, int position, int d)
{
    if(position == 1)
    {
        insertathead(head,d);
        return;
    }
        Node* temp =head;
        int cnt = 1;
        while(cnt<position-1)
        {
            temp = temp -> next;
            cnt++;
        }
        
        if(temp -> next == NULL)
        {
            insertattail(tail,d);
            return;
        }
        Node* nodetoinsert = new Node(d);
        nodetoinsert -> next = temp -> next;
        temp -> next -> prev = nodetoinsert;
        temp -> next = nodetoinsert;
        nodetoinsert -> prev = temp;
    return;
}


void deletenode(Node* &head, int position)
{
    if(position == 1)
        {
            Node* temp = head;
            head = head -> next;
            temp -> next =NULL;
            delete temp;
        }

        else
        {
            Node* curr = head;
            Node* pre = NULL;

            int cnt = 1;
            while(cnt<position)
            {
                pre = curr;
                curr = curr -> next;
                cnt++;
            }
            pre -> next = curr -> next;
            curr -> next -> prev = pre;

        }
}
void print(Node* &head)
{
    Node* temp = head;
    {
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
}
int main()
{
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;

    insertathead(head,11);

    insertathead(head,12);

    insertathead(head,8);

    insertattail(tail,40);

    insertatmid(tail,head,2,50);
    insertatmid(tail,head,2,60);
    insertatmid(tail,head,1,90);
    insertathead(head,100);
    deletenode(head,3);
    print(head);

    return 0;
}


