#ifndef __SCANNER__
#define __SCANNER__
#include<iostream>
#include"const.h"
#include"Token.h"
#define MAX_BUFFER_SIZE 1024

class Scanner{
public:
    Scanner(const char* name);
    ~Scanner();
    int scan();
    int peek();
private:
    FILE* fd;
    const char* filename;
    int line_num = 1;
    int col_num = 0;
    char buffer[MAX_BUFFER_SIZE];
    int read_pos = -1; //
    int line_len = 0; // lenght of buffer
    char last_ch = EOF;

    void load_buff();
};

class Lexer{
public:
    Lexer(Scanner& sc):scanner(sc){
    }

    Token* tokenize();
private:
    Scanner& scanner;
    Token* token = nullptr;
    char ch = ' ';
    bool scan(int need = 0);
    char peek(){
        return scanner.peek();
    };
    void skip_white_space(){
        if(ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
            ch = scanner.scan();
    };
};
#endif