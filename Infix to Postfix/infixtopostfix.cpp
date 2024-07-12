
#include <iostream>
#include <cstring>
using namespace std;

char oper[100];
char post[100];
int otop = 0;
int ptop = 0;

void pusho(char let) {
    oper[otop] = let;
    otop++;
}

void pushp(char let) {
    post[ptop] = let;
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
            pushp(ch[i]);
        } else if (ch[i] >= 97 && ch[i] <= 122) {
            pushp(ch[i]);
        } else {
            if (otop == 0) {
                pusho(ch[i]);
            } else if (ch[i] == '(') {
                pusho(ch[i]);
            } else if (ch[i] == ')') {
                while (oper[otop - 1] != '(') {
                    char temp = pop();
                    pushp(temp);
                }
                otop--; 
            } else {
                while (precedence(ch[i]) <= precedence(oper[otop - 1])) {
                    char temp = pop();
                    pushp(temp);
                }
                pusho(ch[i]);
            }
        }
    }

    while (otop != 0) {
        char temp = pop();
        pushp(temp);
    }
}

int main() {
    char ch[100];

    cout << "Enter Infix Expression: ";
    cin.getline(ch, 100);

    int length = strlen(ch);

    char* inf = ch;

    ItoP(inf, length);

    cout << "Postfix Expression: ";
    for (int j = 0; j < length; j++) {
        cout << post[j];
    }
    cout << endl;

    return 0;
}
