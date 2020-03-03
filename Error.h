#ifndef __ERROR__
#define __ERROR__
#include"Lexer.h"
class Scanner;
class Error{
    static Scanner* scanner;
    
public:
    static int errorNum;
    static void lexError(int code);
    static void synError(int code,Token* token);
    Error(Scanner* sc){
        scanner = sc;
    }
};
#define LEXERROR(code) Error::lexError(code)
#endif