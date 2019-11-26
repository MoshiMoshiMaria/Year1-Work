#include <iostream>
//OVERLOADING LECTURE NOTES IF YOU NEED SOME INFO
using namespace std;
int max(int n1, int n2) {
		int bigger;
		n1 > n2 ? bigger = n1 : bigger = n2;
		return bigger;
	}
float max(float n1, float n2) {
		float bigger;
		n1 > n2 ? bigger = n1 : bigger = n2;
		return bigger;
	}
int main() {
	cout << max(1, 2) << endl;
	cout << max(1.15f, 1.1f) << endl;
	system("pause");

	return 0;
}