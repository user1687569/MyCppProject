//Copyright (c) 2022 user1687569
#ifndef _CD_H_
#define _CD_H_
#include <iostream>
#include <string>

class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd();
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};


class Classic : public Cd
{
private:
    char cdInfo[100];

public:
    Classic();
    Classic(char * info, char * s1, char * s2, int n, double x);
    Classic(char * info, const Cd & d);
    ~Classic();
    virtual void Report() const;
    Classic & operator=(const Classic & classicCd);
};


#endif