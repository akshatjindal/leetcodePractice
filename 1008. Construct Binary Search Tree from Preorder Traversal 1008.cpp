//
//  1008. Construct Binary Search Tree from Preorder Traversal 1008.cpp
//  leetcodePrac
//
//  Created by Akshat Jindal on 5/30/20.
//  Copyright © 2020 Akshat Jindal. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include "string.h"
#include <iostream>
#include <unordered_set>
#include <map>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
     int val;
	TreeNode *left;
    TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};//struct


class Solution {
	
	TreeNode * maxYet = nullptr;
	int maxVal = 0;
	vector<TreeNode *> ptrsByIndex;
	map<int, TreeNode *, greater<int>> descendingByValMap;
	
	void clearUp(){
		ptrsByIndex.clear();
		descendingByValMap.clear();
		maxVal = 0; maxYet = nullptr;
	}
	
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
	
		TreeNode * zeroth = new TreeNode(preorder[0]);
		if(preorder.size() == 1) return zeroth;
		
		maxYet = zeroth; maxVal = preorder[0];
		descendingByValMap.insert(make_pair(preorder[0], nullptr));
		ptrsByIndex.reserve(preorder.size());
		ptrsByIndex.push_back(zeroth);
		
		for(size_t index = 1; index < preorder.size(); ++index){
			TreeNode * node = new TreeNode(preorder[index]);
			ptrsByIndex.push_back(node);
			
			if(preorder[index] < preorder[index-1]){
				ptrsByIndex[index-1]->left = node;
			}
				
			
			else{
				if(preorder[index] > maxVal){
					maxYet->right = node;
					maxVal = node->val;
					maxYet = node;
				}//if this index > maxVal yet.
				
				else{
					auto firstGreaterVal = descendingByValMap.upper_bound(node->val)->second;
					firstGreaterVal->right = node;
				}//else when index val < maxVal
			}//else when index's val > index-1 val
			
			
			descendingByValMap.insert(make_pair(node->val, node));
			
		}//forloop
		
		clearUp();
		
		return zeroth;
	}//func
};//class

int main(){
	
	
	
	
	
	
}
