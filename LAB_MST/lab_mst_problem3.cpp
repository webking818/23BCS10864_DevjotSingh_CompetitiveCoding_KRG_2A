#include<bits/stdc++.h>
using namespace std;
int penalty(vector<int>&nums,int maxOperations){
    priority_queue<int>q;
    for(int i:nums){
        q.push(i);
    }
    int m=0;
    while(m<=maxOperations){
        int n=q.top();
        q.pop();
        if(n%2==0){
            q.push(n/2);
            q.push(n/2);
            m++;
        }else{
            q.push((n/2)-1);
            q.push((n/2)+2);
            m++;
        }
    }
    int res=q.top();
    return res;
}
int main(){
    vector<int> nums1(1);
    vector<int> nums2(4);
    nums1.push_back(9);
    nums2.push_back(2);
    nums2.push_back(4);
    nums2.push_back(8);
    nums2.push_back(2);
    int n=penalty(nums1,2);
    int m=penalty(nums2,4);
    cout<<n<<endl;
    cout<<m;
    return 0;
    
}