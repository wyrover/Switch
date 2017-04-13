examples=( Application Button Calculator CheckBox CheckedListBox Chrono Colors Controls Cursor DockedControls DragAndDrop FolderBrowserDialog Font FontFamily Form FormAndThread FormException FormHelloWorld FormTimer GroupBox ImageList KeyEvents Label ListBox MainMenu MaskedTextBox MessageBox MouseEvents MulticamInstaller NumericUpDown OpenFileDialog Paint Panel PictureBox ProgressBar RadioButton RichTextBox SaveFileDialog Sudoku SystemSound TabControl TextBox UserControl )
for example in ${examples[@]}; do
  echo "appify $example..."
  appify --application_name $example --application_file ../../../Build/Examples/Debug/$example --output_directory ../../../Build/Examples/Debug/
  appify --application_name $example --application_file ../../../Build/Examples/Release/$example --output_directory ../../../Build/Examples/Release/
done
