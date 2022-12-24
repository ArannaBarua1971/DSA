#include<iostream>
using namespace std;
 
class circular_queue
{
    private:
        int front,idx,total=5;
        int arr[5];
    public:
        circular_queue();
        void push_q(int x);
        void pop_q();
        void size_q();
        void front_q();
        void isEmpty_q();
};
circular_queue::circular_queue()
{
    idx=front=-1;
}
void circular_queue::push_q(int x)//push the value in queue
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
void circular_queue::pop_q()//pop the value in queue
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
void circular_queue::size_q()//measure the size of queue
{
    if(front==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    if(front>idx) cout<<(total-front)+idx+1<<endl;
    else cout<<idx-front+1<<endl;   
}
void circular_queue::front_q()//check the front of queue
{
     if(front==-1)
    {
        cout<<"queue is empty"<<endl;
        return;
    }
    cout<<arr[front]<<endl;
}
void circular_queue::isEmpty_q()//check the queue it is empty or not
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
    circular_queue a;//object of circular_queue
 
    a.push_q(56);
    a.push_q(561);
    a.push_q(556);
    a.push_q(526);
    a.push_q(516);
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.pop_q();
    a.front_q();//516
    a.size_q();
    a.push_q(67);
    a.front_q(); //516   
    a.pop_q();
    a.size_q();
    a.front_q();
    a.isEmpty_q();
}