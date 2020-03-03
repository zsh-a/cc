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

void Error::synError(int code,Token* token){
    static const char* syn_error_table[]={
        "type",
        "identifier",
        "length of array",
        "constant",
        "','",
        "';'",
        "'='",
        "':'",
        "\"while\"",
        "'('",
        "')'",
        "'['",
        "']'",
        "'{'",
        "'}'"

    };
    errorNum++;
    if(code & 1){
        //wrong
        printf("%s<line:%d> syntex error : %s lost before %s .\n",
            scanner->filename,scanner->line_num,syn_error_table[code/2],token->to_string().c_str());
    }else{
        // lost
        printf("%s<line:%d> syntex error : %s wrong in %s .\n",
            scanner->filename,scanner->line_num,syn_error_table[code/2],token->to_string().c_str());
    }
}