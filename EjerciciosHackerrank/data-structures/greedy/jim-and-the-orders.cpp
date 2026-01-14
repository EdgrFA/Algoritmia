//https://www.hackerrank.com/challenges/jim-and-the-orders/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jimOrders' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY orders as parameter.
 */

vector<int> jimOrders(vector<vector<int>> orders) {
    for (int i = 0; i < orders.size(); i++) {
        orders[i].push_back(orders[i][0] + orders[i][1]);
        orders[i].push_back(i+1);
    }
    sort(orders.begin(), orders.end(), [](const vector<int>& o1, const vector<int>& o2) {
            return o1[2] < o2[2] || (o1[2] == o2[2] && o1[3] < o2[3]);
        });
        
    vector<int> clients(orders.size());
    transform(orders.begin(), orders.end(), clients.begin(), [](const vector<int>& fila) {
            return fila[3];
        });
    return clients;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> orders(n);

    for (int i = 0; i < n; i++) {
        orders[i].resize(2);

        string orders_row_temp_temp;
        getline(cin, orders_row_temp_temp);

        vector<string> orders_row_temp = split(rtrim(orders_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int orders_row_item = stoi(orders_row_temp[j]);

            orders[i][j] = orders_row_item;
        }
    }

    vector<int> result = jimOrders(orders);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
