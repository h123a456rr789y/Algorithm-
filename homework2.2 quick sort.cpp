#include<iostream>

using namespace std;
int count=0;

typedef long long ll;

ll Partition(ll A[],ll p, ll r){
    ll i=p-1;
    for(ll j=p;j<=r-1;j++){
        count++;
        if(A[j]<=A[r]){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

void Quicksort(ll A[],ll p,ll r){
    if(p<r){
        ll q=Partition(A,p,r);
        Quicksort(A,p,q-1);
        Quicksort(A,q+1,r);
    }
}

int main(){
    int cases;
    cin >> cases;
    ll arr[10000];
    for(int i=0;i<cases;i++){
        count=0;
        int n;
        cin >> n;
        for(int j=1;j<=n;j++){
            ll num;
            cin >> num;
            arr[j]=num;
        }
        Quicksort(arr,1,n);
        // cout<<count<<endl;
        if(count==(n*(n-1))/2){
            cout<< "Yes"<<endl;
        }
        else cout<<"No"<<endl;
        for(int j=1;j<=n;j++){
            cout<< arr[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
