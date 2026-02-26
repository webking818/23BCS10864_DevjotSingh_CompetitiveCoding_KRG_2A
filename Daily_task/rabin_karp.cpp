#include<bits/stdc++.h>
using namespace std;

const int p = 256;
const int mod = 1e9 + 9;

long long power(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    string s, pattern;
    cin >> s >> pattern;

    int n = s.size();
    int m = pattern.size();

    if(m > n) return 0;

    long long pattern_hash = 0;
    long long current_hash = 0;
    long long p_pow = 1;

    for(int i = 0; i < m; i++){
        pattern_hash = (pattern_hash + (pattern[i] - 'a' + 1) * p_pow) % mod;
        current_hash = (current_hash + (s[i] - 'a' + 1) * p_pow) % mod;
        if(i < m - 1)
            p_pow = (p_pow * p) % mod;
    }

    long long p_inv = power(p, mod - 2);   

    for(int i = 0; i <= n - m; i++){

        if(current_hash == pattern_hash)
            cout << i << " ";

        if(i < n - m){
            
            current_hash = (current_hash - (s[i] - 'a' + 1) + mod) % mod;

            
            current_hash = (current_hash * p_inv) % mod;

            
            current_hash = (current_hash + (s[i + m] - 'a' + 1) * p_pow) % mod;
        }
    }

    return 0;
}