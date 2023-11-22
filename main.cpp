#include <iostream>
#include "string"
#include "src/core/model/circle.h"
#include "ctime"
#include "src/core/utils/vector.h"

using namespace std;

class Person {
public:
    string name;
    int age;
};

int main() {
    srand(time(nullptr));

    Vector<Circle> vector{};

    Circle one{};
    Circle two{};

    cout << one << " < " << two << " = " << (one < two) << endl;

    return 0;
}
