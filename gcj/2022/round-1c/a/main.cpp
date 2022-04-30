#include <bits/stdc++.h>

using namespace std;

string join_strings(const vector<string>& vs, const string& separator = "")
{
    ostringstream ss;
    for (size_t i = 0; i < vs.size(); i++) {
        if (i > 0) {
            ss << separator;
        }
        ss << vs[i];
    }
    return ss.str();
}

bool is_valid(const string& s)
{
    unordered_map<char, int> hist;

    for (size_t i = 0; i < s.size(); i++) {
        while (i + 1 < s.size() && s[i] == s[i+1]) {
            i++;
        }
        if (hist[s[i]] == 1) {
            return false;
        }
        hist[s[i]] = 1;
    }

    return true;
}

string solve(vector<string>& S)
{
    sort(S.begin(), S.end());

    do {
        string res = join_strings(S);

        if (is_valid(res)) {
            return res;
        }

    } while (next_permutation(S.begin(), S.end()));

    return "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t T;
    cin >> T;

    for (size_t t = 1; t <= T; t++) {
        size_t N;
        cin >> N;

        vector<string> S(N);
        for (size_t i = 0; i < N; i++) {
            cin >> S[i];
        }

        string sol = solve(S);
        cout << "Case #" << t << ": " << sol << '\n';
    }
}
