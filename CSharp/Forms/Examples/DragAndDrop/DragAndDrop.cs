using System;
using System.Windows.Forms;

namespace DragAndDropExample {
  class Form1 : Form {
    public Form1() {
      this.StartPosition = FormStartPosition.Manual;
      this.Text = "Drag and Drop example";
      this.Location = new System.Drawing.Point(300, 200);
      this.ClientSize = new System.Drawing.Size(640, 480);

      this.panelFill.Parent = this;
      this.panelFill.BackColor = System.Drawing.SystemColors.ControlLightLight;
      this.panelFill.BorderStyle = BorderStyle.None;
      this.panelFill.Dock = DockStyle.Fill;

      this.panelLeft.Parent = this;
      this.panelLeft.BorderStyle = BorderStyle.Fixed3D;
      this.panelLeft.Dock = DockStyle.Left;

      this.panelForm.Parent = this.panelFill;
      this.panelForm.BackColor = System.Drawing.SystemColors.Control;
      this.panelForm.BorderStyle = BorderStyle.FixedSingle;
      this.panelForm.Bounds = new System.Drawing.Rectangle(10, 10, 300, 300);
      this.panelForm.AllowDrop = true;
      this.panelForm.DragEnter += this.OnPanelFormControlDragEnter;
      this.panelForm.DragOver += this.OnPanelFormControlDragOver;
      this.panelForm.DragDrop += this.OnPanelFormControlDragDrop;
      this.panelForm.DragLeave += this.OnPanelFormControlDragLeave;

      this.listBoxControl.Parent = this.panelLeft;
      this.listBoxControl.BorderStyle = BorderStyle.Fixed3D;
      this.listBoxControl.Dock = DockStyle.Fill;
      this.listBoxControl.Items.AddRange(new string[] {"Button", "CheckBox", "CheckedListBox", "Label", "ListBox", "MaskedTextBox", "PictureBox", "ProgressBar", "RadioButton", "RichTextBox", "TextBox"});
      this.listBoxControl.SelectedIndex = 0;
      this.listBoxControl.MouseDown += this.OnListBoxControlMouseDown;
    }

    private void OnListBoxControlMouseDown(object sender, MouseEventArgs e) {
      this.listBoxControl.DoDragDrop(this.listBoxControl.SelectedItem, DragDropEffects.Copy);
    }

    private Control CreateButton() {
      Button control = new Button();
      control.Text = string.Format("button {0}", this.cptButton++);
      return control as Control;
    }

    private Control CreateCheckBox() {
      CheckBox control = new CheckBox();
      control.Text = string.Format("CheckBox {0}", this.cptCheckBox++);
      return control as Control;
    }

    private Control CreateCheckedListBox() {
      CheckedListBox control = new CheckedListBox();
      control.Text = string.Format("CheckedListBox {0}", this.cptCheckedListBox++);
      control.Items.Add("Item 1");
      return control as Control;
    }

    private Control CreateLabel() {
      Label control = new Label();
      control.BackColor = System.Drawing.SystemColors.Control;
      control.AutoSize = true;
      control.Text = string.Format("Label {0}", this.cptLabel++);
      return control as Control;
    }

    private Control CreateListBox() {
      ListBox control = new ListBox();
      control.Text = string.Format("ListBox {0}", this.cptListBox++);
      control.Items.Add("Item 1");
      return control as Control;
    }

    private Control CreateMaskedTextBox() {
      MaskedTextBox control = new MaskedTextBox();
      control.Text = string.Format("MaskedTextBox {0}", this.cptMaskedTextBox++);
      return control as Control;
    }

    private Control CreatePictureBox() {
      PictureBox control = new PictureBox();
      control.Text = string.Format("PictureBox {0}", this.cptPictureBox++);
      control.BorderStyle = BorderStyle.FixedSingle;
      return control as Control;
    }

    private Control CreateProgressBar() {
      ProgressBar control = new ProgressBar();
      control.Value = 50;
      return control as Control;
    }

    private Control CreateRadioButton() {
      RadioButton control = new RadioButton();
      control.BackColor = System.Drawing.SystemColors.Control;
      control.Text = string.Format("radioButton {0}", this.cptRadioButton++);
      return control as Control;
    }

    private Control CreateRichTextBox() {
      RichTextBox control = new RichTextBox();
      control.Text = string.Format("RichTextBox {0}", this.cptRichTextBox++);
      return control as Control;
    }

    private Control CreateTextBox() {
      TextBox control = new TextBox();
      control.Text = string.Format("TextBox {0}", this.cptTextBox++);
      return control as Control;
    }

    private void OnPanelFormControlDragEnter(object sender, DragEventArgs e) {
      e.Effect = DragDropEffects.Copy;
      if (this.controlDrop == null) {
        string str = (string)e.Data.GetData(typeof(string));
        if (str == "Button")
          this.controlDrop = CreateButton();
        if (str == "CheckBox")
          this.controlDrop = CreateCheckBox();
        if (str == "CheckedListBox")
          this.controlDrop = CreateCheckedListBox();
        if (str == "Label")
          this.controlDrop = CreateLabel();
        if (str == "ListBox")
          this.controlDrop = CreateListBox();
        if (str == "MaskedTextBox")
          this.controlDrop = CreateMaskedTextBox();
        if (str == "PictureBox")
          this.controlDrop = CreatePictureBox();
        if (str == "ProgressBar")
          this.controlDrop = CreateProgressBar();
        if (str == "RadioButton")
          this.controlDrop = CreateRadioButton();
        if (str == "RichTextBox")
          this.controlDrop = CreateRichTextBox();
        if (str == "TextBox")
          this.controlDrop = CreateTextBox();
      }
    }

    void OnPanelFormControlDragOver(object sender, DragEventArgs e) {
      if (this.controlDrop != null) {
        this.controlDrop.Parent = this.panelForm;
        this.controlDrop.Location = this.panelForm.PointToClient(new System.Drawing.Point(e.X+1, e.Y+1));
        Application.DoEvents();
      }
    }

    void OnPanelFormControlDragDrop(object sender, DragEventArgs e) {
      if (this.controlDrop != null){
        this.controlDrop.Parent = this.panelForm;
        this.controlDrop.Location = this.panelForm.PointToClient(new System.Drawing.Point(e.X+1, e.Y+1));
        this.controls.Add(this.controlDrop);
        this.controlDrop = null;
      }
    }

    void OnPanelFormControlDragLeave(object sender, EventArgs e) {
      if (this.controlDrop != null) {
        this.controlDrop.Location = new System.Drawing.Point(-1, -1);
        this.controlDrop = null;
      }
    }

    private Panel panelLeft = new Panel();
    private Panel panelFill = new Panel();
    private Panel panelForm = new Panel();
    private ListBox listBoxControl = new ListBox();
    private Control controlDrop = null;
    private System.Collections.Generic.List<Control> controls = new System.Collections.Generic.List<Control>();

    private int cptButton = 1;
    private int cptCheckBox = 1;
    private int cptCheckedListBox = 1;
    private int cptLabel = 1;
    private int cptListBox = 1;
    private int cptMaskedTextBox = 1;
    private int cptPictureBox = 1;
    private int cptRadioButton = 1;
    private int cptRichTextBox = 1;
    private int cptTextBox = 1;
  }

  class MainClass {
    [STAThread]
    public static void Main() {
      Application.EnableVisualStyles();
      Application.Run(new Form1());
    }
  }
}
