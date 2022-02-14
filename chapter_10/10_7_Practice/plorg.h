//Copyright (c) 2022 user1687569
#ifndef _PLORG_H_
#define _PLORG_H_

class Plorg
{
private:
    static const int Len = 20;
    char m_name[Len];
    int m_CI;

public:
    Plorg(const int ci, const char * name = "Plorga");
    void setCi(const int ci);
    void showPlorg() const;
};


#endif