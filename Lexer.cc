#include"Lexer.h"

Scanner::Scanner(const char* name){
    fd = fopen(name,"r");
    if(!fd){
        printf("file %s open failed\n",name);
        exit(FILE_IO_ERROR);
    }
    filename = name;

}
void Scanner::load_buff(){
    if(read_pos == line_len -1){
        // buffer has been used
        line_len = fread(buffer,1,MAX_BUFFER_SIZE,fd);
        if(line_len == 0){
            line_len = 1;
            buffer[0] = EOF;
        }
        read_pos = -1;
    }
}
int Scanner::peek(){
    load_buff();
    return buffer[read_pos + 1];
}
int Scanner::scan(){
    if(!fd){
        // no file
        return -1;
    }
    load_buff();
    read_pos++;
    char ch = buffer[read_pos];
    if(ch == '\n'){
        line_num++;
        col_num = 0;
    }else if(ch == EOF){
        fclose(fd);
        fd =nullptr;
    }else{
        col_num++;
    }
    last_ch = ch;
    return ch;
}

Scanner::~Scanner(){
    if(fd){
        fclose(fd);
    }
}

bool Lexer::scan(int need){

    ch = scanner.scan();
    if(need){
        if(ch != need) return false;
        ch = scanner.scan();
        return true;
    }
    return true;
}

Token* Lexer::tokenize(){

    while(ch != EOF){
        
        Tag tag;
        Token* tk = nullptr;
        skip_white_space();
        
        if(isalpha(ch) || ch == '_'){ // id keyword
            
            string name;
            name += ch;
            scan();
            while(isalpha(ch) || isdigit(ch) || ch == '_'){
                name += ch;
                scan();
            }
            Tag t = Token::getTag(name);
            if(t == ID) tk = new Id(name);
            else tk = new Token(t);
        }else if(ch == '"'){ //string
            string s;
            while(!scan('"')){
                if(ch == '\\'){
                    scan();
                    if(ch == 'n') s.push_back('\n');
                    else if(ch == '\\') s.push_back('\\');
                    else if(ch == 't') s.push_back('\t');
                    else if(ch == '"') s.push_back('"');
                    else if(ch == 0) s.push_back('\0');
                    else if(ch == EOF){
                        tk = new Token(ERR);
                    }
                }else if(ch == EOF || ch == '\n'){
                    // end of file
                    tk = new Token(ERR);
                }else
                    s.push_back(ch);
            }
            if(!tk) tk = new Str(s);
        }else if(isdigit(ch)){ // num constant
            int val = 0;
            if(ch == '0'){
                scan();
                if(ch == 'x' || ch == 'X'){
                    scan();
                    if(isdigit(ch) || (ch >='A' && ch <= 'F') || (ch >='a' || ch <='f')){
                        while(isdigit(ch) || (ch >='A' && ch <= 'F') || (ch >='a' || ch <='f')){
                            val = val * 16  + (ch & 15) + (ch>='A'?9:0); // 16 to 10
                            scan();
                        }
                    }else{

                        tk = new Token(ERR);
                    }
                    
                }else if(ch == 'b' || ch == 'B'){ // binary
                    scan();
                    if(ch == '0' || ch == '1'){
                        while(ch == '0' || ch == '1'){
                            val = val*2 + ch -'0';
                            scan();
                        }
                    }else{
                        tk = new Token(ERR);
                    }
                }else if(ch >= '0' && ch <='7'){
                    while(ch >='0' && ch <='7'){
                        val = val*8 + ch - '0';
                        scan();
                    }
                }
            }else{
                // decincal
                while(isdigit(ch)){
                    val = val*10 + ch -'0';
                    scan();
                }
            }
            if(!tk) tk = new Num(val);
        }else if(ch == '\''){ // char constant
            char c;
            scan();
            if(ch == '\\'){
                scan();
                if(ch == 'n') c = '\n';
                else if(ch ==  't') c = '\t';
                else if(ch == '0') c = '\0';
                else if(ch == '\\')c = '\\';
                else if(ch == EOF||c == '\n'){
                    //error
                    tk = new Token(ERR);
                }else c = ch;
            }else if(ch == EOF||ch == '\n'){
                //error
                tk = new Token(ERR);
            }else if(ch == '\''){
                //error
                tk = new Token(ERR);
                scan();
            }else{
                c = ch;
            }
            if(!tk){
                if(scan('\'')) tk = new Char(c);
                else{
                    tk = new Token(ERR);
                }
            }
        }else if(ch == '%'){
            tk = new Token(MOD);
            scan();
        }else if(ch == '>'){
            tag = GT;
            scan();
            if(ch == '='){
                tag = GE;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '+'){
            tag = ADD;
            scan();
            if(ch == '+'){
                tag = INC;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '-'){
            tag = SUB;
            scan();
            if(ch == '-'){
                tag = DEC;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '*'){
            tk = new Token(MUL);
            scan();
        }else if(ch == '/'){
            // comment
            scan();
            if(ch == '/'){
                while(!(ch == '\n' || ch == EOF))
                    scan();
                tk = new Token(ERR);
            }else if(ch == '*'){
                while(!scan(EOF)){
                    if(ch == '*'){
                        while(scan('*'));
                        if(ch == '/'){
                            tk = new Token(ERR);
                            break;
                        }
                    }
                }
                if(!tk && ch == EOF){
                    // comment error
                    tk = new Token(ERR);
                }
            }else{
                tk = new Token(DIV);
            }
        }else if(ch == '<'){
            tag = LT;
            scan();
            if(ch == '='){
                tag = LE;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '='){
            tag = ASSIGN;
            scan();
            if(ch == '='){
                tag = EQU;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '&'){
            tag = LEA;
            scan();
            if(ch == '&'){
                tag = AND;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == '|'){
            tag = OR;
            scan();
            if(ch != '|') {
                // error ||
                tk = new Token(ERR);
                scan();
            }else{
                tk = new Token(tag);
            }
        }else if(ch == '!'){
            tag = NOT;
            scan();
            if(ch == '='){
                tag = NEQU;
                scan();
            }
            tk = new Token(tag);
        }else if(ch == ','){
            tk = new Token(COMMA);
            scan();
        }else if(ch == ':'){
            tk = new Token(COLON);
            scan();
        }else if(ch == ';'){
            tk = new Token(SEMICON);
            scan();
        }else if(ch == '('){
            tk = new Token(LPAREN);
            scan();
        }else if(ch == ')'){
            tk = new Token(RPAREN);
            scan();
        }else if(ch == '['){
            tk = new Token(LBRACK);
            scan();
        }else if(ch == ']'){
            tk = new Token(RBRACK);
            scan();
        }else if(ch == '{'){
            tk = new Token(LBRACE);
            scan();
        }else if(ch == '}'){
            tk = new Token(RBRACE);
            scan();
        }else if(ch == EOF){
            tk = new Token(ERR);
            scan();
        }else{
            tk = new Token(ERR);
            // error
            scan();
        }

        if(token) delete token; // delete prev token
        token = tk;
        if(token && token->tag != ERR) return token; // return a vailed token
        else continue;
    }
    if(token) delete token;
    return token = new Token(END);
}