#include <iostream>
#include <string>
#include <stack>
#include <cmath>

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
    string post;
    cout << "Enter Postfix Expression: ";
    getline(cin, post);

    int num, num1, num2, ans;

    int k = post.length();

    for (int i = 0; i < k; i++) {
        if (isalpha(post[i])) {
            cout << "Enter value of " << post[i] << ": ";
            cin >> num;
            push(num);
        } else if (isdigit(post[i])) {
            num = post[i] - '0';
            push(num);
        } else {
            num2 = pop();
            num1 = pop();
            switch (post[i]) {
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
            cout << num1 << " " << post[i] << " " << num2 << " = " << ans << endl;
            push(ans);
        }
    }
    cout << "Ans : " << eval.top() << endl;
    return 0;
}
