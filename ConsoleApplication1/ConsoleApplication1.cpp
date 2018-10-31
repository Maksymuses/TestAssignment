#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main() {
	vector<string> vecTimestamp, aveReq, topReq;
	vector<int> average, topAve;
	vector<pair<string, string>> vecReqAndReqDur;
	string line, date, timestamp, threadId, context, request, in, requestDuration, data;
	int iterator = 0, x = 0, strToInt = 0, sum = 0, n = 0, total = 0, aveTotal = 0;

	ifstream infile("timing.log");
	if (!infile)
	{
		cout << "Error in opening file !" << endl;
		return -1;
	}
	
	while (getline(infile, line))
	{
		istringstream read(line);
		read >> date >> timestamp >> threadId >> context >> request;
		if (request[0] == '/') {
			read >> in >> requestDuration;
		}
		else {
			read >> data >> in;
			if (in[0] == 't') {
				read >> in >> requestDuration;
			}
		}
		vecTimestamp.push_back(timestamp);
		vecReqAndReqDur.push_back(make_pair(request, requestDuration));
		iterator++;
		cout << iterator << endl;
	}
	infile.close();

	sort(vecReqAndReqDur.begin(), vecReqAndReqDur.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	/*for (vector<pair<string, string>>::iterator it = vecReqAndReqDur.begin(); it != vecReqAndReqDur.end(); ++it)
	{
		stringstream ss;
		ss << ++x;

		cout << ((pair<string, string>)(*it)).first
			<< " = "
			<< ((pair<string, string>)(*it)).second
			<< endl;
	}*/

	int j = 0, vRARD = (vecReqAndReqDur.size() - 1);

	for (vector<pair<string, string>>::iterator it = vecReqAndReqDur.begin(); it != vecReqAndReqDur.end(); ++it)
	{
		strToInt = atoi(((pair<string, string>)(*it)).second.c_str());
		if (((pair<string, string>)(*it)).first == ((pair<string, string>)(*(it+1))).first && j < vRARD)
		{
			sum = sum + strToInt;
			total = total + strToInt;
		}
		if (((pair<string, string>)(*it)).first != ((pair<string, string>)(*(it+1))).first && j < vRARD)
		{
			sum = sum + strToInt;
			average.push_back(sum / 2); //проблема 1 элемента
			aveReq.push_back(((pair<string, string>)(*it)).first);
			sum = 0;
		}
		if (j == vRARD || j == vecReqAndReqDur.size())
		{
			if (((pair<string, string>)(*it)).first == ((pair<string, string>)(*(it - 1))).first) 
			{
				sum = sum + strToInt;
				total = total + strToInt;
				if (j == vecReqAndReqDur.size()) 
				{
					sum = sum + strToInt;
					average.push_back(sum / 2); //проблема 1 элемента
					aveReq.push_back(((pair<string, string>)(*it)).first);
					sum = 0;
				}
			}
			if (((pair<string, string>)(*it)).first != ((pair<string, string>)(*(it - 1))).first) 
			{
				sum = sum + strToInt;
				average.push_back(sum / 2); //проблема 1 элемента
				aveReq.push_back(((pair<string, string>)(*it)).first);
				sum = 0;
			}
		}
		j++;
	}

	aveTotal = total / vecReqAndReqDur.size();

	for (iterator = 0; iterator < average.size(); iterator++) {
		if (average[iterator] > aveTotal) {
			topAve.push_back(average[iterator]);
			topReq.push_back(aveReq[iterator]);
			n++;
		}
	}

	for (iterator = 0; iterator < topReq.size(); iterator++) {
		cout << "topReq - " << topReq[iterator] << endl;
		cout << "topAve - " << topAve[iterator] << endl;
	}
	
	cout << endl;
	system("pause");
}
