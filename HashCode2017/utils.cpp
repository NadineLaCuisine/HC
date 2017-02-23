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

	fprintf(file, "%d\n", result.size());
	for (int oneServer = 0; oneServer<result.size(); oneServer++){
		fprintf(file, "%d ", oneServer);
		for (int oneVideo = 0; oneVideo<result[oneServer].size(); oneVideo++){
			fprintf(file, "%d ", result[oneServer][oneVideo]);
		}
		fprintf(file, "\n");
	}

}




void checkSolution(vector<vector<int>>& result){
	bool passed(true);
	if (!passed){
		cout << "Check failed...";
		exit(-1);
	}

}


