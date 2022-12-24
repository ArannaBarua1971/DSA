#include<iostream>
using namespace std;
 
class dequeue
{
    private:
        int front,idx,total=5;
        int arr[5];
    public:
        dequeue();
        void push_back_q(int x);
        void push_front_q(int x);
        void pop_front_q();
        void pop_back_q();
        void size_q();
        void front_q();
        void back_q();
        void isEmpty_q();
};
dequeue::dequeue()
{
    idx=front=-1;
}
void dequeue::push_front_q(int x)//push the value in queue
{
    if((front==0 && idx==total-1) || front==idx+1)
    {
        cout<<"queue is full"<<endl;
        return;
    }
    if(front==-1) idx=front=0;
    else if(front==0) front=total-1;
    else front--;
 
    arr[front]=x;
}
void dequeue::push_back_q(int x)//push the value in queue
{
    if((front==0 && idx==total-1) || front==idx+1)
    {
        cout<<"queue is full"<<endl;
        return;
    }
    if(idx==-1) idx=front=0;
    else if(idx==total-1) idx=0;
    else idx++;
 
    arr[idx]=x;
}
void dequeue::pop_front_q()//pop the value in queue
{
    if(front==-1)
    {
        cout<<"queue is already empty"<<endl;
        return;
    }
    if(front==idx) idx=front=-1;
    else if(front==total-1) front=0;
    else front++;
}
void dequeue::pop_back_q()//pop the value in queue
{
    if(front==-1)
    {
        cout<<"queue is already empty"<<endl;
        return;
    }
    if(front==idx) idx=front=-1;
    else if(idx==0) idx=total-1;
    else idx--;
}
void dequeue::size_q()//measure the size of queue
{
    if(front==-1)
    {
        cout<<"0"<<endl;
        return;
    }
    if(front>idx) cout<<(total-front)+idx+1<<endl;
    else cout<<idx-front+1<<endl;   
}
void dequeue::front_q()//check the front of queue
{
     if(front==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<arr[front]<<endl;
}
void dequeue::back_q()//check the front of queue
{
     if(front==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<arr[idx]<<endl;
}
void dequeue::isEmpty_q()//check the queue it is empty or not
{
    if(front==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<"queue is not empty"<<endl;
}
 
int main()
{
    dequeue a;//object of dequeue
    a.push_back_q(56);
    a.push_back_q(78);
    a.push_front_q(16);
    a.back_q();
    a.front_q();
    a.pop_front_q();
    a.front_q();
    a.back_q();
    a.pop_back_q();
    a.size_q();
    a.back_q();
    a.front_q();
    a.pop_front_q();
    a.size_q();
    a.pop_back_q();
    a.pop_front_q();
    a.push_back_q(56);
    a.push_back_q(5e6);
    a.push_back_q(52);
    a.push_back_q(516);
    a.push_back_q(526);
    a.push_back_q(516);
    a.front_q();
    a.back_q();
    a.push_front_q(34);
}