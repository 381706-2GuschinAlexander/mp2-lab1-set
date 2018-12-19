// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле


#include "tbitfield.h"

TBitField::TBitField(int len)
{
	if (len >= 0)
	{
		bitLen = len;
		memLen = len / (8 * sizeof(TELEM)) + 1;
		pMem = new TELEM[memLen];
		for (int i = 0; i < memLen; i++)
			pMem[i] = 0;
	}
	else
		throw(__NEG_SIZE);
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	bitLen = bf.bitLen;
	memLen = bf.memLen;
	pMem = new TELEM[memLen];
	for (int i = 0; i < memLen; i++)
		pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{ 
	if (n > bitLen || n < 0)
		throw(__IND_IS_OUT_OF_RANGE);

	return n / (8 * sizeof(TELEM));

}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	if (n > bitLen || n < 0)
		throw(__IND_IS_OUT_OF_RANGE);

	int shift = n % (8 * sizeof(TELEM));
	return 1 << shift;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return bitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n > bitLen || n < 0)
		throw(__IND_IS_OUT_OF_RANGE);

	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] | GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n > bitLen || n < 0)
		throw(__IND_IS_OUT_OF_RANGE);

	pMem[GetMemIndex(n)] = pMem[GetMemIndex(n)] & ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n > bitLen || n < 0)
		throw(__IND_IS_OUT_OF_RANGE);

	return ((GetMemMask(n) & pMem[GetMemIndex(n)]) == GetMemMask(n) ? 1 : 0);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	delete[] pMem;

	bitLen = bf.bitLen;
	memLen = bf.memLen;

	pMem = new TELEM[memLen];
	
	for (int i = 0; i < memLen; i++)
		pMem[i] = bf.pMem[i];

	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (bitLen != bf.bitLen)
		return 0;
	
	for (int i = 0; i < memLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 0;
			
	return 1;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (bitLen != bf.bitLen)
		return 1;

	for (int i = 0; i < memLen; i++)
		if (pMem[i] != bf.pMem[i])
			return 1;

	return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	TBitField T(bitLen > bf.bitLen ? *this : bf);

	for (int  i = 0; i < memLen; i++)
		T.pMem[i] = pMem[i] | bf.pMem[i];

	return T;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	TBitField T(bitLen > bf.bitLen ? *this : bf);

	for (int i = 0; i < memLen; i++)
		T.pMem[i] = pMem[i] & bf.pMem[i];

	return T;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField T(*this);
	
	for (int i = 0; i < memLen; i++)
		T.pMem[i] = ~pMem[i];

	int shift = 32 - bitLen % (8 * sizeof(TELEM));

	T.pMem[memLen - 1] = T.pMem[memLen - 1] << shift >> shift;

	return T;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
  char sym;
  for (int i = 0; i < bf.bitLen; i++)
  {
    istr >> sym;
    if (sym == '0')
      bf.ClrBit(i);
    else if (sym == '1')
      bf.SetBit(i);
    else break;
  }

  return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	
  for (int i = 0; i < bf.bitLen; i++)
    cout << bf.GetBit(i);
  cout << endl;

  return ostr;
}
