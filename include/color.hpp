#ifndef COLOR_HPP
#define COLOR_HPP

/* If we are we on Windows, we want a single define for it.*/
#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__MINGW32__))
#define _WIN32 //for both 32 and 64 bit. use _WIN64 for 64 bit only
#endif // _WIN32 

#if defined(__GNUC__) || defined(unix) || defined(__unix__) || defined(__unix)
# define _UNIX 
#endif // _UNIX

// in the name of God the most compassionate the most merciful

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <type_traits>
#include <utility>

#ifdef _WIN32
    #include <windows.h>
#endif // _WIN32

// TODO: 
// Refactor everything! and tidy things up! 

// ANSI color escape codes 
// the 8bit color codes, for foreground start with 30, and for background they start with 40
// so \u001b[37m gives you a foreground Gray color, while \u001b[47m will give you the background
// color of gray!

// color ref https://ss64.com/nt/syntax-ansi.html
// https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html
// todo: https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences

// todo : move into hue namespace so it
#define BOLD	        "\u001b[1m"
#define UNDERLINE	    "\u001b[4m"
#define NO_UNDERLINE	"\u001b[24m"
#define REVERSE_TEXT	"\u001b[7m"
#define POSITIVE_TEXT	"\u001b[27m"

#define DEFAULT "\u001b[0m"
#define BLACK   "\u001b[30m"
#define RED     "\u001b[31m"
#define GREEN   "\u001b[32m"
#define YELLOW  "\u001b[33m"
#define BLUE    "\u001b[34m"
#define PURPLE  "\u001b[35m"
#define CYAN    "\u001b[36m"
#define GRAY    "\u001b[90m"
#define WHITE   "\u001b[97m"

#define BK_BLACK   "\u001b[40m"
#define BK_RED     "\u001b[41m"
#define BK_GREEN   "\u001b[42m"
#define BK_YELLOW  "\u001b[43m"
#define BK_BLUE    "\u001b[44m"
#define BK_PURPLE  "\u001b[45m"
#define BK_CYAN    "\u001b[46m"
#define BK_GRAY    "\u001b[47m"
#define BK_WHITE   "\u001b[107m"

#define LIGHT_RED     "\u001b[91m"
#define LIGHT_GREEN   "\u001b[92m"
#define LIGHT_YELLOW  "\u001b[93m"
#define LIGHT_BLUE    "\u001b[94m"
#define LIGHT_PURPLE  "\u001b[95m"
#define LIGHT_CYAN    "\u001b[96m"
#define LIGHT_GRAY    "\u001b[97m"
#define LIGHT_WHITE   "\u001b[97m"

#define BK_LIGHT_RED     "\u001b[101m"
#define BK_LIGHT_GREEN   "\u001b[102m"
#define BK_LIGHT_YELLOW  "\u001b[103m"
#define BK_LIGHT_BLUE    "\u001b[104m"
#define BK_LIGHT_PURPLE  "\u001b[105m"
#define BK_LIGHT_CYAN    "\u001b[106m"
#define BK_LIGHT_GRAY    "\u001b[100m"
#define BK_WHITE         "\u001b[107m"

// For the 256 colors, the background color starts from 48! while the forground starts with 38
#define ORANGE_C256     "\u001b[38;5;202m" // this is a 256 color mode. The previous 8 bit colors are usually supported by all terminals. The 256 are not
#define BK_PURPLE_C256  "\u001b[48;5;90m"

//resets the color codes 
#define RESET "\u001b[0m"


namespace hue
{
    constexpr int DEFAULT_COLOR = 7;
    constexpr int DEFAULT_COLOR_BK = 0;
    constexpr int NO_COLOR = -1;//-256
    int __terminalTextColor = -1;
    int __terminalBackgroundColor = -1;

    const std::map<std::string, int> NAME_IDs = {
        {"black",            0}, {"k",   0},
        {"blue",             1}, {"b",   1},
        {"green",            2}, {"g",   2},
        {"cyan",             3}, {"c",   3},
        {"red",              4}, {"r",   4},
        {"purple",           5}, {"p",   5},
        {"yellow",           6}, {"y",   6},
        {"white",            7}, {"w",   7},
        {"gray",             8}, {"e",   8},
        {"light blue",       9}, {"lb",  9},
        {"light green",     10}, {"lg", 10},
        {"light cyan",      11}, {"lc", 11},
        {"light red",       12}, {"lr", 12},
        {"light purple",    13}, {"lp", 13},
        {"light yellow",    14}, {"ly", 14},
        {"light white",    15},  {"lw", 15}
    };

    const std::map<int, std::string> ID_NAMES = {
        { 0, "black"},
        { 1, "blue"},
        { 2, "green"},
        { 3, "cyan"},
        { 4, "red"},
        { 5, "purple"},
        { 6, "yellow"},
        { 7, "white"},
        { 8, "gray"},
        { 9, "light blue"},
        {10, "light green"},
        {11, "light cyan"},
        {12, "light red"},
        {13, "light purple"},
        {14, "light yellow"},
        {15, "light white"}
    };

    const std::map<const char*, std::string> COLORCODES_NAMES_UNIX = {
    { BLACK,    "black"},
    { BLUE,     "blue"},
    { GREEN,    "green"},
    { CYAN,     "cyan"},
    { RED,      "red"},
    { PURPLE,   "purple"},
    { YELLOW,   "yellow"},
    { WHITE,    "white"},
    { GRAY,     "gray"},
    { LIGHT_BLUE,   "light blue"},
    { LIGHT_GREEN,  "light green"},
    { LIGHT_CYAN,   "light cyan"},
    { LIGHT_RED,    "light red"},
    { LIGHT_PURPLE, "light purple"},
    { LIGHT_YELLOW, "light yellow"},
    { LIGHT_WHITE, "light white"}
    };
    const std::map<const char*, std::string> COLORCODES_BK_NAMES_UNIX = {
    { BK_BLACK,    "black"},
    { BK_BLUE,     "blue"},
    { BK_GREEN,    "green"},
    { BK_CYAN,     "cyan"},
    { BK_RED,      "red"},
    { BK_PURPLE,   "purple"},
    { BK_YELLOW,   "yellow"},
    { BK_WHITE,    "white"},
    { BK_GRAY,     "gray"},
    { BK_LIGHT_BLUE,   "light blue"},
    { BK_LIGHT_GREEN,  "light green"},
    { BK_LIGHT_CYAN,   "light cyan"},
    { BK_LIGHT_RED,    "light red"},
    { BK_LIGHT_PURPLE, "light purple"},
    { BK_LIGHT_YELLOW, "light yellow"},
    { BK_WHITE, "light white"}
    };

    //const std::map< std::string, const char*> NAMES_COLORCODES_BK_UNIX = {
    //{ "black",  BK_BLACK},
    //{ "blue",   BK_BLUE},
    //{ "green",  BK_GREEN},
    //{ "cyan",   BK_CYAN},
    //{ "red",    BK_RED},
    //{ "purple", BK_PURPLE},
    //{ "yellow", BK_YELLOW},
    //{ "white",  BK_WHITE},
    //{ "gray",   BK_GRAY},
    //{ "light blue",     BK_LIGHT_BLUE },
    //{ "light green",    BK_LIGHT_GREEN},
    //{ "light cyan",     BK_LIGHT_CYAN },
    //{ "light red",      BK_LIGHT_RED  },
    //{ "light purple",   BK_LIGHT_PURPLE},
    //{ "light yellow",   BK_LIGHT_YELLOW},
    //{ "light white",    BK_WHITE}
    //};

    const std::map< int, const char*> ID_COLORCODES_UNIX = {
    { 0,  BLACK},
    { 1,  BLUE},
    { 2,  GREEN},
    { 3,  CYAN},
    { 4,  RED},
    { 5,  PURPLE},
    { 6,  YELLOW},
    { 7,  WHITE},
    { 8,  GRAY},
    { 9,  LIGHT_BLUE },
    { 10, LIGHT_GREEN},
    { 11, LIGHT_CYAN },
    { 12, LIGHT_RED  },
    { 13, LIGHT_PURPLE},
    { 14, LIGHT_YELLOW},
    { 15, LIGHT_WHITE}
    };

    const std::map< int, const char*> ID_COLORCODES_BK_UNIX = {
    { 0,  BK_BLACK},
    { 1,  BK_BLUE},
    { 2,  BK_GREEN},
    { 3,  BK_CYAN},
    { 4,  BK_RED},
    { 5,  BK_PURPLE},
    { 6,  BK_YELLOW},
    { 7,  BK_WHITE},
    { 8,  BK_GRAY},
    { 9,  BK_LIGHT_BLUE },
    { 10, BK_LIGHT_GREEN},
    { 11, BK_LIGHT_CYAN },
    { 12, BK_LIGHT_RED  },
    { 13, BK_LIGHT_PURPLE},
    { 14, BK_LIGHT_YELLOW},
    { 15, BK_WHITE}
    };

    inline int encode_colors(int color1, int color2)
    {
        // combining the colors later on we extract them both
        // both c1 = colors>>8, c2 = colors & 0x0f
        // since they are both 8 bit we are shift 8 bits and then 
        // mask the first part and get the second number
        return (color1 << 8) | color2;
    }

    inline std::pair<int,int> decode_colors(int color)
    {
        if (color <= 15)
            return std::make_pair(color, NO_COLOR);
        else
            return std::make_pair((color >> 8), color & 0x0F);
    }

    inline bool is_good(int c)
    {
        #ifdef _WIN32
            return 0 <= c && c < 256;
        #endif // _WIN32
        #ifdef _UNIX
            return 0 <= c && c <= 3855; //0xF0F is the upper bound when a and b both are 0xF ( or 15)
        #endif
    }

    inline int itoc(int c, int b = NO_COLOR)
    {
        #ifdef _WIN32
            auto color = b == NO_COLOR ? c : c + b * 16;
            return is_good(color) ? color : NO_COLOR;
        #endif // _WIN32
        #ifdef _UNIX
            auto color = b == NO_COLOR ? c : encode_colors(c, b);
            return is_good(color) ? color : NO_COLOR;
        #endif
    }

    //inline int itoc(int a, int b)
    //{
    //    return itoc(a + b * 16);
    //}

    // std::string to color
    int stoc(std::string a)
    {
        // convert s to lowercase, and format variants like  "light_blue"
        std::transform(a.begin(), a.end(), a.begin(), [](char c)
            {
                if ('A' <= c && c <= 'Z')
                    c = c - 'A' + 'a';
                else if (c == '_' || c == '-')
                    c = ' ';
                return c;
            });
        // operator[] on std::map is non-const, use std::map::at instead
        return (NAME_IDs.find(a) != NAME_IDs.end()) ? NAME_IDs.at(a) : NO_COLOR;
    }

    int stoc(std::string a, std::string b)
    {
        #ifdef _WIN32
                return itoc(stoc(a), stoc(b));
        #endif // _WIN32
        #ifdef _UNIX
                //forecolor and backgroundcolor
                auto c1 = stoc(a);
                auto c2 = stoc(b);
                // combining the colors later on we extract them both
                // both c1 = colors>>8, c2 = colors & 0x0f
                // since they are both 8 bit we are shift 8 bits and then 
                // mask the first part and get the second number
                auto colors = encode_colors(c1, c2); //(c1 << 8) | c2;
                return colors;
        #endif
    }

    std::string ctos(int c)
    {
        #ifdef _WIN32
            return is_good(c) ? "(text) " + ID_NAMES.at(c % 16) + " + " + "(background) " + ID_NAMES.at(c / 16) : "BAD COLOR";
        #endif // _WIN32
        #ifdef _UNIX
            if (c > 15)
            {
                auto color_pair = decode_colors(c);
                //auto c1 = c >> 8;
                //auto c2 = c & 0x0f;
                return is_good(c) ? "(text) " + ID_NAMES.at(color_pair.first) + " + " + "(background) " + ID_NAMES.at(color_pair.second) : "BAD COLOR";
            }
            else 
                return is_good(c) ? "(text) " + ID_NAMES.at(c) + " + " + "(background) -N/A-" : "BAD COLOR";
        #endif
    }

    int get()
    {
        #ifdef _WIN32
                CONSOLE_SCREEN_BUFFER_INFO i;
                return GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &i) ? i.wAttributes : NO_COLOR;
        #endif // _WIN32
        #ifdef _UNIX
                return (__terminalTextColor != NO_COLOR) ? __terminalTextColor : NO_COLOR;
        #endif
    } 

    int get_text()
    {
        #ifdef _WIN32
            return (get() != NO_COLOR) ? get() % 16 : NO_COLOR;
        #endif // _WIN32
        #ifdef _UNIX
            return (__terminalTextColor != NO_COLOR) ? __terminalTextColor : NO_COLOR;
        #endif
    }

    int get_background()
    {
        #ifdef _WIN32
                return (get() != NO_COLOR) ? get() / 16 : NO_COLOR;
        #endif // _WIN32
        #ifdef _UNIX
                return (__terminalBackgroundColor != NO_COLOR) ? __terminalBackgroundColor : NO_COLOR;
        #endif
    }

    void set(int c1, int c2 = NO_COLOR, std::ostream& os = std::cout)
    {
        #ifdef _WIN32
            auto color = c2 == NO_COLOR ? c1 : c1 + c2 * 16;
            if (is_good(color))
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        #endif // _WIN32
        #ifdef _UNIX
            if (c1 > 15)
            {
                auto pair = decode_colors(c1);
                c1 = pair.first;
                c2 = pair.second;
            }

            c1 = (is_good(c1))? c1 : DEFAULT_COLOR;
            __terminalTextColor = c1;
            os << ID_COLORCODES_UNIX.at(c1);
            if (c2 != NO_COLOR)
            {
                c2 = (is_good(c2))? c2 : DEFAULT_COLOR_BK;
                __terminalBackgroundColor = c2;
                os << ID_COLORCODES_BK_UNIX.at(c2);
            }
        #endif // _UNIX
    }

    //void set(int a, int b)
    //{
    //    set(a + b * 16);
    //}

    void set(std::string a, std::string b, std::ostream& os = std::cout)
    {
        #ifdef _WIN32
                set(stoc(a) + stoc(b) * 16);
        #endif // _WIN32
        #ifdef _UNIX
            set(stoc(a), stoc(b), os);
        #endif // _UNIX
    }

    void set_text(std::string a, std::ostream& os = std::cout)
    {
        set(stoc(a), get_background(), os);
    }

    void set_background(std::string b, std::ostream& os = std::cout)
    {
        set(get_text(), stoc(b), os);
    }

    void _reset(std::ostream& os = std::cout)
    {
        set(DEFAULT_COLOR, DEFAULT_COLOR_BK, os);
    }

    int invert(int c)
    {
        if (is_good(c)) 
        {
            #ifdef _WIN32
                int a = c % 16;
                int b = c / 16;
                return b + a * 16;
            #endif // _WIN32
            #ifdef _UNIX
                auto pair = decode_colors(c);
                return encode_colors(pair.second, pair.first);
            #endif // _UNIX
        }
        else
            return NO_COLOR;
    }

    std::ostream& reset(std::ostream& os) { _reset(os);                return os; }
    std::ostream& black(std::ostream& os) { set_text("k", os);          return os; }
    std::ostream& blue(std::ostream& os) { set_text("b",os);          return os; }
    std::ostream& green(std::ostream& os) { set_text("g", os);          return os; }
    std::ostream& cyan(std::ostream& os) { set_text("c", os);          return os; }
    std::ostream& red(std::ostream& os) { set_text("r", os);          return os; }
    std::ostream& purple(std::ostream& os) { set_text("p", os);          return os; }
    std::ostream& yellow(std::ostream& os) { set_text("y", os);          return os; }
    std::ostream& white(std::ostream& os) { set_text("w", os);          return os; }
    std::ostream& gray(std::ostream& os) { set_text("e", os);          return os; }
    std::ostream& light_blue(std::ostream& os) { set_text("lb", os);         return os; }
    std::ostream& light_green(std::ostream& os) { set_text("lg", os);         return os; }
    std::ostream& light_cyan(std::ostream& os) { set_text("lc", os);         return os; }
    std::ostream& light_red(std::ostream& os) { set_text("lr", os);         return os; }
    std::ostream& light_purple(std::ostream& os) { set_text("lp", os);         return os; }
    std::ostream& light_yellow(std::ostream& os) { set_text("ly", os);         return os; }
    std::ostream& light_white(std::ostream& os) { set_text("lw", os);         return os; }
    std::ostream& on_black(std::ostream& os) { set_background("k", os);    return os; }
    std::ostream& on_blue(std::ostream& os) { set_background("b", os);    return os; }
    std::ostream& on_green(std::ostream& os) { set_background("g", os);    return os; }
    std::ostream& on_cyan(std::ostream& os) { set_background("c", os);    return os; }
    std::ostream& on_red(std::ostream& os) { set_background("r", os);    return os; }
    std::ostream& on_purple(std::ostream& os) { set_background("p", os);    return os; }
    std::ostream& on_yellow(std::ostream& os) { set_background("y", os);    return os; }
    std::ostream& on_white(std::ostream& os) { set_background("w", os);    return os; }
    std::ostream& on_gray(std::ostream& os) { set_background("e", os);    return os; }
    std::ostream& on_light_blue(std::ostream& os) { set_background("lb", os);   return os; }
    std::ostream& on_light_green(std::ostream& os) { set_background("lg", os);   return os; }
    std::ostream& on_light_cyan(std::ostream& os) { set_background("lc", os);   return os; }
    std::ostream& on_light_red(std::ostream& os) { set_background("lr", os);   return os; }
    std::ostream& on_light_purple(std::ostream& os) { set_background("lp", os);   return os; }
    std::ostream& on_light_yellow(std::ostream& os) { set_background("ly", os);   return os; }
    std::ostream& on_light_white(std::ostream& os) { set_background("lw", os);   return os; }
    std::ostream& black_on_black(std::ostream& os) { set("k", "k", os);   return os; }
    std::ostream& black_on_blue(std::ostream& os) { set("k", "b", os);   return os; }
    std::ostream& black_on_green(std::ostream& os) { set("k", "g", os);   return os; }
    std::ostream& black_on_cyan(std::ostream& os) { set("k", "c", os);   return os; }
    std::ostream& black_on_red(std::ostream& os) { set("k", "r", os);   return os; }
    std::ostream& black_on_purple(std::ostream& os) { set("k", "p", os);   return os; }
    std::ostream& black_on_yellow(std::ostream& os) { set("k", "y", os);   return os; }
    std::ostream& black_on_white(std::ostream& os) { set("k", "w", os);   return os; }
    std::ostream& black_on_gray(std::ostream& os) { set("k", "e", os);   return os; }
    std::ostream& black_on_light_blue(std::ostream& os) { set("k", "lb", os);  return os; }
    std::ostream& black_on_light_green(std::ostream& os) { set("k", "lg", os);  return os; }
    std::ostream& black_on_light_cyan(std::ostream& os) { set("k", "lc", os);  return os; }
    std::ostream& black_on_light_red(std::ostream& os) { set("k", "lr", os);  return os; }
    std::ostream& black_on_light_purple(std::ostream& os) { set("k", "lp", os);  return os; }
    std::ostream& black_on_light_yellow(std::ostream& os) { set("k", "ly", os);  return os; }
    std::ostream& black_on_light_white(std::ostream& os) { set("k", "lw", os);  return os; }
    std::ostream& blue_on_black(std::ostream& os) { set("b", "k", os);   return os; }
    std::ostream& blue_on_blue(std::ostream& os) { set("b", "b", os);   return os; }
    std::ostream& blue_on_green(std::ostream& os) { set("b", "g", os);   return os; }
    std::ostream& blue_on_cyan(std::ostream& os) { set("b", "c", os);   return os; }
    std::ostream& blue_on_red(std::ostream& os) { set("b", "r", os);   return os; }
    std::ostream& blue_on_purple(std::ostream& os) { set("b", "p", os);   return os; }
    std::ostream& blue_on_yellow(std::ostream& os) { set("b", "y", os);   return os; }
    std::ostream& blue_on_white(std::ostream& os) { set("b", "w", os);   return os; }
    std::ostream& blue_on_gray(std::ostream& os) { set("b", "e", os);   return os; }
    std::ostream& blue_on_light_blue(std::ostream& os) { set("b", "lb", os);  return os; }
    std::ostream& blue_on_light_green(std::ostream& os) { set("b", "lg", os);  return os; }
    std::ostream& blue_on_light_cyan(std::ostream& os) { set("b", "lc", os);  return os; }
    std::ostream& blue_on_light_red(std::ostream& os) { set("b", "lr", os);  return os; }
    std::ostream& blue_on_light_purple(std::ostream& os) { set("b", "lp", os);  return os; }
    std::ostream& blue_on_light_yellow(std::ostream& os) { set("b", "ly", os);  return os; }
    std::ostream& blue_on_light_white(std::ostream& os) { set("b", "lw", os);  return os; }
    std::ostream& green_on_black(std::ostream& os) { set("g", "k", os);   return os; }
    std::ostream& green_on_blue(std::ostream& os) { set("g", "b", os);   return os; }
    std::ostream& green_on_green(std::ostream& os) { set("g", "g", os);   return os; }
    std::ostream& green_on_cyan(std::ostream& os) { set("g", "c", os);   return os; }
    std::ostream& green_on_red(std::ostream& os) { set("g", "r", os);   return os; }
    std::ostream& green_on_purple(std::ostream& os) { set("g", "p", os);   return os; }
    std::ostream& green_on_yellow(std::ostream& os) { set("g", "y", os);   return os; }
    std::ostream& green_on_white(std::ostream& os) { set("g", "w", os);   return os; }
    std::ostream& green_on_gray(std::ostream& os) { set("g", "e", os);   return os; }
    std::ostream& green_on_light_blue(std::ostream& os) { set("g", "lb", os);  return os; }
    std::ostream& green_on_light_green(std::ostream& os) { set("g", "lg", os);  return os; }
    std::ostream& green_on_light_cyan(std::ostream& os) { set("g", "lc", os);  return os; }
    std::ostream& green_on_light_red(std::ostream& os) { set("g", "lr", os);  return os; }
    std::ostream& green_on_light_purple(std::ostream& os) { set("g", "lp", os);  return os; }
    std::ostream& green_on_light_yellow(std::ostream& os) { set("g", "ly", os);  return os; }
    std::ostream& green_on_light_white(std::ostream& os) { set("g", "lw", os);  return os; }
    std::ostream& cyan_on_black(std::ostream& os) { set("c", "k", os);   return os; }
    std::ostream& cyan_on_blue(std::ostream& os) { set("c", "b", os);   return os; }
    std::ostream& cyan_on_green(std::ostream& os) { set("c", "g", os);   return os; }
    std::ostream& cyan_on_cyan(std::ostream& os) { set("c", "c", os);   return os; }
    std::ostream& cyan_on_red(std::ostream& os) { set("c", "r", os);   return os; }
    std::ostream& cyan_on_purple(std::ostream& os) { set("c", "p", os);   return os; }
    std::ostream& cyan_on_yellow(std::ostream& os) { set("c", "y", os);   return os; }
    std::ostream& cyan_on_white(std::ostream& os) { set("c", "w", os);   return os; }
    std::ostream& cyan_on_gray(std::ostream& os) { set("c", "e", os);   return os; }
    std::ostream& cyan_on_light_blue(std::ostream& os) { set("c", "lb", os);  return os; }
    std::ostream& cyan_on_light_green(std::ostream& os) { set("c", "lg", os);  return os; }
    std::ostream& cyan_on_light_cyan(std::ostream& os) { set("c", "lc", os);  return os; }
    std::ostream& cyan_on_light_red(std::ostream& os) { set("c", "lr", os);  return os; }
    std::ostream& cyan_on_light_purple(std::ostream& os) { set("c", "lp", os);  return os; }
    std::ostream& cyan_on_light_yellow(std::ostream& os) { set("c", "ly", os);  return os; }
    std::ostream& cyan_on_light_white(std::ostream& os) { set("c", "lw", os);  return os; }
    std::ostream& red_on_black(std::ostream& os) { set("r", "k", os);   return os; }
    std::ostream& red_on_blue(std::ostream& os) { set("r", "b", os);   return os; }
    std::ostream& red_on_green(std::ostream& os) { set("r", "g", os);   return os; }
    std::ostream& red_on_cyan(std::ostream& os) { set("r", "c", os);   return os; }
    std::ostream& red_on_red(std::ostream& os) { set("r", "r", os);   return os; }
    std::ostream& red_on_purple(std::ostream& os) { set("r", "p", os);   return os; }
    std::ostream& red_on_yellow(std::ostream& os) { set("r", "y", os);   return os; }
    std::ostream& red_on_white(std::ostream& os) { set("r", "w", os);   return os; }
    std::ostream& red_on_gray(std::ostream& os) { set("r", "e", os);   return os; }
    std::ostream& red_on_light_blue(std::ostream& os) { set("r", "lb", os);  return os; }
    std::ostream& red_on_light_green(std::ostream& os) { set("r", "lg", os);  return os; }
    std::ostream& red_on_light_cyan(std::ostream& os) { set("r", "lc", os);  return os; }
    std::ostream& red_on_light_red(std::ostream& os) { set("r", "lr", os);  return os; }
    std::ostream& red_on_light_purple(std::ostream& os) { set("r", "lp", os);  return os; }
    std::ostream& red_on_light_yellow(std::ostream& os) { set("r", "ly", os);  return os; }
    std::ostream& red_on_light_white(std::ostream& os) { set("r", "lw", os);  return os; }
    std::ostream& purple_on_black(std::ostream& os) { set("p", "k", os);   return os; }
    std::ostream& purple_on_blue(std::ostream& os) { set("p", "b", os);   return os; }
    std::ostream& purple_on_green(std::ostream& os) { set("p", "g", os);   return os; }
    std::ostream& purple_on_cyan(std::ostream& os) { set("p", "c", os);   return os; }
    std::ostream& purple_on_red(std::ostream& os) { set("p", "r", os);   return os; }
    std::ostream& purple_on_purple(std::ostream& os) { set("p", "p", os);   return os; }
    std::ostream& purple_on_yellow(std::ostream& os) { set("p", "y", os);   return os; }
    std::ostream& purple_on_white(std::ostream& os) { set("p", "w", os);   return os; }
    std::ostream& purple_on_gray(std::ostream& os) { set("p", "e", os);   return os; }
    std::ostream& purple_on_light_blue(std::ostream& os) { set("p", "lb", os);  return os; }
    std::ostream& purple_on_light_green(std::ostream& os) { set("p", "lg", os);  return os; }
    std::ostream& purple_on_light_cyan(std::ostream& os) { set("p", "lc", os);  return os; }
    std::ostream& purple_on_light_red(std::ostream& os) { set("p", "lr", os);  return os; }
    std::ostream& purple_on_light_purple(std::ostream& os) { set("p", "lp", os);  return os; }
    std::ostream& purple_on_light_yellow(std::ostream& os) { set("p", "ly", os);  return os; }
    std::ostream& purple_on_light_white(std::ostream& os) { set("p", "lw", os);  return os; }
    std::ostream& yellow_on_black(std::ostream& os) { set("y", "k", os);   return os; }
    std::ostream& yellow_on_blue(std::ostream& os) { set("y", "b", os);   return os; }
    std::ostream& yellow_on_green(std::ostream& os) { set("y", "g", os);   return os; }
    std::ostream& yellow_on_cyan(std::ostream& os) { set("y", "c", os);   return os; }
    std::ostream& yellow_on_red(std::ostream& os) { set("y", "r", os);   return os; }
    std::ostream& yellow_on_purple(std::ostream& os) { set("y", "p", os);   return os; }
    std::ostream& yellow_on_yellow(std::ostream& os) { set("y", "y", os);   return os; }
    std::ostream& yellow_on_white(std::ostream& os) { set("y", "w", os);   return os; }
    std::ostream& yellow_on_gray(std::ostream& os) { set("y", "e", os);   return os; }
    std::ostream& yellow_on_light_blue(std::ostream& os) { set("y", "lb", os);  return os; }
    std::ostream& yellow_on_light_green(std::ostream& os) { set("y", "lg", os);  return os; }
    std::ostream& yellow_on_light_cyan(std::ostream& os) { set("y", "lc", os);  return os; }
    std::ostream& yellow_on_light_red(std::ostream& os) { set("y", "lr", os);  return os; }
    std::ostream& yellow_on_light_purple(std::ostream& os) { set("y", "lp", os);  return os; }
    std::ostream& yellow_on_light_yellow(std::ostream& os) { set("y", "ly", os);  return os; }
    std::ostream& yellow_on_light_white(std::ostream& os) { set("y", "lw", os);  return os; }
    std::ostream& white_on_black(std::ostream& os) { set("w", "k", os);   return os; }
    std::ostream& white_on_blue(std::ostream& os) { set("w", "b", os);   return os; }
    std::ostream& white_on_green(std::ostream& os) { set("w", "g", os);   return os; }
    std::ostream& white_on_cyan(std::ostream& os) { set("w", "c", os);   return os; }
    std::ostream& white_on_red(std::ostream& os) { set("w", "r", os);   return os; }
    std::ostream& white_on_purple(std::ostream& os) { set("w", "p", os);   return os; }
    std::ostream& white_on_yellow(std::ostream& os) { set("w", "y", os);   return os; }
    std::ostream& white_on_white(std::ostream& os) { set("w", "w", os);   return os; }
    std::ostream& white_on_gray(std::ostream& os) { set("w", "e", os);   return os; }
    std::ostream& white_on_light_blue(std::ostream& os) { set("w", "lb", os);  return os; }
    std::ostream& white_on_light_green(std::ostream& os) { set("w", "lg", os);  return os; }
    std::ostream& white_on_light_cyan(std::ostream& os) { set("w", "lc", os);  return os; }
    std::ostream& white_on_light_red(std::ostream& os) { set("w", "lr", os);  return os; }
    std::ostream& white_on_light_purple(std::ostream& os) { set("w", "lp", os);  return os; }
    std::ostream& white_on_light_yellow(std::ostream& os) { set("w", "ly", os);  return os; }
    std::ostream& white_on_light_white(std::ostream& os) { set("w", "lw", os);  return os; }
    std::ostream& gray_on_black(std::ostream& os) { set("e", "k", os);   return os; }
    std::ostream& gray_on_blue(std::ostream& os) { set("e", "b", os);   return os; }
    std::ostream& gray_on_green(std::ostream& os) { set("e", "g", os);   return os; }
    std::ostream& gray_on_cyan(std::ostream& os) { set("e", "c", os);   return os; }
    std::ostream& gray_on_red(std::ostream& os) { set("e", "r", os);   return os; }
    std::ostream& gray_on_purple(std::ostream& os) { set("e", "p", os);   return os; }
    std::ostream& gray_on_yellow(std::ostream& os) { set("e", "y", os);   return os; }
    std::ostream& gray_on_white(std::ostream& os) { set("e", "w", os);   return os; }
    std::ostream& gray_on_gray(std::ostream& os) { set("e", "e", os);   return os; }
    std::ostream& gray_on_light_blue(std::ostream& os) { set("e", "lb", os);  return os; }
    std::ostream& gray_on_light_green(std::ostream& os) { set("e", "lg", os);  return os; }
    std::ostream& gray_on_light_cyan(std::ostream& os) { set("e", "lc", os);  return os; }
    std::ostream& gray_on_light_red(std::ostream& os) { set("e", "lr", os);  return os; }
    std::ostream& gray_on_light_purple(std::ostream& os) { set("e", "lp", os);  return os; }
    std::ostream& gray_on_light_yellow(std::ostream& os) { set("e", "ly", os);  return os; }
    std::ostream& gray_on_light_white(std::ostream& os) { set("e", "lw", os);  return os; }
    std::ostream& light_blue_on_black(std::ostream& os) { set("lb", "k", os);  return os; }
    std::ostream& light_blue_on_blue(std::ostream& os) { set("lb", "b", os);  return os; }
    std::ostream& light_blue_on_green(std::ostream& os) { set("lb", "g", os);  return os; }
    std::ostream& light_blue_on_cyan(std::ostream& os) { set("lb", "c", os);  return os; }
    std::ostream& light_blue_on_red(std::ostream& os) { set("lb", "r", os);  return os; }
    std::ostream& light_blue_on_purple(std::ostream& os) { set("lb", "p", os);  return os; }
    std::ostream& light_blue_on_yellow(std::ostream& os) { set("lb", "y", os);  return os; }
    std::ostream& light_blue_on_white(std::ostream& os) { set("lb", "w", os);  return os; }
    std::ostream& light_blue_on_gray(std::ostream& os) { set("lb", "e", os);  return os; }
    std::ostream& light_blue_on_light_blue(std::ostream& os) { set("lb", "lb", os); return os; }
    std::ostream& light_blue_on_light_green(std::ostream& os) { set("lb", "lg", os); return os; }
    std::ostream& light_blue_on_light_cyan(std::ostream& os) { set("lb", "lc", os); return os; }
    std::ostream& light_blue_on_light_red(std::ostream& os) { set("lb", "lr", os); return os; }
    std::ostream& light_blue_on_light_purple(std::ostream& os) { set("lb", "lp", os); return os; }
    std::ostream& light_blue_on_light_yellow(std::ostream& os) { set("lb", "ly", os); return os; }
    std::ostream& light_blue_on_light_white(std::ostream& os) { set("lb", "lw", os); return os; }
    std::ostream& light_green_on_black(std::ostream& os) { set("lg", "k", os);  return os; }
    std::ostream& light_green_on_blue(std::ostream& os) { set("lg", "b", os);  return os; }
    std::ostream& light_green_on_green(std::ostream& os) { set("lg", "g", os);  return os; }
    std::ostream& light_green_on_cyan(std::ostream& os) { set("lg", "c", os);  return os; }
    std::ostream& light_green_on_red(std::ostream& os) { set("lg", "r", os);  return os; }
    std::ostream& light_green_on_purple(std::ostream& os) { set("lg", "p", os);  return os; }
    std::ostream& light_green_on_yellow(std::ostream& os) { set("lg", "y", os);  return os; }
    std::ostream& light_green_on_white(std::ostream& os) { set("lg", "w", os);  return os; }
    std::ostream& light_green_on_gray(std::ostream& os) { set("lg", "e", os);  return os; }
    std::ostream& light_green_on_light_blue(std::ostream& os) { set("lg", "lb", os); return os; }
    std::ostream& light_green_on_light_green(std::ostream& os) { set("lg", "lg", os); return os; }
    std::ostream& light_green_on_light_cyan(std::ostream& os) { set("lg", "lc", os); return os; }
    std::ostream& light_green_on_light_red(std::ostream& os) { set("lg", "lr", os); return os; }
    std::ostream& light_green_on_light_purple(std::ostream& os) { set("lg", "lp", os); return os; }
    std::ostream& light_green_on_light_yellow(std::ostream& os) { set("lg", "ly", os); return os; }
    std::ostream& light_green_on_light_white(std::ostream& os) { set("lg", "lw", os); return os; }
    std::ostream& light_cyan_on_black(std::ostream& os) { set("lc", "k", os);  return os; }
    std::ostream& light_cyan_on_blue(std::ostream& os) { set("lc", "b", os);  return os; }
    std::ostream& light_cyan_on_green(std::ostream& os) { set("lc", "g", os);  return os; }
    std::ostream& light_cyan_on_cyan(std::ostream& os) { set("lc", "c", os);  return os; }
    std::ostream& light_cyan_on_red(std::ostream& os) { set("lc", "r", os);  return os; }
    std::ostream& light_cyan_on_purple(std::ostream& os) { set("lc", "p", os);  return os; }
    std::ostream& light_cyan_on_yellow(std::ostream& os) { set("lc", "y", os);  return os; }
    std::ostream& light_cyan_on_white(std::ostream& os) { set("lc", "w", os);  return os; }
    std::ostream& light_cyan_on_gray(std::ostream& os) { set("lc", "e", os);  return os; }
    std::ostream& light_cyan_on_light_blue(std::ostream& os) { set("lc", "lb", os); return os; }
    std::ostream& light_cyan_on_light_green(std::ostream& os) { set("lc", "lg", os); return os; }
    std::ostream& light_cyan_on_light_cyan(std::ostream& os) { set("lc", "lc", os); return os; }
    std::ostream& light_cyan_on_light_red(std::ostream& os) { set("lc", "lr", os); return os; }
    std::ostream& light_cyan_on_light_purple(std::ostream& os) { set("lc", "lp", os); return os; }
    std::ostream& light_cyan_on_light_yellow(std::ostream& os) { set("lc", "ly", os); return os; }
    std::ostream& light_cyan_on_light_white(std::ostream& os) { set("lc", "lw", os); return os; }
    std::ostream& light_red_on_black(std::ostream& os) { set("lr", "k", os);  return os; }
    std::ostream& light_red_on_blue(std::ostream& os) { set("lr", "b", os);  return os; }
    std::ostream& light_red_on_green(std::ostream& os) { set("lr", "g", os);  return os; }
    std::ostream& light_red_on_cyan(std::ostream& os) { set("lr", "c", os);  return os; }
    std::ostream& light_red_on_red(std::ostream& os) { set("lr", "r", os);  return os; }
    std::ostream& light_red_on_purple(std::ostream& os) { set("lr", "p", os);  return os; }
    std::ostream& light_red_on_yellow(std::ostream& os) { set("lr", "y", os);  return os; }
    std::ostream& light_red_on_white(std::ostream& os) { set("lr", "w", os);  return os; }
    std::ostream& light_red_on_gray(std::ostream& os) { set("lr", "e", os);  return os; }
    std::ostream& light_red_on_light_blue(std::ostream& os) { set("lr", "lb", os); return os; }
    std::ostream& light_red_on_light_green(std::ostream& os) { set("lr", "lg", os); return os; }
    std::ostream& light_red_on_light_cyan(std::ostream& os) { set("lr", "lc", os); return os; }
    std::ostream& light_red_on_light_red(std::ostream& os) { set("lr", "lr", os); return os; }
    std::ostream& light_red_on_light_purple(std::ostream& os) { set("lr", "lp", os); return os; }
    std::ostream& light_red_on_light_yellow(std::ostream& os) { set("lr", "ly", os); return os; }
    std::ostream& light_red_on_light_white(std::ostream& os) { set("lr", "lw", os); return os; }
    std::ostream& light_purple_on_black(std::ostream& os) { set("lp", "k", os);  return os; }
    std::ostream& light_purple_on_blue(std::ostream& os) { set("lp", "b", os);  return os; }
    std::ostream& light_purple_on_green(std::ostream& os) { set("lp", "g", os);  return os; }
    std::ostream& light_purple_on_cyan(std::ostream& os) { set("lp", "c", os);  return os; }
    std::ostream& light_purple_on_red(std::ostream& os) { set("lp", "r", os);  return os; }
    std::ostream& light_purple_on_purple(std::ostream& os) { set("lp", "p", os);  return os; }
    std::ostream& light_purple_on_yellow(std::ostream& os) { set("lp", "y", os);  return os; }
    std::ostream& light_purple_on_white(std::ostream& os) { set("lp", "w", os);  return os; }
    std::ostream& light_purple_on_gray(std::ostream& os) { set("lp", "e", os);  return os; }
    std::ostream& light_purple_on_light_blue(std::ostream& os) { set("lp", "lb", os); return os; }
    std::ostream& light_purple_on_light_green(std::ostream& os) { set("lp", "lg", os); return os; }
    std::ostream& light_purple_on_light_cyan(std::ostream& os) { set("lp", "lc", os); return os; }
    std::ostream& light_purple_on_light_red(std::ostream& os) { set("lp", "lr", os); return os; }
    std::ostream& light_purple_on_light_purple(std::ostream& os) { set("lp", "lp", os); return os; }
    std::ostream& light_purple_on_light_yellow(std::ostream& os) { set("lp", "ly", os); return os; }
    std::ostream& light_purple_on_light_white(std::ostream& os) { set("lp", "lw", os); return os; }
    std::ostream& light_yellow_on_black(std::ostream& os) { set("ly", "k", os);  return os; }
    std::ostream& light_yellow_on_blue(std::ostream& os) { set("ly", "b", os);  return os; }
    std::ostream& light_yellow_on_green(std::ostream& os) { set("ly", "g", os);  return os; }
    std::ostream& light_yellow_on_cyan(std::ostream& os) { set("ly", "c", os);  return os; }
    std::ostream& light_yellow_on_red(std::ostream& os) { set("ly", "r", os);  return os; }
    std::ostream& light_yellow_on_purple(std::ostream& os) { set("ly", "p", os);  return os; }
    std::ostream& light_yellow_on_yellow(std::ostream& os) { set("ly", "y", os);  return os; }
    std::ostream& light_yellow_on_white(std::ostream& os) { set("ly", "w", os);  return os; }
    std::ostream& light_yellow_on_gray(std::ostream& os) { set("ly", "e", os);  return os; }
    std::ostream& light_yellow_on_light_blue(std::ostream& os) { set("ly", "lb", os); return os; }
    std::ostream& light_yellow_on_light_green(std::ostream& os) { set("ly", "lg", os); return os; }
    std::ostream& light_yellow_on_light_cyan(std::ostream& os) { set("ly", "lc", os); return os; }
    std::ostream& light_yellow_on_light_red(std::ostream& os) { set("ly", "lr", os); return os; }
    std::ostream& light_yellow_on_light_purple(std::ostream& os) { set("ly", "lp", os); return os; }
    std::ostream& light_yellow_on_light_yellow(std::ostream& os) { set("ly", "ly", os); return os; }
    std::ostream& light_yellow_on_light_white(std::ostream& os) { set("ly", "lw", os); return os; }
    std::ostream& light_white_on_black(std::ostream& os) { set("lw", "k", os);  return os; }
    std::ostream& light_white_on_blue(std::ostream& os) { set("lw", "b", os);  return os; }
    std::ostream& light_white_on_green(std::ostream& os) { set("lw", "g", os);  return os; }
    std::ostream& light_white_on_cyan(std::ostream& os) { set("lw", "c", os);  return os; }
    std::ostream& light_white_on_red(std::ostream& os) { set("lw", "r", os);  return os; }
    std::ostream& light_white_on_purple(std::ostream& os) { set("lw", "p", os);  return os; }
    std::ostream& light_white_on_yellow(std::ostream& os) { set("lw", "y", os);  return os; }
    std::ostream& light_white_on_white(std::ostream& os) { set("lw", "w", os);  return os; }
    std::ostream& light_white_on_gray(std::ostream& os) { set("lw", "e", os);  return os; }
    std::ostream& light_white_on_light_blue(std::ostream& os) { set("lw", "lb", os); return os; }
    std::ostream& light_white_on_light_green(std::ostream& os) { set("lw", "lg", os); return os; }
    std::ostream& light_white_on_light_cyan(std::ostream& os) { set("lw", "lc", os); return os; }
    std::ostream& light_white_on_light_red(std::ostream& os) { set("lw", "lr", os); return os; }
    std::ostream& light_white_on_light_purple(std::ostream& os) { set("lw", "lp", os); return os; }
    std::ostream& light_white_on_light_yellow(std::ostream& os) { set("lw", "ly", os); return os; }
    std::ostream& light_white_on_light_white(std::ostream& os) { set("lw", "lw", os); return os; }
}


namespace dye
{
    template<typename T>
    using bar = typename std::conditional<std::is_same<T, const char*>::value, std::string, T>::type;

    template<typename T> class colorful;
    template<typename T> class item;

    template<typename T>
    class colorful : private std::list<item<T>>
    {
    public:
        using std::list<item<T>>::list;

        colorful<T>& operator+=(const colorful<T>& rhs)
        {
            this->insert(this->end(), rhs.begin(), rhs.end());
            return *this;
        }

        colorful<T>& operator+=(colorful<T>&& rhs)
        {
            this->splice(this->end(), std::move(rhs));
            return *this;
        }

        colorful<T>& operator+=(T t)
        {
            this->push_back(std::move(t));
            return *this;
        }

        void push_front(T t)
        {
            this->std::list<item<T>>::push_front(item<T>(std::move(t)));
        }

        void push_back(T t)
        {
            this->std::list<item<T>>::push_back(item<T>(std::move(t)));
        }

        colorful<T>& invert()
        {
            for (auto& elem : *this)
                elem.invert();
            return *this;
        }

        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const colorful<U>&);

        template<typename U>
        friend colorful<U> invert(colorful<U> col);
    };

    template<typename T>
    colorful<T> operator+(colorful<T> lhs, colorful<T> rhs)
    {
        colorful<T> res(std::move(lhs));
        return res += rhs;
    }

    template<typename T>
    colorful<T> operator+(colorful<T> lhs, std::string rhs)
    {
        colorful<T> res(std::move(lhs));
        res.push_back(std::move(rhs));
        return res;
    }

    template<typename T>
    colorful<T> operator+(const std::string& lhs, colorful<T> rhs)
    {
        colorful<T> res(std::move(rhs));
        res.push_front(std::move(lhs));
        return res;
    }

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const colorful<T>& colorful)
    {
        for (const auto& elem : colorful)
            os << elem;
        return os;
    }

    template<typename T>
    colorful<T> invert(colorful<T> col)
    {
        colorful<T> res(std::move(col));
        for (auto& elem : res)
            elem.invert();
        return res;
    }

    template<typename T>
    class item
    {
        T argumentValue;
        int color;

    public:
        item(T t) : argumentValue(std::move(t)), color(hue::get()) {}
        item(T t, int a) : argumentValue(std::move(t)), color(hue::itoc(a)) {}
        item(T t, int a, int b) : argumentValue(std::move(t)), color(hue::itoc(a, b)) {}
        item(T t, std::string a) : argumentValue(std::move(t)), color(hue::stoc(a)) {}
        item(T t, std::string a, std::string b) : argumentValue(std::move(t)), color(hue::stoc(a, b)) {}

        item<T>& invert()
        {
            color = hue::invert(color);
            return *this;
        }

        template<typename U>
        friend class colorful;

        template<typename U>
        friend std::ostream& operator<<(std::ostream&, const item<U>&);
    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const item<T>& it)
    {
        hue::set(it.color);
        os << it.argumentValue;
        hue::_reset(os);
        return os;
    }

    template<typename T> using R = colorful<bar<T>>;
    template<typename T> using S = item<bar<T>>;

    template<typename T> R<T> colorize(T t, std::string a) { return R<T> { S<T>(t, a) }; }
    template<typename T> R<T> vanilla(T t) { return R<T> { S<T>(t) }; }
    template<typename T> R<T> black(T t) { return R<T> { S<T>(t, "k") }; }
    template<typename T> R<T> blue(T t) { return R<T> { S<T>(t, "b") }; }
    template<typename T> R<T> green(T t) { return R<T> { S<T>(t, "g") }; }
    template<typename T> R<T> cyan(T t) { return R<T> { S<T>(t, "c") }; }
    template<typename T> R<T> red(T t) { return R<T> { S<T>(t, "r") }; }
    template<typename T> R<T> purple(T t) { return R<T> { S<T>(t, "p") }; }
    template<typename T> R<T> yellow(T t) { return R<T> { S<T>(t, "y") }; }
    template<typename T> R<T> white(T t) { return R<T> { S<T>(t, "w") }; }
    template<typename T> R<T> gray(T t) { return R<T> { S<T>(t, "e") }; }
    template<typename T> R<T> light_blue(T t) { return R<T> { S<T>(t, "lb") }; }
    template<typename T> R<T> light_green(T t) { return R<T> { S<T>(t, "lg") }; }
    template<typename T> R<T> light_cyan(T t) { return R<T> { S<T>(t, "lc") }; }
    template<typename T> R<T> light_red(T t) { return R<T> { S<T>(t, "lr") }; }
    template<typename T> R<T> light_purple(T t) { return R<T> { S<T>(t, "lp") }; }
    template<typename T> R<T> light_yellow(T t) { return R<T> { S<T>(t, "ly") }; }
    template<typename T> R<T> light_white(T t) { return R<T> { S<T>(t, "lw") }; }
    template<typename T> R<T> on_black(T t) { return R<T> { S<T>(t, "k", "k") }; }
    template<typename T> R<T> on_blue(T t) { return R<T> { S<T>(t, "k", "b") }; }
    template<typename T> R<T> on_green(T t) { return R<T> { S<T>(t, "k", "g") }; }
    template<typename T> R<T> on_cyan(T t) { return R<T> { S<T>(t, "k", "c") }; }
    template<typename T> R<T> on_red(T t) { return R<T> { S<T>(t, "k", "r") }; }
    template<typename T> R<T> on_purple(T t) { return R<T> { S<T>(t, "k", "p") }; }
    template<typename T> R<T> on_yellow(T t) { return R<T> { S<T>(t, "k", "y") }; }
    template<typename T> R<T> on_white(T t) { return R<T> { S<T>(t, "k", "w") }; }
    template<typename T> R<T> on_gray(T t) { return R<T> { S<T>(t, "k", "e") }; }
    template<typename T> R<T> on_light_blue(T t) { return R<T> { S<T>(t, "k", "lb") }; }
    template<typename T> R<T> on_light_green(T t) { return R<T> { S<T>(t, "k", "lg") }; }
    template<typename T> R<T> on_light_cyan(T t) { return R<T> { S<T>(t, "k", "lc") }; }
    template<typename T> R<T> on_light_red(T t) { return R<T> { S<T>(t, "k", "lr") }; }
    template<typename T> R<T> on_light_purple(T t) { return R<T> { S<T>(t, "k", "lp") }; }
    template<typename T> R<T> on_light_yellow(T t) { return R<T> { S<T>(t, "k", "ly") }; }
    template<typename T> R<T> on_light_white(T t) { return R<T> { S<T>(t, "k", "lw") }; }
    template<typename T> R<T> black_on_black(T t) { return R<T> { S<T>(t, "k", "k") }; }
    template<typename T> R<T> black_on_blue(T t) { return R<T> { S<T>(t, "k", "b") }; }
    template<typename T> R<T> black_on_green(T t) { return R<T> { S<T>(t, "k", "g") }; }
    template<typename T> R<T> black_on_cyan(T t) { return R<T> { S<T>(t, "k", "c") }; }
    template<typename T> R<T> black_on_red(T t) { return R<T> { S<T>(t, "k", "r") }; }
    template<typename T> R<T> black_on_purple(T t) { return R<T> { S<T>(t, "k", "p") }; }
    template<typename T> R<T> black_on_yellow(T t) { return R<T> { S<T>(t, "k", "y") }; }
    template<typename T> R<T> black_on_white(T t) { return R<T> { S<T>(t, "k", "w") }; }
    template<typename T> R<T> black_on_gray(T t) { return R<T> { S<T>(t, "k", "e") }; }
    template<typename T> R<T> black_on_light_blue(T t) { return R<T> { S<T>(t, "k", "lb") }; }
    template<typename T> R<T> black_on_light_green(T t) { return R<T> { S<T>(t, "k", "lg") }; }
    template<typename T> R<T> black_on_light_cyan(T t) { return R<T> { S<T>(t, "k", "lc") }; }
    template<typename T> R<T> black_on_light_red(T t) { return R<T> { S<T>(t, "k", "lr") }; }
    template<typename T> R<T> black_on_light_purple(T t) { return R<T> { S<T>(t, "k", "lp") }; }
    template<typename T> R<T> black_on_light_yellow(T t) { return R<T> { S<T>(t, "k", "ly") }; }
    template<typename T> R<T> black_on_light_white(T t) { return R<T> { S<T>(t, "k", "lw") }; }
    template<typename T> R<T> blue_on_black(T t) { return R<T> { S<T>(t, "b", "k") }; }
    template<typename T> R<T> blue_on_blue(T t) { return R<T> { S<T>(t, "b", "b") }; }
    template<typename T> R<T> blue_on_green(T t) { return R<T> { S<T>(t, "b", "g") }; }
    template<typename T> R<T> blue_on_cyan(T t) { return R<T> { S<T>(t, "b", "c") }; }
    template<typename T> R<T> blue_on_red(T t) { return R<T> { S<T>(t, "b", "r") }; }
    template<typename T> R<T> blue_on_purple(T t) { return R<T> { S<T>(t, "b", "p") }; }
    template<typename T> R<T> blue_on_yellow(T t) { return R<T> { S<T>(t, "b", "y") }; }
    template<typename T> R<T> blue_on_white(T t) { return R<T> { S<T>(t, "b", "w") }; }
    template<typename T> R<T> blue_on_gray(T t) { return R<T> { S<T>(t, "b", "e") }; }
    template<typename T> R<T> blue_on_light_blue(T t) { return R<T> { S<T>(t, "b", "lb") }; }
    template<typename T> R<T> blue_on_light_green(T t) { return R<T> { S<T>(t, "b", "lg") }; }
    template<typename T> R<T> blue_on_light_cyan(T t) { return R<T> { S<T>(t, "b", "lc") }; }
    template<typename T> R<T> blue_on_light_red(T t) { return R<T> { S<T>(t, "b", "lr") }; }
    template<typename T> R<T> blue_on_light_purple(T t) { return R<T> { S<T>(t, "b", "lp") }; }
    template<typename T> R<T> blue_on_light_yellow(T t) { return R<T> { S<T>(t, "b", "ly") }; }
    template<typename T> R<T> blue_on_light_white(T t) { return R<T> { S<T>(t, "b", "lw") }; }
    template<typename T> R<T> green_on_black(T t) { return R<T> { S<T>(t, "g", "k") }; }
    template<typename T> R<T> green_on_blue(T t) { return R<T> { S<T>(t, "g", "b") }; }
    template<typename T> R<T> green_on_green(T t) { return R<T> { S<T>(t, "g", "g") }; }
    template<typename T> R<T> green_on_cyan(T t) { return R<T> { S<T>(t, "g", "c") }; }
    template<typename T> R<T> green_on_red(T t) { return R<T> { S<T>(t, "g", "r") }; }
    template<typename T> R<T> green_on_purple(T t) { return R<T> { S<T>(t, "g", "p") }; }
    template<typename T> R<T> green_on_yellow(T t) { return R<T> { S<T>(t, "g", "y") }; }
    template<typename T> R<T> green_on_white(T t) { return R<T> { S<T>(t, "g", "w") }; }
    template<typename T> R<T> green_on_gray(T t) { return R<T> { S<T>(t, "g", "e") }; }
    template<typename T> R<T> green_on_light_blue(T t) { return R<T> { S<T>(t, "g", "lb") }; }
    template<typename T> R<T> green_on_light_green(T t) { return R<T> { S<T>(t, "g", "lg") }; }
    template<typename T> R<T> green_on_light_cyan(T t) { return R<T> { S<T>(t, "g", "lc") }; }
    template<typename T> R<T> green_on_light_red(T t) { return R<T> { S<T>(t, "g", "lr") }; }
    template<typename T> R<T> green_on_light_purple(T t) { return R<T> { S<T>(t, "g", "lp") }; }
    template<typename T> R<T> green_on_light_yellow(T t) { return R<T> { S<T>(t, "g", "ly") }; }
    template<typename T> R<T> green_on_light_white(T t) { return R<T> { S<T>(t, "g", "lw") }; }
    template<typename T> R<T> cyan_on_black(T t) { return R<T> { S<T>(t, "c", "k") }; }
    template<typename T> R<T> cyan_on_blue(T t) { return R<T> { S<T>(t, "c", "b") }; }
    template<typename T> R<T> cyan_on_green(T t) { return R<T> { S<T>(t, "c", "g") }; }
    template<typename T> R<T> cyan_on_cyan(T t) { return R<T> { S<T>(t, "c", "c") }; }
    template<typename T> R<T> cyan_on_red(T t) { return R<T> { S<T>(t, "c", "r") }; }
    template<typename T> R<T> cyan_on_purple(T t) { return R<T> { S<T>(t, "c", "p") }; }
    template<typename T> R<T> cyan_on_yellow(T t) { return R<T> { S<T>(t, "c", "y") }; }
    template<typename T> R<T> cyan_on_white(T t) { return R<T> { S<T>(t, "c", "w") }; }
    template<typename T> R<T> cyan_on_gray(T t) { return R<T> { S<T>(t, "c", "e") }; }
    template<typename T> R<T> cyan_on_light_blue(T t) { return R<T> { S<T>(t, "c", "lb") }; }
    template<typename T> R<T> cyan_on_light_green(T t) { return R<T> { S<T>(t, "c", "lg") }; }
    template<typename T> R<T> cyan_on_light_cyan(T t) { return R<T> { S<T>(t, "c", "lc") }; }
    template<typename T> R<T> cyan_on_light_red(T t) { return R<T> { S<T>(t, "c", "lr") }; }
    template<typename T> R<T> cyan_on_light_purple(T t) { return R<T> { S<T>(t, "c", "lp") }; }
    template<typename T> R<T> cyan_on_light_yellow(T t) { return R<T> { S<T>(t, "c", "ly") }; }
    template<typename T> R<T> cyan_on_light_white(T t) { return R<T> { S<T>(t, "c", "lw") }; }
    template<typename T> R<T> red_on_black(T t) { return R<T> { S<T>(t, "r", "k") }; }
    template<typename T> R<T> red_on_blue(T t) { return R<T> { S<T>(t, "r", "b") }; }
    template<typename T> R<T> red_on_green(T t) { return R<T> { S<T>(t, "r", "g") }; }
    template<typename T> R<T> red_on_cyan(T t) { return R<T> { S<T>(t, "r", "c") }; }
    template<typename T> R<T> red_on_red(T t) { return R<T> { S<T>(t, "r", "r") }; }
    template<typename T> R<T> red_on_purple(T t) { return R<T> { S<T>(t, "r", "p") }; }
    template<typename T> R<T> red_on_yellow(T t) { return R<T> { S<T>(t, "r", "y") }; }
    template<typename T> R<T> red_on_white(T t) { return R<T> { S<T>(t, "r", "w") }; }
    template<typename T> R<T> red_on_gray(T t) { return R<T> { S<T>(t, "r", "e") }; }
    template<typename T> R<T> red_on_light_blue(T t) { return R<T> { S<T>(t, "r", "lb") }; }
    template<typename T> R<T> red_on_light_green(T t) { return R<T> { S<T>(t, "r", "lg") }; }
    template<typename T> R<T> red_on_light_cyan(T t) { return R<T> { S<T>(t, "r", "lc") }; }
    template<typename T> R<T> red_on_light_red(T t) { return R<T> { S<T>(t, "r", "lr") }; }
    template<typename T> R<T> red_on_light_purple(T t) { return R<T> { S<T>(t, "r", "lp") }; }
    template<typename T> R<T> red_on_light_yellow(T t) { return R<T> { S<T>(t, "r", "ly") }; }
    template<typename T> R<T> red_on_light_white(T t) { return R<T> { S<T>(t, "r", "lw") }; }
    template<typename T> R<T> purple_on_black(T t) { return R<T> { S<T>(t, "p", "k") }; }
    template<typename T> R<T> purple_on_blue(T t) { return R<T> { S<T>(t, "p", "b") }; }
    template<typename T> R<T> purple_on_green(T t) { return R<T> { S<T>(t, "p", "g") }; }
    template<typename T> R<T> purple_on_cyan(T t) { return R<T> { S<T>(t, "p", "c") }; }
    template<typename T> R<T> purple_on_red(T t) { return R<T> { S<T>(t, "p", "r") }; }
    template<typename T> R<T> purple_on_purple(T t) { return R<T> { S<T>(t, "p", "p") }; }
    template<typename T> R<T> purple_on_yellow(T t) { return R<T> { S<T>(t, "p", "y") }; }
    template<typename T> R<T> purple_on_white(T t) { return R<T> { S<T>(t, "p", "w") }; }
    template<typename T> R<T> purple_on_gray(T t) { return R<T> { S<T>(t, "p", "e") }; }
    template<typename T> R<T> purple_on_light_blue(T t) { return R<T> { S<T>(t, "p", "lb") }; }
    template<typename T> R<T> purple_on_light_green(T t) { return R<T> { S<T>(t, "p", "lg") }; }
    template<typename T> R<T> purple_on_light_cyan(T t) { return R<T> { S<T>(t, "p", "lc") }; }
    template<typename T> R<T> purple_on_light_red(T t) { return R<T> { S<T>(t, "p", "lr") }; }
    template<typename T> R<T> purple_on_light_purple(T t) { return R<T> { S<T>(t, "p", "lp") }; }
    template<typename T> R<T> purple_on_light_yellow(T t) { return R<T> { S<T>(t, "p", "ly") }; }
    template<typename T> R<T> purple_on_light_white(T t) { return R<T> { S<T>(t, "p", "lw") }; }
    template<typename T> R<T> yellow_on_black(T t) { return R<T> { S<T>(t, "y", "k") }; }
    template<typename T> R<T> yellow_on_blue(T t) { return R<T> { S<T>(t, "y", "b") }; }
    template<typename T> R<T> yellow_on_green(T t) { return R<T> { S<T>(t, "y", "g") }; }
    template<typename T> R<T> yellow_on_cyan(T t) { return R<T> { S<T>(t, "y", "c") }; }
    template<typename T> R<T> yellow_on_red(T t) { return R<T> { S<T>(t, "y", "r") }; }
    template<typename T> R<T> yellow_on_purple(T t) { return R<T> { S<T>(t, "y", "p") }; }
    template<typename T> R<T> yellow_on_yellow(T t) { return R<T> { S<T>(t, "y", "y") }; }
    template<typename T> R<T> yellow_on_white(T t) { return R<T> { S<T>(t, "y", "w") }; }
    template<typename T> R<T> yellow_on_gray(T t) { return R<T> { S<T>(t, "y", "e") }; }
    template<typename T> R<T> yellow_on_light_blue(T t) { return R<T> { S<T>(t, "y", "lb") }; }
    template<typename T> R<T> yellow_on_light_green(T t) { return R<T> { S<T>(t, "y", "lg") }; }
    template<typename T> R<T> yellow_on_light_cyan(T t) { return R<T> { S<T>(t, "y", "lc") }; }
    template<typename T> R<T> yellow_on_light_red(T t) { return R<T> { S<T>(t, "y", "lr") }; }
    template<typename T> R<T> yellow_on_light_purple(T t) { return R<T> { S<T>(t, "y", "lp") }; }
    template<typename T> R<T> yellow_on_light_yellow(T t) { return R<T> { S<T>(t, "y", "ly") }; }
    template<typename T> R<T> yellow_on_light_white(T t) { return R<T> { S<T>(t, "y", "lw") }; }
    template<typename T> R<T> white_on_black(T t) { return R<T> { S<T>(t, "w", "k") }; }
    template<typename T> R<T> white_on_blue(T t) { return R<T> { S<T>(t, "w", "b") }; }
    template<typename T> R<T> white_on_green(T t) { return R<T> { S<T>(t, "w", "g") }; }
    template<typename T> R<T> white_on_cyan(T t) { return R<T> { S<T>(t, "w", "c") }; }
    template<typename T> R<T> white_on_red(T t) { return R<T> { S<T>(t, "w", "r") }; }
    template<typename T> R<T> white_on_purple(T t) { return R<T> { S<T>(t, "w", "p") }; }
    template<typename T> R<T> white_on_yellow(T t) { return R<T> { S<T>(t, "w", "y") }; }
    template<typename T> R<T> white_on_white(T t) { return R<T> { S<T>(t, "w", "w") }; }
    template<typename T> R<T> white_on_gray(T t) { return R<T> { S<T>(t, "w", "e") }; }
    template<typename T> R<T> white_on_light_blue(T t) { return R<T> { S<T>(t, "w", "lb") }; }
    template<typename T> R<T> white_on_light_green(T t) { return R<T> { S<T>(t, "w", "lg") }; }
    template<typename T> R<T> white_on_light_cyan(T t) { return R<T> { S<T>(t, "w", "lc") }; }
    template<typename T> R<T> white_on_light_red(T t) { return R<T> { S<T>(t, "w", "lr") }; }
    template<typename T> R<T> white_on_light_purple(T t) { return R<T> { S<T>(t, "w", "lp") }; }
    template<typename T> R<T> white_on_light_yellow(T t) { return R<T> { S<T>(t, "w", "ly") }; }
    template<typename T> R<T> white_on_light_white(T t) { return R<T> { S<T>(t, "w", "lw") }; }
    template<typename T> R<T> gray_on_black(T t) { return R<T> { S<T>(t, "e", "k") }; }
    template<typename T> R<T> gray_on_blue(T t) { return R<T> { S<T>(t, "e", "b") }; }
    template<typename T> R<T> gray_on_green(T t) { return R<T> { S<T>(t, "e", "g") }; }
    template<typename T> R<T> gray_on_cyan(T t) { return R<T> { S<T>(t, "e", "c") }; }
    template<typename T> R<T> gray_on_red(T t) { return R<T> { S<T>(t, "e", "r") }; }
    template<typename T> R<T> gray_on_purple(T t) { return R<T> { S<T>(t, "e", "p") }; }
    template<typename T> R<T> gray_on_yellow(T t) { return R<T> { S<T>(t, "e", "y") }; }
    template<typename T> R<T> gray_on_white(T t) { return R<T> { S<T>(t, "e", "w") }; }
    template<typename T> R<T> gray_on_gray(T t) { return R<T> { S<T>(t, "e", "e") }; }
    template<typename T> R<T> gray_on_light_blue(T t) { return R<T> { S<T>(t, "e", "lb") }; }
    template<typename T> R<T> gray_on_light_green(T t) { return R<T> { S<T>(t, "e", "lg") }; }
    template<typename T> R<T> gray_on_light_cyan(T t) { return R<T> { S<T>(t, "e", "lc") }; }
    template<typename T> R<T> gray_on_light_red(T t) { return R<T> { S<T>(t, "e", "lr") }; }
    template<typename T> R<T> gray_on_light_purple(T t) { return R<T> { S<T>(t, "e", "lp") }; }
    template<typename T> R<T> gray_on_light_yellow(T t) { return R<T> { S<T>(t, "e", "ly") }; }
    template<typename T> R<T> gray_on_light_white(T t) { return R<T> { S<T>(t, "e", "lw") }; }
    template<typename T> R<T> light_blue_on_black(T t) { return R<T> { S<T>(t, "lb", "k") }; }
    template<typename T> R<T> light_blue_on_blue(T t) { return R<T> { S<T>(t, "lb", "b") }; }
    template<typename T> R<T> light_blue_on_green(T t) { return R<T> { S<T>(t, "lb", "g") }; }
    template<typename T> R<T> light_blue_on_cyan(T t) { return R<T> { S<T>(t, "lb", "c") }; }
    template<typename T> R<T> light_blue_on_red(T t) { return R<T> { S<T>(t, "lb", "r") }; }
    template<typename T> R<T> light_blue_on_purple(T t) { return R<T> { S<T>(t, "lb", "p") }; }
    template<typename T> R<T> light_blue_on_yellow(T t) { return R<T> { S<T>(t, "lb", "y") }; }
    template<typename T> R<T> light_blue_on_white(T t) { return R<T> { S<T>(t, "lb", "w") }; }
    template<typename T> R<T> light_blue_on_gray(T t) { return R<T> { S<T>(t, "lb", "e") }; }
    template<typename T> R<T> light_blue_on_light_blue(T t) { return R<T> { S<T>(t, "lb", "lb") }; }
    template<typename T> R<T> light_blue_on_light_green(T t) { return R<T> { S<T>(t, "lb", "lg") }; }
    template<typename T> R<T> light_blue_on_light_cyan(T t) { return R<T> { S<T>(t, "lb", "lc") }; }
    template<typename T> R<T> light_blue_on_light_red(T t) { return R<T> { S<T>(t, "lb", "lr") }; }
    template<typename T> R<T> light_blue_on_light_purple(T t) { return R<T> { S<T>(t, "lb", "lp") }; }
    template<typename T> R<T> light_blue_on_light_yellow(T t) { return R<T> { S<T>(t, "lb", "ly") }; }
    template<typename T> R<T> light_blue_on_light_white(T t) { return R<T> { S<T>(t, "lb", "lw") }; }
    template<typename T> R<T> light_green_on_black(T t) { return R<T> { S<T>(t, "lg", "k") }; }
    template<typename T> R<T> light_green_on_blue(T t) { return R<T> { S<T>(t, "lg", "b") }; }
    template<typename T> R<T> light_green_on_green(T t) { return R<T> { S<T>(t, "lg", "g") }; }
    template<typename T> R<T> light_green_on_cyan(T t) { return R<T> { S<T>(t, "lg", "c") }; }
    template<typename T> R<T> light_green_on_red(T t) { return R<T> { S<T>(t, "lg", "r") }; }
    template<typename T> R<T> light_green_on_purple(T t) { return R<T> { S<T>(t, "lg", "p") }; }
    template<typename T> R<T> light_green_on_yellow(T t) { return R<T> { S<T>(t, "lg", "y") }; }
    template<typename T> R<T> light_green_on_white(T t) { return R<T> { S<T>(t, "lg", "w") }; }
    template<typename T> R<T> light_green_on_gray(T t) { return R<T> { S<T>(t, "lg", "e") }; }
    template<typename T> R<T> light_green_on_light_blue(T t) { return R<T> { S<T>(t, "lg", "lb") }; }
    template<typename T> R<T> light_green_on_light_green(T t) { return R<T> { S<T>(t, "lg", "lg") }; }
    template<typename T> R<T> light_green_on_light_cyan(T t) { return R<T> { S<T>(t, "lg", "lc") }; }
    template<typename T> R<T> light_green_on_light_red(T t) { return R<T> { S<T>(t, "lg", "lr") }; }
    template<typename T> R<T> light_green_on_light_purple(T t) { return R<T> { S<T>(t, "lg", "lp") }; }
    template<typename T> R<T> light_green_on_light_yellow(T t) { return R<T> { S<T>(t, "lg", "ly") }; }
    template<typename T> R<T> light_green_on_light_white(T t) { return R<T> { S<T>(t, "lg", "lw") }; }
    template<typename T> R<T> light_cyan_on_black(T t) { return R<T> { S<T>(t, "lc", "k") }; }
    template<typename T> R<T> light_cyan_on_blue(T t) { return R<T> { S<T>(t, "lc", "b") }; }
    template<typename T> R<T> light_cyan_on_green(T t) { return R<T> { S<T>(t, "lc", "g") }; }
    template<typename T> R<T> light_cyan_on_cyan(T t) { return R<T> { S<T>(t, "lc", "c") }; }
    template<typename T> R<T> light_cyan_on_red(T t) { return R<T> { S<T>(t, "lc", "r") }; }
    template<typename T> R<T> light_cyan_on_purple(T t) { return R<T> { S<T>(t, "lc", "p") }; }
    template<typename T> R<T> light_cyan_on_yellow(T t) { return R<T> { S<T>(t, "lc", "y") }; }
    template<typename T> R<T> light_cyan_on_white(T t) { return R<T> { S<T>(t, "lc", "w") }; }
    template<typename T> R<T> light_cyan_on_gray(T t) { return R<T> { S<T>(t, "lc", "e") }; }
    template<typename T> R<T> light_cyan_on_light_blue(T t) { return R<T> { S<T>(t, "lc", "lb") }; }
    template<typename T> R<T> light_cyan_on_light_green(T t) { return R<T> { S<T>(t, "lc", "lg") }; }
    template<typename T> R<T> light_cyan_on_light_cyan(T t) { return R<T> { S<T>(t, "lc", "lc") }; }
    template<typename T> R<T> light_cyan_on_light_red(T t) { return R<T> { S<T>(t, "lc", "lr") }; }
    template<typename T> R<T> light_cyan_on_light_purple(T t) { return R<T> { S<T>(t, "lc", "lp") }; }
    template<typename T> R<T> light_cyan_on_light_yellow(T t) { return R<T> { S<T>(t, "lc", "ly") }; }
    template<typename T> R<T> light_cyan_on_light_white(T t) { return R<T> { S<T>(t, "lc", "lw") }; }
    template<typename T> R<T> light_red_on_black(T t) { return R<T> { S<T>(t, "lr", "k") }; }
    template<typename T> R<T> light_red_on_blue(T t) { return R<T> { S<T>(t, "lr", "b") }; }
    template<typename T> R<T> light_red_on_green(T t) { return R<T> { S<T>(t, "lr", "g") }; }
    template<typename T> R<T> light_red_on_cyan(T t) { return R<T> { S<T>(t, "lr", "c") }; }
    template<typename T> R<T> light_red_on_red(T t) { return R<T> { S<T>(t, "lr", "r") }; }
    template<typename T> R<T> light_red_on_purple(T t) { return R<T> { S<T>(t, "lr", "p") }; }
    template<typename T> R<T> light_red_on_yellow(T t) { return R<T> { S<T>(t, "lr", "y") }; }
    template<typename T> R<T> light_red_on_white(T t) { return R<T> { S<T>(t, "lr", "w") }; }
    template<typename T> R<T> light_red_on_gray(T t) { return R<T> { S<T>(t, "lr", "e") }; }
    template<typename T> R<T> light_red_on_light_blue(T t) { return R<T> { S<T>(t, "lr", "lb") }; }
    template<typename T> R<T> light_red_on_light_green(T t) { return R<T> { S<T>(t, "lr", "lg") }; }
    template<typename T> R<T> light_red_on_light_cyan(T t) { return R<T> { S<T>(t, "lr", "lc") }; }
    template<typename T> R<T> light_red_on_light_red(T t) { return R<T> { S<T>(t, "lr", "lr") }; }
    template<typename T> R<T> light_red_on_light_purple(T t) { return R<T> { S<T>(t, "lr", "lp") }; }
    template<typename T> R<T> light_red_on_light_yellow(T t) { return R<T> { S<T>(t, "lr", "ly") }; }
    template<typename T> R<T> light_red_on_light_white(T t) { return R<T> { S<T>(t, "lr", "lw") }; }
    template<typename T> R<T> light_purple_on_black(T t) { return R<T> { S<T>(t, "lp", "k") }; }
    template<typename T> R<T> light_purple_on_blue(T t) { return R<T> { S<T>(t, "lp", "b") }; }
    template<typename T> R<T> light_purple_on_green(T t) { return R<T> { S<T>(t, "lp", "g") }; }
    template<typename T> R<T> light_purple_on_cyan(T t) { return R<T> { S<T>(t, "lp", "c") }; }
    template<typename T> R<T> light_purple_on_red(T t) { return R<T> { S<T>(t, "lp", "r") }; }
    template<typename T> R<T> light_purple_on_purple(T t) { return R<T> { S<T>(t, "lp", "p") }; }
    template<typename T> R<T> light_purple_on_yellow(T t) { return R<T> { S<T>(t, "lp", "y") }; }
    template<typename T> R<T> light_purple_on_white(T t) { return R<T> { S<T>(t, "lp", "w") }; }
    template<typename T> R<T> light_purple_on_gray(T t) { return R<T> { S<T>(t, "lp", "e") }; }
    template<typename T> R<T> light_purple_on_light_blue(T t) { return R<T> { S<T>(t, "lp", "lb") }; }
    template<typename T> R<T> light_purple_on_light_green(T t) { return R<T> { S<T>(t, "lp", "lg") }; }
    template<typename T> R<T> light_purple_on_light_cyan(T t) { return R<T> { S<T>(t, "lp", "lc") }; }
    template<typename T> R<T> light_purple_on_light_red(T t) { return R<T> { S<T>(t, "lp", "lr") }; }
    template<typename T> R<T> light_purple_on_light_purple(T t) { return R<T> { S<T>(t, "lp", "lp") }; }
    template<typename T> R<T> light_purple_on_light_yellow(T t) { return R<T> { S<T>(t, "lp", "ly") }; }
    template<typename T> R<T> light_purple_on_light_white(T t) { return R<T> { S<T>(t, "lp", "lw") }; }
    template<typename T> R<T> light_yellow_on_black(T t) { return R<T> { S<T>(t, "ly", "k") }; }
    template<typename T> R<T> light_yellow_on_blue(T t) { return R<T> { S<T>(t, "ly", "b") }; }
    template<typename T> R<T> light_yellow_on_green(T t) { return R<T> { S<T>(t, "ly", "g") }; }
    template<typename T> R<T> light_yellow_on_cyan(T t) { return R<T> { S<T>(t, "ly", "c") }; }
    template<typename T> R<T> light_yellow_on_red(T t) { return R<T> { S<T>(t, "ly", "r") }; }
    template<typename T> R<T> light_yellow_on_purple(T t) { return R<T> { S<T>(t, "ly", "p") }; }
    template<typename T> R<T> light_yellow_on_yellow(T t) { return R<T> { S<T>(t, "ly", "y") }; }
    template<typename T> R<T> light_yellow_on_white(T t) { return R<T> { S<T>(t, "ly", "w") }; }
    template<typename T> R<T> light_yellow_on_gray(T t) { return R<T> { S<T>(t, "ly", "e") }; }
    template<typename T> R<T> light_yellow_on_light_blue(T t) { return R<T> { S<T>(t, "ly", "lb") }; }
    template<typename T> R<T> light_yellow_on_light_green(T t) { return R<T> { S<T>(t, "ly", "lg") }; }
    template<typename T> R<T> light_yellow_on_light_cyan(T t) { return R<T> { S<T>(t, "ly", "lc") }; }
    template<typename T> R<T> light_yellow_on_light_red(T t) { return R<T> { S<T>(t, "ly", "lr") }; }
    template<typename T> R<T> light_yellow_on_light_purple(T t) { return R<T> { S<T>(t, "ly", "lp") }; }
    template<typename T> R<T> light_yellow_on_light_yellow(T t) { return R<T> { S<T>(t, "ly", "ly") }; }
    template<typename T> R<T> light_yellow_on_light_white(T t) { return R<T> { S<T>(t, "ly", "lw") }; }
    template<typename T> R<T> light_white_on_black(T t) { return R<T> { S<T>(t, "lw", "k") }; }
    template<typename T> R<T> light_white_on_blue(T t) { return R<T> { S<T>(t, "lw", "b") }; }
    template<typename T> R<T> light_white_on_green(T t) { return R<T> { S<T>(t, "lw", "g") }; }
    template<typename T> R<T> light_white_on_cyan(T t) { return R<T> { S<T>(t, "lw", "c") }; }
    template<typename T> R<T> light_white_on_red(T t) { return R<T> { S<T>(t, "lw", "r") }; }
    template<typename T> R<T> light_white_on_purple(T t) { return R<T> { S<T>(t, "lw", "p") }; }
    template<typename T> R<T> light_white_on_yellow(T t) { return R<T> { S<T>(t, "lw", "y") }; }
    template<typename T> R<T> light_white_on_white(T t) { return R<T> { S<T>(t, "lw", "w") }; }
    template<typename T> R<T> light_white_on_gray(T t) { return R<T> { S<T>(t, "lw", "e") }; }
    template<typename T> R<T> light_white_on_light_blue(T t) { return R<T> { S<T>(t, "lw", "lb") }; }
    template<typename T> R<T> light_white_on_light_green(T t) { return R<T> { S<T>(t, "lw", "lg") }; }
    template<typename T> R<T> light_white_on_light_cyan(T t) { return R<T> { S<T>(t, "lw", "lc") }; }
    template<typename T> R<T> light_white_on_light_red(T t) { return R<T> { S<T>(t, "lw", "lr") }; }
    template<typename T> R<T> light_white_on_light_purple(T t) { return R<T> { S<T>(t, "lw", "lp") }; }
    template<typename T> R<T> light_white_on_light_yellow(T t) { return R<T> { S<T>(t, "lw", "ly") }; }
    template<typename T> R<T> light_white_on_light_white(T t) { return R<T> { S<T>(t, "lw", "lw") }; }
}

#endif 
