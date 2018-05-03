/*
��Щ�����У�ֻ���һ�����㵽������������·���ǲ����ģ���Ҫ���ÿ�Զ������̾��룬����������dijkstra�㷨��
���̻���ʱ�临�Ӷȹ��ߣ�������һ�ֱ�̼򵥣�ʱ��Ч�ʸ��ߵ��㷨---Floyd�㷨

Floyd�㷨������������ͼ������ͼ����Ȩ�����ɸ���ΨһҪ���ǲ����и����� 
*/

const int maxn=1001;

//mat�洢ͼ����Ϣ
//dist�洢��̳���
//pre�洢i��j·����j��ǰһ�ڵ�

int n; //n����
void floyd()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=mat[i][j];
			pre[i][j]=i;
		}
		for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		{
			if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX &&dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pre[i][j]=pre[k][j];
				}
		}
	}
}
