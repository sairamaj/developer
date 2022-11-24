using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MapReduceApp
{
	public class NaiveMapReduceProgram<K1, V1, K2, V2, V3>
	{
		public delegate IEnumerable<KeyValuePair<K2, V2>> MapFunction(K1 key, V1 value);
		public delegate IEnumerable<V3> ReduceFunction(K2 key, IEnumerable<V2> values);
		private MapFunction _map;
		private ReduceFunction _reduce;
		public NaiveMapReduceProgram(MapFunction mapFunction, ReduceFunction reduceFunction)
		{
			_map = mapFunction;
			_reduce = reduceFunction;
		}

		public IEnumerable<KeyValuePair<K2, V3>> Execute(IEnumerable<KeyValuePair<K1, V1>> input)
		{
			return Reduce(Map(input));
		}

		private IEnumerable<KeyValuePair<K2, V2>> Map(IEnumerable<KeyValuePair<K1, V1>> input)
		{
			var q = from pair in input
					from mapped in _map(pair.Key, pair.Value)
					select mapped;

			return q;
		}

		private IEnumerable<KeyValuePair<K2, V3>> Reduce(IEnumerable<KeyValuePair<K2, V2>> intermediateValues)
		{
			Console.WriteLine("----------- In Reduce ----------------");
			foreach (var kv in intermediateValues)
			{
				Console.WriteLine($"{kv.Key}: {kv.Value}");
			}
			Console.WriteLine("_____________________________________");
			// First, group intermediate values by key 
			var groups = from pair in intermediateValues
						 group pair.Value by pair.Key into g
						 select g;
			Console.WriteLine("----------- In Reduce Grouping ----------------");
			foreach (var g1 in groups)
			{
				Console.WriteLine($"{g1.Key}");
				foreach (var g11 in g1)
				{
					Console.WriteLine($"\t{g11}");
				}
			}
			Console.WriteLine("_____________________________________");

			// Reduce on each group 
			var reduced = from g in groups
						  let k2 = g.Key
						  from reducedValue in _reduce(k2, g)
						  select new KeyValuePair<K2, V3>(k2, reducedValue);

			return reduced;
		}
	}
}
