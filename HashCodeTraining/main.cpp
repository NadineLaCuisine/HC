/*
 * main.cpp
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

#include "parser.h"
#include "solve.h"
#include "utils.h"


using namespace std;

int R(0), C(0), L(0), H(0);

int main(int argc, char ** argv){
	string fileName(argv[1]);
	ifstream file(fileName);
	vector<vector<char>> pizza;
	readFile(file, R, C, L, H, pizza);
	//~ cout << pizza.size() << endl;

	vector<vector<int>> result = solvePizza(pizza, L, H);
	printSolution(result);
	//~ vector<vector<int>> result2 = solvePizzaLinear2(pizza, L, H);
	//~ printSolution(result2);

	return 0;
}

