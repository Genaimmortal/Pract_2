#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

string rang [9] {"Шестерка", "Семерка", "Восьмерка", "Девятка", "Десятка", "Валет", "Дама", "Король", "Туз"};
string mast [4] {"Крести", "Черви", "Буби", "Пики"};

class karta {
public:
	int mast_karta, real_number;
};

void fill_koloda(vector<karta> &koloda)
{
	int i, mast1=0, number1=6;
	for (i = 0; i < 36; i++) {
		koloda[i].real_number = number1;
		koloda[i].mast_karta = mast1;
		if (mast1 == 3) {
			mast1 = 0;
			number1++;
		} else
			mast1++;
	}
}

void mix(vector<karta>& koloda)
{
	static mt19937 rnd ((uint64_t)&rnd);
	shuffle(koloda.begin(), koloda.end(),rnd);
}

void find_color (vector<karta>& koloda)
{
	int i;
	for (i = 1; i < 36; i++) {
		if ((koloda[i].mast_karta == 1 && koloda[i-1].mast_karta == 2)
             || (koloda[i].mast_karta == 0 && koloda[i-1].mast_karta == 3)
			 || (koloda[i].mast_karta == 1 && koloda[i-1].mast_karta == 1)
			 || (koloda[i].mast_karta == 2 && koloda[i-1].mast_karta == 2)
			 || (koloda[i].mast_karta == 3 && koloda[i-1].mast_karta == 3)
			 || (koloda[i].mast_karta == 4 && koloda[i-1].mast_karta == 4)) {
				 cout << rang[koloda[i-1].real_number - 6] << " ";
				 cout << mast[koloda[i-1].mast_karta] << endl;
				 cout << rang[koloda[i].real_number - 6] << " ";
				 cout << mast[koloda[i].mast_karta] << endl;
				 cout << endl;
			 }
	}
}

void find_mast (vector<karta>& koloda)
{
	int i;
	for (i = 1; i < 36; i++) {
		if (koloda[i].real_number == koloda[i-1].real_number) {
			cout << rang[koloda[i-1].real_number - 6] << " " << mast[koloda[i-1].mast_karta] <<endl;
			cout << rang[koloda[i].real_number - 6] << " " << mast[koloda[i].mast_karta] <<endl;
			cout << endl;
		}
	}
}


void find_dama(vector<karta>& koloda)
{
	int i;
	for (i = 1; i < 36; i++) {
		if (koloda[i].real_number == 12 && koloda[i].mast_karta == 3) {
			cout << rang[koloda[i].real_number - 6] << " " << mast[koloda[i].mast_karta];
			cout << " находится в колоде на " << i+1 << "-ом месте" <<endl;
			break;
		}
	}
}

void print_ace (vector<karta>& t)
{
	int i;
	for (i = 1; i < 36; i++) {
		if (t[i].real_number == 14 && t[i].mast_karta == 0) {
			cout << rang[t[i].real_number - 6] << " " << mast[t[i].mast_karta];
			cout << " находится в колоде на " << i+1 << "-ом месте" <<endl;
		}
		if (t[i].real_number == 14 && t[i].mast_karta == 1) {
			cout << rang[t[i].real_number - 6] << " " << mast[t[i].mast_karta];
			cout << " находится в колоде на " << i+1 << "-ом месте" <<endl;
		}
		if (t[i].real_number == 14 && t[i].mast_karta == 2) {
			cout << rang[t[i].real_number - 6] << " " << mast[t[i].mast_karta];
			cout << " находится в колоде на " << i+1 << "-ом месте" <<endl;
		}
		if (t[i].real_number == 14 && t[i].mast_karta == 3) {
			cout << rang[t[i].real_number - 6] << " " << mast[t[i].mast_karta];
			cout << " находится в колоде на " << i+1 << "-ом месте" <<endl;
		}
	}
}

void print_koloda(vector<karta>& t)
{
	int i;
	for (i = 1; i < 36; i++) {
		cout << rang[t[i].real_number - 6] << " " << mast[t[i].mast_karta] <<endl;
	}
}

int main()
{
	vector<karta> koloda36(36);
	fill_koloda(koloda36);
	mix(koloda36);
	cout << "Поиск в колоде двух подряд карт одинакового цвета:" << endl;
	find_color(koloda36);
	cout << endl << "Поиск в колоде двух подряд карт одинакового номинала:" << endl;
	find_mast(koloda36);
	cout << endl << "Поиск в колоде дамы пик:" << endl;
	find_dama(koloda36);
	cout << endl << "Поиск в колоде всех тузов:" << endl;
	print_ace(koloda36);
	cout << endl << "Вывод колоды:" << endl;
	print_koloda(koloda36);
	cout << endl;
	return 0;
}
