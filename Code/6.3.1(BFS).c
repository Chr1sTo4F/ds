//BFS
bool visited[MAX_VERTEX_NUM]

void BFSTraverse(Gragp G){
    for(i=0;i<G.vexnum;++i)
        visited[i]=FALSE;
    InitQueue[Q];
    for(i=0;i<G.vexnum;++i)
        if(!visited[i])
            BFS(G,i);
}
void BFS(Graph G,int v){
    visit(v);
    visited[v]=TRUE;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))
            if(!visited[w]){
                visit(w);
                visited[w]=TRUE;
                EnQueue(Q,w);
            }
    }
}



//BFS单源最短路径
void BFS_MIN_Distance(Gragp G,int u){
    for(i=0;i<G.vexnum;++i)
        d[i]=999999999999999;
    visited[u]=TRUE;
    d[u]=0;
    Enqueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>0;w=NextNeighbor(G,v,w))
            if(!visited[w]){
                visit(w);
                visited[w]=TRUE;
                d[w]=d[u]+1;
                EnQueue(Q,w);
            }
    }
}