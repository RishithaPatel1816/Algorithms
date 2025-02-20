/*Tower of Hanoi (Divide and Conquer Approach)
The Tower of Hanoi is a classic mathematical problem that involves moving a set of disks from one rod to another following specific rules. It demonstrates the power of recursion and is a perfect example of the Divide and Conquer approach.

Problem Statement
Given three rods (source, helper, and destination) and n disks of different sizes stacked in decreasing order on the source rod, the objective is to move all disks to the destination rod while following these rules:

Only one disk can be moved at a time.
1.A disk can only be placed on top of a larger disk or an empty rod.
2.All disks must be moved from the source rod to the destination rod using the helper rod.
3.Divide and Conquer Approach

The problem is solved recursively using the Divide and Conquer strategy:
Divide:
Move the top n-1 disks from the source rod to the helper rod using the destination rod.
Conquer:
Move the largest nth disk directly from the source rod to the destination rod.
Combine:
Move the n-1 disks from the helper rod to the destination rod using the source rod.
This recursive approach reduces the problem size at each step and follows the recurrence relation:𝑇(𝑛)=2𝑇(𝑛−1)+1
The number of moves required to solve the problem for n disks is:(2 power𝑛)−1*/

#include <bits/stdc++.h>
using namespace std;

int TOH(int n,string source,string helper,string destn){
    if(n==0){
        return 0;
    }
    if(n==1){
        cout<<"Moving disk "<<n<<" from "<<source<<" to "<<destn<<endl;
        return 1;
    }
    int count=0;
    //cout<<"Moving disk "<<n<<" from "<<source<<" to "<<destn<<endl;
    count=count+TOH(n-1,source,destn,helper);
    cout<<"Moving disk "<<n<<" from "<<source<<" to "<<destn<<endl;
    count++;
    return count+TOH(n-1,helper,source,destn);
}

int main(){
    int n;cin>>n;
    //let r1,r2,r3 be the rods
    int count=TOH(n,"r1","r2","r3");
    cout<<"Steps taken is "<<count<<endl;
    return 0;
}
