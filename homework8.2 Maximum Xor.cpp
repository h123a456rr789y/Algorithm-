#include<bits/stdc++.h>

using namespace std;

int main(){
	int T;
	cin >>T;
	for(int i=0;i<T;i++){
		int n;
		cin >> n;
		bool memo[3*n+1][1024];
		memset (memo, false, sizeof(memo));
		int input[3*n+1]; 
		for(int j=1;j<=3*n;j++){
			cin >> input[j];
		}

		memo[1][input[1]]=true;
		memo[2][input[2]]=true;
		memo[3][input[3]]=true;

		for(int j=2;j<=n;j++){
			for(int k=0;k<1024;k++){
				for(int l=(3*j-2);l<=(3*j);l++){
					//cout<< "HH"<<endl;
					if(memo[3*j-5][k]){
						memo[l][input[l]^k]=true;
					}
					if(memo[3*j-4][k]){
						memo[l][input[l]^k]=true;
					}
					if(memo[3*j-3][k]){
						memo[l][input[l]^k]=true;
					}
				}
			}
		}
		int ans = 0;
		for(int i=0; i<1024; i++){
			if(memo[3*n][i]){
				ans = max(ans, i);
			}
			if(memo[3*n-1][i]){
				ans = max(ans, i);
			}
			if(memo[3*n-2][i]){
				ans = max(ans, i);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}