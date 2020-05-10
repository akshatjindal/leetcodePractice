//
//  DP: 64 Minimum Path Sum.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/10/20.
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
	int minPathSum(vector<vector<int>>& grid) {
		
		//can only move right or down at any time.
		
		auto m = grid.size();
		auto n = grid[0].size();
		
		int dp[m][n]; //creates an m by n array.
		
		dp[0][0] = grid[0][0];
		
		for(size_t row = 1; row < m; ++row){
			dp[row][0] = dp[row-1][0] + grid[row][0];
		}//this for loop populates the zeroth column of dp.

		for(size_t row = 0; row < m; ++row){
			
			for(size_t col = 1; col < n; ++col){
				
				if(row == 0){
					dp[row][col] = dp[row][col-1] + grid[row][col];
				}//if at the top row.
				
				else{
					dp[row][col] = min(dp[row-1][col], dp[row][col-1]) + grid[row][col];
				}
				
			}//inner for loop goes thru row by row.
			
		}//bottom up approach, outer for loop goes column by column.
		
		return dp[m-1][n-1];
	}
};


int main(){
	Solution x;
	vector<vector<int>> un = {
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	
	auto result = x.minPathSum(un);
	cout << result << endl;
}
