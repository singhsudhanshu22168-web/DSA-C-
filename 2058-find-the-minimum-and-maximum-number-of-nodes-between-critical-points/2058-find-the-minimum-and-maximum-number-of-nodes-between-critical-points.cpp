/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;        // Position of first critical point
        int prev = -1;         // Position of previous critical point
        int minDist = INT_MAX;

        int pos = 1;

        ListNode* prevNode = head;
        ListNode* curr = head->next;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            // Check if current node is a local maximum or minimum
            bool isCritical =
                (curr->val > prevNode->val && curr->val > nextNode->val) ||
                (curr->val < prevNode->val && curr->val < nextNode->val);

            if (isCritical) {
                if (first == -1) {
                    // First critical point
                    first = pos;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, pos - prev);
                }

                prev = pos;
            }

            prevNode = curr;
            curr = nextNode;
            pos++;
        }

        // Fewer than two critical points
        if (first == -1 || first == prev) {
            return {-1, -1};
        }

        // Maximum distance = last critical point - first critical point
        int maxDist = prev - first;

        return {minDist, maxDist};
    }
};