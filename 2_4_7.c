void RangeDelete(LinkList &L,int min,int max){
    LNode *pre=L,*p=L->next;
    while (p!=NULL)
        if (p->data>min &&p->data<max){
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        else {
            pre=p;
            p=p->next;
            }
               
    
}