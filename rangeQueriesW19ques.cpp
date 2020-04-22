//
//  rangeQueriesW19ques.cpp


//   WINTER 2019 FINAL 281 range_queries

//
//  Created by Akshat Jindal on 4/19/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


struct Query {unsigned int id, start, end;};//struct... note that [start, end] (inclusive)



void range_queries(const vector<unsigned int> & data, const vector<Query> &queries){
	
	//for each query, i wanna create a hashmap for that specific range in data.
	
	for(int i = 0; i < queries.size(); ++i){
		
		unordered_map<unsigned int, int> dataValToCountHash;
		
		for(size_t j = queries[i].start; j <= queries[i].end; ++j){
		
			auto iter = dataValToCountHash.find(data.at(j));
			if(iter != dataValToCountHash.end()){
				
				iter->second += 1;
				
			}//if this data val is already in the hash, then increment its count
			
			
			else{
				
				dataValToCountHash.insert({data.at(j), 1});
			}//if the data val is not already in the hash, the insert it
			
		}//inner for loop that goes thru and populates the temp hash table for this range.
		
		auto idIter = dataValToCountHash.find(queries.at(i).id);
		if(idIter == dataValToCountHash.end())
			cout << 0 << " ";
		else
			cout << idIter->second << " ";
		
	}//outer for loop that goes thru Queries vector.
	
	
}//the func



int main(){
	
	
	vector<unsigned int> data_in = {5,4,3,5,3,3,2,1,3};
	
//	Query one,two,three,four,five;
//	one.id = 4; one.start = 7; one.end = 8;
//	two.id = 3; two.start = 0; two.end = 3;
//	three.id = 3; three.start = 0; three.end = 8;
//	four.id = 7; four.start = 0; four.end = 8;
//	five.id = 5; five.start = 0; five.end = 4;
	vector<Query> query_in = {{4,7,8},{3,0,3}, {3,0,8}, {7,0,8}, {5,0,4}};
	
//	vector<Query> query_in = {one,two,three,four,five};
	
	range_queries(data_in, query_in);
	
}
