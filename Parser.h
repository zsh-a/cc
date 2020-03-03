#pragma once
#include"const.h"
class Lexer;
class Token;
class Parser{
public:

    Parser(Lexer& lex);
    void analyse();
    ~Parser();
private:
    Token* token;
    void move();
    Lexer& lexer;
    Tag type();
    bool F(Tag);// token->tag == tag
    void recovery(bool,SynError lost,SynError wrong);
    bool match(Tag tag);
    void program();
    void def(bool,Tag);
    void idtail();
    void segment();
};
