//邻接表
#define MaxVertexNum 100
    int adjvex;             //该弧指向顶点位置
    strct ArcNode *next;    //指向下一条弧的指针
    //InfoType info;
}ArcNode;

typedef struct VNode{       //顶点表节点
    VertexType data;
    ArcNode *first;
}VNode,AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;       //邻接表
    int vexnum ,arcnum;
}ALGragh;