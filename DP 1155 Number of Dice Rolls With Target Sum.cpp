//
//  DP 1155 Number of Dice Rolls With Target Sum.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/24/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
	int numRollsToTarget(int d, int f, int target) {
		
		vector<vector<int>> memo;
		memo.reserve(target);
		memo.resize(target);
		
		for(size_t i = 0 ; i < memo.size(); ++i){
			vector<int> temp;
			temp.reserve(d);
			temp.resize(d);
			memo[i] = temp;
			temp.clear();
			
		}//for loop that pushes back d number of dies. the cols are going to represent number of die used thus far.
		
		
		//
		
		return memo[target][d];
	}
};


int main(){
	
	Solution x;
	assert(x.numRollsToTarget(1, 6, 3) == 1);
	assert(x.numRollsToTarget(2, 6, 7) == 6);
	assert(x.numRollsToTarget(2, 6, 12) == 1); //both die need to be 6's so there is only one way to achieve that

	
	
	
	
	
	
}
