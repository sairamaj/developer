# Sample parsing date
```csharp
			var pattern = @"(?<datetime>\d{4}-\d{1,2}-\d{1,2} \d{1,2}:\d{1,2}:\d{1,2},\d{1,3})";
			var line = @"2018-04-13 12:00:32,675 [36]  ERROR";
			var regex = new System.Text.RegularExpressions.Regex(pattern);
			var match = regex.Match(line);
			var dt = DateTime.ParseExact(match.Groups["datetime"].Value, "yyyy-MM-dd HH:mm:ss,fff", null);
			Console.WriteLine(dt.ToString("yyyy-MM-dd HH:mm:ss,fff"));

```