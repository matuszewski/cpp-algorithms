#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int> v) {

	for (int i = 0; i < int(v.size()); i++) {
		cout << v.at(i) << ' ';
	}

	cout << endl;
}

void analyseVector(vector<int> v) {
	int size = v.size();
	int max_size = v.max_size();
	int capacity = v.capacity();

	cout << "No. of elements:\t" << size << endl;
	cout << "Max no. of elements:\t" << max_size << endl;
	cout << "Ammount of elements:\t" << capacity << endl;

	cout << "Is empty?\t\t" << v.empty() << endl;

	cout << endl;
}


int main() {
	
	vector<int> v1;
	
	// fills the vector with digits from 0 to 9
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	cout << "Vector:\t\t\t";
	displayVector(v1);

	analyseVector(v1);


	v1.assign(4, 7);
	displayVector(v1);
	analyseVector(v1);

	v1.assign(0, 0);
	displayVector(v1);
	analyseVector(v1);

	// inserts 74 six times
	v1.insert(v1.begin(), 6, 74);


	// adds 8 at start
	v1.insert(v1.begin(), 8);

	displayVector(v1);
	analyseVector(v1);




	return 0;
}
