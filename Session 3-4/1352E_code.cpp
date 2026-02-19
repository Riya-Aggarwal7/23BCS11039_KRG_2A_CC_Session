
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalTests;
    cin >> totalTests;

    while (totalTests--) {
        int arrayLength;
        cin >> arrayLength;

        vector<int> elements(arrayLength);
        for (int index = 0; index < arrayLength; index++)
            cin >> elements[index];

        vector<int> countValue(8005, 0);
        for (int index = 0; index < arrayLength; index++)
            countValue[elements[index]]++;

        vector<int> cumulativeSum(arrayLength + 1, 0);
        for (int index = 0; index < arrayLength; index++)
            cumulativeSum[index + 1] = cumulativeSum[index] + elements[index];

        vector<bool> validSum(8005, false);

        for (int left = 0; left < arrayLength; left++) {
            for (int right = left + 1; right < arrayLength; right++) {
                int currentSum = cumulativeSum[right + 1] - cumulativeSum[left];
                if (currentSum > 8000)
                    break;
                validSum[currentSum] = true;
            }
        }

        int resultCount = 0;
        for (int value = 1; value <= 8000; value++) {
            if (validSum[value])
                resultCount += countValue[value];
        }

        cout << resultCount << "\n";
    }

    return 0;
}
