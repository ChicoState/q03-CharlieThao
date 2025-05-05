/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(GuesserTest, correct_match_test)
{
  Guesser object("Secret");
  bool result = object.match("Secret");
  ASSERT_EQ( 1, result );
}

TEST(GuesserTest, wrong_match_test)
{
  Guesser object("Secret");
  bool result = object.match("Sekret");
  ASSERT_EQ( 0, result );
}

TEST(GuesserTest, locked_forever_no_attempts_left_test)
{
  Guesser object("Secret");
  bool result = object.match("Sekret");
  result = object.match("Sekret");
  result = object.match("Sekret");
  result = object.match("Secret");
  ASSERT_EQ( 0, result );
}

TEST(GuesserTest, locked_forever_brute_force_test)
{
  Guesser object("Secret");
  bool result = object.match("Secretttt");
  result = object.match("Secret");
  ASSERT_EQ( 0, result );
}

TEST(GuesserTest, correct_match_multiple_times_test)
{
  Guesser object("Secret");
  bool result = object.match("Secret");
  result = object.match("Secret");
  result = object.match("Secret");
  result = object.match("Secret");
  ASSERT_EQ( 1, result );
}

TEST(GuesserTest, attempts_reset_test)
{
  Guesser object("Secret");
  bool result = object.match("Sekret");
  result = object.match("Sekret");
  result = object.match("Secret");
  result = object.match("Sekret");
  result = object.match("Sekret");
  result = object.match("Secret");
  ASSERT_EQ( 1, result );
}

TEST(GuesserTest, truncate_test)
{
  Guesser object("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  bool result = object.match("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
  ASSERT_EQ( 0, result );
}

TEST(GuesserTest, case_sensitive_test)
{
  Guesser object("Secret");
  bool result = object.match("secret");
  ASSERT_EQ( 0, result );
}

TEST(GuesserTest, empty_string_test)
{
  Guesser object("");
  bool result = object.match("");
  ASSERT_EQ( 1, result );
}