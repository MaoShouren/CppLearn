#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};
vector<PersonInfo> peoples;
int main() {
	ifstream input_file("b.txt");
	if (!input_file.is_open()) {
		cerr << "can not open b.txt!!!" << endl;
		return 1;
	}
	string line, word;
	while(getline(input_file, line)) {
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		peoples.push_back(info);
	}
	
	for (const auto& content : peoples) {
		cout << content.name << endl;
		for (const auto& phone : content.phones) {
			cout << phone << endl;
		}
	}
	return 1;
}
