#include <iostream>
#include <string>
#include "Stack.cpp"
#include "List.cpp"

using namespace std;

bool checkBrackets(const string &str) {
    Stack<char> st;
    for (int i = 0; i < str.size(); ++i) {
        switch (str[i]) {
            case '(':
            case '{':
            case '[':
                st.push(str[i]);
                break;
            case ')':
                if (st.pop() != '(') return false;
                break;
            case '}':
                if (st.pop() != '{') return false;
                break;
            case ']':
                if (st.pop() != '[') return false;
                break;
        }
    }
    if (st.getSize() > 0) return false;
    return true;
}

ListInt copyListInt(ListInt &ls) {
    ListInt res;

    for (int i = 0; i < ls.getSize(); ++i) {
        res.insert(ls[i]);

    }
    return res;
}

bool isSortedList(ListInt &ls) {
    const int size = ls.getSize();
    if (size == 0) return false;
    if (size == 1) return true;

    int tmp = ls[0];
    if (tmp >= ls[1]) {
        tmp = ls[1];
        for (int i = 2; i < size; ++i) {
            if(tmp >= ls[i]) tmp = ls[i];
            else return false;
        }
    } else {
        tmp = ls[1];
        for (int i = 2; i < size; ++i) {
            if(tmp <= ls[i]) tmp = ls[i];
            else return false;
        }
    }

    return true;
}

int main() {
    // Task 1
    cout << "Task 1:" << endl;
    string str = "(sdf(([(asds(asdf))]))){[90]}";
    cout << (checkBrackets(str) ? "brackets \"" + str + "\" are correct" : "brackets \"" + str + "\" are not correct");

    // Task 2
    cout << endl << endl;
    cout << "Task 2:" << endl;
    ListInt ls;
    ls.insert(5);
    ls.insert(4);
    ls.insert(3);
    ls.insert(1);
    ls.insert(1);
    ListInt newList = copyListInt(ls);

    cout << "list  |  copy list" << endl;
    for (int i = 0; i < ls.getSize(); ++i) {
        cout.width(3);
        cout << ls[i] << "   |     " << newList[i] << endl;
    }
    cout << endl;

    // Task 3
    cout << "Task 3:" << endl;
    cout << (isSortedList(ls) ? "List is sorted" : "List is not sorted");

    return 0;
}
