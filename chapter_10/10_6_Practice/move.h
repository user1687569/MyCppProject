//Copyright (c) 2022 user1687569
#ifndef _MOVE_H_
#define _MOVE_H_

class Move
{
private:
    double x;
    double y;

public:
    Move(double a = 0, double b = 0);
    void showmove() const;
    // double getX() const;
    // double getY() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};


#endif