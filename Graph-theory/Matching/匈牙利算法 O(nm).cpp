/*
�������㷨
*/

// vector�ڽӱ� O(nm)

std::vector<int> link[maxn];
int match[maxn];
int n;
int vis[maxn];
int dfs(int u)
{
  int m = link[u].size();
  for(int i = 0; i < m; i++) {
    if(!vis[link[u][i]]) { // u->i�б�,�ҽڵ�iδ������
    	
      vis[link[u][i]] = 1; //��ǽڵ��ѱ�����

      //��� i ������ǰһ��ƥ�� M �� i ƥ�䵽�Ľڵ����Ѱ�ҵ�����·
      if(match[link[u][i]] == -1 || dfs(match[link[u][i]])) {
        match[link[u][i]] = u; //����ƥ��
        return 1;
      }
    }
  }
  return 0;
}
int hungary()
{
  int cnt = 0;
  memset(match,-1,sizeof(match));
  for(int i = 0; i < n; i++) {
    memset(vis,0,sizeof(vis));
    if(dfs(i)) {
      cnt++;
    }
  }
  return cnt;
}

// ��ͼ�� link[x].push_back(y);
