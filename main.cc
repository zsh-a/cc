#include"Lexer.h"
using namespace std;
int main(){
    Scanner sc("../test/main.cc");
    Lexer lex(sc);
    Token* tk;
    int ch;
    //while( (ch = sc.scan())!= EOF) printf("%c",ch);
    Error e(&sc);
    while((tk = lex.tokenize())->tag!= END){
        cout << "token : " << tk->to_string() << endl;
    }
    return 0;
}
