//
//  Medium (200) Num of Islands.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/26/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
	
	int islandCount = 0;
	
	enum class State :unsigned char {Water, Undiscovered, Discovered, Blackened};//enumclass;
	
	vector<vector<State>> stateTable;
	
	
	//an m by n table of states that initially models the given grid.
	void initializeTable(size_t numRows, size_t numCols, vector<vector<char>>& grid_in){
		vector<vector<State>> x (numRows, vector<State> (numCols, State::Water));
		stateTable = x;
		
		//go column by column.
		for(size_t col = 0; col < numCols; ++col){
			for(size_t row = 0; row < numRows; ++row){
				
				if(grid_in[row][col] == '0'){
					stateTable[row][col] = State::Water;
				}//if water
				
				else
					stateTable[row][col] = State::Undiscovered;
			}//inner f.o.r
		}//outer f.o.r
		
	}//.initializetable. func.
	
	bool outsideOfBoundary(int row, int col){
		if(row < 0 || col < 0 || col >= stateTable[0].size() || row >= stateTable.size()){
			return true;
		}
		
		return false;
	}//..bool outsideofboundary.
	
	void helper(int row, int col, bool parentExists){
		
		if(outsideOfBoundary(row, col))
			return;
		
		if(stateTable[row][col] != State::Undiscovered) return;
		
		if(not parentExists)
			++islandCount;
		
		stateTable[row][col] = State::Discovered;
		
		helper(row-1, col, true); //north
		helper(row+1, col, true);//south
		helper(row, col-1, true);//west
		helper(row, col+1, true);
		
		stateTable[row][col] = State::Blackened;
		
		return;
	}//.helper.
	
public:
	int numIslands(vector<vector<char>>& grid) {
		
		if(grid.empty()) return 0;
		
		size_t numCols = grid[0].size();
		
		initializeTable(grid.size(), numCols, grid);
		
		//go column by column.
		
		for(int col = 0; col < (int)numCols; ++col){
			for(int row = 0; row < (int)grid.size(); ++row){
				
				helper(row, col, false);
				
			}//inner f.o.r
		}//outer f.o.r
		
		int numIslands = islandCount;
		
		stateTable.clear();
		islandCount = 0;
		
		return numIslands;
	}//func
};

int main(){
	
	vector<vector<char>> un {
		{
			{'1','1','1','1','0'},
			{'1','1','0','1','0'},
			{'1','1','0','0','0'},
			{'0','0','0','0','0'},
		}};
	
	vector<vector<char>> deux {
		{
			{'1','1','0','0','0'},
			{'1','1','0','0','0'},
			{'0','0','1','0','0'},
			{'0','0','0','1','1'},
		}};
	
	vector<vector<char>> trois {
		{
			{'0','1','1','0','1'},
			{'1','0','0','0','0'},
			{'0','0','0','0','1'},
			{'1','0','1','0','1'},
			{'0','0','1','0','1'},
		}};
	
	vector<vector<char>> quatre {
		{
			{'1','1','1'},
			{'0','1','0'},
			{'1','1','0'},
		}};
		
	Solution x;
	auto resultOne = x.numIslands(un);
	auto resultTwo = x.numIslands(deux);
	cout << resultTwo << endl ;
	auto resultTrois = x.numIslands(trois);
	auto Quatre = x.numIslands(quatre);

	assert(resultOne == 1);
	assert(resultTwo == 3);
	assert(resultTrois == 6);
	assert(Quatre == 1);
	
//	auto resultTwo = x.numIslands(deux);
//	cout << resultTwo << endl ;
	
	
}
