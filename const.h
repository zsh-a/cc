#ifndef __CONST__
#define __CONST__
enum Tag{
    ERR,
    END,  // end of file
    ID, // identifier
    KW_INT,KW_CHAR,KW_VOID,
    KW_EXTERN,
    NUM,CH,STR, // constant
    NOT,LEA,
    ADD,SUB,MUL,DIV,MOD,
    INC,DEC,
    GT,GE,LT,LE,EQU,NEQU,
    AND,OR,
    LPAREN,RPAREN, // ()
    LBRACK,RBRACK, // []
    LBRACE,RBRACE, // {}
    COMMA,COLON,SEMICON, // , :  ;
    ASSIGN, // =
    KW_IF,KW_ELSE,
    KW_SWITCH,KW_CASE,KW_DEFAULT,
    KW_WHILE,KW_DO,KW_FOR,
    KW_BREAK,KW_CONTINUE,KW_RETURN

};

enum {
    FILE_IO_ERROR
};

#endif