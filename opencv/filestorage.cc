#include <opencv2/core/core.hpp>
int main() {
    std::string strSettingsFile = "/home/wangchao/code/github_code/VIDO-SLAM/src/realtime_demo/../config/kaist_config.yaml";  // 替换为您的文件路径

    cv::FileStorage fsSettings(strSettingsFile.c_str(), cv::FileStorage::READ);

    return 0;
}
