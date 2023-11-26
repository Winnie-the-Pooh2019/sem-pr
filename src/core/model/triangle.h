#ifndef SEM_PR_TRIANGLE_H
#define SEM_PR_TRIANGLE_H

#include "figure.h"
#include "cmath"
#include "nlohmann/json.hpp"

class Triangle : public Figure {
    double firstSide;
    double secondSide;
    double thirdSide;
    double firstSecondAngle;
    double firstThirdAngle;

public:
    Triangle() : Figure() {
        double first = genRandomNumber(10, 20);
        double second = genRandomNumber();
        double third = genRandomNumber();

        while (first <= (second + third)) {
            second = genRandomNumber();
            third = genRandomNumber();
        }

        firstSide = first;
        secondSide = second;
        thirdSide = third;

        firstSecondAngle = std::acos((firstSide * firstSide + secondSide * secondSide - thirdSide * thirdSide)
                                     / (2 * firstSide * secondSide));
        firstThirdAngle = std::acos((firstSide * firstSide + thirdSide * thirdSide - secondSide * secondSide)
                                    / (2 * firstSide * thirdSide));
    }

    Triangle(double first, double second, double third) : Figure() {
        firstSide = first;
        secondSide = second;
        thirdSide = third;

        firstSecondAngle = std::acos((firstSide * firstSide + secondSide * secondSide - thirdSide * thirdSide)
                                     / (2 * firstSide * secondSide));
        firstThirdAngle = std::acos((firstSide * firstSide + thirdSide * thirdSide - secondSide * secondSide)
                                    / (2 * firstSide * thirdSide));
    }

    Triangle(const Triangle& source) : Figure(source) {
        firstSide = source.firstSide;
        secondSide = source.secondSide;
        thirdSide = source.thirdSide;
        firstSecondAngle = source.firstSecondAngle;
        firstThirdAngle = source.firstThirdAngle;
    }

    double getSquare() const override {
        return secondSide * std::sin(firstSecondAngle) * firstSide / 2;
    }

    string toString() const override {
        nlohmann::json json{};

        json["type"] = "circle";
        json["object"]["position"]["x"] = position.getX();
        json["object"]["position"]["y"] = position.getY();
        json["object"]["color"] = color;
        json["object"]["firstSide"] = firstSide;
        json["object"]["secondSide"] = secondSide;
        json["object"]["thirdSide"] = thirdSide;
        json["object"]["firstSecondAngle"] = firstSecondAngle;
        json["object"]["firstThirdAngle"] = firstThirdAngle;

        return json.dump();
    }
};

#endif //SEM_PR_TRIANGLE_H
