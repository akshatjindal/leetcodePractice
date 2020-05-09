//
//  Hash: 3Sum (15) Medium.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/8/20.
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
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		if(nums.size() < 3)
			return {};
		
		
		vector<vector<int>> triplets;
		
		unordered_map<int,vector<int>> valToIndex;
		//each value from nums vec is mapped with a vec of indices containing that elem.
		
		
		for(int index = 0; index < nums.size(); ++index){
			
			auto iter = valToIndex.find(nums[index]);
			
			if(iter == valToIndex.end()){
				vector<int> temp;
				temp.push_back(index);
				valToIndex.insert(make_pair(nums[index], temp));
			}
			
			else
				iter->second.push_back(index);
				
			
		}/*iterate thru the nums vect and put everything into the hashmap*/

		for(int indexOfFixedElem = 0; indexOfFixedElem < nums.size()-2; ++indexOfFixedElem){
			
			for(int indexOfTempElem = indexOfFixedElem + 1; indexOfTempElem < nums.size()-1; ++indexOfTempElem){
				
				int sumOfFixedAndTemp = nums[indexOfFixedElem] + nums[indexOfTempElem];
				//complement is -1 * sumOfFixedAndTemp
				
				auto complement_iter = valToIndex.find(-1*(sumOfFixedAndTemp));
				if(complement_iter == valToIndex.end())
					continue;
				
				else{
					
					//checking condition 1:
					auto iter_to_temp_val = valToIndex.find(nums[indexOfTempElem]);
					bool duplicate_temp_exists = false;
					
					for(int i = 0; i < iter_to_temp_val->second.size(); ++i){
						
						if(iter_to_temp_val->second[i] > indexOfFixedElem && iter_to_temp_val->second[i] < indexOfTempElem){
							duplicate_temp_exists = true;
							break; //duplicate_temp_exists in b/w curr fixed elem and curr temp elem.
						}
						
						if(iter_to_temp_val->second[i] >= indexOfTempElem)
							break;

					}//this for loop iterates thru the vector of indices that contain the temp elem.
					
					if(duplicate_temp_exists)
						continue; //increment temp elem.
					
					else if(not duplicate_temp_exists){
						
						if(complement_iter->second[0] < indexOfFixedElem)
							continue;
						
						if(complement_iter->second[0] == indexOfFixedElem && complement_iter->second.size()==1)
							continue;
						
						if(complement_iter->second[0] == indexOfTempElem && complement_iter->second.size() == 1)
							continue;
						
						if(complement_iter->second[0] > indexOfTempElem){
							//if we pass condition 2: if the first instance of compl is to the right of temp elem.
							triplets.push_back({nums[indexOfFixedElem], nums[indexOfTempElem], -1*sumOfFixedAndTemp});
							
						}//basic way to pass condition 2
						
						//other ways to pass condition 2:
						//if there was no instance of compl in b/w curr fixed elem and curr temp elem, but there
						//...is an instance of compl to the right of curr temp elem.
						
						else{
							
							bool duplicate_compl_exists = false;
							bool complement_exists_to_rightoftemp = false;
							for(int i = 0; i < complement_iter->second.size(); ++i){
								
								if(complement_iter->second[i] < indexOfTempElem && complement_iter->second[i] > indexOfFixedElem){
									duplicate_compl_exists = true;
									break;
								}
								
								if(complement_iter->second[i] > indexOfTempElem){
									complement_exists_to_rightoftemp = true;
									break;
								}
							}//for that goes thru all indices where complement resides
							//...and looks for duplicate compl in b/w fixed elem and temp elem.
							//..this for loop also looks for whether there exists a complement to the right of temp.
							
							
							if(duplicate_compl_exists)
								continue;
							
							else if(not duplicate_compl_exists && complement_exists_to_rightoftemp){
								triplets.push_back({nums[indexOfFixedElem], nums[indexOfTempElem], -1 * sumOfFixedAndTemp});
							}
							
						}//else if basic condition 2 wasn't passed (there are > 1 checks for condition 2)
						
					}//else if condition 1 is passed.
					
					
					
				}/*if a complement does exist, you wanna check two things:
				  1) say the current temp num is 2, and the curr fixed num is -1, then u wanna check whether
				  		is already a 2 to the left of this temp 2 such that that 2 is not the fixed elem. aka,
						you wanna check whether there is a 2 in b/w the fixed elem and the temp, cuz if there is,
				  		then u can just "continue" outta the loop and save urself a duplicate case.
				  
				  2) if condition 1 is false, aka there is no 2 in b/w fixed and temp, then u wanna check
					 whether there is a complement (in this case the compl is -1 cuz -1 + 2 + (-1) == 0). Specifically,
				  	you wanna
				  	 check whether the first instance of the complement is to the right of the curr temp elem. this
				  	 is needed to save urself from a duplicate case once again. cuz if one instance of the compl is
				  	 to the left of the curr temp elem, then that would already have been considered and saved as
					 a triplet*/
					
				
			}//inner for loop goes thru all elems to the right of the fixed elem.
			
			
		}//outer for loop, changes the fixed elem. stops at the third last elem.
		
		
		
		return triplets;
		
	}
};


int main(){
	
	
	vector<int> testOne = {-1, 0, 1, 2, -1, -4};
	vector<int> testTwo = {-1, 0, 1, 2, -1, 2, -1};
	vector<int> testThree = {0,0,0,0,0};
	vector<int> testFour = {-1,1,0,0,1,-1,0,4,-2,-2};
	
	vector<int> testCinq = {1,2,-2,-1};
	vector<int> testSix = {3,-2,1,0};
	
	vector<int> testSeven = {-2,0,0,2,2};
	
	Solution x;
	
	auto resultSeven = x.threeSum(testSeven);
	
//	for(int i = 0; i < resultSeven.size(); ++i){
//		for(int inner = 0; inner < 3; ++inner){
//			cout << resultSeven[i][inner] << " ";
//		}
//		cout << "\n";
//	}
	
	auto resultCinq = x.threeSum(testCinq);
	auto resultSix = x.threeSum(testSix);
	
	auto resultOne = x.threeSum(testOne);
	auto resultTwo = x.threeSum(testTwo);
	auto resultTrois = x.threeSum(testThree);
	auto resultQuatre = x.threeSum(testFour);
	
	for(int i = 0; i < resultSix.size(); ++i){
		for(int inner = 0; inner < 3; ++inner){
			cout << resultSix[i][inner] << " ";
		}
		cout << "\n";
	}

	
	
	
}
