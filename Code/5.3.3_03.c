//后序非递归遍历二叉树
void PostOrder(BiTree T){
    InitStack(S);
    BiTNode *p=T;
    BiTNode *r=NULL;
    while(p || !IsEmpty(s)){
        if(p){
            push(S,p);
            p=p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild && p->rchile!=r)
                p=p->rchild;
            else{
                pop(S,p);
                visit(p->data);
                r=p;    //记录最近访问过的节点
                p=NULL; //节点访问过后重置p
            }
        }
    }
}