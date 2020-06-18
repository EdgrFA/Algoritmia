//https://www.hackerrank.com/contests/code-quest-2/challenges/largest-rectangle/problem
#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the largestRectangle function below.
long largestRectangle(vector<int> h) {
    stack<pair<int, int>> heights;
    long maxHeight = 0;
    for(size_t i = 0; i < h.size(); i++){
        int value = h[i];
        if(heights.empty() || heights.top().first < value){
            pair<int,int> newHeight(value, 1);
            heights.push(newHeight);
        }
        else if(heights.top().first > value){
            do{
	            pair<int,int> lastTop = heights.top();
	            maxHeight = max((long)lastTop.first * lastTop.second, maxHeight);
	            heights.pop();
	            
	            if(heights.empty() || heights.top().first < value){
	                pair<int,int> newHeight(value, 1+lastTop.second);
	                heights.push(newHeight);
	            }
	            else if(heights.top().first == value) heights.top().second += lastTop.second + 1;
	            else heights.top().second += lastTop.second;
        	}while(heights.top().first != value);
        }
        else heights.top().second++;
    }

    while(!heights.empty()){
        pair<int,int> lastTop = heights.top();
        maxHeight = max((long)lastTop.first * lastTop.second, maxHeight);
        heights.pop();
        if(!heights.empty())
            heights.top().second += lastTop.second;
    }
    return maxHeight;
}

int main()
{
	int opt;
	cin >> opt;
	if(opt == 0){
		ifstream inFile;
	    inFile.open("input06.txt");
	    if (!inFile) {
	        cout << "Unable to open file";
	        exit(1); // terminate with error
	    }
	    int n;
		inFile >> n;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		string h_temp_temp;
		getline(inFile, h_temp_temp);
		vector<string> h_temp = split_string(h_temp_temp);
		vector<int> h(n);
		for (int i = 0; i < n; i++) {
		    int h_item = stoi(h_temp[i]);
		    h[i] = h_item;
		}
		inFile.close();
	    long result = largestRectangle(h);
	    cout << result << "\n";
	}else{
		int n;
	    cin >> n;
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    string h_temp_temp;
	    getline(cin, h_temp_temp);
	    vector<string> h_temp = split_string(h_temp_temp);
	    vector<int> h(n);
	    for (int i = 0; i < n; i++) {
	        int h_item = stoi(h_temp[i]);
	        h[i] = h_item;
	    }
	    long result = largestRectangle(h);
	    cout << result << "\n";
	}

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
