#include <stdio.h>
#include <stdlib.h>
#define M 101
#define IN 10000
struct Edge{
	int adj;
	int low;
}closedge[M];
void ZuixiaoTree(int G[M][M],int n)
{
	int i,j,sum=0;
	closedge[1].low=-1;
	for(j=2;j<=n;j++)
	{
		if(G[j][1]<closedge[j].low)
		{
			closedge[j].adj=1;
			closedge[j].low=G[j][1];
		}
	}
	for(i=1;i<n;i++)//遍历n-1次，每次找最小边输出，赋-1更新 
	{
		int k=IN;
		for(j=1;j<n;j++)//先找到一个非零的k 
		{
			if(closedge[j].low!=-1)
			{
				k=j;
				break;
			}
		}
		for(j=1;j<=n;j++)//代价非零的元素中寻找最小的元素  
		{
			if(closedge[j].low!=-1)
			{
				if(closedge[j].low<closedge[k].low)
				k=j;
			}
		}
		sum+=closedge[k].low;
		closedge[k].low=-1;//选择一个最小的并进来 
		//根据k节点更新数组元素代价(所有的点都和k节点连接试试)
		for(j=1;j<=n;j++)
		{
			if(G[j][k]<closedge[j].low)
			{
				closedge[j].adj=k;
				closedge[j].low=G[j][k];
			}
		} 
	}
	printf("%d",sum);
}
int main(int argc, char *argv[]) 
{
	int i,j,n,m;
	int G[M][M];//先用邻接矩阵，1000*1000会超内存 
	//G先初始化为无穷
	for(i=1;i<M;i++) 
	{
		for(j=1;j<M;j++)
		{
			G[i][j]=IN;
		}
	}
	 for(i=0;i<M;i++)
	 {
	 	closedge[i].low=IN;
	 }
	 scanf("%d",&n);
	 m=n*(n-1)/2;
	 for(i=0;i<m;i++)
	 {
	 	int t1,t2,t3,t4;
	 	scanf("%d",&t1);
	 	scanf("%d",&t2);
		scanf("%d",&t3);
	 	scanf("%d",&t4);
	 	if(t4==1)
	 	{
	 		t3=0;//-1代表并入选定集合，0代表路已经修好了 
		}
		G[t1][t2]=t3;
		G[t2][t1]=t3;
	 }
	 ZuixiaoTree(G,n);
	return 0;
}