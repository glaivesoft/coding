/*
 # LeetCode 647. Palindromic Substrings (DP)

Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.


Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
Note:
The input string length won't exceed 1000.
 
 # lintcode 200. Longest Palindromic Substring (Manacher’s Algorithm)
 
 Question
 Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 Example
 Given the string = "abcdzdcab", return "cdzdc".
 Challenge
 O(n2) time is acceptable. Can you do it in O(n) time.

 # laicode 252. Longest Palindromic Substring
 
 Given a string S, find the longest palindromic substring in S.
 
 Assumptions
 There exists one unique longest palindromic substring.
 The input S is not null.
 Examples
 Input:     "abbc"
 Output:  "bb"
 
 Input:     "abcbcbd"
 Output:  "bcbcb"
 
 */


#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Manacher’s Algorithm O(n) Solution
string longestPalindrome(string s)
{
    string T;// Transform S to T
    for(int i=0;i<s.size();i++)
    {
        T+="#"+s.substr(i,1);
    }
    T.push_back('#');
    
    vector<int> P(T.size(),0); // Array to record longest palindrome
    int center=0,boundary=0,maxLen=0,resCenter=0;
    for(int i=1;i<T.size()-1;i++) {
        int iMirror=2*center-i; // calc mirror i = center-(i-center)
        P[i]=(boundary>i)?min(boundary-i,P[iMirror]):0; // shortcut
        while(i-1-P[i]>=0&&i+1+P[i]<=T.size()-1&&T[i+1+P[i]] == T[i-1-P[i]]) // Attempt to expand palindrome centered at i
        P[i]++;
        if(i+P[i]>boundary) { // update center and boundary
            center = i;
            boundary = i+P[i];
        }
        if(P[i]>maxLen) { // update result
            maxLen = P[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - maxLen)/2, maxLen);
}

//
int main(int argc, char *argv[])
{
    //
    string s = "##"; // "###abbc";
    
    string output = longestPalindrome(s);
    
    cout<<output<<endl;
    
    
    //
    return 0;
}






