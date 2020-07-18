#include<iostream>
#include<vector>
#include<cmath>
#define endl '\n'
#define wln(x) cout<<x<<endl
#define pb push_back

#define MAX_V 10005     //记得改，结点数 
#define MAX_LOG_V 30    //记得改 

using namespace std;

vector<int> G[MAX_V];   //邻接表G 
int root;				//根节点root 

int vs[MAX_V * 2 -1];   //DFS访问顺序  
int depth[MAX_V * 2 -1]; 		//节点的深度 
int id[MAX_V];			//各个节点在vs中首次出现的下标


void dfs(int v,int p,int d,int &k)
{
	id[v] = k;			
	vs[k] = v;			
	depth[k++] = d;		
	for(int i=0;i<G[v].size();i++){
		if(G[v][i] != p){
			dfs(G[v][i],v,d+1 ,k);
			vs[k] = v;
			depth[k++] = d;
		}
	}
}


int dp[40050][30];

void rmq_init(int *arr,int n)
{
	//无敌rmq写法，直接记录最小值所在的下标，而不用用结构体 
	for(int i=0;i<n;i++)
	{
		dp[i][0] = i;
	}
	for(int j=1;(1<<j) <= n;j++)				//从小到大 
		for(int i = 0; i+(1<<j)-1<n ;i++)		//因为后面要递推，所以现在大小应该是下面的双倍大 
		{
			int a = dp[i][j-1];
            int b = dp[i + (1<<(j-1))][j-1];
            if(depth[a] <= depth[b])//比较的下标所对应的值
                dp[i][j] = a;//更新下标
            else
                dp[i][j] = b; 
		}
}

void init(int V)
{
	int k=0;
	dfs(root,-1,0,k);
	rmq_init(depth, V*2-1);
}

int rmq(int L,int R)
{
	
	int k = 1;
    while((1<<(k+1)) <= R-L+1) k++;
    int a = dp[L][k];
    int b = dp[R - (1<<k) + 1][k];
    if(depth[a] <= depth[b])
        return a;//返回下标
    else
        return b;
}

int lca(int u,int v)
{
	int x=min(id[u],id[v]);
	int y=max(id[u],id[v]);
	return vs[ rmq(x,y)];  //lca就是求两个id里面的depth最小值的点是哪个了吧。 
}
 
 
void solve()
{
	int V;
	cin>>V;
	for(int i=1;i<=V;i++)	//这步初始化很关键. 
		G[i].clear();
		
	vector<int> in(V+1,0);	//统计记录一下入度，入度为零的点为根节点. 
	for(int i=1;i<V;i++)
	{
		int x,y;
		cin>>x>>y;
		in[y]++;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=V;i++)
		if(in[i]==0) root=i;
	init(V);
	
	int q=1;
	//cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		wln(lca(x,y));
	}
	
}


int main(){
	
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
