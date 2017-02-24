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

#include "utils.h"

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


bool comparatorConnectivity (pair<int,int> A, pair<int,int> B) { return (A.second>B.second); }



vector<vector<int>> solveProblem(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber, const vector<vector<int>>& serverToPoint){
	vector<vector<int>> result;
	//~ cout<<sizeServer<<endl;
	//foreach server
	for (int i(0);i<serverNumber;++i){
		//~ cout<<"i"<<i<<endl;
		vector<int> videoCached;
		vector<int> videoScore(sizeVideos.size(),0);
		vector<int> clients=serverToPoint[i];
		//foreach client
		for(uint j(0);j<clients.size();++j){
			//~ cout<<"j"<<j<<endl;
			point client(pointsVector[clients[j]]);
			for(uint ii(0);ii<client.videosId.size();++ii){
				videoScore[client.videosId[ii]]+=client.nbRequests[ii];
			}
		}
		//compute video score
		for(uint iii(0);iii<videoScore.size();++iii){
			//~ cout<<"iiii"<<iii<<endl;
			videoScore[iii]/=sizeVideos[iii];
		}
		int capacity(0);
		//fill the server
		while(capacity<sizeServer){
			//~ cout<<"lol"<<endl;
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



vector<vector<int>> solveProblemRandom(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber, const vector<vector<int>>& serverToPoint){
	vector<vector<int>> result;
	//~ //foreach server
	for (int i(0);i<serverNumber;++i){
		vector<int> videoCached;
		vector<int> videodispo;
		vector<int> clients=serverToPoint[i];
		//foreach client
		for(uint j(0);j<clients.size();++j){
			point client(pointsVector[clients[j]]);
			for(uint ii(0);ii<client.videosId.size();++ii){
				videodispo.push_back(client.videosId[ii]);
			}
		}
		sort( videodispo.begin(), videodispo.end() );
		videodispo.erase( unique( videodispo.begin(), videodispo.end() ), videodispo.end() );
		int capacity(0);
		//fill the server
		while(capacity<sizeServer and (not videodispo.empty())){
			int indice=rand()%videodispo.size();
			if(sizeVideos[indice]+capacity<=sizeServer){
				capacity+=sizeVideos[indice];
				videoCached.push_back(videodispo[indice]);
				videodispo.erase(videodispo.begin()+indice);
			}else{
				videodispo.erase(videodispo.begin()+indice);
			}
		}
		result.push_back(videoCached);
	}
	return result;
}


vector<vector<int>> solveProble2ouf(const vector<int>& sizeVideos,  const vector<point>& pointsVector, int sizeServer, int serverNumber, const vector<vector<int>>& serverToPoint){
	vector<vector<int>> result;
	result.resize(serverNumber);
	vector<pair<int,int>> serverConnectivity(serverNumber);
	for(int i(0);i<serverNumber;++i){
		serverConnectivity[i].first=i;
	}
	for(int i(0);i<pointsVector.size();++i){
		for(int j(0);j<pointsVector[i].idServers.size();++j){
			serverConnectivity[pointsVector[i].idServers[j]].second++;
		}
	}
	sort(serverConnectivity.begin(),serverConnectivity.end(),comparatorConnectivity);
	//foreach server
	#pragma omp parallel for
	for (int i = 0;i<serverConnectivity.size();++i){
		cout << "Server " << i << "/" << serverConnectivity.size() << endl;
		vector<int> videoLoaded;
		vector<pair<int,int>> videoScore;
		for (int oneVideo=0; oneVideo<sizeVideos.size(); oneVideo++){
			videoScore.push_back({oneVideo, 0});
		}
		set<int> videoSet;
		vector<int> clients=serverToPoint[i];
		for (int j(0);j<clients.size();++j){//LOL PUT J
			point client(pointsVector[clients[j]]);
			for(uint ii(0);ii<client.videosId.size();++ii){
				videoSet.insert(client.videosId[ii]);
			}
		}
		vector<int> videoVector({});
		for(auto video : videoSet) {
			videoVector.push_back(video);
		}
		#pragma omp parallel for
		for(auto oneVideo = 0; oneVideo<videoVector.size(); oneVideo++) {
			auto video = videoVector[oneVideo];
			int score(0);
			for(uint ii(0);ii<clients.size();++ii){
				int bestLatence = getScoreVideoEndPoint(video, ii, pointsVector, result);
				int latence;
				point client(pointsVector[clients[ii]]);
				for(uint id(0);id<client.idServers.size();++id){
					if(client.idServers[id]==i){
						latence=client.latencyToServers[id];
					}
				}
				int nbrequest;
				for(uint id(0);id<client.videosId.size();++id){
					if(client.videosId[id]==video){
						nbrequest=client.nbRequests[id];
					}
				}
				if(latence<bestLatence){
					score+=(bestLatence-latence)*nbrequest;
				}
			}
			videoScore[video].second = score/sizeVideos[videoScore[video].first];

		}
		sort(videoScore.begin(),videoScore.end(),comparatorConnectivity);
		int freespace(sizeServer);

		for(uint indVideoScore(0);indVideoScore<videoScore.size();++indVideoScore){
			int indiceVideo(videoScore[indVideoScore].first);
			int weight(sizeVideos[indiceVideo]);
			if(weight<=freespace){
				videoLoaded.push_back(indiceVideo);
				freespace-=weight;
			}
		}
		result[i]=videoLoaded;
	}
	return result;
}



