#ifndef __CONST__
#define __CONST__
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;

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

enum LexError{
    STR_NO_QUTION,
    NUM_BIN_TYPE,
    NUM_HEX_TYPE,
    CHAR_NO_R_QUTION,
    CHAR_NO_DATA,
    OR_NOT_PAIR,
    COMMENT_NO_END,
    TKOEN_NO_EXIST
};
enum {
    FILE_IO_ERROR
};


enum SynError{
    TYPE_LOST,
    TYPE_WRONG,
    ID_LOST,
    ID_WRONG,
    NUM_LOST,
    NUM_WRONG,
    LITERAL_LOST,
    LITERAL_WRONG,
    COMMA_LOST,
    COMMA_WRONG,
    SEMICON_LOST,
    SEMICON_WRONG,
    ASSIGN_LOST,
    ASSIGN_WRONG,
    COLON_LOST,
    COLON_WRONG,
    WHILE_LOST,
    WHILE_WRONG,
    LPAREN_LOST,
    LPAREN_WRONG,
    RPAREN_LOST,
    RPAREN_WRONG,
    LBRACE_LOST,
    RBRACE_LOST,
    RBRACE_WRONG,
    LBRACK_LOST,
    LBRACK_WRONG,
    RBRACK_LOST,
    RBRACK_WRONG,
};
#endif