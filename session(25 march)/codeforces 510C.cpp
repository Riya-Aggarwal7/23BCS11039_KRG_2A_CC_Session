#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
bool visited[26];
bool inStack[26];
stack<int> topoStack;

// DFS for cycle detection + topological sort
bool dfs(int node) {
    if (inStack[node]) return true;   // cycle detected
    if (visited[node]) return false;

    visited[node] = true;
    inStack[node] = true;

    for (int neighbor : adj[node]) {
        if (dfs(neighbor)) return true;
    }

    inStack[node] = false;
    topoStack.push(node);
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    // Build graph
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool foundDifference = false;

            int minLen = min(words[i].length(), words[j].length());

            for (int k = 0; k < minLen; k++) {
                if (words[i][k] != words[j][k]) {
                    foundDifference = true;
                    int from = words[i][k] - 'a';
                    int to = words[j][k] - 'a';
                    adj[from].push_back(to);
                    break;
                }
            }

            // Case: invalid order (like "abc" before "ab")
            if (!foundDifference && words[i].length() > words[j].length()) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    bool hasCycle = false;

    for (int i = 0; i < 26; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "Impossible\n";
    } else {
        string result;
        vector<bool> printed(26, false);

        // Topological order
        while (!topoStack.empty()) {
            int ch = topoStack.top();
            topoStack.pop();
            result += (char)(ch + 'a');
            printed[ch] = true;
        }

        // Add remaining characters
        for (int i = 0; i < 26; i++) {
            if (!printed[i]) {
                result += (char)(i + 'a');
            }
        }

        cout << result << endl;
    }

    return 0;
}
