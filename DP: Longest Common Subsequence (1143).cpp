//
//  DP: Longest Common Subsequence (1143).cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/11/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <unordered_set>
#include <limits>
using namespace std;


class Solution {
public:
	
	int longestCommonSubsequence(string text1, string text2) {
		
		int m = (int)text1.length();
		int n = (int)text2.length();
		
		if(m == 0 || n == 0)
			return 0;
		
		vector<vector<int>> dp(m+1, vector<int>(n+1));
		
		
		//let dp[i][j] represent the length of the LCS such that we are looking at text1 up to the ith index, and text2
		//...up to the jth index. the first character will be the 1st index (1 based indexing).
		
		//the 0th row and the 0th column of the memo will all be 0's cuz the longest common subsequence of X and Y where
		//...either of these strings is of length 0 is going to be of length 0.
		
		for(size_t col = 0; col <= n; ++col){
			dp[0][col] = 0;
		}//populate 0th row with 0's
		
		for(size_t row = 0; row <= n; ++row){
			dp[row][0] = 0;
		}//populate 0th col with 0's
		
		
		//bottom up approach
		for(size_t row = 1; row <= m; ++row){
			
			for(size_t col = 1; col <= n; ++col){
				
				//text1[row-1] cuz zeroth character of string text1 is depicted by row 1
				//text2[col-1] cuz zeroth character of string text2 is depicted by col 1.
				//col 0 and row 0 represent strings of length 0.
				if(text1[row-1] == text2[col-1]){
					dp[row][col] = dp[row-1][col-1] + 1;
//					cout << dp[row][col] << endl;
				}
				
				else{
					dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
//					cout << dp[row][col] << endl;
				}//if the characters are not the same.
				//there are two subcases:
				
				
				
			}//for loop going col by col.
		}//for loop populating in row-major (row by row) mode.
		
//		cout << dp[m][n] << endl;
		return dp.back().back();
	}
};


int main(){
	Solution x;
	auto resultOne = x.longestCommonSubsequence("abcde", "ace");
	cout << resultOne << endl;
	cout << x.longestCommonSubsequence("ace", "ace") << endl;
	cout << x.longestCommonSubsequence("aaaaa", "bbbb") << endl;
}
