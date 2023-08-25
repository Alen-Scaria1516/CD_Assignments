#include <bits/stdc++.h>
using namespace std;
 
//The grammar:
//E -> -E | E+T | E-T | T
//T -> T*F | T/F | F
//F -> (E) | i
 
/*Modified grammar without left recursion and left factoring
E -> TE' | -E                   ......1
E' -> +TE' | -TE' | e           ......2
T -> FT'                        ......3
T' -> *FT' | /FT' | e           ......4
F -> (E) | i                    ......5
*/
class grammar{
public:
    string input;
    string state = "";
    int input_symbol = 0;
    void takeinput(string s){
        input = s;
    }
    void ADVANCE(){ input_symbol++; }
    void E(){
        if(input[input_symbol] == '-'){
            ADVANCE();
            cout<<"matched by rule 1\n";
            state += "-E";
            cout<<"current state: "<<state<<'\n';
            E();
        }else{
            cout<<"matched by rule 1\n";
            state += "TE'";
            cout<<"current state: "<<state<<'\n';
            T();
            EPRIME();
        }
    }
    void EPRIME(){
        if(input[input_symbol] == '+' || input[input_symbol] == '-'){
            ADVANCE();
            cout<<"matched by rule 2\n";
            if(input[input_symbol] == '+')
                state += "+TE'";
            else
                state += "-TE'";
            cout<<"current state: "<<state<<'\n';
            T();
            EPRIME();
        }
    }
    void T(){
        cout<<"matched by rule 3\n";
            state += "FT'";
            cout<<"current state: "<<state<<'\n';
        F();
        TPRIME();
    }
    void TPRIME(){
        if(input[input_symbol] == '*' || input[input_symbol] == '/'){
            cout<<"matched by rule 4\n";
            if(input[input_symbol] == '*')
                state += "*FT'";
            else state += "/FT'";
            cout<<"current state: "<<state<<'\n';
            F();
            TPRIME();
        }
    }
    void F(){
        if(input[input_symbol] == 'i'){
            ADVANCE();
            cout<<"matched by rule 5\n";
            state += "i";
            cout<<"current state: "<<state<<'\n';
        }else if(input[input_symbol] == '('){
            ADVANCE();
            E();
            if(input[input_symbol] == ')'){
                ADVANCE();
                cout<<"matched by rule 5\n";
                state += "(E)";
                cout<<"current state: "<<state<<'\n';
            }else ERROR(input_symbol, {')'});
        }
        else
            ERROR(input_symbol, {'(', 'i'});
    }
    void ERROR(int input_symbol, vector<char> expectation){
        for(int i = 0; i < expectation.size(); i++){
            if(expectation[i] == 'i'){
                cout<<"Operand var missing at position ";
            }else
                cout<<"Parenthesis missing at position ";
            cout<<input_symbol<<'\n';
        }
    }
};
 
int main(){
    grammar obj;
    string s;
    cin>> s;
    obj.takeinput(s);
    obj.E();
    if(obj.input[obj.input_symbol] == '$')
        cout<<"Parsing Successful\n";
    else cout<<"String not accepted.\n";
}
