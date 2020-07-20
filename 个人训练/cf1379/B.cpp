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
void solve()
{
	ll l,r,m;
	cin>>l>>r>>m;
	ll left = -abs(l-r);
	ll right = abs(l-r);
	for(ll i = l;i<=r;i++)
	{
		ll n=0;
		n = m/i;  //��m��һ���
		ll temp = m-n*i;
		if(n>=1)
		if(left<=temp && temp<=right)
		{
			cout<<i<<" "<<l+temp<<" "<<l<<endl;
			return;
		}
		
		
		n = m/i + (m%i!=0); //��ȡ���� 
		temp = n*i-m;
		if(n>=1)
		if(left<=temp && temp<=right)
		{
			cout<<i<<" "<<l<<" "<<l+temp<<endl;
			return;
		}
	}
}

int main()
{
	rush() 
    solve();
	return 0;
}



/*
ATTENTION:
1.�ǵó�ʼ������
2.0��1�Ǻܶ��������Ĺؼ�
3.���ļ��������㲻��ģ�����Ҳ����������
4.��Ҫ�߹��Լ�
5.��Ҫ����Ϊ��
6.��Ҫ��Ϊ�Լ���ѵ��һ���������ó�
7.���ҿɰ�С�������
*/


