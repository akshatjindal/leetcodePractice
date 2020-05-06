//
//  Hash: Contains Duplicate Easy 219.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/29/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
	
public:
	
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		
		unordered_map<int, int> intToIndex;
		
		for(size_t i = 0; i < nums.size(); ++i){
			
			//read in val from nums and insert into hashmap if it doesnt already exist
			if(intToIndex.count(nums[i]) == 0){
				intToIndex.insert(make_pair(nums[i], i));
			}
			
			else{
				
				//we check if the duplicate is within k range.
				auto iter = intToIndex.find(nums[i]);
				if(i - iter->second <= k)
					return true; //if the duplicate is within or equal to k indices apart.
				
				else
					iter->second = int(i); //else update the index of the elem.
				
				
			}//if the val does already exist in hashmap.
			
		}//goes thru nums and inserts to hash map.
		
		return false;
	}//func
	

};

