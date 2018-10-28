#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void show(const string &str)
{
	cout << str << endl;
}

int main() {
	vector<string> vecTimestamp;
	vector<string> vecRequest;
	vector<int> vecRequestDuration;
	vector<pair<string, int>> vecRequestAndRequestDuration;
	ifstream infile("timing.log");
	if (!infile)
	{
		cout << "Error in opening file !" << endl;
		return -1;
	}
	string line, date, timestamp, threadId, context, request, in;
	int iterator = 0, x = 0, requestDuration;
	while (getline(infile, line))
	{
		istringstream read(line);
		read >> date >> timestamp >> threadId >> context >> request >> in >> requestDuration;
		cout << "date: " << date << endl;
		cout << "timestamp: " << timestamp << endl;
		cout << "threadId: " << threadId << endl;
		cout << "context: " << context << endl;
		cout << "request: " << request << endl;
		cout << in << endl;
		cout << "requestDuration: " << requestDuration << endl;
		cout << "\n\n";
		vecTimestamp.push_back(timestamp);
		vecRequest.push_back(request);
		vecRequestDuration.push_back(requestDuration);
		vecRequestAndRequestDuration.push_back(make_pair(request, requestDuration));
		cout << "timestamp(vector): " << vecTimestamp[iterator] << endl;
		cout << "request(vector): " << vecRequest[iterator] << endl;
		cout << "requestDuration(vector): " << vecRequestDuration[iterator] << endl;
		cout << "\n\n";
		iterator++;
	}
	infile.close();
	//sort(vecRequest.begin(), vecRequest.end());

	std::sort(vecRequestAndRequestDuration.begin(), vecRequestAndRequestDuration.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	//for_each(vecRequestAndRequestDuration.begin(), vecRequestAndRequestDuration.end(), show);


	cout << endl;
	system("pause");
}
