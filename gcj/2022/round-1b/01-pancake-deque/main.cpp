#include <iostream>
#include <deque>

using namespace std;

int main() {
    size_t t;
    cin >> t;

    for (size_t tc = 1; tc <= t; tc++) {
        printf("Case #%zu: ", tc);

        size_t N;
        cin >> N;

        deque<size_t> D;
        for (size_t i = 0; i < N; i++) {
            size_t d;
            cin >> d;
            D.push_back(d);
        }

        size_t paying_count = 0, expectation = 0;
        while (!D.empty()) {
            size_t f = D.at(0);
            size_t l = D.at(D.size() - 1);
            if (f < l) {
                expectation = max(expectation, f);
                if (expectation <= f) {
                    paying_count++;
                }
                D.pop_front();
            } else {
                expectation = max(expectation, l);
                if (expectation <= l) {
                    paying_count++;
                }
                D.pop_back();
            }
        }
        cout << paying_count << '\n';
    }
}
