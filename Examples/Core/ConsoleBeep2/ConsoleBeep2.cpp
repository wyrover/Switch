#include <Pcf/Pcf>

using namespace System;
using namespace System::Threading;

namespace Examples {
  class Program {
    // Define the frequencies of notes in an octave, as well as
    // silence (rest).
    enum class Tone {
      REST   = 0,
      GbelowC = 196,
      A      = 220,
      Asharp = 233,
      B      = 247,
      C      = 262,
      Csharp = 277,
      D      = 294,
      Dsharp = 311,
      E      = 330,
      F      = 349,
      Fsharp = 370,
      G      = 392,
      Gsharp = 415,
    };
    
    // Define the duration of a note in units of milliseconds.
    enum class Duration {
      WHOLE     = 1600,
      HALF      = WHOLE/2,
      QUARTER   = HALF/2,
      EIGHTH    = QUARTER/2,
      SIXTEENTH = EIGHTH/2,
    };
    
    // Define a note as a frequency (tone) and the amount of
    // time (duration) the note plays.
    struct Note : public object {
      Tone     toneVal;
      Duration durVal;
      
      // Define a constructor to create a specific note.
      Note(Tone frequency, Duration time) {
        toneVal = frequency;
        durVal  = time;
      };
      
      Note(const Note& note) : toneVal(note.toneVal), durVal(note.durVal) {}
      Note() : toneVal((Tone)0), durVal((Duration)0) {}
      
      // Define properties to return the note's tone and duration.
      Property<Tone, ReadOnly> NoteTone { pcf_get{ return toneVal; } };
      Property<Duration, ReadOnly> NoteDuration { pcf_get{ return durVal; } };
    };
    
  public:
    // The main entry point for the application.
    static void Main() {
      // Declare the first few notes of the song, "Mary Had A Little Lamb".
      Array<Note> Mary = {
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::GbelowC, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::B, Duration::HALF),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::A, Duration::QUARTER),
        Note(Tone::A, Duration::HALF),
        Note(Tone::B, Duration::QUARTER),
        Note(Tone::D, Duration::QUARTER),
         Note(Tone::D, Duration::HALF)
      };
      // Play the song
      Play(Mary);
    }
   
  protected:
    // Play the notes in a song.
    static void Play(const Array<Note>& tune) {
      for (Note n : tune) {
        if (n.NoteTone == Tone::REST)
          Thread::Sleep((int)n.NoteDuration());
        else
          Console::Beep((int)n.NoteTone(), (int)n.NoteDuration());
      }
    }
  };
}

pcf_startup (Examples::Program)

// This code produces the following output:
//
// The current window width is 100, and the current window height is 60.
//   (Press any key to continue...)
// The new window width is 50, and the new window height is 30.
//   (Press any key to continue...)
// The current window width is 100, and the current window height is 60.
