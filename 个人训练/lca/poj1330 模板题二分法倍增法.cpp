#include<iostream>
#include<vector>
#define endl '\n'
#define wln(x) cout<<x<<endl
#define pb push_back

#define MAX_V 10005     //�ǵøģ������ 
#define MAX_LOG_V 30    //�ǵø� 

using namespace std;

vector<int> G[MAX_V];   //�ڽӱ�G 
int root;				//���ڵ�root 

int parent[MAX_LOG_V][MAX_V];  //parent[t][x], ����x��2^t������˭������parent[0][x],����x�ĸ��� 
int depth[MAX_V]; 		//�ڵ����� 

void dfs(int v,int p,int d){
	parent[0][v] = p;	//��¼v�ڵ�ĸ��� 
	depth[v] = d;		//��¼v�ڵ����� 
	for(int i=0;i<G[v].size();i++){
						//����v�����бߣ�������Ǹ��׽ڵ������ 
		if(G[v][i] != p) dfs(G[v][i],v,d+1);
	}
}

void init(int V)
{ 
	dfs(root ,-1 ,0); 	//��ʼ���������parent[0][1~V] �Լ���� 
	for(int k = 0; k+1<MAX_LOG_V; k++) // for k = 0 ~ MAX_LOG_V-1 
		for(int v = 1; v <= V;v++)  //for v = 1~V  ע��������ǽڵ���1��ʼ��ŵ� 
		{
			if (parent[k][v]<0) parent[k+1][v] = -1;  //����Ѿ�<0�ˣ���֮��ȫ<0 
			else parent[k+1][v] = parent[k][ parent[k][v] ]; //����Ļ�����2�Ĵ���չ���� 
		}
}

int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v); 		//����LCA���Ȱѽ���ڵ㸳ֵv. 
	for( int k=0;k<MAX_LOG_V;k++){
		if((depth[v] - depth[u])>>k & 1){ 	//������ֺ������λ���㣬��������������������� 
			v = parent[k][v];
		}
	}
	
	if(u == v) return u;					//����֮��������ȣ���wkhf�� 
	for(int k=MAX_LOG_V -1;k>=0 ;k--){		//�Ӻ���ǰ���ֲ��ң���Ϊ������ڲ���ȵ�����µ����� 
		if(parent[k][u] != parent[k][v]){	//�������һ���ĸ���һ������ȵġ� 
			u=parent[k][u];
			v=parent[k][v];
		}
	}
	return parent[0][u];					//������ 
}

void solve()
{
	int V;
	cin>>V;
	for(int i=1;i<=V;i++)	//�ⲽ��ʼ���ܹؼ�. 
		G[i].clear();
		
		
	vector<int> in(V+1,0);	//ͳ�Ƽ�¼һ����ȣ����Ϊ��ĵ�Ϊ���ڵ�. 
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
