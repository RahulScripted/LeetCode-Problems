// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified. You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters. Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right. For the last line of text, it should be left-justified, and no extra space is inserted between words.





#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> ans;
        int i=0;
        while(i<n){
            int currLen = words[i].length();
            int end =i+1;
            while(end<n && currLen + words[end].length()+end-i <=maxWidth){
                currLen+=words[end].length();
                end++;
            }

            int num_Word = end-i;
            int total_Space = maxWidth-currLen;
            int space_bw_words = num_Word==1?total_Space:total_Space/(num_Word-1);  
            int extra_space = num_Word==1?0:total_Space%(num_Word-1); 
           
            string line="";
            if(end==n){
                line = words[i];
                for(int k =i+1;k<end;k++){
                    line = line+' '+words[k];
                    total_Space--;
                }
                if(total_Space>0)
                line+=string(total_Space,' ');            

            }

            else{
                for(int k =i;k<end;k++){
                    line = line+words[k];
                    if(line.length()<maxWidth){
                        line+=string(space_bw_words,' ');
                    }
                    if(extra_space>0){
                        line+=' ';
                        extra_space--;
                    }
                }
            }
            i=end;
            ans.push_back(line); 
        }
        return ans;
    }
};

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    Solution solution;
    vector<string> result = solution.fullJustify(words, maxWidth);
    cout << "Justified text:" << endl;
    for (const auto& line : result) {
        cout << "\"" << line << "\"" << endl;
    }
}