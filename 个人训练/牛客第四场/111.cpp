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

int prime[200050];
bool flag[2000500];
void INIT()
{
	memset(flag,true,sizeof(flag));
	int len=0;
	for(int i=2;i<=1e6;i++)
	{
		if(flag[i])
		{
			prime[len++]=i;
			flag[i]=false;
			for(int j=1;i*j<=1e6;j++)
				flag[i*j] = false;			
		}
	}
}
void solve()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	if(n == 1){
		wln(1);
		return;
	}
	if(n <= 3) 
	{
		wln(m);
		return; 
	}
	
	int temp=n;
	int cnt=0;
	for(int i=0;prime[i]<sqrt(n)+1;i++)
	{
		int x=0;
		int y=prime[i];
		while(temp % y == 0) {
			temp /= y;
		 	x++;
		}
		cnt += x;
	}
	if(temp == n)
	{
		wln(m);
		return;
	}
	
	if(temp!=n&&temp!=1) cnt++;
	
	
	wln(qpow(m,cnt,1000000007));
}

int main()
{
	INIT();
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


