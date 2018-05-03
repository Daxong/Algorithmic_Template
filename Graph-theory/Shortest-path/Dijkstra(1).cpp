
// ��Ȩ����ͼ����Դ���������и���������·�����ȡ�
// ��Դ���·�����⣬�����ܴ������Ȩ�ߵ�ͼ 
// ���·��dijkstra�㷨

/*
The time complexity of the  implementation is O(n+mlogm), because
the algorithm goes through all nodes of the graph and adds for each edge at most
one distance to the priority queue.
*/

// �㷨��ʵ��ģ�壺
#define MaxN 10010 //MaxN�ǵ�ĸ���
#define MaxInt 200000000  //MabInt��ʾ���ɴ�
int map[MaxN][MaxN],dist[MaxN];
bool mark[MaxN];
int start,end;

int dijlstra()
{
	for(int i=1;i<=end;i++) dist[i]=MaxInt;
      memset(mark,0,sizeof(mark));
      dist[start]=0;
      //����㲢�뼯�ϣ������ľͿ��Դ����Ѱ�ҵ�һ����̵ı���
	  for(int i=1;i<=end-1;i++)
	  {
	  	min1=MaxInt;
	  	for(int j=1;j<=end;j++)  //���ҵ�ԭ���ϵ���̵ı� 
	  	{
	  		if(!mark[j] && dist[j]<min1)
	  		{
	  			min1=dist[j];
	  			minj=j;
	  		}
	  	}
	  	mark[minj]=1;
//ÿ����һ���㶼Ҫ��ԭ���ı������������֤����ʱ��Դ�㵽Ŀ���ľ��붼����̵� 
		  for(int j=1;j<=end;j++)
		  {
		  	if(!mark[j] && map[minj][j]>0)
			  {
			  	temp=dist[minj]+map[minj][j];
			  	if(temp<dist[j]) dist[j]=temp;
			  } 
		  } 
	  } 
	  return dist[end];
}
 