//
//  Largest Consecutive Divisible Sum - 281 additional MCQ's.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/26/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

int largest_consec_divisible_sum(const vector<int> & nums, int k){
	
	//nums is unsorted. we wanna return the largest contiguous sum divisible by k in O(n) time.
	
	//create a running total: the i'th elem in this vec will represent the running total upto and including that elem
	vector<int> vec;
	vec.reserve(nums.size());
	vec.resize(nums.size());
	vec[0] = nums[0];
	
	for(size_t i = 1; i < vec.size(); ++i){
		
		vec[i] = vec[i-1] + nums[i];
		
	}//for loop that populates the vec containing the running totals. n elements so done in O(n) time.
	
	
	int largest_consec_sum_divisible_by_k = 0;
	
	for(size_t i = 0; i < vec.size(); ++i){
		
		if(vec[i])
		
	}
	//for loop that goes thru the vec containing the running totals: updating the largest_consec_sum_divisible_by_k yet.
	
}//func...

int main(){
	
	vector<int> testOne{6,8,3,5};
	
	assert(largest_consec_divisible_sum(testOne, 7) == 14); //6+8 = 14
	
	
	
}//main...



