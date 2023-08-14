#include <iostream>
#include <fstream>
#include <vector>
int main() {
    std::ifstream inputFile("filename.txt"); // 替换成你的文件名

    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件" << std::endl;
        return 1;
    }

    std::vector<std::string> lines; // 存储文件内容的vector

    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close(); // 关闭文件

    // 现在 lines 含有文件的每一行内容

    for (const auto& content : lines) {
        std::cout << content << std::endl;
    }

    return 0;
}
