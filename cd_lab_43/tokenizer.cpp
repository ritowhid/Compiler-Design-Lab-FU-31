#include <bits/stdc++.h>

using namespace std;

bool isKeyword(string w) {

    string keywords[] = {"int", "string", "main", "float", "return", "double", "char"};
    for (const string& k : keywords) {
        if (w == k) return true;
    }
    return false;
}

bool isOperator(string w) {
    string ops[] = {"+", "-", "*", "/", "="};
    for (const string& o : ops) {
        if (w == o) return true;
    }
    return false;
}

bool isNumber(string w) {
    if (w.empty()) return false;
    for (char c : w) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void identifyToken(string token) {
    if (token.empty()) return;

    char last = token.back();
    bool hasSymbol = (last == ';' || last == ',' || last == '(' || last == ')');
    
    if (hasSymbol) {
        token.pop_back();
    }

    if (!token.empty()) {
        if (isKeyword(token)) cout << token << "\t -> Keyword" << endl;
        else if (isOperator(token)) cout << token << "\t -> Operator" << endl;
        else if (isNumber(token)) cout << token << "\t -> Number" << endl;
        else cout << token << "\t -> Identifier" << endl;
    }

    if (hasSymbol) {
        string s(1, last);
        cout << s << "\t -> Symbol" << endl;
    }
}

int main() {

    string input = "int sum = 10; a + b = 20;";
    stringstream ss(input);
    string token;

    cout << "Analyzing Input: " << input << "\n" << endl;

    while (ss >> token) {
        identifyToken(token);
    }

    return 0;
}