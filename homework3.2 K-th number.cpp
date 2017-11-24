#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef long long int ll;

ll Seq(ll i,ll p,ll q,ll r){
    return ((p*i*i)+(q*i)+r)%1000000;
}

ll partition(ll *a, ll p, ll r)
{
    ll i,j;
    i=p-1;
    j=p;
    while(j<=r-1){
        if(a[j]<=a[r]){
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[i+1],a[r]);
    return i+1;

}

ll QuickSelect(ll *a, ll p, ll r, ll k)
{
    if ( p == r )
        return a[p];
    ll j = partition(a, p, r);
    ll length = j - p + 1;
    if (length==k)
        return a[j];
    else if (k<length)
        return QuickSelect(a, p, j - 1, k);
    else
        return QuickSelect(a, j+1, r, k - length);
}

int main(){
    int num;
    cin >>num;

    for(int i=0;i<num;i++){
        ll n,k,p,q,r;
        cin>> n >> k >> p >> q >>r;
        ll Buf[n];
        for(ll j=1;j<=n;j++){
            Buf[j]=Seq(j,p,q,r);
        }
        cout <<QuickSelect(Buf,1,n,k)<<endl;
    }
    return 0;
}
