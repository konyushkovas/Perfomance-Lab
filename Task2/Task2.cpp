#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};


int determinePosition(const Point& center, double radius, const Point& point) {
    double distSquared = pow(point.x - center.x, 2) + pow(point.y - center.y, 2);
    double radiusSquared = pow(radius, 2);

    if (distSquared < radiusSquared) {
        return 1; 
    }
    else if (distSquared == radiusSquared) {
        return 0; 
    }
    else {
        return 2;
    }
}

int main() {

    string circleFilePath = "circle.txt";
    string pointsFilePath = "points.txt";


    ifstream circleFile(circleFilePath);
    if (!circleFile) {
        cerr << "Error opening file: " << circleFilePath << endl;
        return 1;
    }

 
    Point center;
    double radius;
    circleFile >> center.x >> center.y >> radius;
    circleFile.close();


    ifstream pointsFile(pointsFilePath);
    if (!pointsFile) {
        cerr << "Error opening file: " << pointsFilePath << endl;
        return 1;
    }


    vector<Point> points;
    Point point;
    while (pointsFile >> point.x >> point.y) {
        points.push_back(point);
    }
    pointsFile.close();


    for (const auto& pt : points) {
        cout << determinePosition(center, radius, pt) << endl;
    }

    return 0;
}
