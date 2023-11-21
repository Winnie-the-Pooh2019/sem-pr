#ifndef SEM_PR_CIRCLE_H
#define SEM_PR_CIRCLE_H

#include "figure.h"
#include "cmath"
#include "nlohmann/json.hpp"

class Circle : public Figure {
protected:
    double radius;

public:
    Circle() : Figure() {
        radius = genRandomNumber();
    }

    explicit Circle(double radius) : radius(radius) {}

public:
    double getSquare() const override {
        return radius * radius * M_PI;
    }

    string toString() const override {
        nlohmann::json json{};

        json["type"] = "circle";
        json["object"]["position"]["x"] = position.getX();
        json["object"]["position"]["y"] = position.getY();
        json["object"]["color"] = color;
        json["object"]["radius"] = radius;

        return json.dump();
    }
};

#endif //SEM_PR_CIRCLE_H
