using System.IO;

namespace t4template
{
    // https://humbletoolsmith.com/2018/04/05/t4-csharp_s-little-known-code-generator/
    class Program
    {
        static void Main(string[] args)
        {
            var sample = new SampleCode(new string[]{"One","Two"});
            var file = sample.TransformText();
            File.WriteAllText(@"c:\temp\test.cs", file);
        }
    }
}
