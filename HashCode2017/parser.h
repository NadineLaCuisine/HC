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


void readFile(ifstream& readFile, vector<vector<char>>& problem);
vector<string> split(const string &s, char delim);

struct point{
	int dataCenterLatency;
	vector<int> idServers;
	vector<int> latencyToServers;
	vector<int> videosId;
	vector<int> nbRequests;
};
	



#endif /* PARSER_H_ */
