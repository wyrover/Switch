# Assert
This code example shows how to use Asset with your own message.

## Output
```
Start 2 tests from 2 test cases
  Start 1 test from UserTest1
true can never be equal to false
Expected: False
But was:  True
error: !---OMITTED---!/AssertMessage/AssertMessage.cpp:11
*** FAILED UserTest1.TestWithUserMessage (2 ms)
  End 1 test from UserTest1 (2 ms total)

  Start 1 test from UserTest2
Expected: False
But was:  True
error: !---OMITTED---!/AssertMessage/AssertMessage.cpp:19
*** FAILED UserTest2.TestWithoutUserMessage (0 ms)
  End 1 test from UserTest2 (0 ms total)

  Summary :
    PASSED 0 tests.
*** FAILED 2 tests, listed below:
*** FAILED UserTest1.TestWithUserMessage
*** FAILED UserTest2.TestWithoutUserMessage

2 FAILED TESTS
End 2 tests from 2 test cases ran. (3 ms total)
```
