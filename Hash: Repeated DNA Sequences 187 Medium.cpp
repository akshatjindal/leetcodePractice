//
//  Hash: Repeated DNA Sequences 187 Medium.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/30/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <unordered_set>


using namespace std;
class Solution {
	
public:
	
	vector<string> findRepeatedDnaSequences(string s) {
		
		if(s.length() <= 10)
			return {};
		
		unordered_map<string, int> substrToCount; //each substr is of length ten.
		
		unordered_set<string> repeatedSeqs; //this contains all repeatedSeqs.
		
		for(size_t i = 0; i <= s.length() - 10; ++i){
			
			string temp = s.substr(i, 10);
			
			auto iter = substrToCount.find(temp);
			
			if(iter == substrToCount.end()){
				substrToCount.insert(make_pair(temp,1));
			}//if this substr hasnt been hashed already
			
			else{
				iter->second += 1;
				repeatedSeqs.insert(temp);
			}//else if this subtr has already been hashed, u wanna increment its count
			
		}//for loop that goes thru each character of this string,
		//we get substrings of length 10 each time and store them in our hash map.
		
		vector<string> ans;
		for(const auto & x: repeatedSeqs){
			ans.push_back(x);
		}
	
		return ans;
	}
	
};



int main(){
	Solution x;
	auto vec = x.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	auto vectwo = x.findRepeatedDnaSequences("AAAAAAAAAAAA");
	for(const auto & x:vec){
		cout << x << endl;
	}
	
	for(const auto & x:vectwo)
		cout << x << endl;
}
