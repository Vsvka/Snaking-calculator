#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;


//This function mainly doing math here depending on what is going to be lik + or - or *
long long list_making(long long a, char option, long long b) {
    if (option == '+') return a + b;
    if (option == '-') return a - b;
    return a * b; 
}

//This one is main recursive function it makes sure that everything is on it's place in a row and keep-->
//-->count of actions like +,- and *
long long evaluation(const vector<string>& strings, int row, size_t position, long long total, char action) {
    if (row < 0 || row >= (int)strings.size()) return total;
    if (position >= strings[row].size()) return total;

    char math = strings[row][position];

    if (isdigit((unsigned char)math)) {
        return evaluation(strings, row, position+1, list_making(total, action, math - '0'), action);
    }

    if (math == '+' || math == '-' || math == '*') {
        return evaluation(strings, row, position+1, total, math);
    }

    if (math == '^' || math == 'v') {
        int nr = row + (math == 'v' ? 1 : -1);          
        long long after = evaluation(strings, nr, position, total, action);     
        return evaluation(strings, row, position+1, after, action);           
    }

    
    return evaluation(strings, row, position+1, total, action);
}

//It's just a checke if the bector strings are empty or no
long long evaluateStrings(const vector<string>& strings) {
    if (strings.empty()) return 0;
    return evaluation(strings, 0, 0, 0, '+');
}

//It's just showing a result with the initial formula that was taken from exaple output
int main() {
    vector<string> equation = {
        "257*233+6v790-12",
        "61247833212+*9^3"
    };
    cout << "Result: " << evaluateStrings(equation) << '\n'; 
    return 0;
}