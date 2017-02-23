/*
 * utils.cpp
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

#include "solve.h"
#include "parser.h"
#include "utils.h"

void printSolution(FILE* file, vector<vector<int>>& result){

	fprintf(file, "%d\n", result.size());
	for (int oneServer = 0; oneServer<result.size(); oneServer++){
		fprintf(file, "%d ", oneServer);
		for (int oneVideo = 0; oneVideo<result[oneServer].size(); oneVideo++){
			fprintf(file, "%d ", result[oneServer][oneVideo]);
		}
		fprintf(file, "\n");
	}

}




void checkSolution(vector<vector<int>>& result, vector<int> sizesVideo, int maxSize){

	for (int oneServer = 0; oneServer<result.size(); oneServer++){
		int totalSize = 0;
		for (int oneVideo = 0; oneVideo<result[oneServer].size(); oneVideo++){
			totalSize += sizesVideo[oneVideo];
		}

		if (totalSize > maxSize){
			printf("Error: server %d has too much video (max %d, actual %d)\n", oneServer, maxSize, totalSize);
			exit(-1);
		}
	}
}

int getScore(vector<vector<int>>& result, vector<struct point>& endPoints){

	int score = 0;

	//For all endpoint
	for (int oneEndPoint = 0; oneEndPoint < endPoints.size(); oneEndPoint++){
		int latencyToDataCenter = endPoints[oneEndPoint].dataCenterLatency;

		//For all request from this endpoint
		for (int oneRequest = 0; oneRequest < endPoints[oneEndPoint].idServers.size(); oneRequest++){
			int videoID = endPoints[oneEndPoint].videosId[oneRequest];
			int videoNBRequest = endPoints[oneEndPoint].nbRequests[oneRequest];

			int minLatency = latencyToDataCenter;
			for (int oneConnectedServer = 0; oneConnectedServer < endPoints[oneEndPoint].idServers.size(); oneConnectedServer++){
				int serverId = endPoints[oneEndPoint].idServers[oneConnectedServer];
				int serverLatency = endPoints[oneEndPoint].latencyToServers[oneConnectedServer];

				bool serverContainsVideo = false;
				for (int oneVideoInServer = 0; oneVideoInServer<result[serverId].size(); oneVideoInServer++){
					serverContainsVideo = true;
					break;
				}

				if (serverContainsVideo)
					if (serverLatency<minLatency)
						minLatency = serverLatency;

			}

			//We compute the local score
			int localScore = (latencyToDataCenter - minLatency)*1000*videoNBRequest;
			score += localScore;
		}
	}
}




