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
#include <atomic>

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
	vector<vector<int>> serverToPoint;
	readFile(inFile, values, vecPoints, sizesVideos, serverToPoint);

	vector<vector<int> > result = solveProblem(sizesVideos, vecPoints, values[4], values[3],serverToPoint);
	//~ printf("Result is computed\n");
	//~ checkSolution(result, sizesVideos, values[4]);
	//~ printf("Result is checked\n");
	//~ printf("Score is %ld\n", getScore(result, vecPoints));
	//~ printSolution(outFile, result);

	//~ uint i(0);
	//~ cout << vecPoints[1].videosId.size() << endl;
	//~ cout << values.back() << " " << values[3] << endl;
	atomic<int> bestScore;
	bestScore=0;
	vector<vector<int> > finalResult;
	#pragma omp parallel for
	for (uint i=0; i < 100; ++i){
		//~ cout << "i " << i << endl;
		vector<vector<int> > resultrandom = solveProblemRandom(sizesVideos,  vecPoints, values.back(), values[3], serverToPoint);
		//~ cout << resultrandom.size() <<  endl;
		int scorerandom = getScore(resultrandom, vecPoints);
		//~ cout << scorerandom << endl;
		if (scorerandom > bestScore){
			bestScore = scorerandom;
			finalResult = resultrandom;
		}
	}
	cout << bestScore << endl;
	printSolution(outFile, finalResult);
	//~ cout << vecPoints[1].videosId.size() << endl;

	return 0;
}

