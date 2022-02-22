//Copyright (c) 2022 user1687569
#ifndef _TV_H_
#define _TV_H_
#include <iostream>

// 遥控器 Romote类提到了 电视机 Tv类，
// 所以编译器必须了解Tv类后，才能处理Remote类
// 为此，最简单的方法是首先定义Tv类，也可以使用前向声明

// 友元类的所有方法都可以访问原始类的私有成员和保护成员。
// 在这里，Tv是原始类，Remote是友元类，
// Remote中的所有方法可以访问Tv类中的私有成员和保护成员
class Tv
{
private:
    int state;          // on or off
    int volume;         // assumed to be digitized
    int maxchannel;     // maximum number of channels
    int channel;        // current channel setting
    int mode;           // broadcast/atenna or cable
    int input;          // TV or DVD

public:
    friend class Remote;
    enum {Off, On};                 // 开、关
    enum {MinVal, MaxVal = 20};     // 音量设置
    enum {Antenna, Cable};           // 天线调节模式 还是 有线电视？
    enum {TV, DVD};                 // TV调谐 或 A/V输入

    Tv(int s = Off, int mc = 125) 
        : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
    void onoff() { state = (state == On) ? Off : On; }
    bool ison() const { return state == On; }
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void set_input() { input = (input == TV) ? DVD : TV; }
    void settings() const;
};


// 除构造函数外，所有的Remote方法都将一个Tv对象引用作为参数，
// 这表明遥控器必须针对特定的电视机
class Remote
{
private:
    int mode;       // controls TV or DVD
public:
    Remote(int m = Tv::TV) : mode(m) {}
    bool volup(Tv & t)  { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t)  { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t)   { t.chandown(); }
    void set_chan(Tv & t, int c)  { t.channel = c; }
    void set_mode(Tv & t)   { t.set_mode(); }
    void set_input(Tv & t)  { t.set_input(); } 
    ~Remote() {}
};


#endif