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

    int numberOfAs = count(s.begin(), s.end(), 'a');
    int numberOfBs = 0;
    int totalRemovals = numberOfAs;
        
        for(int i = 0; i < s.size(); i++){

            if(s[i] == 'a'){
                numberOfAs--;
            }else{
                numberOfBs++;
            }

            totalRemovals = min(numberOfAs + numberOfBs, totalRemovals);
        }
        
    return totalRemovals;
        
    }
};

/*
class Solution {
public:
int minimumDeletions(const string& s){
    int b=0,r=0;
    for(const char*p=s.data(),*e=p+s.size();p<e;++p)
        *p=='a'?r=r<b?r+1:b:++b;
    return r;
}
};
*/

/*
int minimumDeletions(const string& s){int b=0,r=0;for(const char*p=s.data(),*e=p+s.size();p<e;++p)*p^97?++b:r=r<b?r+1:b;return r;}
*/
