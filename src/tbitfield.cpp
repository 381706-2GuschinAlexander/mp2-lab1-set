// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "exception.h"
#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len >= 0)
	{
		BitLen = len;
		MemLen = len / (8 * sizeof(TELEM)) + 1;
		pMem = new TELEM[MemLen];
		for (int i = 0; i < MemLen; i++)
			pMem[i] = 0;
	}
	else
		ExThrow(0);
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem = new TELEM[MemLen];
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{ 
	if (n > BitLen || n < 0)
		ExThrow(1);

	return n / (8 * sizeof(TELEM));

}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	if (n > BitLen || n < 0)
		ExThrow(1);

	int shift = n % (8 * sizeof(TELEM));
	return 1 << shift;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n > BitLen || n < 0)
		ExThrow(1);

	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n > BitLen || n < 0)
		ExThrow(1);

	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n > BitLen || n < 0)
		ExThrow(1);

	return ((GetMemMask(n) & pMem[GetMemIndex(n)]) == GetMemMask(n) ? 1 : 0);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	delete[] pMem;

	BitLen = bf.BitLen;
	MemLen = bf.MemLen;

	pMem = new TELEM[MemLen];
	
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i];

	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)
		return 0;
	
	for (int i = 0; i < MemLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 0;
			
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen)
		return 0;

	for (int i = 0; i < MemLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 1;

	return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField T(BitLen > bf.BitLen ? *this : bf);

	for (int  i = 0; i < MemLen; i++)
		T.pMem[i] = pMem[i] | bf.pMem[i];

	return T;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField T(BitLen > bf.BitLen ? *this : bf);

	for (int i = 0; i < MemLen; i++)
		T.pMem[i] = pMem[i] & bf.pMem[i];

	return T;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField T(*this);
	
	for (int i = 0; i < MemLen; i++)
		T.pMem[i] = ~pMem[i];

	int shift = 32 - BitLen % (8 * sizeof(TELEM));

	T.pMem[MemLen - 1] = T.pMem[MemLen - 1] << shift >> shift;

	return T;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	int i = 0;
	char sym;
	do
	{
		istr >> sym;
	} while (sym != ' ');
	while (1)
	{
		if (sym == '0')
			bf.ClrBit(i++);
		else if (sym == '1')
			bf.SetBit(i++);
		else
			break;
	}
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	
	for (int i = 0; i < bf.BitLen; i++)
	{
		if (bf.GetBit(i) == 1)
			ostr << '1';
		else
			ostr << '0';
	}
	return ostr;
}
