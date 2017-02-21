/*
 * parser.cpp
 *
 *  Created on: 21 févr. 2017
 *      Author: simon
 */





#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <unordered_set>

#include "parser.h"


readFile(ifstream& readFile, int& R, int& C, int& L, int& H, vector<vector<char>>& pizza){
	string sequence;
	vector<string> values;
	uint i(0);
	while (not readFile.eof()){
		i = 0;
        getline(readFile, sequence);
        if (not sequence.empty()){
			value = split(sequence, ' ');
			R = stoi(value[0]);
			C = stoi(value[1]);
			L = stoi(value[2]);
			H = stoi(value[3]);
			while (i < R){
				getline(readFile, sequence);
			}
		}
	}
}


vector<string> split(const string &s, char delim){
  stringstream ss(s);
  string item;
  vector<string> elems;
  while (getline(ss, item, delim)) {
    elems.push_back(std::move(item)); 
  }
  return elems;
}
