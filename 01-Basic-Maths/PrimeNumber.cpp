// Leetcode 204 count prime

/*
        204. Count Primes
        Given an integer n, return the number of prime 
        numbers that are strictly less than n.

        Example 1:

        Input: n = 10
        Output: 4
        Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
        Example 2:

        Input: n = 0
        Output: 0
        Example 3:

        Input: n = 1
        Output: 0


        Constraints:

        0 <= n <= 5 * 106

    Prime number- A number N which if (N%i == 0) not a prime
        1.Naive Approach
        2.Sqrt Approch
        3.Sieve of Eratosthenes
        4.Segmented sieve

    */
    #include<iostream>
    #include <vector>
    #include <cmath>

    using namespace std;

    bool isPrime(int n) {
        if (n <= 1)
            return false;
        int sqrtN = sqrt(n);
        for (int i = 2; i <= sqrtN; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        // Approach 1 - Naive Approch
        // int count = 0;

        // for(int i = 0; i < n; i++){
        //     if(isPrime(i)){
        //         ++count;
        //     }
        // }
        // return count; // 17/66 testcases - n is very large

        // Approach - 2 - sqrt app
        // Int this is approch we will only traverse this till sqrt(n)
        // Testcases => 20/66

        // Approach - 3 - Sieve of Eratosthenes
        // Multiples(table) of prime number is always non-prime
        // given 21- mark everything prime from 2-20
        // everything which remains true after traversal will be our count of
        // prime numbers

        if (n == 0)
            return 0;

        vector<bool> prime(n, true);
        prime[0] = prime[1] = false;

        int ans = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                ans++;

                int j = 2 * i;
                while (j <= n - 1) {
                    prime[j] = false;
                    j += i;
                }
            }
        }
        return ans;

        // Approach 4 - Segmented Sieve - Nothing but varitaion of seive of eratosthenes
    }