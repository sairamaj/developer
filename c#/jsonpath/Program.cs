// See https://aka.ms/new-console-template for more information
using System.Text.Json;
using JsonCons.JsonPath;
using static System.Console;

Console.WriteLine("Hello, World!");
var doc = JsonDocument.Parse(File.ReadAllText(@"c:\temp\person.json"));
var selector = JsonSelector.Parse("$.name");

Console.WriteLine("Select values" + selector.GetType());
IList<JsonElement> values = selector.Select(doc.RootElement);
foreach (var val in values)
{
    WriteLine(val);
}

var extracts = new Dictionary<string, string>{
    { "name", "$.name"},
    { "age", "$.age"},
    { "hobbies.id", "$.hobbies[*].id"},
    { "hobbies.game", "$.hobbies[*].game"}
};

var extractor = new Extractor(File.ReadAllText(@"c:\temp\person.json"), extracts);
WriteLine($"name: {extractor.Get("name")}");
WriteLine($"age: {extractor.Get("age")}");
WriteLine($"hobbies.id.0: {extractor.Get("hobbies.id.0")}");
WriteLine($"hobbies.id.1: {extractor.Get("hobbies.id.1")}");
WriteLine($"hobbies.game.1: {extractor.Get("hobbies.game.1")}");
return;
var vals = new Dictionary<string, IList<string>>();
foreach (var extract in extracts)
{
    selector = JsonSelector.Parse(extract.Value);
    values = selector.Select(doc.RootElement);
    var items = new List<string>();
    foreach (var val in values)
    {
        items.Add(val.ToString());
    }
    vals[extract.Key] = items;
}

WriteLine("--------------------");
foreach(var kv in vals){
    WriteLine(kv.Key);
    foreach(var s in kv.Value)
    {
        WriteLine($"\t{s}");
    }
    WriteLine("+++++++++++++++++");
}



WriteLine("--------------------");