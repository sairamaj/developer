using System;
using System.Collections.Generic;
using System.Linq;

class Block
{
    IList<string> _facility = new List<string>();

    public Block(params string[] facilities)
    {
        foreach (var facility in facilities)
        {
            this._facility.Add(facility);
        }
    }

    public bool IsExists(string facility)
    {
        return this._facility.FirstOrDefault(
                f => String.Equals(f, facility, StringComparison.OrdinalIgnoreCase)
            ) != null;
    }

    public IList<string> Facilities => this._facility;

    public override string ToString()
    {
        return String.Join(",", this._facility.ToArray());
    }
}

class BlockFinder
{
    IList<Block> _blocks;

    public BlockFinder(IList<Block> blocks)
    {
        this._blocks = blocks;
    }

    /* brute force
        for each block walk to the other block 
        see whether requirement exists
            if yes count how many step (diff in index)
        at the end find out the minimal distance.
    
        Ex:
            b1->b2  = 0
            b1->b3  = 2
            b1->b4  = 3
            // from here we can stop once we reach all requirements.

            b2->b1  = 0
        Pseudo
            key : blockindex1-blockindex2
            value: distance
            IDictinary<string,int> blockDistMap;

            for(int i=0; i<len; i++) {
                // walk through each requirement block requirement
                // if present distance is 0
                // remove from requirements if found
                // if all found in the same block
                //   exit from here as this is the optimal block.
                for(int j=0; j<len; j++) {
                    if(i!= j)
                    {
                        // start looking for remaining requirement
                        // if found then distance is
                        abs(i-j);
                        // remove from requirement.
                    }
                }
            }
    ex:
         requirement: "gym", "school", "store"
         b1:
            school exists
            ["gym","store]
            b2:
                gym exists
                distance:1
                remaining : [store]
            b3:
                no store found
            b4:
                no store found
            b5:
                found store:
                distance: 4-0 = 4
        [0] = 4;
            // see whether map can change to simply block number if we don't need destination block
        
        // at the end look for least distance from the map.
    */
    public Block Get(string[] requirement)
    {
        var distanceMap = new Dictionary<int, Tuple<Block,int>>();
        for (var i = 0; i < this._blocks.Count; i++)
        {
            var requiredFacilities = requirement.Where(r => !this._blocks[i].IsExists(r)).ToArray();
            if (!requiredFacilities.Any())
            {
                // we got all requirements, in the same block
                return this._blocks[i];
            }
            for (var j = 0; j < this._blocks.Count; j++)
            {
                requiredFacilities = requiredFacilities
                    .Where(r => !this._blocks[j].IsExists(r))
                    .ToArray();
                if (!requiredFacilities.Any())
                {
                    distanceMap[i] = Tuple.Create<Block,int>(this._blocks[i],Math.Abs(i - j));
                    break;
                }
            }
        }

        // print the map for debug
        var blockInfo = distanceMap.First().Value;
        var block = blockInfo.Item1;
        var min = blockInfo.Item2;
        foreach (var kv in distanceMap)
        {
            if(kv.Value.Item2 < min){
                min = kv.Value.Item2;
                block = kv.Value.Item1;
            }
            System.Console.WriteLine($"{kv.Key}:{kv.Value.Item2}");
        }

        return block;
    }
}

class Solution
{
    private void Assert(Block expected, Block actual)
    {
        if (expected == actual)
        {
            System.Console.WriteLine($"Success: expected:{expected} actual:{actual}");
            return;
        }

        Console.WriteLine($"Error: expected:{expected} actual:{actual}");
    }

    public void Test(string[] requirements, int expectedBlock)
    {
        var blocks = new List<Block>();
        blocks.Add(new Block("school"));
        blocks.Add(new Block("gym"));
        blocks.Add(new Block("gym", "school"));
        blocks.Add(new Block("school"));
        blocks.Add(new Block("school", "store"));

        var optimalBlock = new BlockFinder(blocks).Get(requirements);
        this.Assert(blocks[expectedBlock], optimalBlock);
    }
}

public class Test
{
    public static void Main()
    {
        new Solution().Test(new string[] { "gym", "school", "store" }, 3);
        new Solution().Test(new string[] { "gym"}, 1);
    }
}
