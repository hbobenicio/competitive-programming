#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

int main() {
    size_t t;
    cin >> t;

    for (size_t tc = 1; tc <= t; tc++) {
        printf("Case #%zu: ", tc);

        size_t N, P;
        cin >> N >> P;

        vector<size_t> X;
        X.reserve(N * P);
        
        size_t *p = new size_t[P];

        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < P; j++) {
                cin >> p[j];
            }

            if (i % 2 == 0) {
                std::sort(p, p + P);
            } else {
                std::sort(p, p + P, greater<size_t>());
            }

            X.insert(end(X), p, p + P);
            // copy(p, p + P, back_inserter(X));
        }

        delete[] p;
        p = nullptr;

        size_t bump = 0, count = 0;
        for (size_t x: X) {
            cout << x << ' ';
            if (bump < x) {
                count += x - bump;
            } else {
                count += bump - x;
            }
            // cout << "count=" << count << ' ';
            bump = x;
        }

        cout << count << '\n';
    }
}