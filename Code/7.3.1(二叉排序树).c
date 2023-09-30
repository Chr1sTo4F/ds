//二叉排序树
//非递归查找算法
BSTNode *BST_Search(BiTree T,ElemType key){
    while(T!=NULL && key!=T->data){
        if(key<T->data)
            T=T->lchild;
        else T=T->rchild;
    }
    return T;
}

//插入
int BST_Insert(BiTree &T,KeyType k){
    if(T==NULL){                            //原树为空，新插入的记录为根节点
        T=(BiTree)malloc(sizeof(BSTNode));
        T->data=k;
        T->lchild=T->rchild=NULL;
        return 1;   //return 1,success
    }
    else if(k==T->data)
        return 0;
    else if(k<T->data)
        return BST_Insert(T->child,k);
    else 
        return BST_Search(T->rchild,k);
}

//构造
void Create_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}