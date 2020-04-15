//
//  DP53maxSubarray.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/15/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
	
public:
	
	int maxSubArray(vector<int>& nums) {
		
		int currSum = nums[0];
		int maxSum = nums[0];
		
		for(size_t i = 1; i < nums.size(); ++i){
			
			if(currSum < 0)
				currSum = 0;
			
			currSum += nums.at(i);
			
			if(currSum > maxSum)
				maxSum = currSum;
			
			if(nums.at(i) > maxSum){
				maxSum = nums.at(i);
//				currSum = maxSum;
			}
		}//for
		
		return maxSum;
	}//maxSubArrayFunc
};
int main(){
	
	vector<int> testOne = {3,-4,-1,8};
	vector<int> testTwo = {5,-1,6,-6,1,6,1};
	vector<int> testThree = {2,-1,2,2,2};
	vector<int> testFour = {2,-1,2,-1,2};
	vector<int> testFive = {2,100,-3,4,-1,2,1,-5,4};
	vector<int> testSix = {8,-19,5,-4,20};
	
	Solution x;
	int a = x.maxSubArray(testOne);
	assert(a == 8);
	
	int b = x.maxSubArray(testTwo);
	assert(b == 12);
	
	int c = x.maxSubArray(testThree);
	assert(c == 7);
	
	int d = x.maxSubArray(testFour);
	assert(d == 4);
	
	int e = x.maxSubArray(testFive);
	assert(e == 105);
	
	int f = x.maxSubArray(testSix);
	assert(f == 21);
}











