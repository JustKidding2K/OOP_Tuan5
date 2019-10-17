#pragma once
class Phanso
{
protected:
	int mTu;
	int mMau;
public:
	Phanso();
	~Phanso();
	Phanso(int);
	Phanso(int, int);
	//Phanso& operator=(const Phanso&);
	void pSetTu(int);
	void pSetMau(int);
	int pGetTu();
	int pGetMau();
	Phanso operator+(const Phanso&);
	Phanso operator-(const Phanso&);
	Phanso operator*(const Phanso&);
	Phanso operator/(const Phanso&);
	Phanso& pQuyDong(Phanso&);
	Phanso& pRutgon();
	int UCLN(int, int);
};

