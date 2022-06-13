AdjList change(MGrape q)
{
    *AdjList p=(*AdjList)malloc(sizeof(AdjList)); //为邻接表头分配空间
    for(register int i=0;i<=MAX_VERTEX_INUM;i++) //行遍历
    {
        p[i]->data=q->vexs[i]; 
        p[i]->firstarc=NULL; //初始化邻接表头信息
        for(register int j=0;j<=MAX_VERTEX_INUM;j++) //列遍历
        {
            if(q->arcs[i][j]&&p[i]->firstarc==NULL) //为1且只有表头
            {
                *ArcNode q=(*ArcNode)malloc(sizeof(ArcNode)); //分配空间
                q->adjvex=j;
                q->nextarc=p[i]->firstarc;
                p[i]->firstarc=q;  //插入
            }
            else if(q->arcs[i][j]) //为1不只有表头
            {
                *ArcNode q=p[i]->firstarc;
                while(q->nextarc!=NULL) q=q->nextarc;//定位末节点
                *ArcNode r=(*ArcNode)malloc(sizeof(ArcNode)); //分配空间
                r->adjvex=j;
                r->nextarc=q->nextarc;
                q->nextarc=r;  //插入
            }
        }
    }
    return p; //返回表头
}
p=change(q) //q为邻接矩阵的指针,p为生成邻接表的表头