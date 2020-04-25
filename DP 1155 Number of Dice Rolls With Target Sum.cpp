//
//  DP 1155 Number of Dice Rolls With Target Sum.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/24/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		
		if(target > (d*f))
			return 0;
		
		vector<vector<int>> memo;
		memo.reserve(target + 1);
		memo.resize(target + 1);
		
		for(size_t i = 0 ; i < memo.size(); ++i){
			vector<int> temp;
			temp.reserve(d + 1);
			temp.resize(d + 1);
			memo[i] = temp;
			temp.clear();
			
		}//for loop that pushes back d number of dies. the cols are going to represent number of die used thus far.
		
		
		int temp = f;
		if(f > target)
			temp = target;
		
		//start at row = 1 cuz 1 die will never roll a 0 (so the 0th row is all 0's - its essentially to comply w/ zero based indexing)
		for(size_t row = 1; row <= temp; ++row){
			
			memo[row][1] = 1;//with 1 die, there is only one way to roll a 3 or a 4 given that faces f >=4;
			
		}//for loop that populates the first column.
		
		if(d < 2)
			return memo[target][d]; //if only one die, return either a 0 or a 1.
		
		for(size_t die_used = 2; die_used <= d; ++die_used){
			
			int tempEndIndex = int(die_used*f); //if target < the max sum possible at that die throw, then loop till that max sum possible.
			if(tempEndIndex > target)
				tempEndIndex = target; //we only wanna loop to target sum if possible
			
			for(size_t sum_achieved = die_used; sum_achieved <= tempEndIndex; ++sum_achieved){
				
				if(sum_achieved == die_used)
					memo[sum_achieved][die_used] = 1;
				//so memo[2][2] means that after rolling 2 die, there is only one way to get to a sum of 2.
				
				else{
					//say we are on [2][8], and f = 6, then we wanna dgo from [8-6][1] to [1*f = 6][1] and sum it all together.
					int sum = 0;
					
					int tempStartIndex = int(sum_achieved - f);
					if(tempStartIndex < 1)
						tempStartIndex = 1;
					
					int tempEndIndex = int((die_used - 1)*f);
					if(tempEndIndex >= sum_achieved)
						tempEndIndex = int(sum_achieved - 1);
					
					
					for(size_t index = tempStartIndex; index <= tempEndIndex; ++index){
						sum = (sum + memo[index][die_used-1]) % 1000000007;
					}
					
					memo[sum_achieved][die_used] = sum;
				}
				
				
			}//inner for loop goes thru rows.
			
		}//outer for goes thru col by col
		
		
		return memo[target][d];
	}
};

int main(){
	
	Solution x;
	assert(x.numRollsToTarget(1, 6, 3) == 1);
	assert(x.numRollsToTarget(2, 6, 7) == 6);
	assert(x.numRollsToTarget(2, 6, 12) == 1); //both die need to be 6's so there is only one way to achieve that
	
	
	cout << x.numRollsToTarget(30, 30, 500);
	
	
	
	
}
