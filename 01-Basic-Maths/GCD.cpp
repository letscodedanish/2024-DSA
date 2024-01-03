/*
    GCD - Greates common divisor
    1.Euclid's Algorthim to find GCD
        a. gcd(a,b) = gcd(a-b,b) OR gcd(a%b,b)
        {gcd(a,b) = gcd(a-b,b) if a>b
        gcd(a,b) = gcd(b-a,a) if a<b} Apply this formula till
        one the parameter(a or b) becomes 0.
        The remained parameter other than 0 is the answer
            

    2.LCM(a,b) * GCD(a,b) = a*b 
*/

#include<iostream>
using namespace std;

int gcd(int A, int B) 
	{ 
	    // code here
	    //Formula GCD(a,b) = gcd(a-b,b) : a>b
	    // GCD(a,b) = gcd(b-a,a) : b>a
	    
	    if(A == 0) return B;
	    if(B == 0) return A;
	    
	    if(A > B){
	        gcd(A-B,B);
	    }
	    else{
	        gcd(B-A,A);
	    }
	      
	} 

int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}