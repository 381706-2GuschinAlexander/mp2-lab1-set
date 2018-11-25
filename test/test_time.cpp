#include "tset.h"

#include <gtest.h>

int l1 = 100000000;
TBitField A1(l1), B1(l1);

int l2 = 200000000;
TBitField A2(l2), B2(l2);

int l3 = 300000000;
TBitField A3(l3), B3(l3);

//		new TBitField
TEST(TBitFieldTime, new_TBitF_with_100_mil)
{
	ASSERT_NO_THROW(TBitField C(l1));
}

TEST(TBitFieldTime, new_TBitF_with_200_mil)
{
	ASSERT_NO_THROW(TBitField C(l2));
}

TEST(TBitFieldTime, new_TBitF_with_300_mil)
{
	ASSERT_NO_THROW(TBitField C(l3));
}

//		new TBitField from old
TEST(TBitFieldTime, new_TBitF_from_old_with_100_mil)
{
	ASSERT_NO_THROW(TBitField C(A1));
}

TEST(TBitFieldTime, new_TBitF_from_old_with_200_mil)
{
	ASSERT_NO_THROW(TBitField C(A2));
}

TEST(TBitFieldTime, new_TBitF_from_old_with_300_mil)
{
	ASSERT_NO_THROW(TBitField C(A3));
}

//		=
TEST(TBitFieldTime, eq_with_100_mil)
{
	ASSERT_NO_THROW(A1 = B1);
}

TEST(TBitFieldTime, eq_with_200_mil)
{
	ASSERT_NO_THROW(A2 = B2);
}

TEST(TBitFieldTime, eq_with_300_mil)
{
	ASSERT_NO_THROW(A3 = B3);
}

//		==
TEST(TBitFieldTime, if_eq_with_100_mil)
{
	ASSERT_NO_THROW(A1 == B1);
}

TEST(TBitFieldTime, if_eq_with_200_mil)
{
	ASSERT_NO_THROW(A2 == B2);
}

TEST(TBitFieldTime, if_eq_with_300_mil)
{
	ASSERT_NO_THROW(A3 == B3);
}

//		!=
TEST(TBitFieldTime, if_uneq_with_100_mil)
{
	ASSERT_NO_THROW(A1 != B1);
}

TEST(TBitFieldTime, if_uneq_with_200_mil)
{
	ASSERT_NO_THROW(A2 != B2);
}

TEST(TBitFieldTime, if_uneq_with_300_mil)
{
	ASSERT_NO_THROW(A3 != B3);
}

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


//		and
TEST(TBitFieldTime, and_with_100_mil)
{
	ASSERT_NO_THROW(A1 & B1);
}

TEST(TBitFieldTime, and_with_200_mil)
{
	ASSERT_NO_THROW(A2 & B2);
}

TEST(TBitFieldTime, and_with_300_mil)
{
	ASSERT_NO_THROW(A3 & B3);
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