/*
Title: Minimum Deletions To Make String Balanced
Difficulty: Medium
Author: Cavan Ray Theiss

Description: 

You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. 
s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

to clarify:
You must delete characters so no 'b' appears before any 'a'. 
The goal is to maximize the number of characters kept, specifically by keeping a valid split point between 'a's and 'b's. 

Return the minimum number of deletions needed to make s balanced.
*/

class Solution {
public:
    int minimumDeletions(string s) {

        int count;
        bool isA = true;
        vector<int> countBuckets;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a'){
                if(i == 0){
                    count++;
                }else if(isA){
                    count++;
                }else{
                    countBuckets.push_back(count);
                    count = 1;
                }
            }else{
                if(i == 0){
                    count++;
                    isA = false;
                }else if(!isA){
                    count++;
                }else{
                    countBuckets.push_back(count);
                    count = 1;
                }
            }
        }
        
    }
};
