//
//  DP 714 best time to buy and sell stocks.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 4/23/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	
public:
	int maxProfit(vector<int>& prices, int fee) {
		
		vector<vector<int>> profit;
		profit.reserve(2);
		profit.resize(2);
		
		for(size_t i = 0 ; i < 2; ++i){
		
			vector<int> temp;
			temp.reserve(prices.size());
			temp.resize(prices.size());
			profit[i] = temp;
			temp.clear();
			
		}//for that creates a 2d vector reperesenting a 2 by n matrix where n = num of stocks = prices.size
		//the zeroth row represents max profit at that stock if you own stock
		//the first row represents max profit at that stock if you don't own any stock at that point.
		
		//initializing the zeroth column
		profit[0][0] = -1 * prices.at(0);
		profit[1][0] = 0;
		
		//start at 1 cuz zeroth col has been populated already
		for(size_t col = 1; col < prices.size(); ++col){
			
			for(size_t row = 0; row < 2; ++row){
				
				if(row == 0){
					
					//in order to own a stock, i want the max of the previous time i own the stocked
					//...or buying a stock from scratch
					profit[row][col] = max(profit[row][col-1], profit[row + 1][col - 1] - prices.at(col));
					
				}//if we are in the row that represents "owns stock"
				
				else {
					
					/*in order to not own a stock, i either sell the stock i previously owned, or i
					 continue not owning a stock
					 
					 when i sell the stock i currently owned, i need to pay the transaction fee*/
					
					profit[row][col] = max(profit[row - 1][col -1] + prices.at(col) - fee, profit[row][col - 1]);
					
				}//if we are in the row that represents "don't own stock"
				
			}//inner for loop that goes thru the rows
			
		}//for loop that populates column by column the best prices yet.
		
		int maxGain = profit[0][prices.size()-1];
		if(profit[1][prices.size()-1] > maxGain)
			maxGain = profit[1][prices.size()-1];
		
		return maxGain;
	}//func
};//class

int main(){
	
	vector<int> test_one = {1,3,2,8};
	vector<int> test_two = {1,3,2,8,4,9};
	
	Solution x;
	assert(x.maxProfit(test_one, 2) == 5);
	assert(x.maxProfit(test_two, 2) == 8);
	return 0;
}//main
