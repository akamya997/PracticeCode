#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool solve()
{
    string number;
    cin >> number;
    
    char minDigit = '9';
    int indexLastMinDigit = 0;
    
    for (int i = 0; i < number.size(); ++i) {
        char digit = number[i];
        if (digit == '0')
            continue;
    
        minDigit = min(minDigit, digit);
        if (minDigit == digit)
            indexLastMinDigit = i;
    }
    
    bool needReduce = false;
    for (int i = indexLastMinDigit + 1; i < number.size(); ++i)
        needReduce |= number[i] < '9';
    
    for (int i = indexLastMinDigit - 1; i >= 0; --i) {
        char digit = number[i];
        if (minDigit == '9') {
            needReduce |= digit < minDigit;
        } else {
            needReduce |= digit > '0' && digit <= minDigit;
        }
    }

    if (needReduce && minDigit > '1')
        --minDigit;
    cout << minDigit;
    
    return false;
}

int main()
{
    solve();
    return 0;
}
