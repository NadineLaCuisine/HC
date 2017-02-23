/*
 * parser.h
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
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>

#ifndef PARSER_H_
#define PARSER_H_

using namespace std;


//~ void readFile(ifstream& readFile, vector<vector<char>>& problem);


struct point{
	int dataCenterLatency;
	vector<int> idServers;
	vector<int> latencyToServers;
	vector<int> videosId;
	vector<int> nbRequests;
	
};

void readFile(ifstream& readFile, vector<int>& values, vector<point>& vecPoints, vector<int>& sizesVideos);

vector<int> split(const string &s, char delim);



#endif /* PARSER_H_ */
