
#include <unordered_map>

int highestFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; ++i) {
        ++freq[arr[i]];
        maxFreq = max(maxFreq, freq[arr[i]]);
    }

    int maxFreqElement;

    for (int i = 0; i < n; ++i) {
        if (freq[arr[i]] == maxFreq) {
            maxFreqElement = arr[i];
            break;
        }
    }

    return maxFreqElement;
}
