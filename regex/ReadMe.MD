# Sample parsing date
```csharp
    // \d - digit
    // \d{4} - 4 digits
    // \d{1,2} - 1 or 2 digits
    // \w+ - word
    var pattern = @"(?<datetime>\d{4}-\d{1,2}-\d{1,2} \d{1,2}:\d{1,2}:\d{1,2},\d{1,3}) \[(?<tid>\d{1,3})\] (?<level>\w+)";
    var line = @"2018-04-13 12:00:32,675 [36] ERROR";
    var regex = new System.Text.RegularExpressions.Regex(pattern);
    var match = regex.Match(line);
    Console.WriteLine(match.Groups["datetime"].Value);
    Console.WriteLine(match.Groups["tid"].Value);
    Console.WriteLine(match.Groups["level"].Value);
    var dt = DateTime.ParseExact(match.Groups["datetime"].Value, "yyyy-MM-dd HH:mm:ss,fff", null);
    Console.WriteLine(dt.ToString("yyyy-MM-dd HH:mm:ss,fff"));

```