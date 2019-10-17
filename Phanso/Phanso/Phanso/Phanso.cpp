
#include"Header.h"
#include "Phanso.h"

int main()
{
	//Phanso a(1, 2);
	//Phanso b(3, 4);
	//Phanso c = a + b;
	//cout << c.pGetTu() << "/" << c.pGetMau();
	//system("pause");
	string input;
	cin >> input;
	Process(input);
	system("pause");
}



Phanso::Phanso()
{
	mTu = 0;
	mMau = 1;

}


Phanso::~Phanso()
{
}
Phanso::Phanso(int a) {
	mTu = a;
	mMau=1;
}

Phanso::Phanso(int a, int b) {
	mTu = a;
	if (b != 0)
		mMau = b;
	else mMau = 1;
}
void Phanso::pSetTu(int a) {
	mTu = a;
}

void Phanso::pSetMau(int b) {
	if (b == 0)mMau = 1;
	else mMau = b;
}

int Phanso::pGetTu() {
	return mTu;
}

int Phanso::pGetMau() {
	return mMau;
}
void swap(int& a,int& b) {
	int temp = a;
	a = b;
	b = temp;

}
int Phanso::UCLN(int a,int b) {
	int x;
	int y;
	int temp;
	x =a;
	y =b;
	if (x < y)swap(x, y);
	while (y != 0) {
		temp = x%y;
		x = y;
		y = temp;
	}
	return x;
}

Phanso& Phanso::pQuyDong(Phanso& a) {
//euclid
	int k = this->mMau * a.mMau / UCLN(this->mMau, a.mMau);

	this->mTu = this->mTu * k / this->mMau;
	this->mMau = k;

	a.mTu = a.mTu * k / a.mMau;
	a.mMau = k;
	return *this;
}

Phanso Phanso::operator+(const Phanso& a) {
	Phanso temp = a;
	this->pQuyDong(temp);
	this->mTu = this->mTu + temp.mTu;
	return *this;
}

Phanso Phanso::operator-(const Phanso& a) {
	Phanso temp = a;
	this->pQuyDong(temp);
	this->mTu = this->mTu - temp.mTu;
	return *this;
}

Phanso Phanso::operator*(const Phanso& a) {
	this->mTu = this->mTu * a.mTu;
	this->mMau = this->mMau * a.mMau;
	return *this;
}

Phanso Phanso::operator/(const Phanso& a) {
	this->mTu = this->mTu * a.mMau;
	this->mMau = this->mMau * a.mTu;
	return *this;
}

Phanso& Phanso::pRutgon() {
	int k = UCLN(mTu, mMau);
	mTu = mTu / k;
	mMau = mMau / k;
	return *this;
}
