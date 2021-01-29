#include <iostream>
#include <string>
#include <queue>
#include<stack>
using namespace std;

class Node {
public:
	string data;
	Node() {}
	Node(string x) { data = x; }
};

class Graph {
public:
	Node * V;
	int ** M;
	int size = 0;
	int last = -1;

	Graph() {}
	Graph(int n) {
		size = n;
		V = new Node[n]; // created array of vertices
		M = new int*[n]; // created array that is pointed to integers
		for (int i = 0; i < n; i++) { // initializing arrays for each letter
			M[i] = new int[n];
			for (int j = 0; j < n; j++) {
				M[i][j] = 0; // initialize all elements in the array for each letter is 0 at first
			}
		}
	}
		void Insert(string x) {
			Node node(x);
			last++;
			V[last] = node;
		}

		void Connect(string src, string dest) {
			int s = Search(src);
			int d = Search(dest);
			M[s][d] = 1;
			M[d][s] = 1; //by commenting this out we made our graph one directional 
		}
	
		int Search(string key) { // key is the letter
			for (int i = 0; i <= last; i++) {
				if (V[i].data == key) return i;
			}
			return -1;
		}

		void PrintMatrix() {
			cout << "    ";
			for (int i = 0; i <= last; i++) {
				cout << V[i].data << " ";
			}
			cout << endl;

			for (int i = 0; i <= last; i++) {
				cout << V[i].data << " | ";
				for (int j = 0; j <= last; j++) {
					cout << M[i][j] << " ";
				}
				cout << endl;
			}
		}

		void PrintAdjacent(string vert) {
			int v = Search(vert);
			for (int i = 0; i <= last; i++) {
				if (M[v][i] == 1) {
					cout << V[i].data << " ";
				}
			}
			cout << endl;
		}

		void PrintIncoming(int x) {

		}

		void PrintOutgoing(int x) {

		}

		void BFT(string start) {
			bool *visited = new bool[size];
			for (int i = 0; i < size; i++) {
				visited[i] = false;
			}
			int index = Search(start);
			visited[index] = true; // becomes 1

			//going to put it in a queue
			queue<string> Q;
			Q.push(start);

			cout << "Bredth First Traversal" << endl;
			while (!Q.empty()) {
				string vert = Q.front();// reads value and throws it out but doesn't delete it
				Q.pop(); // deletes element
				int index = Search(vert);
				cout << V[index].data << endl;

				for (int i = 0; i < size; i++) {
					if (M[index][i] > 0 && !visited[i]) {
						visited[i] = true;
						Q.push(V[i].data);
					}
				}
			}
			cout << "---------------------------" << endl;
		}

		void DFT(string start) {
			bool *visited = new bool[size];
			for (int i = 0; i < size; i++) {
				visited[i] = false;
			}
			int index = Search(start);
			visited[index] = true; // becomes 1

			//going to put it in a queue
			stack<string> S;
			S.push(start);

			cout << "Depth First Traversal" << endl;
			while (!S.empty()) {
				string vert = S.top();// reads value and throws it out but doesn't delete it
				S.pop(); // deletes element
				int index = Search(vert);
				cout << V[index].data << endl;

				for (int i = 0; i < size; i++) {
					if (M[index][i] > 0 && !visited[i]) {
						visited[i] = true;
						S.push(V[i].data);
					}
				}
			}
			cout << "---------------------------" << endl;
		}

		
};

int main() {
	Graph * g = new Graph(6);
	g->Insert("A");
	g->Insert("B");
	g->Insert("C");
	g->Insert("D");
	g->Insert("E");
	g->Insert("F");

	g->Connect("A", "B");
	g->Connect("A", "C");
	g->Connect("A", "E");
	g->Connect("A", "F");
	g->Connect("B", "D");
	g->Connect("B", "E");
	g->Connect("C", "D");
	g->Connect("C", "F");
	g->Connect("E", "F");

	g->PrintMatrix();
	g->PrintAdjacent("A"); // B C E F
	g->PrintAdjacent("F"); // A C E

	g->BFT("F");
	g->DFT("D");
	
	getchar();
}