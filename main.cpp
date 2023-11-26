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

    vector.add(one);
    vector.add(two);

    for (int i = 0; i < 10; i++) {
        Circle c{};
        vector.add(c);
    }

    Vector<Circle> v{};

    v.add(one);
    v.add(&vector);

    cout << "\n\n";
    for (int i = 0; i < v.length(); i++) {
        cout << v[i] << endl;
    }

    cout << "\n\n";
    v.add(two, 1);

    for (int i = 0; i < v.length(); i++) {
        cout << v[i] << endl;
    }

    cout << "VECTOR: size = " << v.length() << " capacity = " << v.capacity;

    v.removeByIndex(1);

    cout << "\n\n";
    for (int i = 0; i < v.length(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
