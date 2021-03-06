#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> vecTimestamp;
	vector<string> vecRequest;
	vector<string> vecRequestDuration;
	ifstream infile("timing.log");
	if (!infile)
	{
		cout << "Error in opening file !" << endl;
		return -1;
	}
	string line, date, timestamp, threadId, context, request, in, requestDuration;
	int iterator = 0;
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
		cout << "timestamp(vector): " << vecTimestamp[iterator] << endl;
		cout << "request(vector): " << vecRequest[iterator] << endl;
		cout << "requestDuration(vector): " << vecRequestDuration[iterator] << endl;
		cout << "\n\n";
	}

	infile.close();
	cout << endl;
	system("pause");
}
