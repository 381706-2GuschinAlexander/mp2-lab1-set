#include "tset.h"

#include <gtest.h>

int l1 = 100000000;
TBitField A1(l1), B1(l1);

int l2 = 200000000;
TBitField A2(l2), B2(l2);

int l3 = 300000000;
TBitField A3(l3), B3(l3);

//		or
TEST(TBitFieldTime, or_with_100_mil)
{
	ASSERT_NO_THROW(A1 | B1);
}

TEST(TBitFieldTime, or_with_200_mil)
{
	ASSERT_NO_THROW(A2 | B2);
}

TEST(TBitFieldTime, or_with_300_mil)
{
	ASSERT_NO_THROW(A3 | B3);
}

//		~
TEST(TBitFieldTime, neg_with_100_mil)
{
	ASSERT_NO_THROW(~A1);
}

TEST(TBitFieldTime, neg_with_200_mil)
{
	ASSERT_NO_THROW(~A2);
}

TEST(TBitFieldTime, neg_with_300_mil)
{
	ASSERT_NO_THROW(~A3);
}