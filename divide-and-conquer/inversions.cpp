/*To find ranking similaritybetween 2 things
We will assume that one persons ranking is 1 to n and others is arr with permutation(1,n)
Approach:DIVIDE AND CONQUER
We will recursively divide the array into two parts 
and find inversion in that recursively sorted arrays
*/

#include <bits/stdc++.h>
using namespace std;

int crossinversions(vector<int> & arr,int l1,int h1,int l2,int h2){
    vector<int> arr1,arr2;
    for(int i=l1;i<=h1;i++){arr1.push_back(arr[i]);}
    for(int i=l2;i<=h2;i++){arr2.push_back(arr[i]);}
    int itr1=0;int itr2=0;
    int ans=0;
    int i;
    for(i=l1;i<=h2;i++){
        if(itr1>=arr1.size() || itr2>=arr2.size()){break;}
        if(arr1[itr1]>arr2[itr2]){
            ans=ans+(arr1.size()-itr1);
            arr[i]=arr2[itr2];
            itr2++;;
        }
        else{
            arr[i]=arr1[itr1];
            itr1++;
        }
    }
    while(itr1<arr1.size()){
        arr[i]=arr1[itr1];
        itr1++;i++;
    }
    while(itr2<arr2.size()){
        arr[i]=arr2[itr2];
        itr2++;i++;
    }
    return max(0,ans);
}

int mergeandcount(vector<int> &arr,int low ,int high){
    if((high-low+1)<10){
        int count=0;
        for(int i=low;i<=high;i++){
            for(int j=i+1;j<=high;j++){
                if(arr[j]<arr[i]){count++;}
            }
        }
        sort(arr.begin()+low,arr.begin()+high+1);
        return count;
    }
    int mid=low+(high-low)/2;
    int count1=mergeandcount(arr,low,mid);
    int count2=mergeandcount(arr,mid+1,high);
    int count3=crossinversions(arr,low,mid,mid+1,high);
    //cout<<count1<<" "<<count2<<" "<<count3<<endl;
    return count3+count2+count1;
}

int findInversions(vector<int>& arr){
    return mergeandcount(arr,0,arr.size()-1);
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findInversions(arr)<<endl;
}
