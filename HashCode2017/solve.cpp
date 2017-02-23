/*
 * solve.cpp
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



int maxVector(vector<int>& V){
	int res(V[0]),indice(0);
	for(uint i(0);i<V.size();++i){
		if(V[i]>res){
			res=V[i];
			indice=i;
		}
	}
	V[indice]=0;
	return indice;
}



vector<vector<int>> solveProblem(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber){
	vector<vector<int>> result;
	vector<vector<int>> serverToPoint;
	//foreach server
	for (uint i(0);i<serverNumber;++i){
		vector<int> videoCached;
		vector<int> videoScore(sizeVideos.size(),0);
		vector<int> clients=serverToPoint[i];
		//foreach client
		for(uint j(0);j<clients.size();++j){
			point client(pointsVector[clients[j]]);
			for(uint ii(0);ii<client.videosId.size();++ii){
				videoScore[client.videosId[ii]]+=client.nbRequests[ii];
			}
		}
		//compute video score
		for(uint iii(0);iii<videoScore.size();++iii){
			videoScore[iii]/=sizeVideos[iii];
		}
		uint capacity(0);
		//fill the server
		while(capacity<sizeServer){
			int indiceMax(maxVector(videoScore));
			if(capacity+sizeVideos[indiceMax]<=sizeServer){
				capacity+=sizeVideos[indiceMax];
				videoCached.push_back(indiceMax);
			}else{
				capacity=sizeServer;
			}
		}
		result.push_back(videoCached);
	}
	return result;
}



vector<vector<int>> solveProblemRandom(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber){
	vector<vector<int>> result;
	vector<vector<int>> serverToPoint;
	//foreach server
	for (uint i(0);i<serverNumber;++i){
		vector<int> videoCached;
		vector<int> videoScore(sizeVideos.size(),0);
		vector<int> clients=serverToPoint[i];
		//foreach client
		for(uint j(0);j<clients.size();++j){
			point client(pointsVector[clients[j]]);
			for(uint ii(0);ii<client.videosId.size();++ii){
				videoScore[client.videosId[ii]]+=client.nbRequests[ii];
			}
		}
		uint capacity(0);
		//fill the server
		uint iter(0);
		while(capacity<sizeServer and iter<1000){
			int indice=rand()%videoScore.size();
			if(videoScore[indice]!=0){
				if(sizeVideos[indice]+capacity<=sizeServer){
					capacity+=sizeVideos[indice];
				}else{
					iter++;
				}
			}
		}
		result.push_back(videoCached);
	}
	return result;
}



