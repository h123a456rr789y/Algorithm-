#include<iostream>

using namespace std;

int main(){
    int n;
    cin >>n;
    int map[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>map[i][j];
        }
    }
    int sum[n][n];
    sum[0][0]=map[0][0];
    for(int i=1;i<n;i++){
        sum[0][i]=sum[0][i-1]+map[0][i];
    }
    for(int i=1;i<n;i++){
        sum[i][0]=sum[i-1][0]+map[i][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(sum[i-1][j]>sum[i][j-1]){
                sum[i][j]=sum[i-1][j]+map[i][j];
            }
            else{
                sum[i][j]=sum[i][j-1]+map[i][j];
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout <<endl;
    }*/
    cout << sum[n-1][n-1]<<endl;

    return 0;
}
