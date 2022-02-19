//Copyright (c) 2022 user1687569
#ifndef _DMAABC_H_
#define _DMAABC_H_
#include <iostream>
#include <string>

class DMAABC
{
private:
    char * label;
    int rating;

public:
    DMAABC(const char * l = "null", int r = 0);
    DMAABC(const DMAABC & dmaABC);
    virtual ~DMAABC();
    DMAABC & operator=(const DMAABC & dmaABC);
    virtual void View() = 0;
};


class baseDMA : public DMAABC
{
public:
    baseDMA(const char * l = "null", 
            int r = 0) : DMAABC(l, r) {}
    baseDMA(const baseDMA & rs) : DMAABC(rs) {}
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    virtual void View();
};


class lacksDMA : public DMAABC
{
private:
    enum {COLOR_LEN = 40};
    char color[COLOR_LEN];

public:
    lacksDMA(const char * c = "blank",
             const char * l = "null",
             int r = 0);
    lacksDMA(const char * c, const DMAABC & rs);
    lacksDMA(const lacksDMA & rs);
    virtual ~lacksDMA();
    lacksDMA & operator=(const lacksDMA & rs);
    virtual void View();
};


class hasDMA : public DMAABC
{
private:
    char * style;

public:
    hasDMA(const char * s = "none",
           const char * l = "null",
           int r = 0);
    hasDMA(const char * s, const DMAABC & rs);
    hasDMA(const hasDMA & hs);
    virtual ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    virtual void View();
};


#endif