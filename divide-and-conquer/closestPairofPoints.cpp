/*
    Closest Pair of Points Problem (Divide and Conquer Approach)  
    This program finds the smallest distance between two points in a given set of points on a 2D plane.
    Approach:
    - Uses a divide-and-conquer strategy to efficiently compute the closest pair of points.
    - The brute-force method is used for small input sizes (<= 5 points).
    - For larger input sizes, the points are divided into left and right halves, and the smallest distance is found recursively.
    - A middle "band" of points is also considered to check for closer pairs across the dividing line.
    - The overall time complexity is **O(n log n)**.

    Functions:
    - `bruteforce()`: Computes the closest pair distance using a nested loop (**O(n²)**).
    - `findSmallest()`: Implements divide-and-conquer to find the smallest distance (**O(n log n)**).
    - `findbetween()`: Checks for close points in the strip region across the midpoint.
    - `comparex()` and `comparey()`: Sorting helper functions for x and y coordinates.
    
    Input:
    - An integer `n` (number of points).
    - `n` pairs of integers `(x, y)` representing the coordinates of the points.
    
    Output:
    - The smallest distance between any two points in the set.
    
    Author: Rishitha Patel
*/


#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
        int x;int y;
        Point(){x=0;y=0;}
        Point(int a,int b){x=a;y=b;}
        float dist(Point& p1){
            return sqrt(pow(x-p1.x,2)+pow(y-p1.y,2));
        }
};

float bruteforce(vector<Point>& arr,int low,int high){
    float ans=FLT_MAX;
    for(int i=low;i<=high;i++){
        for(int j=i+1;j<=high;j++){
            if(ans>arr[i].dist(arr[j])){
                ans=arr[i].dist(arr[j]);
            }
        }
    }
    return ans;
}

bool comparex(const Point & p1,const Point & p2){
    if(p1.x==p2.x){return p1.y<p2.y;}
    return p1.x<p2.x; 
}

bool comparey(const Point & p1,const Point & p2){
    if(p1.y==p2.y){return p1.x<p2.x;}
    return p1.y<p2.y;
}

float findbetween(vector<Point> arr,float dist_min){
    float ans=INT_MAX;
    int n=arr.size();
    sort(arr.begin(),arr.end(),comparey);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n && (arr[j].y-arr[i].y)<dist_min;j++){
            ans = min(ans, arr[i].dist(arr[j]));
        }
    }
   // cout<<arr[0].x<<" "<<arr[0].y<<" "<<ans<<endl;
    return ans;
}

float findSmallest(vector<Point> arr,int low,int high){
    if((high-low+1)<=5){
        //we will do brute force
        //cout<<low<<" "<<high<<endl;
        return bruteforce(arr,low,high);
    }
    //RECURSIVE STEP
    int mid=low+(high-low)/2;
    Point midpoint=arr[mid];
    float dl=findSmallest(arr,low,mid);
    float dr=findSmallest(arr,mid+1,high);
    float minoflr=min(dl,dr);
    cout<<"";
    vector<Point> band;
    for(int i=low;i<=high;i++){
        if(abs((arr[i].x)-midpoint.x)<=minoflr){
            band.push_back(arr[i]);
        }
    }
    return min(minoflr,findbetween(band,minoflr));
}

void findsmall(vector<Point> arr){
    sort(arr.begin(),arr.end(),comparex);
    cout<<"Smallest distance is "<<findSmallest(arr,0,arr.size()-1)<<endl;;
    return;
}

int main(){
    int n;
    cin>>n;
    vector<Point> arr(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr[i]=Point(x,y);
    }
    cout<<bruteforce(arr,0,n-1)<<endl;;
    findsmall(arr);
    return 0;
}
