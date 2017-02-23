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


void readFile(ifstream& readFile, vector<int>& values, vector<point>& vecPoints, vector<int>& sizesVideos, vector<vector<int>>& serverToPoint){
	string sequence;
	//~ vector<int> sizesVideos;
	vector<int> infoPoint;
	vector<int> infoServer;
	int nbPoints(0), nbVideos(0);
	int nbServers(0);
	vector<int> servers;
	vector<int> latency;
	vector<int> infoVideo;
	while (not readFile.eof()){
	    //~ cout << "wut" << endl;
	    getline(readFile, sequence);
	    if (not sequence.empty()){
		values = split(sequence, ' '); // V E R C X
		getline(readFile, sequence);
		sizesVideos = split(sequence, ' '); // sizes of videos
		
		//points info
		while (nbPoints < values[1]){
		    //~ cout << values[1] << endl;
		    getline(readFile, sequence);
		    infoPoint = split(sequence, ' ');
		    nbServers = 0;
		    servers = {};
		    latency = {};
		    while(nbServers < infoPoint[1]){
			getline(readFile, sequence);
			infoServer = split(sequence, ' ');
			servers.push_back(infoServer[0]);
			latency.push_back(infoServer[1]);
			++nbServers;
		    }
		    point p({infoPoint[0], servers, latency, {}, {}});
		    vecPoints.push_back(p);
		    ++nbPoints;
		}
		//~ cout << "vid" << endl;
		// videos info
		
		while ((not readFile.eof()) and nbVideos < values[0]){
		    //~ cout << nbVideos << endl;
		    getline(readFile, sequence);
		    infoVideo = split(sequence, ' ');
		    vecPoints[infoVideo[1]].videosId.push_back(infoVideo[0]);
		    vecPoints[infoVideo[1]].nbRequests.push_back(infoVideo[2]);
		    ++nbVideos;
		}
		//~ cout << "endvid" << endl;
	    }
			    //~ i = 0;
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
		//~ }
	}
	
	serverToPoint.reserve(values[3]);
	for (uint i(0); i < vecPoints.size(); ++i){
	    for (auto&& id : vecPoints[i].idServers){
		serverToPoint[id].push_back(i);
	    }
	}
}


vector<int> split(const string &s, char delim){
  stringstream ss(s);
  string item;
  //~ vector<string> elems;
  vector<int> elems;
  while (getline(ss, item, delim)) {
    elems.push_back(std::move(stoi(item))); 
  }
  return elems;
}
