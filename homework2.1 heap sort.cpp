#include<iostream>

using namespace std;

int Left(int i){return 2*i;};
int Right(int i){return 2*i+1;};
int heapsize=0;

void MaxHeapify(int A[],int i){
    int l=Left(i);
    int r=Right(i);
    int largest=i;
    if(l<=heapsize&&A[l]>A[i]){
        largest=l;
    }
    if(r<=heapsize&&A[r]>A[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(A[i],A[largest]);
        MaxHeapify(A,largest);
    }
}

void buildMaxHeap(int A[]){
      for(int i = (heapsize/2);i>=1;i--){
        MaxHeapify(A, i);
      }
}
void HeapSort(int A[]){
      buildMaxHeap(A);
      for(int i=heapsize;i>=2;i--){
           swap(A[1],A[i]);
           heapsize--;
           MaxHeapify(A,1);
      }
}
int main(){
    int n;
    cin>>n;
    int a;
    int arr[100000];
    heapsize=n;

    for(int i=1;i<=n;i++){
        int num;
        cin >> num;
        arr[i]=num;
        a=i;
    }
    buildMaxHeap(arr);

    for(int i=1;i<=n;i++){
        cout <<arr[i]<<" ";
    }
    cout <<endl;

    HeapSort(arr);

    for(int i=1;i<=n;i++){
        cout <<arr[i]<<" ";
    }
    cout <<endl;

    return 0;
}
