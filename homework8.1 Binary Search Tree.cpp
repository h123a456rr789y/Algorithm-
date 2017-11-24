#include <iostream>

using namespace std;


struct Node{
	int value;
	Node* left;
	Node* right;
};

Node* insert(int v, Node* n){
	if(n == NULL){
        n = new Node;
        n->value = v;
        n->left = n->right = NULL;
    }
    else if(v < n->value)
        n->left = insert(v, n->left);
    else if(v > n->value)
        n->right = insert(v, n->right);
    return n;
}
Node* insert_m(int v, Node* n){
	if(n == NULL){
        n = new Node;
        n->value = v;
        n->left = n->right = NULL;
        //cout<<"lol"<<endl;
    }
    else if(v < n->value){
		cout << 'L';
		n->left = insert_m(v, n->left);
    }
    else if(v > n->value){
    	cout << 'R';
		n->right = insert_m(v, n->right);
    }
    return n;
}

int main(){
	int n,m;
	while(cin >> n >> m){
		//cout<<"Hey"<<endl;
		Node* root;
		root=NULL;

		int num;

		for(int i=0;i<n;i++){
			cin>>num;
			//cout<<"W"<<endl;
			if(num!=m){
				root=insert(num,root);
			}
			else{
				root=insert_m(num,root);
				cout <<endl;
			}
		}
	}
	return 0;
}