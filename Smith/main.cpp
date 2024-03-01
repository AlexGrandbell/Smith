#include <iostream>

using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int primeFactorSum(int n) {
    int sum = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            sum += digitSum(i);
            n /= i;
        }
    }
    if (n > 1) {
        sum += digitSum(n);
    }
    return sum;
}

int findSmithNumber(int n) {
    int num = n + 1;
    while (true) {
        if (digitSum(num) == primeFactorSum(num)) {
            return num;
        }
        ++num;
    }
}

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        int result = findSmithNumber(N);
        cout << result << endl;
    }
    return 0;
}