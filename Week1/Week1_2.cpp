#include<iostream>
using namespace std;
void nth_step_cycle_left(int ar[],int n,int step){
    int ar_new[n]={0};
    for(int i=0;i<n;i++){      
        ar_new[(i-step)%n]=ar[i];
    }
    for(int i=0;i<n;i++){
        cout<<ar_new[i]<<" ";
    }
}

int main() {
    int ar[5]={1,2,3,4,5};
    int size = sizeof(ar)/sizeof(ar[0]);
    nth_step_cycle_left(ar,size,2);
    return 0;
}