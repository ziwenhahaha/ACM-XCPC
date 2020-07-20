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

int f[605][605]; 
int a[605][605];
bool cmp(int x,int y)
{
	return x>y;
}
int n,x,y;
int calc(int x,int y)
{
	vector<int> v;
	v.clear();
	for(int i=-3;i<=3;i++)
		for(int j=-3;j<=3;j++)
		{
			int xx=x+i;
			int yy=y+j;
			if(xx >=1 && xx<=n && yy>=1 && yy<=n)
			{
				if(abs(xx-x)+abs(yy-y)<=3)
				{
					if(xx==x&& yy==y) continue;
					v.pb(a[xx][yy]);
				}
			}
		}
		
		
	sort(v.begin(),v.end(),cmp);
	int per=a[x][y];
	int day=8/per+(8%per!=0);
	int total=day*per;
	
	for(int i=1;i<=7;i++)
	{
		if(i<=v.size())
		per += v[i-1];
		int mubiao = 8*(i+1)*(i+1);
		if(mubiao>total)
		{
			int need=(mubiao - total)/per+ ((mubiao - total)%per!=0); 
			day += need;
			total += need*per;
		}else{
			int need=1;
			day += need;
			total += need*per;
		}
	}
	return day;
}
int ans;
void INIT()
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			f[i][j] = calc(i,j);
			int dist= (abs(i-x)+abs(j-y))/2+(abs(i-x)+abs(j-y))%2;
			f[i][j] += dist;
			ans = min(ans,f[i][j]);
		}
}
void solve()
{
	cin>>n>>x>>y; 
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	ans=1e9;
	int temp = calc(x,y);
	//wln(temp);
	INIT();
	wln(ans); 
}

int main()
{
	rush() 
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


