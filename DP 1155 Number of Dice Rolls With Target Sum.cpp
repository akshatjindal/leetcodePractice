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
		
		if(target < d)
			return 0; //cuz each die must atleast throw 1 and so there is no way to achieve 50 by using 55 dice.
		
		if(d <= 1 && target <= (f*d))
			return 1;
		
		vector<int> penultimateDiceThrow;
		vector<int> lastDiceThrow;
		penultimateDiceThrow.reserve(target + 1);
		penultimateDiceThrow.resize(target + 1);
		lastDiceThrow.reserve(target + 1);
		lastDiceThrow.resize(target + 1);
		
		int tempEndIndex = f;
		if(f > target)
			tempEndIndex = target;
		
		for(size_t row = 1; row <= tempEndIndex; ++row){
			
			penultimateDiceThrow[row] = 1;
			//with one die throw, there is one way to reach a sum of 1,2,3...,f
			
		}//for loop that initalizes the penUltimateVector (for the first dice throw).
		
		
		for(size_t die_used = 2; die_used <= d; ++die_used){
			
			int tempEndIndex = int(die_used*f);
			//if target > the max sum possible at that die throw, then loop till that max sum possible.
			
			if(tempEndIndex > target)
				tempEndIndex = target; //we don't wanna loop past the target if possible.
			
			for(size_t sum_achieved = die_used; sum_achieved <= tempEndIndex; ++sum_achieved){
				
				if(sum_achieved == die_used)
					lastDiceThrow[sum_achieved] = 1;
				//so memo[2][2] means that after rolling 2 die, there is only one way to get to a sum of 2.
				
				else{
					int sumOfPreviousFRolls = 0;
					int tempStartIndex = int(sum_achieved - f);
					if(tempStartIndex < 1)
						tempStartIndex = 1;
					
					int end_index = int((die_used - 1)*f);
					if(end_index >= sum_achieved)
						end_index = int(sum_achieved - 1);
					
					for(size_t index = tempStartIndex; index <= end_index; ++index){
						sumOfPreviousFRolls = (sumOfPreviousFRolls + penultimateDiceThrow[index]) % (1000000000+7);
					}
					
					lastDiceThrow[sum_achieved] = sumOfPreviousFRolls;
					
				}//else...
				
				
			}//inner for loop goes thru rows.
			
			penultimateDiceThrow = lastDiceThrow;
			
		}//outer for loop is for the dice_thrown.
		
		return penultimateDiceThrow[target ];
		
	}//func
};


int main(){
	
	Solution x;
	assert(x.numRollsToTarget(1, 6, 3) == 1);
	assert(x.numRollsToTarget(2, 6, 7) == 6);
	assert(x.numRollsToTarget(2, 6, 12) == 1); //both die need to be 6's so there is only one way to achieve that
	
	cout << x.numRollsToTarget(30, 30, 500);
	
	
	
	
	
	
}
