/*
    Fast Exponentiation
    1.Normal Solution to find a^b => O(b)
    2.Better Solution a^b => O(log b)
*/

#include<iostream>
using namespace std;
// Normal Method
int power(int a, int b){
    int ans = 1;
    for(int i = 0; i < b; i++){
        ans *= a;
    }
    return ans;
}
// Better Method using Fermat's Little Theorem
// a^b = a^(b/2) * a^(b/2) if b is even
// a^b = a^(b-1) * a if b is odd
int fastPower(int a, int b){
    if(b == 0) return 1;
    // If number is even use the above formula else use below one
    int smallAns = fastPower(a,b/2);
    smallAns *= smallAns;
    // Additional multiplication when b is odd
    if(b&1){//if b is odd
        return a*smallAns;
    }
    return smallAns;

    //Other way
    int ans = 1;
    while(b > 0){
        //if b is odd
        if(b & 1){
            ans = ans * a;
        }
        a = a * a;
        b = b >> 1; // Right shift divide by 2 => b = b/2
    }
    // return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
    cout<<fastPower(a,b)<<endl;
    return 0;
}