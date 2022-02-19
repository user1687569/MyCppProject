//Copyright (c) 2022 user1687569
#include <cstring>
#include "dmaABC.h"

DMAABC::DMAABC(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}


DMAABC::DMAABC(const DMAABC & dmaABC)
{
    label = new char[std::strlen(dmaABC.label) + 1];
    std::strcpy(label, dmaABC.label);
    rating = dmaABC.rating;
}


DMAABC::~DMAABC()
{
    delete [] label;
}


DMAABC & DMAABC::operator=(const DMAABC & dmaABC)
{
    if(this == &dmaABC)
        return *this;
    delete [] label;
    label = new char[std::strlen(dmaABC.label) + 1];
    std::strcpy(label, dmaABC.label);
    rating = dmaABC.rating;
    
    return *this;
}


void DMAABC::View()
{
    std::cout << "Label: " << label << std::endl;
    std::cout << "Rating: " << rating << std::endl;
}


baseDMA::~baseDMA()
{
}


baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
        return *this;

    DMAABC::operator=(rs);    
    return *this;
}


void baseDMA::View()
{
    DMAABC::View();
}


lacksDMA::lacksDMA(const char * c, const char * l, int r)
    : DMAABC(l, r)
{
    std::strncpy(color, c, 39);
    color[39] = '\0';
}


lacksDMA::lacksDMA(const char * c, const DMAABC & dmaABC)
    : DMAABC(dmaABC)
{
    std::strncpy(color, c, COLOR_LEN - 1);
    color[COLOR_LEN - 1] = '\0';
}


lacksDMA::lacksDMA(const lacksDMA & rs)
    : DMAABC(rs) 
{
    std::strncpy(color, rs.color, COLOR_LEN - 1);
    color[COLOR_LEN - 1] = '\0';
}


lacksDMA::~lacksDMA()
{
}


lacksDMA & lacksDMA::operator=(const lacksDMA & rs)
{
    if(this == &rs)
        return *this;
    
    DMAABC::operator=(rs);
    strcpy(color, rs.color);
    return *this;
}


void lacksDMA::View()
{
    DMAABC::View();
    std::cout << "Color: " << color << std::endl;
}


hasDMA::hasDMA(const char * s, const char * l, int r)
    : DMAABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}


hasDMA::hasDMA(const char * s, const DMAABC & dmaABC)
    : DMAABC(dmaABC)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}


hasDMA::hasDMA(const hasDMA & hs)
    : DMAABC(hs)
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}


hasDMA::~hasDMA()
{
    delete [] style;
}


hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if(this == &hs)
        return *this;
    DMAABC::operator=(hs);
    
    delete [] style;
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);

    return *this;
}


void hasDMA::View()
{
    DMAABC::View();
    std::cout << "Style: " << style << std::endl;
}


