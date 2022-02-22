//Copyright (c) 2022 user1687569
#ifndef _TV_H_
#define _TV_H_
#include <iostream>

// --------------------------------------------
// 这个工程与上一个工程的区别在于，只有一个Remote方法是Tv类的友元
// 而在原来的版本中，所有的Remote方法都是Tv类的友元

// 唯一直接访问Tv成员的Remote方法是 Remote::setchan()
// 因此它是唯一需要作为友元的方法
// --------------------------------------------



// --------------------------------------------
// 正确的排列顺序
// class Tv;       // 前向声明 forward declaration
// class Remote { ... };
// class Tv { ... };
// --------------------------------------------
// 错误的排列顺序
// class Remote;
// class Tv { ... };
// class Remote { ... };
// 错误的原因是：编译器在Tv类的声明中看到Remote的一个方法被声明为Tv类的友元之前，
//              应该先看到 Remote类的声明和 set_chan()方法的声明
// --------------------------------------------




class Tv;   // 前向声明，前向声明使编译器看到Remote类声明中
            // 的友元声明时，知道 Tv 是一种类型


// 除构造函数外，所有的Remote方法都将一个Tv对象引用作为参数，
// 这表明遥控器必须针对特定的电视机
class Remote
{
private:
    int mode;       // controls TV or DVD

public:
    enum State{Off, On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV, DVD};

public:
    Remote(int m = TV) : mode(m) {}
    bool volup(Tv & t);
    bool voldown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_chan(Tv & t, int c);   // 只有 Remote::set_chan()能偶影响Tv的私有成员
    void set_mode(Tv & t);
    void set_input(Tv & t);
};



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
    friend void Remote::set_chan(Tv & t, int c);
    enum State{Off, On};            // 开、关
    enum {MinVal, MaxVal = 20};     // 音量设置
    enum {Antenna, Cable};          // 天线调节模式 还是 有线电视？
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


// 内联函数的链接性是内部的，这意味着函数定义必须在使用函数的文件中
// Remote methods as inline functions
// 也可以将定义放在实现文件中，但必须删除关键字 inline, 这样函数的链接性将是外部的
inline bool Remote::volup(Tv & t) { return t.volup(); }
inline bool Remote::voldown(Tv & t) { return t.voldown(); }
inline void Remote::onoff(Tv & t) { t.onoff(); }
inline void Remote::chanup(Tv & t) { t.chanup(); }
inline void Remote::chandown(Tv & t) { t.chandown(); }
inline void Remote::set_mode(Tv & t) { t.set_mode(); }
inline void Remote::set_input(Tv & t) { t.set_input(); }
inline void Remote::set_chan(Tv & t, int c) { t.channel = c; }




#endif