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

struct ss{
	ll x,y;
};
ss a[200050];

bool cmp(ss x,ss y)
{
	return x.x>y.x;
}
ll sum[200050]; 
void solve()
{
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[i].x=x;
		a[i].y=y;
	}
	sort(a+1,a+1+m,cmp);
	sum[0]= 0;
	for(int i=1;i<=m;i++)
	{
		sum[i] = sum[i-1] + a[i].x;
	}
	ll ansans=0;
	for(int i=1;i<=m;i++)
	{
		ll x=a[i].x;
		ll y=a[i].y;
		
		ll l=1;
		ll r=m;
		ll ans=0;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(a[mid].x>=y) {
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		
		if(ans<i){
			ll need = min(ans,n-1);
			ll temp = sum[need] + x + (n-1-need)*y;
			ansans = max(ansans,temp);
		}else{
			ll need = min(ans,n);
			ll temp = sum[need] + (n-need)*y;
			ansans = max(ansans,temp);
		}
	}
	wln(ansans);
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


