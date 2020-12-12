/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, isColumnFull) {
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(0);
}

TEST(PiezasTest, isFULL)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
}

TEST(PiezasTest, Invalid_greater)
{
	Piezas b;
	ASSERT_EQ(b.dropPiece(4), Invalid);
}

TEST(PiezasTest, Invalid_less_than)
{
	Piezas b;
	ASSERT_EQ(b.dropPiece(-2), Invalid);
}

TEST(PiezasTest, check_game_empty)
{
	Piezas b;
	ASSERT_EQ(b.gameState(), Invalid);
}

TEST(PiezasTest, resetboardCheck)
{
	Piezas b;
	b.reset();
}

TEST(PiezasTest, DropPieceX)
{
	Piezas b;
	ASSERT_EQ(X, b.dropPiece(2));
}

TEST(PiezasTest, DropPieceO)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_EQ(O, b.dropPiece(2));
}

TEST(PiezasTest, outofBounds)
{
	Piezas b;
	ASSERT_EQ(Invalid, b.pieceAt(4,4));
}

TEST(PiezasTest, outofBoundsCol)
{
	Piezas b;
	ASSERT_EQ(Invalid, b.pieceAt(2,4));
}

TEST(PiezasTest, outofBoundsRow)
{
	Piezas b;
	ASSERT_EQ(Invalid, b.pieceAt(4,2));
}

TEST(PiezasTest, checkPieceExistX)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_EQ(X, b.pieceAt(2,0));
}

TEST(PiezasTest, checkPieceExistO)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	ASSERT_EQ(O, b.pieceAt(1,0));
}

TEST(PiezasTest, checkPieceNoExist)
{
	Piezas b;
	b.dropPiece(0);
	ASSERT_FALSE(O == b.pieceAt(2,0));
}

TEST(PiezasTest, gameStateTie)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), Blank);
}

TEST(PiezasTest, gameStateTie2)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), Blank);
}

TEST(PiezasTest, gameStateTie3)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(2);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), Blank);

}

TEST(PiezasTest, gameState_x_wins)
{
	Piezas b;
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(2);
	b.dropPiece(0);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), X);
}

TEST(PiezasTest, gameState_o_wins)
{
	Piezas b;
	b.dropPiece(4);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(0);
	b.dropPiece(0);
	b.dropPiece(1);
	b.dropPiece(1);
	b.dropPiece(2);
	b.dropPiece(3);
	b.dropPiece(2);
	b.dropPiece(0);
	b.dropPiece(3);
	ASSERT_EQ(b.gameState(), O);
}


