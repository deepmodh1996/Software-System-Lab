#include <iostream>
#include<ctime>
using namespace std;

// domain: x >= 0
int fibonacci (int x) {
	if (x <= 1) return x;
	return fibonacci(x-1) + fibonacci(x-2);
	/* (later) think about making this tail recursive */
}

int main (int argc, char* argv[]) {

clock_t begin = clock();

	if (argc < 2)
		return 1;

	int n = atoi(argv[1]);
	cout <<n<<","<< fibonacci(n)<<",";
clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
cout<<elapsed_secs<<endl;
	return 0;

}
