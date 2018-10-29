#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	vector<string> vecTimestamp;
	vector<string> vecRequest;
	vector<string> vecRequestDuration;
	vector<pair<string, string>> vecReqAndReqDur;
	ifstream infile("timing2.log");
	if (!infile)
	{
		cout << "Error in opening file !" << endl;
		return -1;
	}
	string line, date, timestamp, threadId, context, request, in, requestDuration, data;
	int iterator = 0, x = 0;
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
		vecRequest.push_back(request);
		vecRequestDuration.push_back(requestDuration);
		vecReqAndReqDur.push_back(make_pair(request, requestDuration));
		cout << "timestamp(vector): " << vecTimestamp[iterator] << endl;
		cout << "request(vector): " << vecRequest[iterator] << endl;
		cout << "requestDuration(vector): " << vecRequestDuration[iterator] << endl;
		cout << "\n\n";
		iterator++;
	}
	infile.close();

	std::sort(vecReqAndReqDur.begin(), vecReqAndReqDur.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});

	for (std::vector<std::pair<std::string, std::string>>::iterator it = vecReqAndReqDur.begin(); it != vecReqAndReqDur.end(); ++it)
	{
		std::stringstream ss;
		ss << ++x;

		std::cout << ((std::pair<std::string, std::string>)(*it)).first
			<< " = "
			<< ((std::pair<std::string, std::string>)(*it)).second
			<< std::endl;
	}


	cout << endl;
	system("pause");
}
