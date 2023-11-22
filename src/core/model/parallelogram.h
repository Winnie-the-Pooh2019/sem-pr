#ifndef SEM_PR_PARALLELOGRAM_H
#define SEM_PR_PARALLELOGRAM_H

#include "figure.h"
#include "cmath"
#include "nlohmann/json.hpp"

class Parallelogram : public Figure {
protected:
    double length;
    double width;
    double angle;

public:
    Parallelogram(double length, double width, double angle) : length(length), width(width), angle(angle) {}

    Parallelogram(const Point& position, const string &color, double length, double width, double angle) : Figure(
            position, color) {
        this->length = length;
        this->width = width;
        this->angle = angle;
    }

    Parallelogram() {
        length = genRandomNumber();
        width = genRandomNumber();
        angle = genRandomNumber(M_PI * 15 / 180, M_PI * 70 / 180);
    }

    Parallelogram& operator = (const Parallelogram& source) = default;

    double getLength() const {
        return length;
    }

    void setLength(double length) {
        Parallelogram::length = length;
    }

    double getWidth() const {
        return width;
    }

    void setWidth(double width) {
        Parallelogram::width = width;
    }

    double getAngle() const {
        return angle;
    }

    void setAngle(double angle) {
        Parallelogram::angle = angle;
    }

public:
    double getSquare() const override {
        return length * sin(angle) * width;
    }

    string toString() const override {
        nlohmann::json json{};

        json["type"] = "parallelogram";
        json["object"]["position"]["x"] = position.getX();
        json["object"]["position"]["y"] = position.getY();
        json["object"]["color"] = color;
        json["object"]["length"] = length;
        json["object"]["width"] = width;
        json["object"]["angle"] = angle;

        return json.dump();
    }
};

#endif //SEM_PR_PARALLELOGRAM_H
