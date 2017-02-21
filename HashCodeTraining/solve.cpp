/*
 * solve.cpp
 *
 *  Created on: 21 févr. 2017
 *      Author: simon
 */
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <chrono>
#include <map>
#include <set>
#include <vector>



using namespace std;



vector<vector<int>> solvePizzaTrivial(vector<vector<char>>& pizza, uint numberIngredient,uint maxSize){
	vector<vector<int>> res;
	res.push_back({0,0,pizza.size(),pizza[0].size()});
	return res;
}



vector<vector<int>> solvePizza(vector<vector<char>>& pizza, uint numberIngredient,uint maxSize){
	vector<vector<int>> res;
	//~ vector<vector<bool> > used(pizza.size(), std::vector<int>(pizza[0].size()));
	uint numberShroom(0);
	uint numberTomato(0);
	uint lastI(0),lastJ(0);
	for(uint i(0);  i<pizza.size();++i){
		lastI=0;
		for(uint j(0);j<pizza[0].size();++j){
			if(pizza[i][j]=='M'){
				numberShroom++;
			}else{
				numberTomato++;
			}
			if(numberShroom>=numberIngredient and numberTomato>=numberIngredient){
				res.push_back({lastI,j,i,j});
				lastI=i+1;
			}
		}
	}
	return res;
}



