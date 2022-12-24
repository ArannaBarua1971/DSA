#include<iostream>
using namespace std;
 
class normal_queue
{
    private:
        int front,idx,total=10;
        int arr[10];
    public:
        normal_queue();
        void push_q(int x);
        void pop_q();
        void size_q();
        void front_q();
        void isEmpty_q();
};
normal_queue::normal_queue()
{
    idx=front=-1;
}
void normal_queue::push_q(int x)//push the value in queue
{
    if(front==0 && idx==total)
    {
        cout<<"queue is full"<<endl;
    }
    else if(idx==-1)
    {
        idx=0;
        front=0;
        arr[idx]=x;
        idx++;
    }
    else
    {
        arr[idx]=x;
        idx++;
    }
}
void normal_queue::pop_q()//pop the value in queue
{
    if(front==idx)
    {
        cout<<"queue is already empty"<<endl;
        return;
    }
    front++;
}
void normal_queue::size_q()//measure the size of queue
{
    if(front==idx)
    {
        cout<<"0"<<endl;
        return;
    }
    cout<<idx-front<<endl;   
}
void normal_queue::front_q()//check the front of queue
{
    if(front==idx)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<arr[front]<<endl;  
}
void normal_queue::isEmpty_q()//check the queue it is empty or not
{
    if(front==idx)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"queue is not empty"<<endl;
}
 
int main()
{
    normal_queue a;//object of normal_queue
 
    a.push_q(5);
    a.push_q(53);
    a.push_q(25);
    a.push_q(51);
    a.push_q(57);
    a.push_q(95);
    a.push_q(65);
 
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.size_q();
    a.front_q();
}