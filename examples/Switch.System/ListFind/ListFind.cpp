#include <Switch/Switch>

using namespace System;
using namespace System::Collections::Generic;

namespace Examples {
  struct Book : public object {
    static Book Empty() {return Book();}

    string iD;
    string author;
    string title;
    string genre;
    double price = .0;
    DateTime publishDate;
    string description;
    
    bool Equals(const Book& book) const {
      return this->iD == book.iD && this->author == book.author && this->title == book.title && this->genre == book.genre && this->price == book.price && this->publishDate == book.publishDate && this->description == book.description;
    }
    
    bool Equals(const object& obj) const noexcept override {
      return is<Book>(obj) && Equals((const Book&)obj);
    }
  };

  class Program : public object {
  public:
    // The main entry point for the application.
    static void Main() {
      FillList();
      DisplayResults(books, "All books:");

      // Find a book by its iD.
      Book result = books.Find(_delegate(const Book& book) {return book.iD.Equals(idToFind);});
      if (result != Book::Empty())
        DisplayResult(result, String::Format("Find by iD: {0}", idToFind));
      else
        Console::WriteLine("\nNot found: " + idToFind);

      // Find last book in collection published before 2001.
      result = books.FindLast(_delegate(const Book& book) {return book.publishDate < DateTime(2001, 1, 1);});
      if (result != Book::Empty())
        DisplayResult(result, "Last book in collection published before 2001:");
      else
        Console::WriteLine("\nNot found a book before 2001.");
      
      // Find all computer books.
      List<Book> results = books.FindAll(FindComputer);
      if (results.Count != 0)
        DisplayResults(results, "All computer:");
      else
        Console::WriteLine("\nNo books found.");

      // Find all books under $10.00.
      results = books.FindAll(_delegate(const Book& book) {return book.price < 10;});
      if (results.Count != 0)
        DisplayResults(results, "Books under $10:");
      else
        Console::WriteLine("\nNo books found.");
      
      // Find index values.
      Console::WriteLine();
      int ndx = books.FindIndex(FindComputer);
      Console::WriteLine("Index of first computer book: {0}", ndx);
      ndx = books.FindLastIndex(FindComputer);
      Console::WriteLine("Index of last computer book: {0}", ndx);

      int mid = books.Count / 2;
      ndx = books.FindIndex(mid, mid, FindComputer);
      Console::WriteLine("Index of first computer book in the second half of the collection: {0}", ndx);

      ndx = books.FindLastIndex(books.Count - 1, mid, FindComputer);
      Console::WriteLine("Index of last computer book in the second half of the collection: {0}", ndx);
    }

  private:
    static void FillList() {
      if (!System::IO::File::Exists(System::IO::Path::Combine(System::IO::Path::GetTempPath(), "books.csv"))) {
        System::IO::File::WriteAllText(System::IO::Path::Combine(System::IO::Path::GetTempPath(), "books.csv"),
                                       "iD;author;title;genre;price;publishDate;description\n"
                                       "bk100;Michael KERRISK;The Linux Programming Interface;Computer;99.95;2008;The definitive guide to Linux and Unix system programming.\n"
                                       "bk101;Pierre Chatelier;De C++ à Objective-C;Computer;0;2009;Ce document est un guide de passage de C++ à Objective-C.\n"
                                       "bk102;Paul W. JOIREMAN;Doxygen Quick Reference;Computer;0;2006;Doxygen commands quick reference.\n"
                                       "bk103;Laurent Gomila;La meta-programmation en C++;Computer;0;2005;Dans cet article, nous allons explorer une partie peu connnue mais pourtant extrêmement puissante du C++ : la meta-programmation.\n"
                                       "bk104;Benjamin Roux;Les sockets en C;Computer;0;2009;Cet article vous présentera les sockets en langage C, du TCP à l'UDP de Windows à Linux.\n"
                                       "bk105;Cisco;WebEx Meeting Center User Guide;User Guide;0;2012;WebEx Meeting Center User Guide for Hosts, Presenters, and Participants.\n"
                                       );
      }
      
      _using (System::IO::StreamReader reader(System::IO::Path::Combine(System::IO::Path::GetTempPath(), "books.csv"))) {
        Array<string> columns = reader.ReadLine().Split(';');

        while (!reader.EndOfStream()) {
          Array<string> values = reader.ReadLine().Split(';');
          Collections::Generic::Dictionary<string, string> record;
          int index = 0;

          for (string column : columns)
            record[column] = values[index++];

          Book book;
          book.iD = record["iD"];
          book.author = record["author"];
          book.title = record["title"];
          book.genre = record["genre"];
          book.price = Double::Parse(record["price"]);
          book.publishDate = DateTime::Parse(record["publishDate"]);
          book.description = record["description"];
          books.Add(book);
        }
      }
    }

    static void DisplayResult(const Book& result, const string& title) {
      Console::WriteLine();
      Console::WriteLine(title);
      Console::WriteLine("\n" + result.iD + "\t" + result.author + "\t" + result.title + "\t" + result.genre + "\t" + result.price + "\t" + result.publishDate.ToShortDateString());
      Console::WriteLine();
    }

    static void DisplayResults(const List<Book>& results, const string& title) {
      Console::WriteLine();
      Console::WriteLine(title);
      for (Book book : results)
        Console::Write("\n" + book.iD + "\t" + book.author + "\t" + book.title + "\t" + book.genre + "\t" + book.price + "\t" + book.publishDate.ToShortDateString());
      Console::WriteLine();
    }

    static bool FindComputer(const Book& book) {
      return book.genre == "Computer";
    }

    static string idToFind;
    static List<Book> books;
  };

  string Program::idToFind = "bk109";
  List<Book> Program::books;
}

_startup(Examples::Program);
