/*
Challenge #: 1768
Difficulty: Easy
Title: Merge Strings Alternately
Author: Cavan Ray Theiss

Description:

You are given two strings word1 and word2. 
Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
      string word3;
      int k = 0;
      for(char letter : word1){
        word3.push_back(letter);
        if(k <= word2.size()){
          word3.push_back(word2[k]);
        }
        k++;
      }
      while(k <= word2.size()){
        word3.push_back(word2[k]);
        k++
      } 
    }
};
