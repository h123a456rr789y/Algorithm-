#include<iostream>

#define ll long long
#define prime 109397
#define Max 110000

using namespace std;

struct HashTable{
	ll data;
	ll times;
};

int main(){
	int T;
	cin>> T;
	ll ans=0;

	for(int i=0;i<T;i++){
		ans=0;
		ll n,k;
		cin>> n>>k;
		HashTable table[prime];
		for(int j=0;j<prime;j++){
			table[j].data=Max;
			table[j].times=0;
		}
		for(int j=0;j<n;j++){
			ll num;
			cin >> num;
			for(ll cnt=0;cnt<=j-1;cnt++){
				ll key=(k-num+cnt*cnt)%prime;
                if(key<0){
                    key+=prime;
                }
				if(table[key].data==(k-num)){
					ans+=table[key].times;
					break;
				}
				if(table[key].data==Max){
					break;
				}
			}
			for(ll cnt=0;cnt<=j;cnt++){
				ll key=(num+cnt*cnt)%prime;
                if(key<0){
                    key+=prime;
                }
				if(table[key].data==Max||table[key].data==num){
					table[key].data=num;
					table[key].times++;
					break;
				}
			}
		}
		cout <<ans<<endl;
	}
	return 0;
}
