#include <bits/stdc++.h>
using namespace std;
int Size=-1;

class Node
{
public:
    int data;
    int pirotyNumber;
    Node *next;
    Node(int x, int y);
};

Node::Node(int x, int y)
{
    data = x;
    pirotyNumber = y;
    next = NULL;
    Size++;
}

void insertion(Node *&head, int x, int y)
{  
    Node *temp = new Node(x, y);
    Node *p1 = head;
    Node *p2;
    
    if(Size==1)
    {
        if(p1->pirotyNumber <= temp->pirotyNumber)
        {
            p1->next=temp;
        }
    }
    else{
        while((p1->pirotyNumber <= temp->pirotyNumber))
        {
            p2=p1;
            if(p2->next==NULL) break;
            p1=p1->next;
        }

        if(p2->next==NULL)
        {
            p2->next=temp;
        }
        else
        {
            temp->next=p1;
            p2->next=temp;
        }
    }
}

void delet(Node* &head)
{
    head=head->next;
    Size--;
}

void print(Node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    Node obj(3, 1);
    Node *head = &obj;

    insertion(head, 458, 3);
    insertion(head, 45, 3);
    insertion(head, 5, 5);
    insertion(head, 55, 5);
    insertion(head, 0, 99);
    print(head);
}