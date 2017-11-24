#include<iostream>

using namespace std;


int main(){
    int T;
    cin >> T;
    int count;
    for(int i=0;i<T;i++){
        int n;
        cin >>n;
        long long int c[n];
        for(int j=0;j<n;j++){
            cin >>c[j];
        }
        long long int memo[n];
        memo[n-1]=1;
        int max;
        for(int j=n-2;j>=0;j--){
            max=0;
            for(int k=n-1;k>j;k--){
                if(c[k]>c[j]){
                    count=memo[k]+1;
                }
                else {
                    count=1;
                }
                if(count> max){
                    max=count;
                }
            }
            memo[j]=max;
        }
        max=memo[0];
        for(int i=1;i<n;i++){
            if(memo[i]>max){
                max=memo[i];
            }
        }
        cout <<max<<endl;
    }
    return 0;
}
