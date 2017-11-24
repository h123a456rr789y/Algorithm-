#include <iostream>

using namespace std;


int main(){
	int T;
	int count=0;
	cin >> T;
	for(int i=0;i<T;i++){
		count=0;
		int n,m;
		cin >> n >>m;
		string str;
		cin >> str;
		//cout << str[0] <<str[1];
		int j=0;
		while(j<n){
			if((str[j]-'0')%m==0){
				count++;
				j++;
				//cout<<count<<endl;
			}
			else{
				int tmp=(str[j]-'0');
				while(tmp%m!=0){	
					tmp=tmp%m*10+(str[j+1]-'0');
					j++;
				}
				//cout<<tmp<<endl;
				if(tmp%m==0){
					count++;
					tmp=0;
					j++;
				}
				//cout <<count<<endl;
			}
		}
		cout <<count<<endl;
	}
	return 0;
}
