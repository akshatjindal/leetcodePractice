//
//  Hash: word patterns Easy 290.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/29/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
	
public:
	
	bool wordPattern(string pattern, string str) {
		
		unordered_map<char, string> charToCorrespString; //this maps an 'a' to a particular word, a 'b' to a particular word etc.
		
		unordered_set<string> uniqueWords;
		
		
		
		istringstream stream(str);
		string temp_word;
		size_t char_count = 0;
		
		while(stream >> temp_word || pattern[char_count] != '\0'){
			
			auto iter = charToCorrespString.find(pattern[char_count]);
			
			if(iter == charToCorrespString.end()){
				
				
				if(uniqueWords.count(temp_word) != 0){
					return false;
				}//for every new character being inserted, we wanna check with all previously existing unique
				///...characters that this temp_word isn't already in the set.
				
				charToCorrespString.insert(make_pair(pattern[char_count], temp_word));
				uniqueWords.insert(temp_word);
				
			}//if this 'a' or 'c' or x char hasn't already been read in.
			
			else{
				
				//check if the value this key is mapped to is the same as the temp_word that was just read in
				if(iter->second != temp_word)
					return false;
				
			}//if this char has already been mapped.
			
			++char_count;
			
		
			
		}//while that reads in each word from str individually
		
		
		return true;
		
	}//func
};



int main(){
	Solution x;
	cout << x.wordPattern("jquery", "jquery");
	
	cout << x.wordPattern("abba", "dog cat cat dog");
	
}
