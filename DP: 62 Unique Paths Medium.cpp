//
//  DP: 62 Unique Paths Medium.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/13/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//https://leetcode.com/problems/unique-paths/

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
	int uniquePaths(int m, int n) {
		
		vector<vector<int>> dp(n, vector<int>(m));
		//the way the problem state is written indicates that we need a n by m memo.
		
		for(size_t row = 0; row < n; ++row){
			
			for(size_t col = 0; col < m; ++col){
				
				if(row == 0 && col == 0){
					dp[0][0] = 1;
					continue;
				}
				
				if(row == 0 || col == 0){
					dp[row][col] = 1;
					//zeroth column or zeroth row.
					//going all down or all right from start.
				}
				
				else
					dp[row][col] = dp[row-1][col] + dp[row][col-1];
				
			}//inner for goes thru columns.
			
		}//outer for goes thru rows - we are filling in the dp in row-major mode.
		//bottom up approach
		
		return dp[n-1][m-1];
	}
};


int main(){
	Solution x;
	auto resultOne = x.uniquePaths(2, 3);
	cout << resultOne << endl ;
}
