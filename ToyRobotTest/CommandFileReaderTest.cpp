#include "pch.h"

const std::string testFile1("TestFiles\\TestFile1.txt");
const std::string testFile2("TestFiles\\TestFile2.txt");
const std::string testFile3("TestFiles\\TestFile3.txt");

TEST(CommandFileReaderTest, GetCommand_WillReturnPlaceCommandWithVectorOfArguments_WhenValidPlaceCommandIsInputted)
{
  CommandFileReader reader(testFile1);
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Place);
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(0).c_str(), "0");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(1).c_str(), "0");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(2).c_str(), "NORTH");

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Exit);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST(CommandFileReaderTest, GetCommand_WillReturnCorrectSequenceOfCommands_WhenGivenSequenceOfCommandsInFile)
{
  CommandFileReader reader(testFile2);
  
  auto commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Place);
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(0).c_str(), "0");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(1).c_str(), "0");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(2).c_str(), "NORTH");

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Move);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Report);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Exit);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST(CommandFileReaderTest, GetCommand_WillReturnInvalid_WhenGivenSequenceOfInvalidCommandsInFile)
{
  CommandFileReader reader(testFile3);
  
  auto commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Invalid);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Invalid);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Invalid);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());

  commandWithArgs = reader.GetCommand();
  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Exit);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST(CommandFileReaderTest, IsFileOpen_WillReturnFalse_WhenFileIsNotFound)
{
  CommandFileReader reader("notfound.txt");
  EXPECT_FALSE(reader.IsFileOpen());
}

TEST(CommandFileReaderTest, IsFileOpen_WillReturnTrue_WhenFileIsFound)
{
  CommandFileReader reader(testFile1);
  EXPECT_TRUE(reader.IsFileOpen());
}