/*
 * utils.h
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

#ifndef UTILS_H_
#define UTILS_H_

void printSolution(FILE* file, vector<vector<int>>& result);
void checkSolution(vector<vector<int>>& result, vector<int> sizesVideo, int maxSize);
int64_t getScore(vector<vector<int>>& result, vector<struct point>& endPoints);
int getScoreVideoEndPoint(int videoId, int endPointId, vector<struct point>& endPoints, vector<vector<int>>& result);



#endif /* UTILS_H_ */
