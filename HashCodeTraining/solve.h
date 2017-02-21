/*
 * solve.h
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



#ifndef SOLVE_H_
#define SOLVE_H_



vector<vector<int>> solvePizzaLinear2(vector<vector<char>>& pizza, uint NumberIngredient,uint maxSize);
vector<vector<int>> solvePizzaLinear(vector<vector<char>>& pizza, uint NumberIngredient,uint maxSize);
vector<vector<int>> solvePizzaTrivial(vector<vector<char>>& pizza, uint NumberIngredient,uint maxSize);





#endif /* SOLVE_H_ */
