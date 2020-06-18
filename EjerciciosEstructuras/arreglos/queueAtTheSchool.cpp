//https://codeforces.com/problemset/problem/266/B
#include <bits/stdc++.h>
using namespace std;

string queueAtTheSchool(int t, string queue){
	for (int i = 0; i < t && i < queue.size()-1; i++){
		for(int p = 0; true; p+=2){
			while(p+1 < queue.size() && !(queue[p] == 'B' && queue[p+1] == 'G'))
				p++;
			if(p+1 >= queue.size())
				break;
			swap(queue[p], queue[p+1]);
		}
	} 
	return queue;
}

int main(){
	int n, t;
	string queue;
	cin >> n >> t >> queue;
	cout << queueAtTheSchool(t, queue);
}

/****
Input
5 2
BGGBG

Output
GGBGB
****/