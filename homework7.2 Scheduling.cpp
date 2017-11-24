#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Work{
	ll T;
	ll S;
	ll key;
};

ll Partition(Work *work,ll p, ll r){
    ll i=p-1;
    for(ll j=p;j<=r-1;j++){
        if(work[j].T*work[r].S < work[j].S*work[r].T){
            i++;
            swap(work[i],work[j]);
        }
    }
    swap(work[i+1],work[r]);
    return i+1;
}

void Quicksort(Work *work,ll p,ll r){
    if(p<r){
        ll q=Partition(work,p,r);
        Quicksort(work,p,q-1);
        Quicksort(work,q+1,r);
    }
}
int main(){
	int M;
	cin >> M;
	ll ans;	
	for(int i=0;i<M;i++){
		ans=0;
		int job;
		cin >> job;
		Work work[job+1];
		for(int j=1;j<=job;j++){
			cin >>work[j].T;
			work[j].key=j;
		}
		for(int j=1;j<=job;j++){
			cin >>work[j].S;
		}

		Quicksort(work,1,job);
		ll sum=0;
		for(int j=1;j<=job;j++){
			sum+=work[j].S;
		}
		//cout <<sum<<endl;
		for(int j=1;j<=job;j++){
			ans+=work[j].T*(sum-work[j].S);
			//cout <<work[j].S<<endl;
			sum-=work[j].S;
		}
		cout << ans <<endl;
		for(int j=1;j<=job;j++){
			cout <<work[j].key<<" ";
		}
		cout<<endl;
	}

	return 0;
}