// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : bitField(mp)
{
	if (mp > 0)
		maxPower = mp;
	else
		throw(__NEG_SIZE);
}

// конструктор копирования
TSet::TSet(const TSet &s) : bitField(s.maxPower)
{
	maxPower = s.maxPower;
	bitField = s.bitField;
}

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : bitField(bf.GetLength())
{
	maxPower = bf.GetLength();
	bitField = bf;
}

TSet::operator TBitField()
{
	return TBitField(maxPower);
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return maxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	return bitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	bitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{
	bitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	maxPower = s.maxPower;
	bitField = s.bitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
    return (maxPower == s.maxPower && bitField == s.bitField ? 1 : 0);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	return (maxPower != s.maxPower || bitField != s.bitField ? 1 : 0);
}

TSet TSet::operator+(const TSet &s) // объединение
{
	TSet T(maxPower > s.maxPower ? maxPower : s.maxPower);
	T.bitField = bitField | s.bitField;
	return T;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	bitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	bitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{
	TSet T(maxPower > s.maxPower ? maxPower : s.maxPower);
	T.bitField = bitField & s.bitField;
	return T;
}

TSet TSet::operator~(void) // дополнение
{
	bitField = ~bitField;
	return *this;
}

// перегрузка ввода/вывода

istream &operator>>(istream &istr, TSet &s) // ввод
{
  istr >> s.bitField;
  return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
  ostr << s.bitField;
  return ostr;
}
