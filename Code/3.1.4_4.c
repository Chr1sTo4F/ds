#include <stdio.h>

int dc(LinkList L,int n){
    int i;
    char s[n/2];
    LNode *p=L->next;
    for(i=0;i<n/2;i++){
        s[i]=p->data;
        p=p->next;
    }
    i--;
    if(n%2==1)
        p=p->next;
    while(p!=NULL &&s[i])==p->data){
        i--;
        p=p->next;
    }
    if(i==-1)
        return 1; //空栈表示中心对称
    else
        return 0;
}