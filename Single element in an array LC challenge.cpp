//
//  Single element in an array LC challenge.cpp
//  leetcodePrac
//  Single Element in a Sorted Array

//  Created by Akshat Jindal on 5/12/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

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
	
	int singleNonDuplicate(vector<int>& nums) {
		
		//must be done in O(logn) time and O(1) space
		
		if(nums.size() == 1)
			return nums.front();
		
		
		auto first_iter = nums.begin();
		first_iter++;
		auto second_iter = nums.rbegin();
		second_iter++;
//		cout << *second_iter << endl ;
		
		for(size_t index = 1; index <= nums.size()/2; ++index){
			
			auto the_one_before_first = first_iter - 1;
//			cout << *the_one_before_first << endl;
			if(*first_iter != (*the_one_before_first))
				return *the_one_before_first;
			
			auto the_one_before_second = second_iter-1; //reverse iterator so this is actually the element to the right
			//...of what second_iter is currently pointing to.
//			cout << *the_one_before_second << endl;
			
			if(*second_iter != *the_one_before_second)
				return *the_one_before_second;
			
			first_iter+=2;
			second_iter+=2;
		}//goes to the middle elem (unless func returns before that happens) .
		
		
		return -1; //arb
	}
};

int main(){
	
	Solution x;
	vector<int> one = {1,1,2,3,3,4,4,8,8};
	vector<int> two = {3,3,7,7,10,11,11};
	vector<int> three = {0,0,1,1,2,3,3,4,4,5,5,6,6,7,7};
	vector<int> four = {0,0,1};
	vector<int> five = {1,2,2};
	vector<int> six = {1,1,2,3,3};
	auto resultOne = x.singleNonDuplicate(one);
	auto resultTwo = x.singleNonDuplicate(two);
	auto resultThree = x.singleNonDuplicate(three);

	auto resultFour = x.singleNonDuplicate(four);
	auto resultSix = x.singleNonDuplicate(six);
	
	assert(resultOne == 2);
	assert(resultTwo == 10);
	assert(resultThree == 2);
	assert(resultFour == 1);
	assert(x.singleNonDuplicate(five) == 1);
	assert(resultSix == 2);
	
	
}
