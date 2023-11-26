//
// Created by ivan on 11/17/23.
//

#ifndef SEM_PR_POINT_H
#define SEM_PR_POINT_H

class Point {
private:
    int x;
    int y;

public:
    Point() {
        this->x = 0;
        this->y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    Point(const Point& point) {
        this->x = point.x;
        this->y = point.y;
    }

    Point& operator = (const Point& point) {
        this->y = point.y;
        this->x = point.x;

        return *this;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }
};

#endif //SEM_PR_POINT_H
