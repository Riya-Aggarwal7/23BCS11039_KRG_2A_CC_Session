#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> result;

    if (m > n) return result;

    long long p = 31;           
    long long mod = 1e9 + 7;   

    long long patternHash = 0;
    long long textHash = 0;
    long long power = 1;
    for (int i = 0; i < m - 1; i++)
        power = (power * p) % mod;
    for (int i = 0; i < m; i++) {
        patternHash = (patternHash * p + (pattern[i] - 'a' + 1)) % mod;
        textHash = (textHash * p + (text[i] - 'a' + 1)) % mod;
    }

    for (int i = 0; i <= n - m; i++) {

        if (patternHash == textHash) {
            if (text.substr(i, m) == pattern)
                result.push_back(i);
        }

        if (i < n - m) {
            textHash = (textHash - (text[i] - 'a' + 1) * power % mod + mod) % mod;
            textHash = (textHash * p + (text[i + m] - 'a' + 1)) % mod;
        }
    }

    return result;
}

int main() {
    string text = "ababcababa";
    string pattern = "aba";

    vector<int> ans = rabinKarp(text, pattern);

    for (int index : ans)
        cout << "Pattern found at index: " << index << endl;

    return 0;
}
