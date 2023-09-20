/* 双亲表示法 */
#define MAX_TREE_SIZE 100
typedef struct 
{
    ElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode  nodes[MAX_TREE_SIZE];
    int n;
}PTree;

/* 孩子兄弟表示法（二叉树表示法） */
typedef struct CSNode{
    ElemType data;
    CSNode *firstchild, *nextsibling;
}CSNode,*CSTree;
