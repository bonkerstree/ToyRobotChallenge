The binary ToyRobot.exe is already built and can already be run in the Debug folder.

To run the application in console mode, simply double click ToyRobot.exe or run it in the console without any arguments.

To run the application in file mode, provide the file name as argument to ToyRobot.exe like the following:
  
    ToyRobot.exe file.txt

There are existing test files in the Debug folder that can be used as examples:
  
    ToyRobot.exe TestFiles/TestFile1.txt

If the file argument provided does not exist, the application will not run.

The ToyRobotTest.exe binary can be run to execute the unit tests of the application. This binary uses the test files inside Debug/TestFiles so if they have been modified, some of the tests may fail.
