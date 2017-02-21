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


void readFile(ifstream& readFile, vector<vector<char>>& problem){
	string sequence;
	vector<string> values;
	int i(0);
	while (not readFile.eof()){
		
        getline(readFile, sequence);
        
        if (not sequence.empty()){
			i = 0;
//			values = split(sequence, ' ');
//			R = stoi(values[0]);
//			C = stoi(values[1]);
//			L = stoi(values[2]);
//			H = stoi(values[3]);
//
//			while (i < R){
//				vector<char> rowPizz = {};
//				getline(readFile, sequence);
//				if (not sequence.empty()){
//					for (char c : sequence){
//						rowPizz.push_back(c);
//					}
//				}
//				++i;
//				//~ cout << "*** "<<rowPizz.size() << endl;
//				pizza.push_back(rowPizz);
//			}
//
//			//~ cout << R << " " << C << " "<< L << " " <<H << endl;
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
