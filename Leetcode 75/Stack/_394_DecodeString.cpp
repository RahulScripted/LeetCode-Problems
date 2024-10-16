// Given an encoded string, return its decoded string. The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer. You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].





#include <iostream>
using namespace std;

class Solution {
public:
    string decodeString(string &s, int &index){
        string dstring;
        int num = 0;
        
        while(index < s.length()){
            char ch = s[index];
            
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }else if(ch == '['){
                index++;
                string nestedstring = decodeString(s, index);
                for(int i = 0; i < num; i++){
                    dstring += nestedstring;
                }
                num = 0;
            }else if(ch == ']'){
                return dstring;
            }else{
                dstring += ch;
            }
            index++;
        }
        return dstring;
    }

    string decodeString(string s) {
        // Without Stack
        int index = 0;
        return decodeString(s, index);

        // With Stack
        // stack<string>st;
        // int n=s.size();
        // int i=0;
        // string ans="";
        // while(i<n){
        //     if(s[i]==']') {
        //         string op="";
        //         while(!st.empty()){
        //             if(st.top()=="["){
        //                 st.pop();
        //                 break;
        //             }
        //             op = st.top() + op;
        //             st.pop();
        //         }
        //         string ok=op;
        //         string num="";
        //         //  Find the number of times you have to multiply the string
        //         while(!st.empty()){
        //             if(st.top()>="0"&&st.top()<="9")
        //             num+=st.top();
        //             else
        //             break;
        //             st.pop();
        //         }
        //         reverse(num.begin(),num.end());
        //         int k=stoi(num);
        //         // cout<<num<<endl;
        //         op="";
        //         while(k>0){
        //             op+=ok;
        //             k--;
        //         }
        //         // push the string in stack
        //         st.push(op);
        //     }
        //     else{
        //         string g = "";
        //         g += s[i]; 
            
        //         st.push(g); 
        //     }
        //     i++;

        // }
        
        // while(!st.empty()) reverse(st.top().begin(),st.top().end());ans+=st.top();st.pop();
        // reverse(ans.begin(),ans.end());
        // return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter the encoded string: ";
    cin >> s;

    string decodedString = sol.decodeString(s);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}