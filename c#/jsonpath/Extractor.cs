using System.Text.Json;
using JsonCons.JsonPath;
using Microsoft.VisualBasic;

class Extractor
{
    private IDictionary<string, IList<string>> extracted = new Dictionary<string, IList<string>>();
    public Extractor(string json, IDictionary<string, string> extracts)
    {
        this.Parse(json,extracts);
    }

    public string? Get(string name)
    {
        // name
        // hobbies.id.0
        // hobbies.id.1

        var nameKey = name;
        var nameIndex = -1;
        var index = nameKey.LastIndexOf('.');
        if (index > 0)
        {
            nameKey = name.Substring(0, index);
            nameIndex = Convert.ToInt32(name.Substring(index + 1));
        }

        if (!this.extracted.TryGetValue(nameKey, out var val))
        {
            return null;
        }

        if(nameIndex == -1)
        {
            return val.FirstOrDefault();
        }

        return val[nameIndex];
    }
    private void Parse(string json, IDictionary<string, string> extracts)
    {
        var doc = JsonDocument.Parse(json);
        foreach (var extract in extracts)
        {
            var selector = JsonSelector.Parse(extract.Value);
            var values = selector.Select(doc.RootElement);
            var items = new List<string>();
            foreach (var val in values)
            {
                items.Add(val.ToString());
            }
            extracted[extract.Key] = items;
        }
    }
}