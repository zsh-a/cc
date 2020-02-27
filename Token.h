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
    Token(Tag t):tag(t){}

public:
    static unordered_map<string,Tag> key_words;
};
unordered_map<string,Tag> Token::key_words = {
    {"int",KW_INT},
    {"char",KW_CHAR},
    {}
};
// id token
class Id:public Token{
public:
    string name;
    Id(const string& id):Token(ID),name(id){}
};

// char constant
class Char:public Token{
public:
    char ch;
    Char(char c):Token(CH),ch(c){}
};
// string constant
class Str:public Token{
public:
    string str;
    Str(const string& s):Token(STR),str(s){}
};

// num constant
class Num:public Token{
public:
    int num;
    Num(int n):Token(NUM),num(n){}
};

#endif