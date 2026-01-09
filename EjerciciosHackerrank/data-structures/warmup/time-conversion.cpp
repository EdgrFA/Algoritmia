//https://www.hackerrank.com/challenges/time-conversion/problem
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    int hora = stoi(s.substr(0,2));
    if (s[8] == 'P') {
        if (hora != 12) {
            hora += 12;
        }
    } 
    else if (hora == 12) {
        hora = 0;
    }
    return (hora < 10 ? "0" : "") + to_string(hora) + s.substr(2, 6);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
