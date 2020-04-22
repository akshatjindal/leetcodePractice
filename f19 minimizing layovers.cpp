//
//  f19 minimizing layovers.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/22/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

//QUESTION 26- f19

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <limits>
using namespace std;

enum class Color: unsigned char {black, white, gray};//enum

struct Airport{
	string code = "";
//	string parent_code = ""; //empty string
	int distance_from_origin = std::numeric_limits<int>::infinity();
	Color color = Color::white; //white represents that this node hasn't been set. black represents that this airport has been set (aka the closest distance from the origin to it has been found).
	
	Airport(){};
};//airpirt struct

int fewestLayovers(vector<vector<string>>& flights, string origin, string dest){
	
	//since this is an unweighted graph, instead of doing Dijkstra's, we can use BFS.

	
	//hash map that maps airport codes (strings) to their correpsonding airport objects. the other hash map will have pointers to objects in here.
	
	unordered_map<string, Airport> code_to_object;
	
	for(size_t row = 0 ; row < flights.size(); ++row){
		
		//col<=1 cuz each row only has its an orig (0th elem) and a dest (1st elem).
		for(size_t col = 0; col <= 1; ++col){
			
			if(code_to_object.count(flights[row][col]) == 0){
				Airport airport_object;
				airport_object.code = flights[row][col];
				code_to_object.insert({airport_object.code, airport_object});
			}//if this airport object hasn't been created already, then create it.
			
		}//for
		
		
	}//for loop that creates airport objects and stores them in a hash map.
	
	
	if(code_to_object.count(dest) == 0){
		return -1;
	}//if the destination doesn't exist in flights vector.
	
	//BFS needs an adjacency list. we can use a hash map to store the adj list of each airport.
	unordered_map<string, vector<Airport *>> adj_list;
	
	for(size_t row = 0 ; row < flights.size(); ++row){
		
		for(size_t col = 0; col <= 1; ++col){
			
			if(col == 0 && adj_list.count(flights[row][0]) == 0){
				
				adj_list.insert({flights[row][0], {}});
				
			}//if this origin airport didn't have an adjacency list, create an empty adj list.
				
			else if(col == 1){
				
				auto correspOrigin = adj_list.find(flights[row][0]);
				auto corresp_airport_object_iter = code_to_object.find(flights[row][col]);
				
				correspOrigin->second.push_back(&(corresp_airport_object_iter->second));
				//pushback into the adjacency list a pointer to the corresponding airport object.
				
			}//if we are looking at destination.
			
		}//inner for loop.
		
		
	}//outer for loop that goes thru the rows.
	//these two for loop populate the adjaceny list.
	
	
	//BFS algorithm from pg 595 CLRS
	
	//set origin as the starting vertex.
	auto iter_to_start_object = code_to_object.find(origin);
	iter_to_start_object->second.color = Color::gray;
	iter_to_start_object->second.distance_from_origin = 0;
	
	//BFS uses a queue (FIFO).
	queue<Airport *> the_queue; //Q initially starts out empty
	the_queue.push(&(iter_to_start_object->second)); //now it has a pointer to the starting vertex.
	
	while(the_queue.empty() == false){
		Airport * u = the_queue.front();
		the_queue.pop();
		
		auto airport_u = adj_list.find(u->code);
		
		for(size_t i = 0; i < airport_u->second.size(); ++i){
			
			if(airport_u->second.at(i)->color == Color::white){
				
				airport_u->second.at(i)->color = Color::gray;
				airport_u->second.at(i)->distance_from_origin = u->distance_from_origin + 1;
				
				//add this adjacent airport to the queue.
				the_queue.push(airport_u->second.at(i));
				
			}//if the color of this adjacent airport to u is white, then it is unvisited.
			
		}//this for loop traverses thru the adjacency list of u.
		
		//after all the previously white elements that were adjacent to airport u have been visited,
		//we can mark u as black.
		u->color = Color::black;
		
	}//while..
	//at the end of this while loop, the underlying airport objects should have the correct distance, but we are looking for layovers.
	
	return (code_to_object.find(dest)->second.distance_from_origin - 1);
}//fewestLayovers...


int main(){
	
	vector<vector<string>> flights_in_one { {"ATL", "JFK"},
		{"ORD", "LAX"},
		{"MIA", "PHL"},
		{"DTW", "ATL"},
		{"SEA", "ORD"}, {"DTW", "ORD"}, {"SFO", "SEA"}, {"ORD", "ATL"}, {"LAX", "SEA"}, {"ATL", "ORD"}, {"LAX", "ATL"}, {"ORD", "JFK"} };
	
	
	cout << fewestLayovers(flights_in_one, "DTW", "SEA") << endl;
	
	
	
	vector<vector<string>> flights_test_two {
		{"DTW", "ORD"},
		{"ORD", "ATL"},
		{"ATL", "DTW"}
	};
	
	cout << fewestLayovers(flights_test_two, "DTW", "SFO");
	return 0;
}





