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




int main(int argc, char ** argv){
	//LABASE
	srand (time(NULL));


	//Opening input file
	string inFileName(argv[1]);
	ifstream inFile(inFileName);

	FILE* outFile = fopen(argv[2], "w");

	vector<int> values;
	vector<point> vecPoints;
	vector<int> sizesVideos;
	readFile(inFile, values, vecPoints, sizesVideos);

	//~ vector<vector<int>> result = solveProblem(sizesVideos, vecPoints, values[4], values[3]);

	//~ checkSolution(result);

	//~ printSolution(outFile, result);


	return 0;
}

