//
//  getMaxNuts Fall 2019.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/23/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <limits>

using namespace std;

int getMaxNuts(vector<vector<int>>& diag, int nrow, int ncol) {
	
	//bottom-up solution.
	vector<vector<int>> nuts;
	nuts.reserve(nrow);
	nuts.resize(nrow);
	
	for(size_t row = 0; row < nrow; ++row){
		
		vector<int> temp;
		temp.reserve(ncol);
		temp.resize(ncol);
		nuts[row] = temp;
		temp.clear();
		
	}//pushback an inner vector of ncols for each row. this makes the matrix an m*n.
	
	
	for(size_t row = 0; row < nuts.size(); ++row){
		
		nuts[row][0] = diag[row][0];
		
	}//this for loop populates the first column of nuts. this will help w/ bottom up approach.
	
	//start at col = 1 cuz the 0th column is already populated.
	for(size_t col = 1; col < ncol; ++col){
		
		for(size_t row = 0; row < nrow; ++row){
			
			if(row == 0){
				
				nuts[row][col] = diag[row][col] + nuts[row + 1][col - 1];
				
			}//if we are the 0th row. aka top border of each col
			
			else if(row == (nrow - 1)){
				nuts[row][col] = diag[row][col] + nuts[row - 1][col - 1];
			}//if the last row, aka bottom border of each col
			
			else{
				nuts[row][col] = diag[row][col] + max(nuts[row-1][col - 1], nuts[row+1][col-1]);
			}
			
		}//inner for loop that goes thru the rows.
		
		
	}//outer loop that goes thru cols
	//bottom-up approach.
	
	
	int maxNuts = nuts[0][ncol-1];
	for(size_t row = 1; row < nrow; ++row){
		if(nuts[row][ncol-1] > maxNuts)
			maxNuts = nuts[row][ncol-1];
	}//this for loop finds out the maximum num of nuts. this should be stored in the last col of nuts.
	
	
	return maxNuts;
}//getMaxNuts function



int main(){
	
	vector<vector<int>> test_one {
								  {2,4,5,3},
								  {7,0,4,9},
								  {3,1,6,2},
								  {2,9,3,8}
	};
	
	assert(getMaxNuts(test_one, 4, 4) == 27);
	
	
	vector<vector<int>> test_two{
		{2,4,5},
		{7,0,4},
		{3,1,6}};
	
	assert(getMaxNuts(test_two, 3, 3) == 15);
	
	vector<vector<int>> test_three{
		{8,2},
		{4,5},
		{6,9}
	}; //a 3 * 2 matrix
	
	assert(getMaxNuts(test_three, 3, 2));
	
	
	
	
	return 0;
}
