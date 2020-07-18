#include<iostream>
#include<vector>
#define endl '\n'
#define wln(x) cout<<x<<endl
#define pb push_back

#define MAX_V 10005     //记得改，结点数 
#define MAX_LOG_V 30    //记得改 

using namespace std;

vector<int> G[MAX_V];   //邻接表G 
int root;				//根节点root 

int parent[MAX_LOG_V][MAX_V];  //parent[t][x], 代表x的2^t祖先是谁，比如parent[0][x],代表x的父亲 
int depth[MAX_V]; 		//节点的深度 

void dfs(int v,int p,int d){
	parent[0][v] = p;	//记录v节点的父亲 
	depth[v] = d;		//记录v节点的深度 
	for(int i=0;i<G[v].size();i++){
						//迭代v的所有边，如果不是父亲节点则继续 
		if(G[v][i] != p) dfs(G[v][i],v,d+1);
	}
}

void init(int V)
{ 
	dfs(root ,-1 ,0); 	//初始化，计算出parent[0][1~V] 以及深度 
	for(int k = 0; k+1<MAX_LOG_V; k++) // for k = 0 ~ MAX_LOG_V-1 
		for(int v = 1; v <= V;v++)  //for v = 1~V  注意这道题是节点是1开始标号的 
		{
			if (parent[k][v]<0) parent[k+1][v] = -1;  //如果已经<0了，那之后全<0 
			else parent[k+1][v] = parent[k][ parent[k][v] ]; //否则的话进行2的次幂展开。 
		}
}

int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v); 		//计算LCA，先把较深节点赋值v. 
	for( int k=0;k<MAX_LOG_V;k++){
		if((depth[v] - depth[u])>>k & 1){ 	//这个二分很巧妙，用位运算，看看哪里可以跳，则跳。 
			v = parent[k][v];
		}
	}
	
	if(u == v) return u;					//跳完之后两者相等，那wkhf吧 
	for(int k=MAX_LOG_V -1;k>=0 ;k--){		//从后往前二分查找，因为这个是在不相等的情况下迭代的 
		if(parent[k][u] != parent[k][v]){	//所以最后一个的父亲一定是相等的。 
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];					//返回他 
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


int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		solve();
	
	return 0;
} 
