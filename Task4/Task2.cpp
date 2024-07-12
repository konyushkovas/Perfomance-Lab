#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> nums = {};
    int numberOfElements;
    cout << "Введите количество элементов: ";
    cin >> numberOfElements;

    for (int i = 0; i < numberOfElements; ++i) {
        int value;
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> value;
        nums.push_back(value);
    }

    double sum = 0.0;
    for (int n : nums)
        sum += n;

    sum /= nums.size();

    int to = static_cast<int>(sum);
    sum -= to;

    if (sum > 0.5)
        to++;

    int res = 0;
    for (int n : nums)
        res += abs(n - to);

    cout << res;
}
