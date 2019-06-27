#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

void sort (vector<string>& mass, unsigned size);
void find_family (vector<string>& mass, unsigned size);
void find_name (vector<string>& mass, int size);
int space (string s, unsigned begin = 0);

int main()
{
	unsigned i = 0;
	ifstream file ("file.txt");
	vector<string> s;
	string line;
	while (getline(file,line)) {
		if (line != "" || line != " " || line != "\n")
			s.push_back(line);
	}
	sort(s, s.size());
	cout << "Отсортированный список ФИО:" << endl;
	for (i=0; i<s.size(); i++)
		cout << s[i] << endl;
		cout << endl << "Однофамильцы:" << endl;
		find_family(s,s.size());
		cout << endl;
		find_name(s,s.size());
		file.close();
		return 0;
}


void sort (vector<string>& mass, unsigned size)
{
	unsigned i,j;
	bool swap;
	for (i = 0; i < size -1; i++){
		swap = false;
		for (j = 0; j < size - i - 1; j++) {
			if (mass[j] > mass[j+1]) {
				string Tmp = mass[j];
				mass[j] = mass[j+1];
				mass[j+1] = Tmp;
				swap = true;
			}
		}
		if (swap == false)
			break;
	}
}

void find_family (vector<string>& mass, unsigned size)
{
	string family1, family2;
	int prob;
	unsigned i=0, j=0;
	for (i = 0; i < size; i++){
		prob = space(mass[i]);
		family1 = mass[i].substr(0,prob);
		for (j=i+1; j<size; j++){
			prob = space(mass[j]);
			family2 = mass[j].substr(0,prob);
			if (family1 == family2){
				cout << mass[i] << endl << mass[j] << endl;
			}
		}
	}
}

int space(string s, unsigned begin)
{
	int i = 0;
	if (begin > 0){
		begin++;
		i++;
	}
	while (s[begin] != ' ') {
		i++;
		begin++;
	}
	return i;
}

void find_name (vector<string>& mass, int size)
{
	string name1, name2;
	int prob1, prob2;
	int i=0, j=0, max=-1, min = size+1;
	int name_count[size];
	for (i=0; i < size; i++)
		name_count[i]=0;
	for (i=0; i < size; i++){
		prob1 = space (mass[i]);
		prob2 = space (mass[i], prob1);
		name1 = mass[i].substr(prob1,prob2);
		for (j=0; j < size; j++){
		prob1 = space (mass[j]);
		prob2 = space (mass[j], prob1);
		name2 = mass[j].substr(prob1,prob2);
		if ((mass[i] != mass[j]) && (name1 == name2))
			name_count[i]++;
	}
}
	for (i=0; i < size; i++){
		if (name_count[i]>max)
			max = name_count[i];
			else if (name_count[i]<min)
				min = name_count[i];
}
name1 = "";
name2 = "";
cout << "Самые популярные имена: " <<endl;
for (i = 0; i < size; i++){
	if (name_count[i]==max){
		prob1 = space(mass[i]);
		prob2 = space(mass[i], prob1);
		name1 = mass[i].substr(prob1+1,prob2);
		if (name1 == name2)
			continue;
			cout << name1 << endl;
			name2 = name1;
	}
}
name1 = "";
name2 = "";
cout << "Самые редкие имена: " <<endl;
for (i = 0; i < size; i++){
	if (name_count[i]==min){
		prob1 = space(mass[i]);
		prob2 = space(mass[i], prob1);
		name1 = mass[i].substr(prob1+1,prob2);
		if (name1 == name2)
			continue;
			cout << name1 << endl;
			name2 = name1;
	}
  }
}

