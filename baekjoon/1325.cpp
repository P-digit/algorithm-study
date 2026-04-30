#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> T_node;
vector <int> T_time;
vector <int> total_time;
vector <int> D;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;
	T_node.resize(N+1);
	T_time.resize(N+1);
	D.resize(N+1);
	total_time.resize(N+1);
	
	for(int i=1; i<=N; ++i) {
		int time;
		cin >> time;
		
		T_time[i] = time;
		
		while(true) {
			int input;
			
			cin >> input;
			
			if(input == -1)
				break;
			
			T_node[input].push_back(i);
			D[i] += 1;
		}
	}
	
	queue <int> myqueue;
	
	for(int i=1; i<=N; ++i) {
		if(D[i] == 0)
			myqueue.push(i);
	}
	
	while(!myqueue.empty()) {
		int cur = myqueue.front();
		myqueue.pop();
		
		for(int next : T_node[cur]) {
			--D[next];
			total_time[next] = max(total_time[next], total_time[cur] + T_time[cur]);
			if(D[next] == 0) myqueue.push(next);
		}
	}
	
	for(int i=1; i<=N; ++i) {
		cout << total_time[i] + T_time[i]<< '\n';
	}
	
	
	return 0;
}