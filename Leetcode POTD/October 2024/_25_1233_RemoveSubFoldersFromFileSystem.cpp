// Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order. If a folder[i] is located within another folder[j], it is called a sub-folder of it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c". The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        // Initialize result vector with the first folder
        vector<string> ans;
        ans.push_back(folder[0]);

        // Iterate through remaining folders starting from index 1
        for(int i = 1; i < folder.size(); i++) {
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) ans.push_back(folder[i]);
        }

        return ans;
    }
};

int main() {
    Solution solution;

    vector<string> folders = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
    vector<string> result = solution.removeSubfolders(folders);
    
    // Print the output
    cout << "Folders without sub-folders:" << endl;
    for (const string& folder : result) cout << folder << endl;
}
