#include <iostream>
#include <fstream>
#include <unordered_map>
#include "json.hpp"
#include <string>

using json = nlohmann::json;
using namespace std;
void updateValues(json& tests, const std::unordered_map<int, string>& valueMap) {
    for (auto& test : tests) {
        int id = test["id"];
        if (valueMap.find(id) != valueMap.end()) {
            test["value"] = valueMap.at(id);
        }
        if (test.contains("values")) {
            updateValues(test["values"], valueMap);
        }
    }
}

int main() {
    std::ifstream valuesFile("values.json");
    std::ifstream testsFile("tests.json");

    if (!valuesFile.is_open() || !testsFile.is_open()) {
        std::cerr << "Error opening file(s)" << std::endl;
        return 1;
    }
    
    json valuesData;
    json testsData;

    valuesFile >> valuesData;
    testsFile >> testsData;

    std::unordered_map<int, string> valueMap;
    for (const auto& valueObj : valuesData["values"]) {
        int id = valueObj["id"];
        string value = valueObj["value"];
        valueMap[id] = value;
    }

    updateValues(testsData["tests"], valueMap);

    std::ofstream reportFile("report.json");
    reportFile << std::setw(2) << testsData << std::endl;

    std::cout << "Values updated successfully!" << std::endl;

    return 0;
}
