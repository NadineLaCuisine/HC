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

using namespace std;

int R(0), C(0), L(0), H(0);

int main(int argc, char ** argv){
	string fileName(argv[1]);
	ifstream file(fileName);
	vector<vector<char>> pizza;
	//~ readFile(file, R, C, L, H, pizza);
	cout << "it works BISCUIT " << endl;
	return 0;
}

