using System;
using NUnit.Framework;

namespace CSharpUnitTests {
  [TestFixture]
  public class StringUT {
    [Test]
    public void StringCreatedByAssignment() {
      String s = "This is a string created by assignment.";
      Assert.AreEqual("This is a string created by assignment.", s);
    }

    [Test]
    public void StringCreatedByAssignmentWithBackslash() {
      String s = "The path is C:\\PublicDocuments\\Report1.doc";
      Assert.AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s);
    }

    [Test]
    public void StringCreatedByAssignmentWithVerbatimBackslash() {
      String s = @"The path is C:\PublicDocuments\Report1.doc";
      Assert.AreEqual("The path is C:\\PublicDocuments\\Report1.doc", s);
    }

    [Test]
    public void StringCreatedByConstructorWithChars() {
      char[] chars = { 'w', 'o', 'r', 'd' };
      String s = new string(chars);
      Assert.AreEqual("word", s);
    }

    [Test]
    public void CreateAStringThatConsistsOfACharacterRepeated20Times() {
      String s = new string('C', 20);
      Assert.AreEqual("CCCCCCCCCCCCCCCCCCCC", s);
    }

    [Test]
    public void StringCreatedByConstructorWithPointerOnSBytes() {
      unsafe {
        sbyte[] bytes = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x00 };
        fixed (sbyte* pbytes = bytes) {
          String s = new string(pbytes);
          Assert.AreEqual("ABCDE", s);
        }
      }
    }

    [Test]
    public void StringCreatedByConstructorWithPointerOnChars() {
      unsafe {
        char[] chars = { 'w', 'o', 'r', 'd' };
        fixed (char* pchars = chars) {
          String s = new string(pchars);
          Assert.AreEqual("word", s);
        }
      }
    }

    [Test]
    public void StringCreatedByAssignmentWithUnicodeStringLiteral() {
      String s = "こんにちは世界!";
      Assert.AreEqual("こんにちは世界!", s);
      Assert.AreEqual('こ', s[0]);
      Assert.AreEqual('ん', s[1]);
      Assert.AreEqual('に', s[2]);
      Assert.AreEqual('ち', s[3]);
      Assert.AreEqual('は', s[4]);
      Assert.AreEqual('世', s[5]);
      Assert.AreEqual('界', s[6]);
      Assert.AreEqual('!', s[7]);
    }
  }
}
