#include <Pcf/Pcf>
#include "Home32.h"
#include "HomeHighlight32.h"

using namespace System;
using namespace System::Windows::FormsD;

namespace Sudoku {
  enum class Level {
    Easy,
    Medium,
    Hard,
    Impossible
  };
  
  class Cell : public System::Windows::FormsD::Control {
  public:
    Cell() {}
    Cell(const Cell& cell) : value(cell.value), readOnly(cell.readOnly) {}
    
    Property<int> Value {
      pcf_get {return this->value;},
      pcf_set {
        if (value < 0 || value > 9)
          throw System::ArgumentOutOfRangeException(pcf_current_information);
        if (this->value != value) {
          this->value = value;
          this->Invalidate();
          this->OnValueChanged(System::EventArgs());
        }
      }
    };

    Property<bool> ReadOnly {
      pcf_get {return this->readOnly;},
      pcf_set {this->readOnly = value;}
    };
    
    void OnPaint(System::Windows::FormsD::PaintEventArgs& e) override {
      if (this->ReadOnly)
        e.Graphics().FillBox(System::Drawing::BoxType::Up, System::Drawing::SolidBrush(this->BackColor), e.ClipRectangle);
      else
        e.Graphics().FillBox(System::Drawing::BoxType::Down, System::Drawing::SolidBrush(System::Drawing::SystemColors::Window), e.ClipRectangle);

      if (this->Focused)
        e.Graphics().FillRectangle(System::Drawing::SolidBrush(System::Drawing::SystemColors::Highlight), 4, 4, e.ClipRectangle().Width - 8, e.ClipRectangle().Height - 8);
      
      if (this->value != 0) {
        System::Drawing::StringFormat format;
        format.Alignment = System::Drawing::StringAlignment::Center;
        format.LineAlignment = System::Drawing::StringAlignment::Center;
        e.Graphics().DrawString(string::Format("{0}", this->value), System::Drawing::Font("Courier New", e.ClipRectangle().Height - 10, System::Drawing::FontStyle::Bold), System::Drawing::SolidBrush(this->ForeColor), e.ClipRectangle(), format);
      }
    }
    
    void OnKeyPress(System::Windows::FormsD::KeyPressEventArgs& e) override {
      if (e.KeyChar >= '0' && e.KeyChar <= '9')
        this->Value = e.KeyChar - '0';
      else if (e.KeyChar == (char32)System::Windows::FormsD::Keys::Back || e.KeyChar == (char32)System::Windows::FormsD::Keys::Delete)
        this->Value = 0;
      this->KeyPress(*this, e);
    }
    
    virtual void  OnValueChanged(const System::EventArgs& e) {this->ValueChanged(*this, e);}

    bool GetCanFocus() const override {return !this->readOnly;}
    
    System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(98, 98);}

    System::EventHandler ValueChanged;
    
  private:
    int value = 0;
    bool readOnly = true;
  };

  class Chrono : public System::Windows::FormsD::Label {
  public:
    Chrono() {
      this->timer.Interval = 31;
      this->Text = "00:00:00";
      this->timer.Tick += pcf_delegate(const object&, const System::EventArgs& e) {
        if (this->showMilliseconds)
          this->Text = string::Format("{0:D2}:{1:D2}:{2:D2}.{3:D3}", this->chrono.Elapsed().Hours, this->chrono.Elapsed().Minutes, this->chrono.Elapsed().Seconds, this->chrono.Elapsed().Milliseconds);
        else
          this->Text = string::Format("{0:D2}:{1:D2}:{2:D2}", this->chrono.Elapsed().Hours, this->chrono.Elapsed().Minutes, this->chrono.Elapsed().Seconds);
      };
    }
    
    Property<bool> ShowMilliseconds {
      pcf_get {return this->showMilliseconds;},
      pcf_set {
        this->showMilliseconds = value;
        if (!this->isRunning)
          this->Reset();
      }
    };
    
    Property<bool, ReadOnly> IsRunning {
      pcf_get {return this->isRunning;}
    };
    
    void Start() {
      this->isRunning = true;
      this->chrono.Start();
      this->timer.Enabled = true;
    }
    
    void Pause() {this->timer.Enabled = false;}
    
    void Resume() {this->timer.Enabled = true;}
    
    void Stop() {
      this->isRunning = false;
      this->chrono.Stop();
      this->timer.Enabled = false; 
    }
    
    void Reset() {
      this->Stop();
      this->chrono.Reset();
      this->Text = this->showMilliseconds ? "00:00:00.000" : "00:00:00";
    }
    
  private:
    System::Diagnostics::Stopwatch chrono;
    System::Windows::FormsD::Timer timer;
    bool isRunning = false;
    bool showMilliseconds = false;
  };
  
  class MenuPanel : public System::Windows::FormsD::Panel {
  public:
    MenuPanel() {}
    
    Property<MenuItemCollection> Items {
      pcf_get {return this->items;},
      pcf_set {
        this->items = value;
      }
    };
    
  private:
    MenuItemCollection items;
    System::Collections::Generic::List<sp<Label>> values;
  };
  
  class FormSudoku : public Form {
  public:
    // The main entry point for the application.
    static void Main() {
      Application::EnableVisualStyles();
      Application::Run(Sudoku::FormSudoku());
    }

    FormSudoku() {
      this->Text = "Sudoku";
      this->StartPosition = FormStartPosition::Manual;
      this->Location = System::Drawing::Point(300, 100);
      this->ClientSize = System::Drawing::Size(333, 383);
      this->KeyPreview = true;

      this->SizeChanged += pcf_delegate(const object& sender, const EventArgs& e) {
        this->menuPanel.Size = this->ClientSize;
        
        this->newGameLabel.Location = System::Drawing::Point(0,  0);
        this->newGameLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->newGameLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->resumeLabel.Location = System::Drawing::Point(0,  this->newGameLabel.Location().Y +  this->newGameLabel.Size().Height);
        this->resumeLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->resumeLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->setingsLabel.Location = System::Drawing::Point(0,  this->resumeLabel.Location().Y +  this->resumeLabel.Size().Height);
        this->setingsLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->setingsLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->statisticsLabel.Location = System::Drawing::Point(0,  this->setingsLabel.Location().Y +  this->setingsLabel.Size().Height);
        this->statisticsLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->statisticsLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->helpLabel.Location = System::Drawing::Point(0,  this->statisticsLabel.Location().Y +  this->statisticsLabel.Size().Height);
        this->helpLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->helpLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->exitLabel.Location = System::Drawing::Point(0,  this->helpLabel.Location().Y +  this->helpLabel.Size().Height);
        this->exitLabel.Size = System::Drawing::Size(this->menuPanel.Size().Width, this->menuPanel.Size().Height / 6);
        this->exitLabel.Font = System::Drawing::Font("Courier New", this->menuPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->levelPanel.Size = this->ClientSize;

        System::Drawing::Point l;
        for(Label& levelLabel : levelLabels) {
          levelLabel.Location = l;
          levelLabel.Size = System::Drawing::Size(this->levelPanel.Size().Width, this->levelPanel.Size().Height / 6);
          levelLabel.Font = System::Drawing::Font("Courier New", this->levelPanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
          l = System::Drawing::Point(0, levelLabel.Location().Y + levelLabel.Size().Height);
        }
        
        this->gamePanel.Size = System::Drawing::Size(this->ClientSize().Width, this->ClientSize().Height - 50);
        for(int i = 0; i < 81; i++) {
          cells(i / 9, i % 9).Size = System::Drawing::Size((this->gamePanel.Size().Width / 9) - 2, (this->gamePanel.Size().Height / 9) - 2);
          cells(i / 9, i % 9).Location = System::Drawing::Point(5 * (i%9/3 +1) + ((this->gamePanel.Size().Width / 9) - 2) * (i % 9), 5 * (i/27 +1) + ((this->gamePanel.Size().Height / 9) - 2) * (i / 9));
        }
        this->winLabel.Location = System::Drawing::Point(0,  0);
        this->winLabel.Size = System::Drawing::Size(this->gamePanel.Size().Width, this->gamePanel.Size().Height / 6);
        this->winLabel.Font = System::Drawing::Font("Courier New", this->gamePanel.Size().Width / 8, System::Drawing::FontStyle::Bold);
        
        this->boardPanel.Location = System::Drawing::Point(0, this->ClientSize().Height-50);
        this->boardPanel.Size = System::Drawing::Size(this->ClientSize().Width, 50);
        this->chrono.Location = System::Drawing::Point(this->boardPanel.Size().Width - this->chrono.Size().Width, 8);
      };
      
      this->KeyDown += pcf_delegate(const object& sender, const KeyEventArgs& e) {
        if (e.KeyData() == (Keys::Command | Keys::Shift | Keys::S))
          SolveGame();
        else if (e.KeyData() == (Keys::Command | Keys::Shift | Keys::R))
          RestartGame();
        else if (e.KeyCode == Keys::Escape) {
          if (this->levelPanel.Visible) {
            this->levelPanel.Visible = false;
            this->menuPanel.Visible = true;
          } else if (this->menuPanel.Visible) {
            this->menuPanel.Visible = false;
            this->gamePanel.Visible = true;
            this->boardPanel.Visible = true;
          } else {
            this->menuPanel.Visible = true;
            this->gamePanel.Visible = false;
            this->boardPanel.Visible = false;
          }
        }
      };
      
      this->menuPanel.Parent = *this;
      this->menuPanel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->menuPanel.Visible = false;

      this->newGameLabel.Parent = this->menuPanel;
      this->newGameLabel.Text = "New Game";
      this->newGameLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->newGameLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->newGameLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->newGameLabel.Cursor = Cursors::Hand;
      this->newGameLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->newGameLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->newGameLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->newGameLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->newGameLabel.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->menuPanel.Visible = false;
        this->levelPanel.Visible = true;
      };
      
      this->resumeLabel.Parent = this->menuPanel;
      this->resumeLabel.Text = "Resume";
      this->resumeLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->resumeLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->resumeLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->resumeLabel.Cursor = Cursors::Hand;
      this->resumeLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->resumeLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->resumeLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->resumeLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->resumeLabel.Click += pcf_delegate(const object& sender, const EventArgs& z) {
        this->menuPanel.Visible = false;
        this->gamePanel.Visible = true;
        this->boardPanel.Visible = true;
      };
      
      this->setingsLabel.Parent = this->menuPanel;
      this->setingsLabel.Text = "Setings";
      this->setingsLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->setingsLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->setingsLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->setingsLabel.Cursor = Cursors::Hand;
      this->setingsLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->setingsLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->setingsLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->setingsLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->setingsLabel.Click += pcf_delegate(const object& sender, const EventArgs& z) {
      };
      
      this->statisticsLabel.Parent = this->menuPanel;
      this->statisticsLabel.Text = "Statistics";
      this->statisticsLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->statisticsLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->statisticsLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->statisticsLabel.Cursor = Cursors::Hand;
      this->statisticsLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->statisticsLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->statisticsLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->statisticsLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->statisticsLabel.Click += pcf_delegate(const object& sender, const EventArgs& z) {
      };
      
      this->helpLabel.Parent = this->menuPanel;
      this->helpLabel.Text = "Help";
      this->helpLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->helpLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->helpLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->helpLabel.Cursor = Cursors::Hand;
      this->helpLabel.Enabled = false;
      this->helpLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->helpLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->helpLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->helpLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->helpLabel.Click += pcf_delegate(const object& sender, const EventArgs& z) {
      };
      
      this->exitLabel.Parent = this->menuPanel;
      this->exitLabel.Text = "Exit";
      this->exitLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->exitLabel.ForeColor = System::Drawing::SystemColors::Window;
      this->exitLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->exitLabel.Cursor = Cursors::Hand;
      this->exitLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->exitLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
      this->exitLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->exitLabel.ForeColor = System::Drawing::SystemColors::Window;};
      this->exitLabel.Click += pcf_delegate(const object& sender, const EventArgs& z) {
        this->Close();
      };
      
      this->levelPanel.Parent = *this;
      this->levelPanel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->levelPanel.Visible = false;
      
      int index = 0;
      for(Label& levelLabel : levelLabels) {
        levelLabel.Parent = this->levelPanel;
        levelLabel.Text = Enum<Level>::GetNames()[index];
        levelLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
        levelLabel.ForeColor = System::Drawing::SystemColors::Window;
        levelLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
        levelLabel.Cursor = Cursors::Hand;
        levelLabel.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {levelLabel.ForeColor = System::Drawing::SystemColors::Highlight;};
        levelLabel.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {levelLabel.ForeColor = System::Drawing::SystemColors::Window;};
        levelLabel.Click += [&, index](const object& sender, const EventArgs& e) {this->NewGame(Enum<Level>::GetValues()[index]);};
        index++;
     }
      
      this->boardPanel.Parent = *this;
      this->boardPanel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      //this->boardPanel.Dock = DockStyle::Bottom;
      
      this->homePicture.Parent = this->boardPanel;
      this->homePicture.Size = System::Drawing::Size(32, 32);
      this->homePicture.Image = *System::Drawing::Image::FromData(home32);
      this->homePicture.Location = System::Drawing::Point(9, 9);
      this->homePicture.Cursor = Cursors::Hand;
      this->homePicture.MouseEnter += pcf_delegate(const object& sender, const EventArgs& e) {this->homePicture.Image = *System::Drawing::Image::FromData(homeHighlight32);};
      this->homePicture.MouseLeave += pcf_delegate(const object& sender, const EventArgs& e) {this->homePicture.Image = *System::Drawing::Image::FromData(home32);};
      this->homePicture.Click += pcf_delegate(const object& sender, const EventArgs& e) {
        this->gamePanel.Visible = false;
        this->boardPanel.Visible = false;
        this->menuPanel.Visible = true;
      };
      
      this->chrono.Parent = this->boardPanel;
      this->chrono.Font = System::Drawing::Font("Courier New", 30, System::Drawing::FontStyle::Bold);
      this->chrono.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->chrono.ForeColor = System::Drawing::SystemColors::Window;
      this->chrono.AutoSize = true;
      this->chrono.Reset();
      
      this->gamePanel.Parent = *this;
      this->gamePanel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      //this->boardPanel.Dock = DockStyle::Fill;
      
      for(int i = 0; i < 81; i++) {
        this->cells(i / 9, i % 9).Parent = this->gamePanel;
        this->cells(i / 9, i % 9).ValueChanged += pcf_delegate(const object& sender, const EventArgs& e) {
          if (!this->chrono.IsRunning)
            this->chrono.Start();
          this->CheckGame();
        };
      }
      
      this->winLabel.Parent = this->gamePanel;
      this->winLabel.Text = "You win";
      this->winLabel.BackColor = System::Drawing::SystemColors::ControlDarkDark;
      this->winLabel.ForeColor = System::Drawing::Color::LightGreen;
      this->winLabel.TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
      this->winLabel.Visible = false;

      this->SizeChanged(*this, EventArgs());
      
      LoadGame();
    }
    
  private:
    void NewGame(Level level) {
      this->level = level;
      this->Text = string::Format("Sudoku - {0}", this->level);
      
      for (int i = 0; i < this->game.GetLength(0); i++)
        for (int j = 0; j < this->game.GetLength(1); j++) {
          cells(i, j).ReadOnly = true;
          cells(i, j).Cursor = Cursors::Default;
        }
      
      Random rand(System::DateTime::Now().GetHashCode());
      this->game = GenerateGrid(rand);
      
      static System::Collections::Generic::SortedDictionary<Level, int> levelToNumberOfRemovdCells {{Level::Easy, 26}, {Level::Medium, 37}, {Level::Hard, 48}, {Level::Impossible, 59}};
      for (int i = 0; i < levelToNumberOfRemovdCells[this->level]; i++) {
        int row = rand.Next(0, 9);
        int col = rand.Next(0, 9);
        cells(row, col).ReadOnly = false;
        cells(row, col).Cursor = Cursors::IBeam;
      }

      this->RestartGame();
      this->Focus();
      this->chrono.Reset();
    }
    
    void RestartGame() {
      this->menuPanel.Visible = false;
      this->levelPanel.Visible = false;
      this->gamePanel.Visible = true;
      this->boardPanel.Visible = true;

      for (int i = 0; i < this->game.GetLength(0); i++)
        for (int j = 0; j < this->game.GetLength(1); j++)
          cells(i, j).Value = cells(i, j).ReadOnly ? this->game(i, j) : 0;
      this->winLabel.Visible = false;
    }
    
    void SolveGame() {
      for (int i = 0; i < this->game.GetLength(0); i++)
        for (int j = 0; j < this->game.GetLength(1); j++)
          cells(i, j).Value = this->game(i, j);
    }
    
    void LoadGame() {NewGame(Level::Medium);}
    
    void SaveGame() {}
    
    void CheckGame() {
      for (int i = 0; i < cells.GetLength(0); i++) {
        for (int j = 0; j < cells.GetLength(1); j++) {
          if (cells(i, j).Value != this->game(i, j)) {
            return;
          }
        }
      }
      
      this->chrono.Stop();
      this->winLabel.Visible = true;
    }

    bool Focus() override {
      for (int i = 0; i < cells.GetLength(0); i++) {
        for (int j = 0; j < cells.GetLength(1); j++) {
          if (!cells(i, j).ReadOnly) {
            cells(i, j).Focus();
            return true;
          }
        }
      }
      return false;
    }

    Array<int, 2> GenerateGrid(const System::Random& rand) {
      Array<int, 2> values(9, 9);
      for (int j = 0; j < 9; j += 3) {
        for (int k = 0; k < 9; k += 3) {
          for (int t = 1; t <= 9; t ++) {
            int count;
            for (count = 0; count < 20; count ++) {
              int m = j + rand.Next(0, 3);
              int n = k + rand.Next(0, 3);
              if (m >= 0 && m < 9 && n >= 0 && n < 9 && !values(m, n)) {
                int mm;
                for (mm = 0; mm < m; mm ++)
                  if (values(mm, n) == t) break;
                if (mm < m) continue;
                
                int nn;
                for (nn = 0; nn < n; nn ++)
                  if (values(m, nn) == t) break;
                if (nn < n) continue;
                
                values(m, n) = t;
                break;
              }
            }
            
            if (count == 20) {
              k = 9;
              j = -3;
              Array<int, 2>::Clear(values, 0, 9*9);
            }
          }
        }
      }
      return values;
    }

    Array<int, 2> game  = Array<int, 2>(9, 9);
    MainMenu mainMenu;
    Label winLabel;
    Panel gamePanel;
    Array<Cell, 2> cells = Array<Cell, 2>(9, 9);
    Panel boardPanel;
    PictureBox homePicture;
    Chrono chrono;
    Panel menuPanel;
    Label newGameLabel;
    Label resumeLabel;
    Label setingsLabel;
    Label statisticsLabel;
    Label helpLabel;
    Label exitLabel;
    Panel levelPanel;
    Array<Label> levelLabels {Enum<Level>::GetValues().Count};
    Level level;
  };
}

template<>
class EnumToStrings<Sudoku::Level> {
public:
  void operator()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)Sudoku::Level::Easy, "Easy"}, {(int64)Sudoku::Level::Medium, "Medium"}, {(int64)Sudoku::Level::Hard, "Hard"}, {(int64)Sudoku::Level::Impossible, "Impossible"}};
    flags = false;
  }
};

pcf_startup (Sudoku::FormSudoku);