#include<stdio.h>
#define size 100
 
struct stack{
    int num[size];
    int idx;
};
 
void position(struct stack* s1){
    s1->idx=-1;
}
void push(struct stack* s1,int n){
    if(s1->idx==100){
        printf("stack is already full.You can't give any value.\n");
    }
    s1->num[++s1->idx]=n;
}
void pop(struct stack* s1){
    if(s1->idx==-1){
        printf("stack is already empty.You can't remove any value.\n");
        return;
    }
    s1->idx--;
}
void top(struct stack* s1){
    if(s1->idx>=0){
        printf("%d\n",s1->num[s1->idx]);
        return;
    }
    else{
        printf("Stack is empty.No value is available in stack.\n");
    }
}
void isEmpty(struct stack* s1){
    if(s1->idx==-1){
        printf("stack is empty.\n");
        return;
    }
    printf("stack is not empty.\n");
}
 
void Size(struct stack* s1){
    printf("%d\n",s1->idx+1);
}
int main(){
 
    struct stack s1;
    position(&s1);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    push(&s1,7);
    top(&s1);
    isEmpty(&s1);
    Size(&s1);
}