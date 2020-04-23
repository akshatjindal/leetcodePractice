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
		
		
		int smallestValSoFar = prices.at(0);
		int indexOfSmallestSoFar = 0;
		
		for(int i = 1; i < prices.size(); ++i){
			
			if(prices.at(i) > smallestValSoFar)
				break;
			
			//else
			if(prices.at(i) < smallestValSoFar){
				smallestValSoFar = prices.at(i);
				indexOfSmallestSoFar = i;
			}
				
			
		}//this finds the first elem such that there is a higher elem to the right of it.
		//so if this prices vector is a completely decreasing vector, we can just return 0.
		
		if(indexOfSmallestSoFar == (prices.size() - 1))
			return 0;
		
		//this is a bottom up DP approach, the 0th elem of both of these vectors represents the max profit
		//...given that u own a stock at this particular point.
		
		//the 1st elem of both of these vectors represents the max profit given that u don't own a stock at
		//...at this point.
		
		vector<int> penUltimateCol;
		vector<int> ultimateCol;
		penUltimateCol.reserve(2);
		ultimateCol.reserve(2);
		penUltimateCol.resize(2);
		ultimateCol.resize(2);
		
		//initialize penUltimateCol;
		penUltimateCol[0] = -1 * prices.at(indexOfSmallestSoFar); //at the start, if u own the zeroth stock, then ur prof is -1 * the price of the stock
		penUltimateCol[1] = 0;
		
		for(size_t stocknum = indexOfSmallestSoFar; stocknum < prices.size(); ++stocknum){
			
			for(size_t row = 0; row <= 1; ++row){
				
				if(row == 0){
					
					//in order to own a stock, i want the max of the previous time i own the stocked
					//...or buying a stock from scratch
					
					ultimateCol[0] = max(penUltimateCol[0], penUltimateCol[1] - prices.at(stocknum));
					
				} //row == 0 represents max profit when u own a stock
				
				else{
					
					/*in order to not own a stock, i either sell the stock i previously owned, or i
					 continue not owning a stock
					 
					 when i sell the stock i currently owned, i need to pay the transaction fee*/
					
					ultimateCol[1] = max(penUltimateCol[0] + prices.at(stocknum) - fee, penUltimateCol[1]);
					
				}//when row == 1, this represents max profit when u don't own a stock.
				
			}//inner for loop goes thru the 2 rows. the zeroth row and the first row represent different things.
			
			penUltimateCol[0] = ultimateCol[0];
			penUltimateCol[1] = ultimateCol[1];
			
			
		}//for loop that goes thru each stock (except for the zeroth one) and updates the vectors with the best possible price yet.
		
		return max(ultimateCol[0], ultimateCol[1]);
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
