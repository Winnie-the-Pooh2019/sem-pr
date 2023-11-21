#include <iostream>
#include "string"
#include "src/core/model/circle.h"
#include "ctime"

using namespace std;

class Person {
public:
    string name;
    int age;
};

int main() {
    srand(time(nullptr));

    Circle one{};
    Circle two{};

    cout << one << " < " << two << " = " << (one < two) << endl;

    return 0;
}
