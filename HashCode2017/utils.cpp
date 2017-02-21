/*
 * utils.cpp
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

#include "solve.h"
#include "parser.h"
#include "utils.h"

void printSolution(FILE* file, vector<vector<int>>& result){

	fprintf(file, "This should be a solution\n");


}




void checkSolution(vector<vector<int>>& result){
	bool passed(true);
	if (!passed){
		cout << "Check failed...";
		exit(-1);
	}

}


