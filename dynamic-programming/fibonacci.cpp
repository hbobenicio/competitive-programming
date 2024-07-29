#include <iostream>
#include <unordered_map>

uint64_t fibonacci(uint64_t n)
{
    if (n == 0 || n == 1) return 1;

    static std::unordered_map<uint64_t, uint64_t> memo;
    if (auto it = memo.find(n); it != memo.cend()) {
        return it->second;
    }

    uint64_t res = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = res;

    return res;
}

int main()
{
    for (uint64_t i = 0; i < 25; i++) {
        std::cout << "fib(" << i << "): " << fibonacci(i) << '\n';
    }
}
