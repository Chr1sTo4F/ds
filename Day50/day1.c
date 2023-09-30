//Day01
//在带头结点的单链表L中,删除所有值为x的结点,并释放其空间,假设值为x的结点不唯一
//编写算法以实现上述操作
void Del_x(LinkList &L,ElemType x){
	LNode *p = L->next,*pre = L,*q;
	while(p != NULL){
		if(p->data == x){
			q = p;//q用来标记待删除的结点
			p = p->next;
			pre->next = p;
			free(q);
		} else {
			pre = p;
			p = p->next;
		}
	}
}