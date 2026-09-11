class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};

        // Store how many times each digit occurs
        for (int d : digits) {
            freq[d]++;
        }

        int count = 0;

        // Check every 3-digit number
        for (int num = 100; num <= 999; num++) {

            // Number must be even
            if (num % 2 != 0)
                continue;

            int a = num / 100;          // hundreds digit
            int b = (num / 10) % 10;    // tens digit
            int c = num % 10;           // units digit

            // Temporarily use the digits
            freq[a]--;
            freq[b]--;
            freq[c]--;

            // If all frequencies are >= 0, number can be formed
            if (freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0) {
                count++;
            }

            // Restore frequencies
            freq[a]++;
            freq[b]++;
            freq[c]++;
        }

        return count;
    }
};