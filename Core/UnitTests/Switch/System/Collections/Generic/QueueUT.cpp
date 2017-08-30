#include <Switch/System/Collections/Generic/Queue.hpp>
#include <Switch/TUnit/Assert.hpp>
#include <Switch/TUnit/TestFixture.hpp>

using namespace System;
using namespace System::Collections::Generic;
using namespace TUnit;

namespace {

TEST(Queue, Constructor) {
  Queue<int32> queue1;
  EXPECT_EQ(queue1.Count, 0);
  
  Queue<int32> queue2(7);
  EXPECT_EQ(queue2.Count, 0);
  
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue3(myArray);
  EXPECT_EQ(myQueue3.Count, 10);
}

TEST(Queue, Clear) {
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue(myArray);
  EXPECT_EQ(myQueue.Count, 10);
  myQueue.Clear();
  EXPECT_EQ(myQueue.Count, 0);
}

TEST(Queue, Contains) {
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue(myArray);
  EXPECT_TRUE(myQueue.Contains(5));
  EXPECT_FALSE(myQueue.Contains(24));
}

TEST(Queue, CopyTo) {
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue(myArray);
  Array<int32> myArray2(10);
  myQueue.CopyTo(myArray2,0);
  EXPECT_EQ(myArray2[0], 1);
  EXPECT_EQ(myArray2[1], 2);
  EXPECT_EQ(myArray2[2], 3);
  EXPECT_EQ(myArray2[3], 4);
  EXPECT_EQ(myArray2[4], 5);
  EXPECT_EQ(myArray2[5], 6);
  EXPECT_EQ(myArray2[6], 7);
  EXPECT_EQ(myArray2[7], 8);
  EXPECT_EQ(myArray2[8], 9);
  EXPECT_EQ(myArray2[9], 10);
}

TEST(Queue, Dequeue) {
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue(myArray);
  
  EXPECT_EQ(myQueue.Dequeue(), 1);
  EXPECT_EQ(myQueue.Dequeue(), 2);
  EXPECT_EQ(myQueue.Dequeue(), 3);
  EXPECT_EQ(myQueue.Dequeue(), 4);
  EXPECT_EQ(myQueue.Dequeue(), 5);
  EXPECT_EQ(myQueue.Dequeue(), 6);
  EXPECT_EQ(myQueue.Dequeue(), 7);
  EXPECT_EQ(myQueue.Dequeue(), 8);
  EXPECT_EQ(myQueue.Dequeue(), 9);
  EXPECT_EQ(myQueue.Dequeue(), 10);
  EXPECT_THROW(myQueue.Dequeue(), InvalidOperationException);
}

TEST(Queue, Enqueue) {
  Queue<int32> myQueue(10);
  myQueue.Enqueue(1);
  myQueue.Enqueue(2);
  myQueue.Enqueue(3);
  myQueue.Enqueue(4);
  myQueue.Enqueue(5);
  myQueue.Enqueue(6);
  myQueue.Enqueue(7);
  myQueue.Enqueue(8);
  myQueue.Enqueue(9);
  myQueue.Enqueue(10);
  myQueue.Enqueue(11);
  myQueue.Enqueue(12);
  EXPECT_EQ(myQueue.Count, 12);
}

TEST(Queue, GetEnumerator) {
  Queue<int32> myQueue(10);
  myQueue.Enqueue(1);
  myQueue.Enqueue(2);
  myQueue.Enqueue(3);
  myQueue.Enqueue(4);
  myQueue.Enqueue(5);
  myQueue.Enqueue(6);
  myQueue.Enqueue(7);
  myQueue.Enqueue(8);
  myQueue.Enqueue(9);
  myQueue.Enqueue(10);
  myQueue.Enqueue(11);
  myQueue.Enqueue(12);
  Enumerator<int32> enumerator = myQueue.GetEnumerator();
  int32 index = 0;
  while (enumerator.MoveNext())
    EXPECT_EQ(enumerator.Current, ++index);
  EXPECT_EQ(index, 12);
}

TEST(Queue, Foreach) {
  Queue<string> words;
  words.Enqueue("one");
  words.Enqueue("two");
  words.Enqueue("three");
  words.Enqueue("four");
  words.Enqueue("five");

  string reference[5] = { "one", "two", "three", "four", "five" };

  int32 index = 0;
  for (string s : words)
    ASSERT_EQ(reference[index++], s);
}

TEST(Queue, Foreach_NonConst) {
  Queue<string> words;
  words.Enqueue("one");
  words.Enqueue("two");
  words.Enqueue("three");
  words.Enqueue("four");
  words.Enqueue("five");

  string reference[5] = { "one 1", "two 2", "three 3", "four 4", "five 5" };

  int32 index = 1;
  for (string& s : words)
    s = String::Format("{0} {1}", s, index++);

  index = 0;
  for (string s : words)
    ASSERT_EQ(reference[index++], s);

}

TEST(Queue, GetSyncRoot) {
  Queue<int32> myQueue(10);
  
  pcf_lock (myQueue.SyncRoot) {
    myQueue.Enqueue(1);
    myQueue.Enqueue(2);
    myQueue.Enqueue(3);
    myQueue.Enqueue(4);
    myQueue.Enqueue(5);
    myQueue.Enqueue(6);
    myQueue.Enqueue(7);
    myQueue.Enqueue(8);
    myQueue.Enqueue(9);
    myQueue.Enqueue(10);
    myQueue.Enqueue(11);
    myQueue.Enqueue(12);
  }
  Enumerator<int32> enumerator = myQueue.GetEnumerator();
  int32 index = 0;
  while (enumerator.MoveNext())
    EXPECT_EQ(enumerator.Current, ++index);
  EXPECT_EQ(index, 12);
}

TEST(Queue, Peek_Const) {
  Queue<string> words;
  for (int32 i = 1; i <= 10 ; i++)
    words.Enqueue(Int32(i).ToString());
  EXPECT_EQ(words.Count, 10);
  const Queue<string>& const_words = words;
  EXPECT_EQ(const_words.Peek(), "1");
  EXPECT_EQ(words.Count, 10);
}

TEST(Queue, Peek_NonConst) {
  Queue<string> words;
  for (int32 i = 1; i <= 10 ; i++)
    words.Enqueue(Int32(i).ToString());
  EXPECT_EQ(words.Count, 10);
  EXPECT_EQ(words.Peek(), "1");
  EXPECT_EQ(words.Count, 10);
  words.Peek() = "one";
  EXPECT_EQ(words.Count, 10);
  EXPECT_EQ(words.Peek(), "one");
  EXPECT_EQ(words.Count, 10);
}

TEST(Queue, ToArray) {
  int32 natArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Array<int32> myArray(natArray, 10);
  Queue<int32> myQueue(myArray);
  
  Array<int32> arrayDest;
  arrayDest = myQueue.ToArray();
  EXPECT_EQ(arrayDest.Length, 10);
  
  Enumerator<int32> Enumerator = arrayDest.GetEnumerator();
  int32 index = 0;
  while (Enumerator.MoveNext())
    EXPECT_EQ(Enumerator.Current, ++index);
  EXPECT_EQ(index, 10);
}

TEST(Queue, TrimExcess) {
  Queue<int32> myQueue(10);
  myQueue.Enqueue(1);
  myQueue.Enqueue(2);
  myQueue.TrimExcess();
  EXPECT_EQ(myQueue.Count, 2);
}

}
