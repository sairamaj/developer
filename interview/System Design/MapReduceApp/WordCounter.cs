using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapReduceApp
{
	internal class WordCounter
	{
		public IDictionary<string,int> CalculateWordCount(IEnumerable<KeyValuePair<string, string>> inputData)
		{
			NaiveMapReduceProgram<string, string, string, int, int> master = new NaiveMapReduceProgram<string, string, string, int, int>(MapFromMem, Reduce);
			var result = master.Execute(inputData).ToDictionary(key => key.Key, v => v.Value);
			return result;
		}
		public IList<KeyValuePair<string, int>> MapFromMem(string key, string value)
		{
			List<KeyValuePair<string, int>> result = new List<KeyValuePair<string, int>>();
			foreach (var word in value.Split(' '))
			{
				result.Add(new KeyValuePair<string, int>(word, 1));
			}
			return result;
		}

		public IEnumerable<int> Reduce(string key, IEnumerable<int> values)
		{
			int sum = 0;
			foreach (int value in values)
			{
				sum += value;
			}
			return new int[1] { sum };
		}

	}
}
