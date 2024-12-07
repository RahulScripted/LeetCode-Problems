// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'. Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string. Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f=0;
    bool isNode(string &A, string &B){
        f=0;
        for(int i=0;i<8;i++){
            if(A[i]!=B[i]){
                if(f==1)
                    return false;
                else f=1;
            }
        }
        return true;
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<int,vector<int>> m;
        unordered_set<int> s;
        int req;
        for(int i=0;i<bank.size();i++){
            if(bank[i]==endGene){
                req=i;
            }
            for(int j=i+1;j<bank.size();j++){
                if(isNode(bank[i],bank[j])){
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
        queue<int> q;
        int ans=1;
        for(int i=0;i<bank.size();i++){
            if(isNode(startGene,bank[i])){
                s.insert(i);
                q.push(i);
            }
        }
        int x,y;
        while(!q.empty()){
            x=q.size();
            while(x--){
                if(q.front()==req)
                    return ans;
                y=q.front();
                q.pop();
                for(int i=0;i<m[y].size();i++){
                    if(s.find(m[y][i])!=s.end()) continue;
                    s.insert(m[y][i]);
                    q.push(m[y][i]);
                }  
            }
            ans++;
        }
        return -1;
    }
};

int main() {
    Solution solution;

    string startGene = "AACCGGTT";
    string endGene = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    int result = solution.minMutation(startGene, endGene, bank);
    cout << "Minimum number of mutations required: " << result << endl;
}