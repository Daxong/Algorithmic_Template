#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAXNODE = 10005;
const int MAXEDGE = 100010;
const int INF = 0x3f3f3f3f;

struct Edge{
    int v, id, next;
    bool bridge;
    Edge() {}
    Edge(int v, int id, int next): v(v), id(id), next(next), bridge(false){}
}E[MAXEDGE * 2], cut[MAXEDGE];

struct Node {
    int u, v;
    Node() {}
    Node(int u, int v): u(u), v(v) {}
};

stack<Node> Stack;
//bcc��ʾ����һ��bcc����ĵ�
vector<int> bcc[MAXNODE];
//pre��¼����ʱ���,lowlink��¼���Ǹõ㼰�������ڵ����ܷ��ص�����ʱ����Ƕ���,bccno��¼���Ǹõ㵱ǰ�������ĸ�bcc��
int head[MAXNODE], pre[MAXNODE], lowlink[MAXNODE], bccno[MAXNODE];
int n, m, tot, bcc_cnt, dfs_clock, cut_cnt; 
bool iscut[MAXNODE];

//˫��ߵ����
void AddEdge(int u, int v, int id) {
    E[tot] = Edge(v, id, head[u]);
    head[u] = tot++;
    E[tot] = Edge(u, id, head[v]);
    head[v] = tot++;
}

void init() {
    memset(head, -1, sizeof(head));
    tot = 0;
}

//��˫��ͨ
void dfs(int u, int fa) {
    pre[u] = lowlink[u] = ++dfs_clock;
    int child = 0;//��¼��ǰ�ڵ��ж��ٸ��ӽڵ�
    for (int i = head[u]; ~i; i = E[i].next) {
        int v = E[i].v;
        if (!pre[v]) {
            Stack.push(Node(u, v));
            child++;
            dfs(v, u);
            lowlink[u] = min(lowlink[u], lowlink[v]);//����
            //�ӽڵ���෵�ص��õ�
            if (lowlink[v] >= pre[u]) {
                //�ñ�Ϊ��
                if (lowlink[v] > pre[u]) {
                    E[i].bridge = E[i ^ 1].bridge = true;
                    cut[cut_cnt++] = E[i];
                }
                iscut[u] = true;
                bcc_cnt++; bcc[bcc_cnt].clear();
                while (1) {
                    Node x = Stack.top(); Stack.pop();
                    if (bccno[x.u] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }
                    if (bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if (x.u == u && x.v == v) break;
                }
            }
        }
        else if (v != fa && pre[v] < pre[u]) {//�����
            Stack.push(Node(u, v));
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    //u�Ǹ���㣬��ֻ��һ�����ӣ��ǾͲ��Ǹ����
    if (fa < 0 && child == 1) iscut[u] = 0;
}

void find_bcc() {
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    dfs_clock = bcc_cnt = cut_cnt = 0;
    for (int i = 0; i < n; i++) 
        if (!pre[i]) dfs(i, -1);
}

int main() {
    init();
    return 0;
}