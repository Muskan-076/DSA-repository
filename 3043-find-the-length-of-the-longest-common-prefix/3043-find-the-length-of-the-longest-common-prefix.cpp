class TrieNode {
public:
    TrieNode* children[10];

    TrieNode() {
        for (int i = 0; i < 10; i++)
            children[i] = nullptr;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();

        // Insert arr1 numbers into Trie
        for (int num : arr1) {
            TrieNode* node = root;
            string s = to_string(num);

            for (char c : s) {
                int digit = c - '0';

                if (node->children[digit] == nullptr)
                    node->children[digit] = new TrieNode();

                node = node->children[digit];
            }
        }

        int maxLen = 0;

        // Find longest prefix match for arr2 numbers
        for (int num : arr2) {
            TrieNode* node = root;
            string s = to_string(num);
            int currLen = 0;

            for (char c : s) {
                int digit = c - '0';

                if (node->children[digit] == nullptr)
                    break;

                currLen++;
                node = node->children[digit];
            }

            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};