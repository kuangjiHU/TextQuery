//runQueries.cpp
#include<iostream>
#include<fstream>
#include"TextQuery.h"

using namespace std;

string make_plural(size_t crt, string word, string ending)
{
	return (crt > 1) ? word + ending : word;
}

ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.sought << " occurs " << qr.lines->size() << " "
	   << make_plural(qr.lines->size(), "time", "s") << endl;

	for (auto num : *qr.lines) {
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}

void runQueries(ifstream &infile){
	// ����һ���洢��ѯ���ࡣ
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter a word to query, or q to quit" << endl;
		string s ;
		if (!(cin >> s) || s == "q") break;
		print(cout, tq.query(s)) << endl;
	}

}

int main() {
	ifstream in("input.txt", ios::in);
	if (!in.is_open()) {
		cout << "no file"<< endl;
		exit(0);
	}
	runQueries(in);
	return 0;
}