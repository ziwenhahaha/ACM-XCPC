#include<iostream>
#include<vector>
#include<cmath>
#define endl '\n'
#define wln(x) cout<<x<<endl
#define pb push_back

#define MAX_V 10005     //�ǵøģ������ 
#define MAX_LOG_V 30    //�ǵø� 

using namespace std;

vector<int> G[MAX_V];   //�ڽӱ�G 
int root;				//���ڵ�root 

int vs[MAX_V * 2 -1];   //DFS����˳��  
int depth[MAX_V * 2 -1]; 		//�ڵ����� 
int id[MAX_V];			//�����ڵ���vs���״γ��ֵ��±�


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
	//�޵�rmqд����ֱ�Ӽ�¼��Сֵ���ڵ��±꣬�������ýṹ�� 
	for(int i=0;i<n;i++)
	{
		dp[i][0] = i;
	}
	for(int j=1;(1<<j) <= n;j++)				//��С���� 
		for(int i = 0; i+(1<<j)-1<n ;i++)		//��Ϊ����Ҫ���ƣ��������ڴ�СӦ���������˫���� 
		{
			int a = dp[i][j-1];
            int b = dp[i + (1<<(j-1))][j-1];
            if(depth[a] <= depth[b])//�Ƚϵ��±�����Ӧ��ֵ
                dp[i][j] = a;//�����±�
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
        return a;//�����±�
    else
        return b;
}

int lca(int u,int v)
{
	int x=min(id[u],id[v]);
	int y=max(id[u],id[v]);
	return vs[ rmq(x,y)];  //lca����������id�����depth��Сֵ�ĵ����ĸ��˰ɡ� 
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


int main(){
	
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
