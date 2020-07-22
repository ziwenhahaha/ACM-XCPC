#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	 
	int T;cin>>T;
	while(T--){
		int k,L;cin>>k>>L;
		if(L>=2000){
			cout<<"-1\n";
			continue;
		}
		cout<<"1999\n-1";
		k+=1999;
		int cnt=1;		
		while(k!=0){
			if(k>1e6){
				cout<<" 1000000";
				k-=1e6;	
			}
			else{
				cout<<" "<<k;
				k=0;
			}
			++cnt;
		}
		for(int i=0;i<1999-cnt;++i){
			cout<<" 0";
		}
		cout<<endl;
	}

	//fclose(stdin);
	//fclose(stdout);
}