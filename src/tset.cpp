// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	if (mp > 0)
		MaxPower = mp;
	else
		throw(__NEG_SIZE);
}

// конструктор копирования
TSet::TSet(const TSet &s) : BitField(s.MaxPower)
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf.GetLength())
{
	MaxPower = bf.GetLength();
	BitField = bf;
}

TSet::operator TBitField()
{
	return TBitField(MaxPower);
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (MaxPower == s.MaxPower && BitField == s.BitField ? 1 : 0);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return (MaxPower != s.MaxPower || BitField != s.BitField ? 1 : 0);
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet T(MaxPower > s.MaxPower ? MaxPower : s.MaxPower);
	T.BitField = BitField | s.BitField;
	return T;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	BitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	BitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet T(MaxPower > s.MaxPower ? MaxPower : s.MaxPower);
	T.BitField = BitField & s.BitField;
	return T;
}

TSet TSet::operator~(void) // дополнение
{
	BitField = ~BitField;
	return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
	int temp;
	char sym;
	do{
		istr >> sym;
	} while (sym != '{');

	do {
		istr >> temp;
		s.InsElem(temp);
		do {
			istr >> sym;
		} while (sym != ',' && sym != '}');

	} while (sym != '}');

	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
	int i, n;
	char sym = ' ';
	ostr << '{';
	n = s.GetMaxPower();
	for(i = 0; i < n; i++)
	return ostr;
}
