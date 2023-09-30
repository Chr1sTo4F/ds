//进队时tag=1,出队时tag=0,
#include <stdio.h>
 int EnQueue(SqQueue &Q,ElemType x){
    if(Q.front==Q.rear && Q.tag==1)
        return 0; //队满
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%Maxsize;
    Q.tag=1;
    return 1;
 }

int DeQueue(SqQueue &Q,ElemType &x){
     if(Q.front==Q.rear && Q.tag==0)
        return 0; //队空
    x=Q.data[front];
    Q.front=(Q.front+1)%Maxsize;
    Q.tag=0;
    return 1;
}