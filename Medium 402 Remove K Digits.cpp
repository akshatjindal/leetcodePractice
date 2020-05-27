//
//  Medium 402 Remove K Digits.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/14/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

//https://leetcode.com/problems/remove-k-digits/

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <unordered_set>
#include <stack>
#include <limits>
#
using namespace std;


class Solution {
public:
	string removeKdigits(string num, int k) {
		
		if(k >= num.size())
			return "0";
		
		if(k == 0)
			return num;
		
		//gonna use a greedy solution with a stack
		int num_elems_removed = 0;
		
		int fixedVal = num[0];
		size_t index_of_fixedVal = 0;
		
		for(size_t index = 1; index < num.size(); ++index){
			
			if(num[index] > fixedVal){
				num[index] = 'r';
				/*signifies that this char has been removed.
				 ..i dont wanna use std::string erase cuz it moves the string around in memory and that may be inefficent.
				 	*/
				++num_elems_removed; 
			}
			
			else if(num[index] < fixedVal){
				num[index_of_fixedVal] = 'r';
				fixedVal = num[index];
				index_of_fixedVal = index;
				
				++num_elems_removed;
			}
			
			
			if(num_elems_removed == k)
				break; 
			
			
		}//go thru the string, starting at the 1st character (not the 0th)
		
	
		if(num_elems_removed != k){
			
			for(size_t index = 0; index < num.size(); ++index){
				
				if(num[index] == 'r')
					continue;
				
				else{
					num[index] = 'r'; //remove from the left.
					++num_elems_removed;
				}
				
				if(num_elems_removed == k)
					break;
					
			}
			
		}//if for example the characters of the string were all equal. or it was like 66663 and k = 2.
		
		string tmp;
		tmp.reserve(num.size() - k);
		
		bool pushedback_nonzero = false;
		
		for(size_t index = 0; index < num.size(); ++index){
			if(num[index] == 'r')
				continue;
		
			if(not pushedback_nonzero && num[index] == '0')
				continue; //don't push back a zero if we haven't pushed back a non zero
			
			tmp.push_back(num[index]);
			pushedback_nonzero = true;
				
				
		}//for loop that is in charge of creating a new string that is then returned.
		
		if(tmp.size() == 0)
			return "0";
		return tmp;
	}
};


int main(){
	Solution x;
	cout << x.removeKdigits("68593", 2) << endl;
	cout << x.removeKdigits("98765", 1) << endl;
	cout << x.removeKdigits("10200", 1) << endl; //output most not contain any leading 0's.
	cout << x.removeKdigits("10", 1) << endl;
	cout << x.removeKdigits("100009", 1) << endl;
	
	
	
	cout << x.removeKdigits("12345678", 2) << endl;
}

