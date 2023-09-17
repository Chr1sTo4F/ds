#include <stdio.h>
LinkList Search_1st_Common(LinkList L1,LinkList L2){
    int dist;
    LinkList llist,slist;//定义长短链表，之后让他们分别指向这两个
    int len1=Length(L1),len2=Length(L2);
    if(len1>len2){
        llist=L1->next;
        slist=L2->next;
        dist=len1-len2;
    }
    else{
        llist=L2->next;
        slist=L1->next;
        dist=len2-len1;
    }
    while(dist--)
        llist=llist->next;
    while (llist!=NULL)
    {
        if(llist==slist)
            return llist;
        else{
            llist=llist->next;
            slist=slist->next;
        }     
    }
    return NULL;
    
}