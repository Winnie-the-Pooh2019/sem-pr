//
// Created by ivan on 11/17/23.
//

#ifndef SEM_PR_FIGURE_H
#define SEM_PR_FIGURE_H

#include "point.h"
#include "string"
#include "sstream"
#include "random"

using namespace std;

class Figure {
protected:
    Point position;
    string color;

public:
    Figure() {
        color = generateColor();
    }

    Figure(Point position, string color) {
        this->color = color;
        this->position = position;
    }

    Figure(int x, int y, string color) {
        this->position = Point(x, y);
        this->color = color;
    }

    Figure(int x, int y, int red, int green, int blue) {
        this->position = Point(x, y);
        this->color = rgbToHex(red, green, blue);
    }

    const Point getPosition() const {
        return position;
    }

    void setPosition(Point position) {
        Figure::position = position;
    }

    void changeRandomColor() {
        this->color = generateColor();
    }

    bool operator == (const Figure& other) const {
        return getSquare() == other.getSquare();
    }

    bool operator != (const Figure& other) const {
        return getSquare() != other.getSquare();
    }

    bool operator > (const Figure& other) const {
        return getSquare() > other.getSquare();
    }

    bool operator >= (const Figure& other) const {
        return getSquare() >= other.getSquare();
    }

    bool operator < (const Figure& other) const {
        return getSquare() < other.getSquare();
    }

    bool operator <= (const Figure& other) const {
        return getSquare() <= other.getSquare();
    }

    friend std::ostream& operator << (std::ostream& stream, const Figure& figure) {
        stream << figure.toString();
        return stream;
    }

    virtual double getSquare() const = 0;

    virtual string toString() const = 0;

protected:
    static string generateColor() {
        string res;
        char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        for (int i = 0; i < 6; i++)
            res += hex[rand() % 16];

        return res;
    }

    static string rgbToHex(int red, int green, int blue) {
        stringstream ss;

        ss << hex << (red << 16 | green << 8 | blue);

        return ss.str();
    }

    static double genRandomNumber(double min = 5, double max = 15) {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> distribution(min, max);

        return distribution(gen);
    }
};

#endif //SEM_PR_FIGURE_H
