#include <iostream>
#include <chrono>

using namespace std;

// Function to calculate factorial and return runtime
pair<long long, double> factorial(int n) {
    auto start = chrono::high_resolution_clock::now();
    
    if (n == 0 || n == 1) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        return {1, duration.count()};
    }
    
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return {result, duration.count()};
}

// Function to calculate nth Fibonacci number and return runtime
pair<long long, double> fibonacci(int n) {
    auto start = chrono::high_resolution_clock::now();
    
    if (n <= 0) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        return {0, duration.count()};
    }
    if (n == 1) {
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        return {1, duration.count()};
    }
    
    long long a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = b;
        b = a + b;
        a = temp;
    }
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    return {b, duration.count()};
}

int main() {
    // Test factorial
    int num1 = 5;
    auto [fact_result, fact_time] = factorial(num1);
    cout << "Factorial of " << num1 << " = " << fact_result << endl;
    cout << "Time taken for factorial: " << fact_time << " seconds" << endl;

    // Test Fibonacci
    int num2 = 10;
    auto [fib_result, fib_time] = fibonacci(num2);
    cout << "Fibonacci number at position " << num2 << " = " << fib_result << endl;
    cout << "Time taken for Fibonacci: " << fib_time << " seconds" << endl;

    return 0;
}
