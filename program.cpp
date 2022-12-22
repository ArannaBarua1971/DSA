// today i create a single circuler LInkedList

// if we know single linkedlist have two parts
//  one is data part
//  another is address or next part(which indicates the next block address)
//  so before start next step we need to know that which operation we do in LINKedList
//  first operation is that
//  insert_front
//  insert_back
//  size
//  and we need this for making sepearate function to do different function

#include <bits/stdc++.h>
using namespace std;

// before start the program I want to creat a class which indicates the the block of linked List
class singlecirculerLInkedList
{ // this is the name of class(block) ,you can write this name by anything

public: // this is restrictact which is the part of OOP(object oriented programming)
    int data;
    singlecirculerLInkedList *next;  // this is the next part .we know that for store address we need pointer and same data type(like :singlecirculerLInkedList )
    singlecirculerLInkedList(int x); // this is the constractor which have parameter .and this parameter is use for data part of a block
};

// constructor purpose to intialize default  value of data part and next(address) part
singlecirculerLInkedList::singlecirculerLInkedList(int x)
{ // this is the method to create constructor//there i write (int x) because singlecirculerLInkedList have a parameter;
    data = x;
    next = NULL; // for the frist block next is NULL(which means in this next part there have no address of another block)
}

// now i create insert_front()function for insert block in first of the LinkedList
void insert_fornt(singlecirculerLInkedList* tail,int x)//this two parameter use for to create new block and to fulfill the datapart
{
    //for use this fuction we need the a pointer which bear the next block address
    //now i create the temporary block
    singlecirculerLInkedList* temp = new singlecirculerLInkedList(x);//this is the method of create a new block and object of class
    //for the constructor data=x and next =NULL intialized for 38 line
    // so data is intialize by the constractor
    // now we need to intialize the value of next pointer(part)
    //so
    temp->next=tail->next;//this is for circular single linkedList
    tail->next=temp;//this is for circular single linkedList
}

int main()
{
    // this is main function from there the program is start

    // so now we need make a object of singlecirculerLInkedList in main function
    singlecirculerLInkedList a(45); // and we enter a vlaue but for this we need a constructor(which calls automaticlly when create a object)

    //so for indicating next block address we need tail name address
    singlecirculerLInkedList* tail;//which always indicate the last block of linkedlist
    tail->next=tail;//this is for circular single linkedList
}