#include"Token.h"
unordered_map<string,Tag> Token::key_words = {
    {"int",KW_INT},
    {"char",KW_CHAR},
    {"void",KW_VOID},
    {"extern",KW_EXTERN},
    {"if",KW_IF},
    {"else",KW_ELSE},
    {"switch",KW_SWITCH},
    {"case",KW_CASE},
    {"default",KW_DEFAULT},
    {"while",KW_WHILE},
    {"do",KW_DO},
    {"for",KW_FOR},
    {"break",KW_BREAK},
    {"continue",KW_CONTINUE},
    {"return",KW_RETURN}
};