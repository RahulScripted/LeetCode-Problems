// You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path. The rules of a Unix-style file system are as follows:

// 1.  A single period '.' represents the current directory.

// 2.  A double period '..' represents the previous/parent directory.

// 3.  Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.

// 4.  Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.

// The simplified canonical path should follow these rules:

// 1.  The path must start with a single slash '/'.

// 2.  Directories within the path must be separated by exactly one slash '/'.

// 3.  The path must not end with a slash '/', unless it is the root directory.

// 4.  The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.

// Return the simplified canonical path.






#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') continue;
            string temp;
			
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }

            if(temp == ".") continue;
            else if(temp == "..") {
                if(!st.empty()) st.pop();
            } else {
                st.push(temp);
            }
        }
        
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};

int main() {
    Solution solution;

    string path = "/a/./b/../../c/";
    string result = solution.simplifyPath(path);
    cout << "Simplified path: " << result << endl;
}