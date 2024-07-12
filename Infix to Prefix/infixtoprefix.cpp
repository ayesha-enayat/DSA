
#include <iostream>
#include <cstring>
using namespace std;

char oper[100];
char pre[100];
int otop = 0;
int ptop = 0;

void pusho(char let) {
    oper[otop] = let;
    otop++;
}

void pushp(char let) {
    pre[ptop] = let;
    ptop++;
}

char pop() {
    char temp = oper[otop - 1];
    otop--;
    return temp;
}

int precedence(char op) {
    switch (op) {
        case '(':
        case ')':
            return 8;
        case '^':
            return 7;
        case '*':
        case '/':
            return 6;
        case '+':
        case '-':
            return 5;
        case '<':
        case '>':
            return 4;
        case '=':
        case '!':
            return 3;
        case '&':
            return 2;
        case '|':
            return 1;
        default:
            return 0;
    }
}

void ItoP(char* ch, int size) {
    for (int i = 0; i < size; i++) {
        if (ch[i] >= 65 && ch[i] <= 92) {
            cout << "Uppercase Alphabet\n";
            pushp(ch[i]);
        } else if (ch[i] >= 97 && ch[i] <= 122) {
            pushp(ch[i]);
            cout << "Lowercase Alphabet\n";
        } else {
            if (otop == 0) {
                pusho(ch[i]);
                cout << "Top : " << otop << " -- Initial Operator\n";
            } else if (ch[i] == '(') {
                pusho(ch[i]);
                cout << "Opening Parentheses\n";
            } else if (ch[i] == ')') {
                while (oper[otop - 1] != '(') {
                    char temp = pop();
                    pushp(temp);
                }
                otop--; // Discard '('
            } else {
                while (precedence(ch[i]) <= precedence(oper[otop - 1])) {
                    char temp = pop();
                    pushp(temp);
                }
                pusho(ch[i]);
                cout << "Precedence Check\n";
            }
        }
    }

    while (otop != 0) {
        char temp = pop();
        pushp(temp);
    }
    cout << "All Check\n";
}

int main() {
    char ch[100];

    cout << "Enter Infix Expression: ";
    cin.getline(ch, 100);

    int length = strlen(ch);
    strrev(ch);

    for (int i = 0; i < length; i++) {
        if (ch[i] == '(') {
            ch[i] = ')';
            i++;
        } else if (ch[i] == ')') {
            ch[i] = '(';
            i++;
        }
    }

    char* inf = ch;

    ItoP(inf, length);

    cout << strrev(pre) << endl;

    return 0;
}




