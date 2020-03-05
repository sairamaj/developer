using System.Diagnostics;
using System.Windows.Input;
using ICSharpCode.AvalonEdit.Editing;

namespace wpfcsharpeditor
{
    class CustomTextEditor : ICSharpCode.AvalonEdit.TextEditor
    {
        public CustomTextEditor()
        {
            TextArea.TextEntering += OnTextEntering;
            TextArea.TextEntered += OnTextEntered;

            TextArea.TextEntering += OnTextEntering;
            TextArea.TextEntered += OnTextEntered;

            var ctrlSpace = new RoutedCommand();
            ctrlSpace.InputGestures.Add(new KeyGesture(Key.Space, ModifierKeys.Control));
            var cb = new CommandBinding(ctrlSpace, OnCtrlSpaceCommand);
            this.CommandBindings.Add(cb);
        }

        private void OnTextEntered(object sender, TextCompositionEventArgs textCompositionEventArgs)
        {
            Trace.WriteLine($"[CodeEditor] On Text Entered...");
        }

        private void OnTextEntering(object sender, TextCompositionEventArgs textCompositionEventArgs)
        {
            Trace.WriteLine($"[CodeEditor] On Text OnTextEntering...");
        }


        private void OnCtrlSpaceCommand(object sender, ExecutedRoutedEventArgs executedRoutedEventArgs)
        {
            ShowCompletion(null, true);
        }

        private void ShowCompletion(string enteredText, bool controlSpace)
        {
            Trace.WriteLine($"[CodeEditor] ShowCompletion  {enteredText}");
        }
    }
}
