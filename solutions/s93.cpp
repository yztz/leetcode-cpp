#include "lib.h"

using namespace std;

class Solution {
public:
    // struct cmp {
    //     bool operator() (const pair<int, int> &a, const pair<int, int> &b)  {
    //         return a.second > b.second;
    //     }
    // };

    int heap_top(vector<pair<int, int>>& heap) {
        return heap[0].first;
    }

    bool heap_insert(vector<pair<int, int>>& heap, pair<int, int> val) {
        if (heap.size() == heap.capacity()) return false;
        heap.push_back(val);
        heap_adjust_up(heap, heap.size() - 1);
        return true;
    }

    void heap_adjust_down(vector<pair<int, int>>& heap, int root) {
        int n = heap.size();
        int cur = root;
        while(cur < n) {
            int left = cur * 2 + 1;
            int right = cur * 2 + 2;
            if (left >= n && right >= n) break;
            int less_node = left;
            if (right < n && heap[left] > heap[right]) less_node = right;
            if (heap[cur] > heap[less_node]) {
                swap(heap[cur], heap[less_node]);
                cur = less_node;
            } else {
                break;
            }
        }
    }

    void heap_adjust_up(vector<pair<int, int>>& heap, int root) {
        int n = heap.size();
        int cur = root;
        while(cur < n && cur != 0) {
            int parent = (cur - 1) / 2;
            if (heap[cur] < heap[parent]) {
                swap(heap[cur], heap[parent]);
                cur = parent;
            } else {
                break;
            }
        }
    }

    void heap_pop(vector<pair<int, int>>& heap) {
        int n = heap.size();
        
        heap[0] = make_pair(0, INT_MAX);

        heap_adjust_down(heap, 0);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counts;
        for(int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> heap;
        heap.reserve(k);
        
        for (auto &[num, c] : counts) {
            if (heap.size() == k) {
                if (heap_top(heap) < c) {
                    heap[0] = {c, num};
                    heap_adjust_down(heap, 0);
                }
            } else {
                heap_insert(heap, {c, num});
            }
        }

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(heap[i].second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector v = {1,1,1,2,2,3};
    vector v2 = {38,36,23};

    s.topKFrequent(v, 2);

    return 0;
}
