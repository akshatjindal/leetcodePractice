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
	
	unordered_map<int,vector<int>> valToIndex;
	
	bool we_have_already_seen_this_fixed_elem(int fixedVal, int index_of_fixed_elem){
		
		auto iter_to_fixed = valToIndex.find(fixedVal);
		if (iter_to_fixed->second[0] < index_of_fixed_elem) {
			return true;
		}
		
		return false;
	}
	
	bool duplicate_temp_exists_in_given_range(int tempVal, int indexOfTemp, int fixedIndex){
		
		
		auto iter_to_temp = valToIndex.find(tempVal);
		if(iter_to_temp->second[0] < fixedIndex)
			return true;
		
		if(iter_to_temp->second.size() == 1)
			return false;
		
		else{
			for(int i = 0; i < iter_to_temp->second.size(); ++i){
				if(iter_to_temp->second[i] > fixedIndex && iter_to_temp->second[i] < indexOfTemp)
					return true;
				if(iter_to_temp->second[i] > indexOfTemp)
					break;
			}
		}
		
		return false;
	}
	
	
	//returns true if there is a complement to the left of temp such that complement is not the fixed elem.
	bool duplicate_complement_exists_to_the_left_of_temp(unordered_map<int, vector<int>>::iterator iter_to_compl, int indexOfTemp, int indexOfFixed){
		
		if(iter_to_compl->second[0] < indexOfFixed)
			return true;
		
		for(int i = 0 ; i < iter_to_compl->second.size(); ++i){
			if(iter_to_compl->second[i] > indexOfFixed && iter_to_compl->second[i] < indexOfTemp)
				return true;
			if(iter_to_compl->second[i] > indexOfTemp)
				break;
		}
		
		return false;
	}
	
	bool complement_exists_to_the_right_of_temp(unordered_map<int, vector<int>>::iterator iter_to_compl, int indexOfTemp, int indexOfFixed){
		
		bool flag = false;
		
		for(int i = 0; i < iter_to_compl->second.size(); ++i){
			
			if(iter_to_compl->second[i] > indexOfTemp){
				flag = true;
				break;
			}
			
		}
		
		
		return flag;
	}
	
	vector<vector<int>> threeSum(vector<int>& nums) {
		
		if(nums.size() < 3)
			return {};
		
		
		vector<vector<int>> triplets;
		
		
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
				
				if(we_have_already_seen_this_fixed_elem(nums[indexOfFixedElem], indexOfFixedElem))
					continue;
				
				int sumOfFixedAndTemp = nums[indexOfFixedElem] + nums[indexOfTempElem];
				//complement is -1 * sumOfFixedAndTemp
				
				int complement = -1*sumOfFixedAndTemp;
				
				auto compl_iter = valToIndex.find(complement);
				
				if(compl_iter == valToIndex.end())
					continue; //complement doesn't exist.
				
				
				//if a complement does exist:
				
				//if there is only one instance of complement and it is to the left of temp elem.
				if(compl_iter->second.size() == 1 && compl_iter->second[0] < indexOfTempElem)
					continue;
				
	
				//has this this temp value already been seen in b/w fixed elem and this temp elem.
				if(duplicate_temp_exists_in_given_range(nums[indexOfTempElem], indexOfTempElem, indexOfFixedElem))
					continue;
				
				//if a duplicate temp doesnt exist in the given range.
				
				if(duplicate_complement_exists_to_the_left_of_temp(compl_iter, indexOfTempElem, indexOfFixedElem))
					continue;
				
				if(complement_exists_to_the_right_of_temp(compl_iter, indexOfTempElem, indexOfFixedElem))
					triplets.push_back({nums[indexOfFixedElem], nums[indexOfTempElem], complement});
				
				
			}//inner for loop
			
		}//outer for loop
		
		
		valToIndex.clear();
		return triplets;
		
	}
};


int main(){
	
	vector<int> testKosi = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
	
	
	vector<int> testOne = {-1, 0, 1, 2, -1, -4};
	vector<int> testTwo = {-1, 0, 1, 2, -1, 2, -1};
	vector<int> testThree = {0,0,0,0,0};
	vector<int> testFour = {-1,1,0,0,1,-1,0,4,-2,-2};
	
	vector<int> testCinq = {1,2,-2,-1};
	vector<int> testSix = {3,-2,1,0};
	
	vector<int> testSeven = {-2,0,0,2,2};
	
	Solution x;
	auto kosi = x.threeSum(testKosi);
	
	
	auto resultSeven = x.threeSum(testSeven);
	
//	for(int i = 0; i < kosi.size(); ++i){
//		for(int inner = 0; inner < 3; ++inner){
//			cout << kosi[i][inner] << " ";
//		}
//		cout << "\n";
//	}
	
	auto resultCinq = x.threeSum(testCinq);
	auto resultSix = x.threeSum(testSix);
	
	auto resultOne = x.threeSum(testOne);
	auto resultTwo = x.threeSum(testTwo);
	auto resultTrois = x.threeSum(testThree);
	auto resultQuatre = x.threeSum(testFour);
	
	for(int i = 0; i < kosi.size(); ++i){
		for(int inner = 0; inner < 3; ++inner){
			cout << kosi[i][inner] << " ";
		}
		cout << "\n";
	}

	
	
	
}
