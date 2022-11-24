namespace MapReduceApp
{
	internal class Program
	{
		static void Main(string[] args)
		{
			var counter = new WordCounter();
			var inputData = new List<KeyValuePair<string, string>>();
			inputData.Add(new KeyValuePair<string, string>("first", "This is one sentenance. This also contains another"));
			inputData.Add(new KeyValuePair<string, string>("second", "This is another"));

			var results = counter.CalculateWordCount(inputData);
			foreach (var result in results)
			{
				Console.WriteLine($"{result.Key}:{result.Value}");
			}
		}
	}
}