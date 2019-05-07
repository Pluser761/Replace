#include <iostream>
#include <fstream>
#include <string>

#include <algorithm>
#include <iterator>

using namespace std;

char eng[] = { 'E', 'T', 'O', 'P', 'A', 'H', 'K', 'X', 'C', 'B', 'M', 'e', 'o', 'p', 'a', 'k', 'x', 'c', 'm' };
char rus[] = { 'Å', 'Ò', 'Î', 'Ð', 'À', 'Í', 'Ê', 'Õ', 'Ñ', 'Â', 'Ì', 'å', 'î', 'ð', 'à', 'ê', 'õ', 'ñ', 'ì' };

int finder(char c)
{
	for (int i = 0; i < 19; i++)
		if (rus[i] == c) return i;
	return -1;
}

int main()
{
	string str = "file.txt";
	//cin >> str;

	ifstream fin;
	fin.open(str.c_str(), ifstream::in);
	ofstream fout;
	str = "out_" + str;
	fout.open(str.c_str(), ofstream::out);
	fout.clear();
	if (!fin.is_open())
		cout << "Shit0" << endl;
	if (!fout.is_open())
		cout << "Shit1" << endl;
	char c;
	int ind;
	while (fin.good())
	{
		c = fin.get();
		ind = finder(c);
		if (ind != -1)
			fout << eng[ind];
		else
			fout << c;
	}
	fin.close();
	fout.close();
	
	/*
	ofstream fout;



	fout.close();
	*/

	system("pause");
	return 0;
}