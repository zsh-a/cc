#include"Parser.h"
#include"Lexer.h"
Parser::Parser(Lexer& lex):lexer(lex){
}

Tag Parser::type(){
    // todo 
}

bool Parser::F(Tag tag){
    return token->tag == tag;
}

void Parser::recovery(bool cond,SynError lost,SynError wrong){ // is or not the fllowing token
    if(cond){
        // somthing miss
        Error::synError(lost,token);
    }else{
        // match error
        Error::synError(wrong,token);
        move();
    }
}
void Parser::analyse(){
    move();
    program();
}
void Parser::program(){
    if(token->tag == END) return;
    segment();
    program();
}
bool Parser::match(Tag tag){
    if(token->tag == tag){
        move();
        return true;
    }
    return false;
}
void Parser::move(){
    token = lexer.tokenize();
}


/*
    <segment>-> KW_EXTERN <type><def> | <type><def>
    <type>->KW_INT|KW_CHAR|KW_VOID
*/
void Parser::segment(){
    bool ext = match(KW_EXTERN);
    //Tag t = type();
    //def(ext,t);
}

/*
    <def>->ID <idtail> | MUL ID <init><deflist>
    // func can not return type of pointer
*/
void Parser::def(bool ext,Tag t){
    string name;
    if(match(MUL)){ // pointer
        if(F(ID)){
            name = static_cast<Id*>(token)->name;
            move();
        }else
            recovery(F(SEMICON) || F(COMMA) || F(ASSIGN),ID_LOST,ID_WRONG);
        
    }else{
        // var or array or fun
        if(F(ID)){
            name = static_cast<Id*>(token)->name;
            move();
        }else
            recovery(F(SEMICON) || F(COMMA) || F(ASSIGN) || F(LPAREN) || F(LBRACK),ID_LOST,ID_WRONG);

    }
}
