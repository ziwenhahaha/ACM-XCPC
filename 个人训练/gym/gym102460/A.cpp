#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second

#define pb push_back
#define mp make_pair
#define rush() int TT;cin>>TT;while(TT--)
#define pii pair<int,int>

#define rep0(i,n) for(int i=0;i<n;i++)
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define rrep(i,l,r) for(int i=l;i>=r;i--)

#define wln(x) cout<<x<<"\n"
#define w(x) cout<<x;
#define wsp() cout<<" "

#define mem(a,b) memset(a,b,sizeof(a));
#define retrun return

#define endl "\n"

#define DEBUG false

#define dwln(x) if(DEBUG) cout<<"DEBUG "<<#x<<": "<<x<<"\n"

void print(vector<ll>  &a){			//print Vii
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" \n"[i==a.size()-1];
}
void print(vector<int> &a){			//print Vll
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" \n"[i==a.size()-1];
}
void print(int a[],int l,int r){	//print a int
	for(int i=l;i<=r;i++)
		cout<<a[i]<<" \n"[i==r];
}
void print(ll  a[],int l,int r){		//print a ll
	for(int i=l;i<=r;i++)
		cout<<a[i]<<" \n"[i==r];
}

ll qpow(ll x,ll y)
{
	ll temp=x;
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*temp);
		temp=(temp*temp);
		y>>=1;
	}
	return ans;
}

ll qpow(ll x,ll y,ll MOD)
{
	ll temp=x;
	ll ans=1;
	while(y){
		if(y&1) ans=(ans*temp)%MOD;
		temp=(temp*temp)%MOD;
		y>>=1;
	}
	return ans;
}

void INIT()
{

}

struct Car{
	int x,y;
	int w;
	int car_num;
	bool heng; //坐标x，y，长度w，是否横竖。 
};


struct ID{
	int car_num;
	int mov;
};

struct ss{
	vector<Car> car;
	int G[7][7];
	int step;
	vector<ID> id;
};

int a[15][15];

void print(ss x,bool flag=true){
	wln("");
	printf("Step: %d\n",x.step);
	for(auto i:x.car)
	{
		printf("{%d,%d}, w=%d, heng=%d\n",i.x,i.y,i.w,i.heng);
	}
	if(flag)
	{
		for(int i=1;i<=6;i++)
			print(x.G[i],1,6);		
	}
}

set<int> st;
int n=0;

int mv[]={1,-1};


bool check_heng(int G[7][7],Car x,int mov)
{
	if(mov>0&& x.y+x.w>=1 && x.y+x.w<=6 &&G[x.x][x.y+x.w] == 0){
		return true;
	}
	if(mov<0&& x.y-1>=1 && x.y-1<=6 &&G[x.x][x.y-1] == 0)
		return true;
	
	return false;
}

bool check_shu(int G[7][7],Car x,int mov)
{
	if(mov>0 && x.x+x.w>=1 && x.x+x.w<=6 && G[x.x+x.w][x.y] == 0){
		return true;
	} 
	if(mov<0&&x.x-1>=1 &&x.x-1<=6&&G[x.x-1][x.y] == 0) 
		return true;
		
	return false;
}

int q[5005];

bool fl[5005]={true};
void get_prime()
{
	memset(fl,true,sizeof(fl));
	int len=0;
	for(int i = 2;i<=5000;i++)
	{
		if(fl[i])
		{
			q[len++]=i;
			for(int j=2;j*i<=5000;j++)
				fl[i*j] = false;
		}
		
	} 
	int b=len;
}

int toKey(ss x)
{
	ll ret = 0;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			ret = ret*233 + 1LL * x.G[i][j];
			ret %= 1000000007LL;
		}
	}
	return ret;
}

void bfs(ss now)
{
	now.step = 0;
	now.id.pb({0,0});
	queue<ss> Q;
	Q.push(now); 
	int key = toKey(now);
	st.insert(key);
	int ansans=100;
	
	while(!Q.empty())
	{
		//print(Q.front());
		vector<Car> &cars = Q.front().car;
		int G[7][7];
		memcpy(G,Q.front().G,sizeof(G));
		int step = Q.front().step;
		
		if(step>=9)
		{
			break;
			continue;
		}
		for(int i=0;i<n;i++)
			if(cars[i].car_num == 1)
				{
					Car x = cars[i];
					if(x.y+x.w-1 == 6&&x.heng&&x.x==3) //如果刚好能到终点 
					{
						if(step+x.w<=10){
							ansans=min(ansans,step+x.w);
							/*for(int i=1;i<=ansans;i++)
							{
								cout<<Q.front().id[i].car_num<<" "<<Q.front().id[i].mov<<endl; 
							}*/
							wln(step+x.w);
							return;
						}
					}
				}
			
			
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(cars[i].heng && check_heng(G,cars[i],mv[j])){
					ss temp = Q.front();
					Car c = temp.car[i];
					
					for(int k=0;k<c.w;k++) 
						temp.G[c.x][c.y+k]=0;
						
					c.y += mv[j];
					for(int k=0;k<c.w;k++) 
						temp.G[c.x][c.y+k]=c.car_num;
						
					temp.car[i]=c;
					temp.step = step+1;
					temp.id.pb({c.car_num,mv[j]});
					if(st.find(toKey(temp))==st.end())
					{
						st.insert(toKey(temp)); 
						Q.push(temp);
					}
				}else
				
				if(!cars[i].heng && check_shu(G,cars[i],mv[j])){
					ss temp = Q.front();
					Car c = temp.car[i];
					
					for(int k=0;k<c.w;k++) 
						temp.G[c.x+k][c.y]=0;
						
					c.x += mv[j];
					
					
					for(int k=0;k<c.w;k++) 
						temp.G[c.x+k][c.y]=c.car_num;
					temp.car[i]=c;
					temp.step = step+1;
					temp.id.pb({c.car_num,mv[j]});
					if(st.find(toKey(temp))==st.end())
					{
						st.insert(toKey(temp)) ;
						Q.push(temp);
					}
				}
			}
		}
		Q.pop();
	}
	
	wln(-1);
}



void solve()
{
	ss now;
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			cin>>a[i][j];
			now.G[i][j]=a[i][j];
		}
	}
	
	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			int cnt=1;
			for(int k=1;k<=2;k++)
			{
				if((j+k)<=6 && a[i][j+k]==a[i][j]) {
					cnt++;
				}
			}
			if(cnt >=2 && a[i][j]!=0){
				now.car.pb({i,j,cnt,a[i][j],true});
				j+=cnt-1;
			}
		}
	}

	for(int i=1;i<=6;i++)
	{
		for(int j=1;j<=6;j++)
		{
			int cnt=1; 
			for(int k=1;k<=2;k++)
			{
				if((j+k<=6)&&a[j+k][i]==a[j][i]) {
					cnt++;
				}
			}
			if(cnt >= 2 && a[j][i]!=0){
				now.car.pb({j,i,cnt,a[j][i],false});
				j+=cnt-1;
			}
		}
	}
	 
	n = now.car.size();
	if(n==0){
		wln("-1");
		return;
	}
	//print(now);
	bfs(now);
}

int main()
{
	cin.tie(0);
    ios::sync_with_stdio(false);
	//freopen(" C:\\Users\\HP\\Desktop\\secret\\secret5.in ","r",stdin);
	get_prime(); //获得素数表去哈希 
    solve();
	return 0;
}



/*
ATTENTION:
1.记得初始化数组
2.0和1是很多问题解决的关键
3.别心急，坚信你不会的，别人也很难做出来
4.不要高估自己
5.不要自以为是
6.不要以为自己所训练一定会派上用场
7.想找可爱小姐姐撒娇
*/