#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr,vector<int> arr1,vector<int> arr2,int start,int end){
    int i=start;
    int itr1=0;
    int itr2=0;
    while(i<=end && itr1<arr1.size() && itr2<arr2.size()){
        if(arr1[itr1]>arr2[itr2]){
            arr[i]=arr2[itr2];itr2++;
        }
        else{
            arr[i]=arr1[itr1];itr1++;
        }
        i++;
    }
    while(itr1<arr1.size()){
        arr[i]=arr1[itr1];
        i++;itr1++;
    }
    while(itr2<arr2.size()){
        arr[i]=arr2[itr2];
        i++;itr2++;
    }
    return;
}

void mergeSort(vector<int> &arr,int start,int end){
    //if(end<start){return;}
    if(end-start+1<=15){sort(arr.begin()+start,arr.begin()+end+1);return;}  //BASE CASE
    //RECURSION
    int m=(end-start+1)/2; //get the middle index
    mergeSort(arr,start,start+m);
    mergeSort(arr,start+m+1,end);
    vector<int> arr1;
    vector<int> arr2;
    for(int i=start;i<=start+m;i++){
        arr1.push_back(arr[i]);
    }
    for(int i=start+m+1;i<=end;i++){
        arr2.push_back(arr[i]);
    }
    merge(arr,arr1,arr2,start,end);
    return;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){cin>>arr[i];}
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}