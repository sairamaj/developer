namespace wpfcsharpeditor.ViewModel
{
    class MainViewModel
    {
        public MainViewModel()
        {
            this.SourceEditorViewModel = new SourceEditorViewModel();
        }
        public SourceEditorViewModel SourceEditorViewModel { get; set; }
    }
}
