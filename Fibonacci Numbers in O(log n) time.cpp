#include<iostream>

using namespace std;

void multiply(long long a[2][2],long long b[2][2]){
    long long F1=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    long long F2=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    long long F3=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    long long F4=a[1][0]*b[0][1]+a[1][1]*b[1][1];
    a[0][0]=F1%29989;
    a[0][1]=F2%29989;
    a[1][0]=F3%29989;
    a[1][1]=F4%29989;
}

void power(long long  M[2][2],int n){
    if(n==0||n==1) return;
    long long FibM[2][2]={{1,1},{1,0}};
    power(M,n/2);
    multiply(M,M);
    if(n%2==1) multiply(M,FibM);
}

int fib(int n){
    long long Fib[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(Fib,n-1);
    return Fib[0][0];
}

int main(){
    int cases;
    cin>> cases;
    for(int i=0;i<cases;i++){
        int n;
        cin>> n;
        cout<< fib(n) <<endl;
    }
    return 0;
}
