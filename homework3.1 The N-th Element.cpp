#include<iostream>
#include<limits>
#include<algorithm>

using namespace std;

typedef long long int ll;
ll arrA(ll p,ll q,ll r,ll i){
    return (p*i*i)+(q*i)+r;
}
ll arrB(ll x,ll y,ll z,ll i){
    return (x*i*i)+(y*i)+z;
}

ll KthSmallest(ll p,ll q,ll r,ll x,ll y,ll z,ll N){
    ll m,n, min,max,half_len;
    ll Ai,Ai_1,Bj,Bj_1;
    ll i,j;
    m=N;n=N;
    min=0,max=m;
    half_len=(m+n+1)/2;
    while(min<=max){
        i=(max+min)/2;
        j=half_len-i;

        Ai=arrA(p,q,r,i);
        Ai_1=arrA(p,q,r,i-1);
        Bj=arrB(x,y,z,j);
        Bj_1=arrB(x,y,z,j-1);
        if((i<m)&&(Bj_1>Ai)){
            min=i+1;
        }
        else if((i>0)&&(Ai_1>Bj)){
            max=i-1;
        }
        else{
            if(i==0){
                return Bj_1;
            }
            else if(j==0){
                return Ai_1;
            }
            else{
                if(Ai_1>Bj_1)
                    return Ai_1;
                else
                    return Bj_1;
            }
        }
    }
}

int main(){
    int cases;
    cin >> cases;
    for(int i=0;i<cases;i++){
        ll p,q,r;
        cin >> p>>q>>r;
        ll x,y,z;
        cin >>x>>y>>z;
        ll N;
        cin >>N;
        cout <<KthSmallest(p,q,r,x,y,z,N)<<endl;
    }

    return 0;
}
