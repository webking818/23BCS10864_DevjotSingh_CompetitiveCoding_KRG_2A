#include <bits/stdc++.h>
using namespace std;

int sc(vector<int>& a,int k){
    vector<int> b=a;
    sort(b.begin(),b.end(),greater<int>());
    int s=0;
    for(int i=0;i<k;i++) s+=b[i]*b[i];
    return s;
}

int f(vector<int>& a,int k){
    int n=a.size();
    bool ch=1;

    while(ch){
        ch=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int cur=sc(a,k);

                int x=a[i],y=a[j];
                int ni=x&y,nj=x|y;

                a[i]=ni;
                a[j]=nj;

                int nw=sc(a,k);

                if(nw>cur) ch=1;
                else{
                    a[i]=x;
                    a[j]=y;
                }
            }
        }
    }

    return sc(a,k);
}

int main(){
    vector<int> a={2,6,5,8};
    int k=2;

    cout<<f(a,k);
}