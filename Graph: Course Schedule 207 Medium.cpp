//
//  Graph: Course Schedule 207 Medium.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/30/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
// htt ps://leetcode.com/problems/course-schedule/

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <unordered_set>
#include <limits>



using namespace std;

class Solution {
	
	
	enum class Color: unsigned char {white, grey, black};
	
	class Vertex{
	public:
		int course_id = -1;  //aka vertex number
		Color color = Color::white; //initially all vertices are white.
		int parent_id = -1;
		
		Vertex(){}; //default constructor
		Vertex(int _course):course_id{_course}{};
	};//class
	
	vector<Vertex> courses; //contains all courses in their corresponding buckets. Course n will be in the nth bucket.
	unordered_map<unsigned int, vector<Vertex *>> adj_list; //this maps an int (repping a particular course) to its adjacency list.
public:
	
	bool DFS_Visit(int course_num){
		bool flag = true;
		courses[course_num].color = Color::grey;
		//grey indicates that this vertex has been visited but not completed (not yet black).
		
		auto iter = adj_list.find(course_num);
		
		if(iter!= adj_list.end()){
			for(int i = 0; i < iter->second.size(); ++i){
				
				auto adj_vertex_ptr = iter->second.at(i); //this will hold a ptr to the prerequisite course.
				if(adj_vertex_ptr->color == Color::grey){
					flag = false; //if back edge found.
					break;
				}
				
				if(adj_vertex_ptr->color == Color::white){
					adj_vertex_ptr->parent_id = course_num;
					flag = DFS_Visit(adj_vertex_ptr->course_id);
					if(not flag)
						break;
				}
				
			}//goes thru adjacency list of this course, returns false if a back edge is found.
		}
		
		courses[course_num].color = Color::black;
		
		return flag;
		
	}
	
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		
		/*DFS search to find out if a cycle exists. a cycle exists if whilst going from a vertex u to vertex v,
		 ...we find that v has already been visited but v isn't the parent of u.
		 
		 if we don't find a cycle then that means there exists atleast one course that we can take first that will
		 give us a topological ordering such that we can take all other courses (in some order whilst keeping the
		 pre-requisites in mind).
		 
		 DFS requires an adj_list for each vertex.
		 
		 How do we know that we have found a cycle in the DFS:
		 	- If we discover a back-edge while doing the BFS, then we have found a cycle.
		 	- A back edge is when u find a gray vertex that is not the parent of the current vertex you are at.
		 */
		
		if(prerequisites.size() == 0 || prerequisites.size() == 1)
			return true;
		
		courses.reserve(numCourses);
		courses.resize(numCourses);
		
		for(unsigned int i = 0; i < prerequisites.size(); ++i){
			
			if(courses[prerequisites[i][0]].course_id == -1)
				courses[prerequisites[i][0]] = Vertex(prerequisites[i][0]);
			
			if(courses[prerequisites[i][1]].course_id == -1)
				courses[prerequisites[i][1]] = Vertex(prerequisites[i][1]);
			
			//the above two if's created the vertex objects if they weren't already created.
			
			auto iter = adj_list.find(prerequisites[i][0]);
			
			if(iter == adj_list.end()){
				vector<Vertex *> temp;
				temp.push_back(&(courses[prerequisites[i][1]]));
				adj_list.insert(make_pair(prerequisites[i][0], temp));
			}//if this course hadn't already been inserted into hashmap.
			
			else{
				iter->second.push_back(&(courses[prerequisites[i][1]]));
			}//else if this course had already been inserted into hashmap.
			
			
		}//outer forloop that goes thru the rows
		//these for loops create the vertex objects and populates their adjacency list.
		
		
		for(int i = 0; i < courses.size(); ++i){
			if(courses[i].color == Color::white){
				bool flag = DFS_Visit(i);
				if(flag == false){
					adj_list.clear();
					courses.clear();
					return false;
				}
			}
		}//for that goes thru entire courses vector and calls DFS visit each time.
		
		
		adj_list.clear();
		courses.clear();
		return true;
	}
	
};



int main(){
	
	Solution x;
	vector<vector<int>> testOne = {
		{1,0},
		{0,1}
	};
	
	vector<vector<int>> testTwo = {
		{0,1},
		{1,3},
		{3,2},
		{2,1}
	};
	
	vector<vector<int>> testTrois = {
		{1,0},
		{2,0}
	};
	
	vector<vector<int>> testFour = {
		{0,1},
		{0,2},
		{1,0}
	};
	
	cout<<x.canFinish(2, testOne);
	
	cout << x.canFinish(4, testTwo);
	
	cout << x.canFinish(3, testTrois);
	
	cout << x.canFinish(3, testFour);
	
	
	
}//...
