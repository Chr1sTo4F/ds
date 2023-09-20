//线索二叉树
//中序线索化(递归)
void InThread(TreadTree &p,ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){
            p->lchild=pre;//左子树为空，建立前驱线索
            p->ltag=1;
        }
        if(pre!=NULL & pre->rchild==NULL){ //建立前驱节点的后继线索
            pre->lchild=p;
            pre->tag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}

void CreateInThread(ThreadTree T){
    ThreadTree pre=NULL;
    if(T!=NULL){
        InThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}

//中序线索二叉树的遍历
//求中序线索二叉树中 中序序列下的第一个节点
ThreadNode *Firstnode(ThreadNode *p){
    while(p->tag==0) p-p>lchild; /* 最左下节点，不一定是叶节点 */
    return p;
}
//求中序线索二叉树中节点p在中序系列下的后继
ThreadNode *Nextnode(ThreadNode *p){
    if(p->rtag==0) return
}