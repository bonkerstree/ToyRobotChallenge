#include "pch.h"

class CommandConsoleReaderTest : public testing::Test
{
public:
  void SetReaderInput(CommandConsoleReader& reader, std::string input)
  {
    reader.SetStreamBuffer(m_InputBuffer);

    m_InputBuffer.sputn(input.c_str(), input.size());
  }

private:
  std::stringbuf m_InputBuffer;
};

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnPlaceCommandWithVectorOfArguments_WhenValidPlaceCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "PLACE 1,2,NORTH");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Place);
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(0).c_str(), "1");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(1).c_str(), "2");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(2).c_str(), "NORTH");
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnMoveCommandWithEmptyArgVector_WhenValidMoveCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "MOVE");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Move);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnLeftCommandWithEmptyArgVector_WhenValidLeftCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "LEFT");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Left);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnRightCommandWithEmptyArgVector_WhenValidRightCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "RIGHT");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Right);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnReportCommandWithEmptyArgVector_WhenValidReportCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "REPORT");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Report);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnInvalidCommandWithEmptyArguments_WhenInvalidCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "ABC 1,2,NORTH");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Invalid);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnMoveCommandWithEmptyArgVector_WhenLowercaseMoveCommandIsInputted)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "move");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Move);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnMoveCommandWithEmptyArgVector_WhenMoveCommandIsInputtedWithExcessiveSpaces)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "        MoVe       ");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Move);
  EXPECT_TRUE(std::get<1>(commandWithArgs).empty());
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnPlaceCommandWithVectorOfArguments_WhenPlaceCommandIsInputtedWithExcessiveSpaces)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "  PLACE    1      ,2     , NORTH    ");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Place);
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(0).c_str(), "1");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(1).c_str(), "2");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(2).c_str(), "NORTH");
}

TEST_F(CommandConsoleReaderTest, GetCommand_WillReturnPlaceCommandWithVectorOfArguments_WhenPlaceCommandIsInputtedWithLowerCaseLetters)
{
  CommandConsoleReader reader;
  SetReaderInput(reader, "    PlAcE 1 ,2, norTh  ");
  
  auto commandWithArgs = reader.GetCommand();

  EXPECT_EQ(std::get<0>(commandWithArgs), CommandReader::Command::Place);
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(0).c_str(), "1");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(1).c_str(), "2");
  EXPECT_STREQ(std::get<1>(commandWithArgs).at(2).c_str(), "NORTH");
}