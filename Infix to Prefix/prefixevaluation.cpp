#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm> 

using namespace std;

stack<int> eval;

void push(int val) {
    eval.push(val);
}

int pop() {
    int temp = eval.top();
    eval.pop();
    return temp;
}

int main() {
    string pre;
    cout << "Enter Prefix Expression: ";
    getline(cin, pre);

    int num, num1, num2, ans;

    // Reverse the input string
    reverse(pre.begin(), pre.end());

    int k = pre.length();

    for (int i = 0; i < k; i++) {
        if (isdigit(pre[i])) {
            num = pre[i] - '0';
            push(num);
        } else if (isalpha(pre[i])) {
            cout << "Enter value of " << pre[i] << ": ";
            cin >> num;
            push(num);
        } else {
            num1 = pop();
            num2 = pop();
            switch (pre[i]) {
                case '^':
                    ans = pow(num1, num2);
                    break;
                case '*':
                    ans = num1 * num2;
                    break;
                case '/':
                    ans = num1 / num2;
                    break;
                case '+':
                    ans = num1 + num2;
                    break;
                case '-':
                    ans = num1 - num2;
                    break;
                case '<':
                    ans = num1 < num2;
                    break;
                case '>':
                    ans = num1 > num2;
                    break;
                case '=':
                    ans = num1 == num2;
                    break;
                case '!':
                    ans = num1 != num2;
                    break;
                case '&':
                    ans = num1 && num2;
                    break;
                case '|':
                    ans = num1 || num2;
                    break;
                default:
                    ans = 0;
            }
            cout << num1 << " " << pre[i] << " " << num2 << " = " << ans << endl;
            push(ans);
        }
    }
    cout << "Ans : " << eval.top() << endl;
    return 0;
}
