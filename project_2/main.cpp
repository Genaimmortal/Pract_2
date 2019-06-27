#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;

int RandomGenerator()
{
	static mt19937 random(50);
	uniform_int_distribution <int> diap(-1000000000,1000000000);
	return diap(random);
}

int main()
{
	vector <int> vector_1;
	mt19937 random(50);
	uniform_int_distribution<int>Diap(-1000000000,1000000000);
	for (int i=0; i < 10000000; i++)
		vector_1.push_back(Diap(random));
	vector<int> vector_2(10000000);
	generate(vector_2.begin(),vector_2.end(),RandomGenerator);
	steady_clock::time_point tp_1 =
	    steady_clock::now();
	sort(vector_2.begin(),vector_2.end());
	steady_clock::time_point tp_2 =
	    steady_clock::now();
	duration <double> Chr = tp_2 - tp_1;
	cout << "Сортировка: " << Chr.count() << endl;
	vector <int> vector_3(vector_2);
	tp_1 = steady_clock::now();
	stable_sort (vector_3.begin(), vector_3.end());
	tp_2 = steady_clock::now();
	Chr = tp_2 - tp_1;
	cout << "Сортировка слиянием: " << Chr.count() << endl;
	return 0;
}


