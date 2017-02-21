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



vector<vector<int>> solvePizzaLinear(vector<vector<char>>& pizza, uint numberIngredient,uint maxSize){
	vector<vector<int>> res;
	//~ vector<vector<bool> > used(pizza.size(), std::vector<int>(pizza[0].size()));
	uint numberShroom(0);
	uint numberTomato(0);
	uint lastI(0),lastJ(0);
	for(uint i(0); i<pizza.size();++i){
		lastJ=0;
		numberShroom=0;
		numberTomato=0;
		for(uint j(0);j<pizza[0].size();++j){
			if(pizza[i][j]=='M'){
				numberShroom++;
			}else{
				numberTomato++;
			}
			if(j-lastJ>maxSize){
				if(pizza[i][lastJ]=='M'){
					numberShroom--;
				}else{
					numberTomato--;
				}
				lastJ++;
			}
			if(numberShroom>=numberIngredient and numberTomato>=numberIngredient){
				res.push_back({i,lastJ,i,j});
				lastJ=j+1;
				numberShroom=0;
				numberTomato=0;
			}
		}
	}
	return res;
}



vector<vector<int>> solvePizzaLinear2(vector<vector<char>>& pizza, uint numberIngredient,uint maxSize){
	vector<vector<int>> res;
	//~ vector<vector<bool> > used(pizza.size(), std::vector<int>(pizza[0].size()));
	uint numberShroom(0);
	uint numberTomato(0);
	uint lastI(0),lastJ(0);
	for(uint i(0); i<pizza[0].size();++i){
		lastJ=0;
		for(uint j(0);j<pizza.size();++j){
			if(pizza[j][i]=='M'){
				numberShroom++;
			}else{
				numberTomato++;
			}
			//~ cout<<pizza[i][j]<<endl;
			if(j-lastJ>maxSize){
				if(pizza[lastJ][i]=='M'){
					numberShroom--;
				}else{
					numberTomato--;
				}
				lastJ++;
			}
			if(numberShroom>=numberIngredient and numberTomato>=numberIngredient){
				res.push_back({i,lastJ,i,j});
				lastJ=j+1;
				numberShroom=0;
				numberTomato=0;
			}
		}
	}
	return res;
}



vector<vector<int>> solvePizza(vector<vector<char>>& pizza, uint numberIngredient,uint maxSize){
	auto lol(solvePizzaLinear(pizza,numberIngredient,maxSize));
	auto lol2(solvePizzaLinear2(pizza,numberIngredient,maxSize));
	if(lol.size()>lol2.size()){
		return lol;
	}else{
		return lol2;
	}
}



