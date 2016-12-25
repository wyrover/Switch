using System;
using System.Windows.Forms;

namespace MainMenuExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Location = new System.Drawing.Point(400, 200);
      this.ClientSize = new System.Drawing.Size(300, 300);
      this.Text = "MainMenu example";

      this.menuClicks.Parent = this;
      this.menuClicks.Anchor = AnchorStyles.Left | AnchorStyles.Top | AnchorStyles.Right | AnchorStyles.Bottom;
      this.menuClicks.Bounds = new System.Drawing.Rectangle(10, 10, this.ClientSize.Width - 20, this.ClientSize.Height - 20);

      MenuItem[] openRecentsMenu = new MenuItem[] {
        new MenuItem("File 1", new EventHandler(this.OnFileOpenRecentSelected)),
        new MenuItem("File 2", new EventHandler(this.OnFileOpenRecentSelected))
      };

      MenuItem[] fileMenu = new MenuItem[] {
        new MenuItem("New", new EventHandler(this.OnFileNewSelected), Shortcut.CtrlN),
        new MenuItem("-"),
        new MenuItem("Open...", new EventHandler(this.OnFileOpenSelected), Shortcut.CtrlO),
        new MenuItem("Open recent", openRecentsMenu),
        new MenuItem("-"),
        new MenuItem("Close", new EventHandler(this.OnFileCloseSelected), Shortcut.CtrlW),
        new MenuItem("-"),
        new MenuItem("Save", new EventHandler(this.OnFileSaveSelected), Shortcut.CtrlS),
        new MenuItem("Save as...", new EventHandler(this.OnFileSaveAsSelected))};

      MenuItem[] editMenu = new MenuItem[] {
        new MenuItem("Undo", new EventHandler(this.OnEditUndoSelected), Shortcut.CtrlZ),
        new MenuItem("Redo", new EventHandler(this.OnEditRedoSelected), Shortcut.CtrlY),
        new MenuItem("-"),
        new MenuItem("Cut", new EventHandler(this.OnEditCutSelected), Shortcut.CtrlX),
        new MenuItem("Copy", new EventHandler(this.OnEditCopySelected), Shortcut.CtrlC),
        new MenuItem("Paste", new EventHandler(this.OnEditPasteSelected), Shortcut.CtrlV),
        new MenuItem("-"),
        new MenuItem("Select All", new EventHandler(this.OnEditSelectAllSelected), Shortcut.CtrlA)};

      MenuItem[] viewMenu = new MenuItem[] {
        new MenuItem("Show", new EventHandler(this.OnViewShowSelected)),
        new MenuItem("Hide", new EventHandler(this.OnViewHideSelected))
      };

      this.mainMenu.MenuItems.Add(new MenuItem("File", fileMenu));
      this.mainMenu.MenuItems.Add(new MenuItem("Edit", editMenu));
      this.mainMenu.MenuItems.Add(new MenuItem("View", viewMenu));

      this.mainMenu.MenuItems[0].MenuItems[3].MenuItems.Add(new MenuItem("File 3", new EventHandler(this.OnFileOpenRecentSelected)));
      this.Menu = this.mainMenu;
    }

    private void OnFileNewSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("File/New selected");
    }

    private void OnFileOpenSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("File/Open... selected");
    }

    private void OnFileOpenRecentSelected(object sender, EventArgs e) {
      menuClicks.Items.Add(string.Format("File/OpenRecent [{0}] selected", (sender as MenuItem).Text));
    }

    private void OnFileCloseSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("File/Close selected");
    }

    private void OnFileSaveSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("File/Save selected");
    }

    private void OnFileSaveAsSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("File/Save as... selected");
    }

    private void OnEditUndoSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Undo selected");
    }

    private void OnEditRedoSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Redo selected");
    }

    private void OnEditCutSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Cut selected");
    }

    private void OnEditCopySelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Copy selected");
    }

    private void OnEditPasteSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Paste selected");
    }

    private void OnEditSelectAllSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("Edit/Select All selected");
    }

    private void OnViewShowSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("View/Show selected");
    }

    private void OnViewHideSelected(object sender, EventArgs e) {
      menuClicks.Items.Add("View/Hide selected");
    }

    private MainMenu mainMenu = new MainMenu();
    private ListBox menuClicks = new ListBox();
    }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
