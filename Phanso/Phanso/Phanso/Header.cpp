#include "Header.h"


void Process(string a) {
	vector<Phanso> list;
	vector<int> toantu;
	Phanso temp;
	char* cc = new char[100];
	int j = 0;
	while (j < a.size() && a[j] == ' ')j++;
	if ((a[j] == '+') or (a[j] == '-'))a.insert(j, "0/1");
	for (int i = 1; i < a.size(); i++) {
		if ((a[i-1] != ' ') && (a[i] != ' '))a.insert(i," ");
	}
	strcpy(cc, a.c_str());
	
	char* p = new char;
	p = strtok(cc, " /");
	while (p != NULL) {
		temp.pSetTu(atof(p));
		p = strtok(NULL, " /");
		temp.pSetMau(atof(p));
		p = strtok(NULL," ");
		list.push_back(temp);
		if (p == NULL)break;
		if (strcmp(p, "+") == 0)toantu.push_back(1);
		else if (strcmp(p, "-") == 0)toantu.push_back(2);
		p = strtok(NULL, " /");
	}
	temp = list[0];
	for (int i = 1; i < list.size(); i++) 
	{
		if (toantu[i-1] == 1)
			temp = temp + list[i];
		else temp = temp - list[i];
		
	}
	temp.pRutgon();
	if (temp.pGetMau() == 1)
		cout << temp.pGetTu();
	else
		if (temp.pGetTu() == 0) cout << 0;
		else
			cout << temp.pGetTu() << "/" << temp.pGetMau();
	cout << endl;
}