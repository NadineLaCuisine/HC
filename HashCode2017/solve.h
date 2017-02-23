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
#include "parser.h"



using namespace std;



#ifndef SOLVE_H_
#define SOLVE_H_




vector<vector<int>> solveProblem(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber);





#endif /* SOLVE_H_ */
