#ifndef __TOKEN__
#define __TOKEN__
#include "const.h"
#include<string>
#include<unordered_map>
using namespace std;

// basic token 
class Token{
public:
    Tag tag;
    virtual string to_string(){
        return string("tag : ") + std::to_string(tag);
    }
    Token(Tag t):tag(t){}

public:
    static unordered_map<string,Tag> key_words;
    static Tag getTag(const string& name) {
        return key_words.count(name)?key_words[name]:ID;
    }
};

// id token
class Id:public Token{
public:
    string name;
    Id(const string& id):Token(ID),name(id){}
    string to_string(){
        return string("ID : ") + name;
    }
};

// char constant
class Char:public Token{
public:
    char ch;
    Char(char c):Token(CH),ch(c){}
    string to_string(){
        return string("Char : ") + ch;
    }
};
// string constant
class Str:public Token{
public:
    string str;
    Str(const string& s):Token(STR),str(s){}
    string to_string(){
        return string("str : ") + str;
    }
};

// num constant
class Num:public Token{
public:
    int num;
    Num(int n):Token(NUM),num(n){}
    string to_string(){
        return string("str : ") + std::to_string(num);
    }
};

#endif