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
	vector<int> infoPoint;
	vector<int> infoServer;
	int nbPoints(0), nbVideos(0);
	int nbServers(0);
	vector<int> servers;
	vector<int> latency;
	vector<int> infoVideo;
	while (not readFile.eof()){
	    getline(readFile, sequence);
	    if (not sequence.empty()){
		values = split(sequence, ' '); // V E R C X
		getline(readFile, sequence);
		sizesVideos = split(sequence, ' '); // sizes of videos
		nbPoints = 0;
		//points info
		while (nbPoints < values[1]){
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
		while ((not readFile.eof()) and nbVideos < values[2]){
		    getline(readFile, sequence);
		    infoVideo = split(sequence, ' ');
		    vecPoints[infoVideo[1]].videosId.push_back(infoVideo[0]);
		    vecPoints[infoVideo[1]].nbRequests.push_back(infoVideo[2]);
		    ++nbVideos;
		}
	    }

	}
	//~ cout << "here" << endl;
	serverToPoint.resize(uint(values[3]), {});
	//~ cout << values[3] << endl;
	//~ for (int i(0); i < values[3]; ++i){
	    //~ serverToPoint.push_back({});
	//~ }
	for (uint i(0); i < vecPoints.size(); ++i){
	    for (uint id(0); id < vecPoints[i].idServers.size(); ++id){
		serverToPoint[vecPoints[i].idServers[id]].push_back(i);
	    }
	}
	cout << "End parsing." << endl;
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
