#include <iostream>
using namespace std;

// Iterative Fibonacci:
// Time Complexity : O(n)
// Space Complexity: O(1)

int iterativeFibonacci(int n)
{
    // Edge Case : If n equal to 0 then return 0;
    if (n == 0)
    {
        return 0;
    }

    // Edge Case : If n equal to 1 then return 1;
    if (n == 1)
    {
        return 1;
    }

    // Initialize first two fibonacci numbers
    int num1 = 0;
    int num2 = 1;

    // Iteratively find next number till we get the nth term
    for (int i = 2; i <= n; i++)
    {
        int num3 = num2 + num1;
        num1 = num2;
        num2 = num3;
    }

    // Return result
    return num2;
}

// Recursive Fibonacci:
// Time Complexity: O(2**n)
// Space Complexity: O(n), For recursive call stack

int recursiveFibonacci(int n)
{
    // Base Case : If n equal to 0 then return 0;
    if (n == 0)
    {
        return 0;
    }

    // Base Case : If n equal to 1 then return 1;
    if (n == 1)
    {
        return 1;
    }

    // Recurrence Relation : nth term is sum of (n-1)th tem and (n-2)th term
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main()
{
    // Take n as input
    int n;
    cin >> n;

    // Invoke iterative fibonacci function to compute nth term
    cout << "Result from Iterative Fibonacci : " << iterativeFibonacci(n - 1) << endl;

    // Invoke recursive fibonacci function to compute nth term
    cout << "Result from Recursive Fibonacci : " << recursiveFibonacci(n - 1) << endl;

    return 0;
}