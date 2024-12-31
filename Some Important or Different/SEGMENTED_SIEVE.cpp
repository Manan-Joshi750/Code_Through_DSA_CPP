#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to find all primes up to a given limit using the simple sieve
vector<int> simpleSieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= limit; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= limit; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

// Function to find primes in a given range [low, high] using the segmented sieve
vector<int> segmentedSieve(int low, int high) {
    int limit = sqrt(high);
    vector<int> primes = simpleSieve(limit);

    vector<bool> isPrime(high - low + 1, true);

    for (int prime : primes) {
        int start = max(prime * prime, (low + prime - 1) / prime * prime);

        for (int j = start; j <= high; j += prime) {
            isPrime[j - low] = false;
        }
    }

    vector<int> result;
    for (int i = max(low, 2); i <= high; i++) {
        if (isPrime[i - low]) {
            result.push_back(i);
        }
    }

    return result;
}

int main() {
    int low = 10;
    int high = 50;
    vector<int> primes = segmentedSieve(low, high);

    cout << "Primes in range [" << low << ", " << high << "] : ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    return 0;
}