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

void printSolution(vector<vector<int>>& result){
	int nbSlice = result.size();

	fprintf(stderr, "%d\n", nbSlice);

	for(int oneSlice = 0; oneSlice < nbSlice; oneSlice++){
		for (int oneCoordinate = 0; oneCoordinate < 4; oneCoordinate++){
			fprintf(stderr, "%d ", result[oneSlice][oneCoordinate]);
		}
		fprintf(stderr, "\n");
	}

}




void checkSolution(vector<vector<int>>& result, const vector<vector<char>>& pizza, int L, int H){
	int nbSlice = result.size();
	bool passed(true);
	for(int oneSlice = 0; oneSlice < nbSlice; oneSlice++){
		int firstRow, lastRow, firstColumn, lastColumn;

		firstRow = result[oneSlice][0];
		lastRow = result[oneSlice][2];
		firstColumn = result[oneSlice][1];
		lastColumn = result[oneSlice][2];

		int sizeSlice = (lastRow - firstRow) * (lastColumn - firstColumn);

		if (sizeSlice > H){
			cout << "Failed : too many cells per slice !" << endl;
			passed = false;
		} else {
			uint Ts(0);
			uint Ms(0);
			for (int i(firstRow); i <= lastRow; ++i){
				for (int j(firstColumn); i <= lastColumn; ++j){
					cout << pizza[i][j] << endl;
					if (pizza[i][j] == 'M'){
						++Ms;
					}
					else if (pizza[i][j] == 'T'){
						++Ts;
					} else {
						cout << "Empty cell" << endl;
						passed = false;
						break;
					}
					
					if (not (Ts >= uint(L))){
						passed = false;
						cout << "Failed : not enough tomatoe !" << endl;
						break;
					}
					if (Ms >= uint(L)){
						passed = false;
						cout << "Failed : not enough shrooms !" << endl;
						break;
					}
				}
			}
		}
	}
	if (passed){
		cout << "Passed ! " << endl;
	} 

}


