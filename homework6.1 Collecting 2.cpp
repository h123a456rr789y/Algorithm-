#include<iostream>

using namespace std;


int main(){
    int ans;
    int n;
    cin >>n;
    int map[n][n];
    int map2[n][n];
    int map5[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >>map[i][j];
        }
    }
    int count;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            count=0;
            int tmp=map[i][j];
            while(tmp%2==0){
                count++;
                tmp/=2;
            }
            map2[i][j]=count;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            count=0;
            int tmp=map[i][j];
            while(tmp%5==0){
                count++;
                tmp/=5;
            }
            map5[i][j]=count;
        }
    }

    int sum2[n][n];
    sum2[0][0]=map2[0][0];
    
    for(int i=1;i<n;i++){
        sum2[0][i]=sum2[0][i-1]+map2[0][i];
    }
    for(int i=1;i<n;i++){
        sum2[i][0]=sum2[i-1][0]+map2[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(sum2[i-1][j]<sum2[i][j-1]){
                sum2[i][j]=sum2[i-1][j]+map2[i][j];
            }
            else{
                sum2[i][j]=sum2[i][j-1]+map2[i][j];
            }
        }
    }

    int sum5[n][n];
    sum5[0][0]=map5[0][0];

    for(int i=1;i<n;i++){
        sum5[0][i]=sum5[0][i-1]+map5[0][i];
    }
    for(int i=1;i<n;i++){
        sum5[i][0]=sum5[i-1][0]+map5[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(sum5[i-1][j]<sum5[i][j-1]){
                sum5[i][j]=sum5[i-1][j]+map5[i][j];
            }
            else{
                sum5[i][j]=sum5[i][j-1]+map5[i][j];
            }
        }
    }

    ans=min(sum2[n-1][n-1],sum5[n-1][n-1]);

    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout <<endl;
    }*/
    cout<<ans<<endl;

    return 0;
}
