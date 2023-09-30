//DFS
bool visited[MAX_VERTEX_NUM]

void DFSTraverse(Grapgh G){
    for(v=0;v<G.vexnum;++i)
        visited[v]=FALSE;
    for(v=0;v<G.vexnum;++v)
        DFS(G,v);
}
void DFS(Gragh G,int v){
    visit(v);
    visited[v]=TRUE;
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w])
            DFS(G,w);
}