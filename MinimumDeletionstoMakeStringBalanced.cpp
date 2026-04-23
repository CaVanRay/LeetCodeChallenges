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

    int preBs = 0, postAs = 0, lowestRemovals = INT_MAX;
        for(int i = s.size() - 1; i >= 0; i--){ // i = the boundry between left and right side at each possible location
            for(int k = s.size() - 1; k >= 0; k--){ // k runs through and counts how many are on each side
                if(k >= i && s[k] == 'a'){
                    postAs++;
                }else if(k < i && s[k] == 'b'){
                    preBs++;
                }
            }
            if(postAs + preBs < lowestRemovals){
                lowestRemovals = postAs + preBs;
            }
            preBs = 0;
            postAs = 0;
        }
    return lowestRemovals;
    }
};
