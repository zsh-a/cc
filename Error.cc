#include"Error.h"


int Error::errorNum = 0;
Scanner* Error::scanner;
void Error::lexError(int code){
    static const char* lex_error_table[] = {
        "string miss right \"",
        "binary number has no data",
        "hex number has no data",
        "char miss right'",
        "not support empty char",
        "error 'or' operation",
        "multi comment end exceptional",
        "there is no token"
    };
    errorNum++;
    printf("%s<%d,%d> lexerror : %s\n",scanner->filename,scanner->line_num,scanner->col_num,lex_error_table[code]);

}
