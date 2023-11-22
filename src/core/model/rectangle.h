#ifndef SEM_PR_RECTANGLE_H
#define SEM_PR_RECTANGLE_H

#include "parallelogram.h"
#include "figure.h"

class Rectangle : Parallelogram {
public:
    Rectangle(double length, double width) : Parallelogram(length, width, 90) {}

    Rectangle(const Point &position, const string &color, double length, double width) : Parallelogram(
            position, color, length, width, 90) {}

    Rectangle() {
        length = genRandomNumber();
        width = genRandomNumber();
        angle = 90;
    }

    Rectangle& operator = (const Rectangle& source) = default;

public:
    string toString() const override {
        nlohmann::json json{};

        json["position"]["x"] = position.getX();
        json["position"]["y"] = position.getY();
        json["color"] = color;
        json["length"] = length;
        json["width"] = width;

        return json.dump();
    }
};

#endif //SEM_PR_RECTANGLE_H
