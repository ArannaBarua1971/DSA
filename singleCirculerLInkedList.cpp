#include <bits/stdc++.h>
using namespace std;
class linkedList
{
public:
    int data;
    linkedList *next;
    linkedList(int x);
};
 
linkedList::linkedList(int x)
{
    data = x;
    next = NULL;
}
 
void insert_front(linkedList *tail, int x)
{
    linkedList *temp = new linkedList(x);
    temp->next = tail->next;
    tail->next = temp;
}
 
void insert_back(linkedList *&tail, int x)
{
    linkedList *temp = new linkedList(x);
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
}
 
int Size(linkedList *tail)
{
    int value = tail->data;
    int count = 0;
    do
    {
        tail = tail->next;
        count += 1;
    } while (tail->data != value);
    return count;
}
 
void insert_anywhere(linkedList *&tail, int idx, int x)
{
    int total = Size(tail) + 1;
    if (idx <= total)
    {
        if (idx == 1)
            insert_front(tail, x);
        else if (total == idx)
            insert_back(tail, x);
        else
        {
            linkedList *start = tail->next;
            for (int i = 0; i < (idx - 1); i++)
            {
                start = start->next;
            }
            linkedList *temp = new linkedList(x);
            temp->next = start->next;
            start->next = temp;
        }
    }
}
 
void deletation(linkedList *&tail, int idx)
{
    int total = Size(tail);
    if (idx <= total)
    {
        linkedList *start = tail;
        for (int i = 0; i < (idx - 1); i++)
        {
            start = start->next;
        }
        if (idx == 1)
            tail->next = tail->next->next;
        else if (total == idx)
        {
            start->next=tail->next;
            tail=start;
        }
        else{
            start->next=start->next->next;
        }
    }
}
void print(linkedList *tail)
{
    int value = tail->data;
    do
    {
        tail = tail->next;
        cout << tail->data << " ";
    } while (tail->data != value);
    cout << endl;
}
int main()
{
 
    linkedList a(45);
    linkedList *tail = &a;
    tail->next = tail;
 
    insert_front(tail, 46);
    insert_front(tail, 67);
    insert_back(tail, 78);
    insert_anywhere(tail, 5, 99);
 
    deletation(tail,2);
    deletation(tail,4);
    print(tail);
    cout<<tail->data<<"::"<<Size(tail);
}