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
	for(i=1;i<n;i++)//����n-1�Σ�ÿ������С���������-1���� 
	{
		int k=IN;
		for(j=1;j<n;j++)//���ҵ�һ�������k 
		{
			if(closedge[j].low!=-1)
			{
				k=j;
				break;
			}
		}
		for(j=1;j<=n;j++)//���۷����Ԫ����Ѱ����С��Ԫ��  
		{
			if(closedge[j].low!=-1)
			{
				if(closedge[j].low<closedge[k].low)
				k=j;
			}
		}
		sum+=closedge[k].low;
		closedge[k].low=-1;//ѡ��һ����С�Ĳ����� 
		//����k�ڵ��������Ԫ�ش���(���еĵ㶼��k�ڵ���������)
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
	int G[M][M];//�����ڽӾ���1000*1000�ᳬ�ڴ� 
	//G�ȳ�ʼ��Ϊ����
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
	 		t3=0;//-1������ѡ�����ϣ�0����·�Ѿ��޺��� 
		}
		G[t1][t2]=t3;
		G[t2][t1]=t3;
	 }
	 ZuixiaoTree(G,n);
	return 0;
}