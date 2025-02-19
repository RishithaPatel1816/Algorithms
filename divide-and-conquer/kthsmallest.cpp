/*This algorithm find the kth smallest element in an unsorted array.
It will be done in O(n) time where n is no. of elemnts in the array
The idea is to use DIVIDE AND CONQUER method
We will find the median of the array and then rank accordingly
Then find whr the kth element exists
Repeat this recursively*/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int low,int high,int mom){
    int pivotind;
    for(pivotind=low;pivotind<=high;pivotind++){
        if(arr[pivotind]==mom){
            break;
            //get that pivot
        }
    }
    swap(arr[pivotind],arr[high]);
    //making pivot index as higher one
    int i=low;
    for(int j=low;j<high;j++){
        if(arr[j]<mom){
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}

// Function to find the median of a small array
int findMedian(vector<int>& arr, int low, int high) {
    sort(arr.begin() + low, arr.begin() + high + 1);
    return arr[ceil((low+high)/2)];
}

int MOM(vector<int>&arr,int low,int high,int k){
    //Base case is no. of elemnts is less than 20
    if(high-low+1<=20){
        sort(arr.begin()+low,arr.begin()+high+1);
        //we have the sorted array 
        //need kth smalles element
        return arr[low+k];
    }
    // last elements can be less than 5
    //we will iterate m-1 times and find median by sorting them(can be done without that too)
    vector<int> med;
    for(int i=low;i<=high;i+=5){
        int end=min(i+4,high);
        med.push_back(findMedian(arr,i,end));
    }
    //find median of medians
    int mom=MOM(med,0,med.size()-1,ceil(med.size()/2));
    //now we have to do the partition
    int r=partition(arr,low,high,mom);
    //r is rank of mom
    if(k>r-low){
        //we have to search in bigger half
        return MOM(arr,r+1,high,k-(r-low+1));
    }
    else if(k<r-low){
        return MOM(arr,low,r-1,k);
    }
    else{
        return arr[r];
    }
    return -1;
}

int findKthsmallest(vector<int>& arr,int k){
    return MOM(arr,0,arr.size()-1,k);
}


int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //arr[i]=100-i;
    }
    int k;cin>>k;
    cout<<k<<"-th smallest number in the array is "<<findKthsmallest(arr,k-1)<<endl;
    // sort(arr.begin(),arr.end());
    // cout<<arr[k-1]<<endl;
}
