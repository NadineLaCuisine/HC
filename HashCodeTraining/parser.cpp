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


void readFile(ifstream& readFile, int& R, int& C, int& L, int& H, vector<vector<char>>& pizza){
	string sequence;
	vector<string> values;
	int i(0);
	while (not readFile.eof()){
		i = 0;
        getline(readFile, sequence);
        if (not sequence.empty()){
			values = split(sequence, ' ');
			R = stoi(values[0]);
			C = stoi(values[1]);
			L = stoi(values[2]);
			H = stoi(values[3]);
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
