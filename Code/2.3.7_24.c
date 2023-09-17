//核心思想：空间换时间
#include <stdio.h>

typedef struct node{
    int data;
    struct node *link;
}NODE;
typedef NODE *PNODE;

void func (PNODE h,int n){
    PNODE p=h,r;
    int *q,m;
    q=(int *)malloc(sizeof(int)*(n+1));
    for(int i=0;i<n+1;i++)          //initialize-->0
        *(q+1)=0;
    while(p->link!=NULL){
        m=p->link->data>0?p->link->data:-p->link->data; //absolute value
        if(*(q+m)==0){
            *(q+m)=1;
            p=p->link;
        }
        else{
            r=p->link;
            p->link=r->link;
            free(r);
        }
        free(q);
    }
}