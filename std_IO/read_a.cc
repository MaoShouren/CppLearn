#include <iostream>
#include <fstream>
#include <vector>

int main() {
	std::vector<std::string> v_1;
	std::ifstream input_file("a.txt");
	if(!input_file.is_open()) {
		std::cout << "can not open file!!!" << std::endl;
		return 1;	
	}
	std::string line;
	while (std::getline(input_file, line)) {
		v_1.push_back(line);
	}
	input_file.close();

	for (const auto& content : v_1) {
		std::cout << content << std::endl;
	}
	return 0;
}


