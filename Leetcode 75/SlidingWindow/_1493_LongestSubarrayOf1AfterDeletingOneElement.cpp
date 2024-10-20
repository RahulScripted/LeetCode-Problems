// Given a binary array nums, you should delete one element from it. Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.





#include <iostream>
#include <vector>
using namespace std;

class Solution {

public:
    int longestSubarray(vector<int>& nums) {
        int a=nums.size();
        int i=0;
        int ans=0;
        
        while(i<a){
            int j=i-1;
            int k=i+1;
            int count=0;
            
            if(nums[i] == 0 ){
                while(j>=0 && nums[j]==1){
                    count++;
                    j--;
                }
                while(k<a && nums[k]==1){
                    count++;
                    k++;
                    
                }
                ans=max(ans,count);
                i=k;
            }
            else if(nums[i]==1){
                i++;
                if(i==a)ans=a-1;
            }
            
            else i++;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 1, 0, 1};
    cout << "Longest subarray after deleting one 0 in test case 1: " << solution.longestSubarray(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << "Longest subarray after deleting one 0 in test case 2: " << solution.longestSubarray(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 1, 1};
    cout << "Longest subarray after deleting one 0 in test case 3: " << solution.longestSubarray(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {1, 1, 0, 0, 1, 1};
    cout << "Longest subarray after deleting one 0 in test case 4: " << solution.longestSubarray(nums4) << endl;

    // Test case 5
    vector<int> nums5 = {0, 0, 0};
    cout << "Longest subarray after deleting one 0 in test case 5: " << solution.longestSubarray(nums5) << endl;

    return 0;
}