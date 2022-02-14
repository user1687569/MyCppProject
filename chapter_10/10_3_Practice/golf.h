//Copyright (c) 2022 user1687569
#ifndef _GOLF_H_
#define _GOLF_H_


class Golf
{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;

public:
    Golf() {}
    Golf(const char * name, int hc);
    Golf & setGolf(int & result);
    void setHandicap(int & hc);
    void showgolf() const;
};


#endif