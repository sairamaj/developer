using System;
using System.Collections.Generic;

public class Solution1
{
    public bool CheckIfExist(int[] arr)
    {
        for(var i=0; i<arr.Length; i++){
            for(var j=i+1; j<arr.Length; j++){
                if(arr[i] * 2 == arr[j] || arr[j] * 2 == arr[i]){
                    return true;
                }
            }
        }
        return false;
    }
}

public class Solution
{
    public bool CheckIfExist(int[] arr)
    {
        var items = new Dictionary<int, int>();
        for (var i = 0; i < arr.Length; i++)
        {
            if ((arr[i] % 2 == 0)) { 
                // even
                // look for 1/2 or double
                if(items.ContainsKey(arr[i]/2) || items.ContainsKey(arr[i]*2) )
                {
                    return true;
                }
            }else{
                if(items.ContainsKey(arr[i]*2)){
                    return true;
                }
            }
            items[arr[i]] = i;
        }

        return false;
    }
}

class Test{
    public static void Main()
    {
        var array = new int[] { 10, 2, 5, 3 };
        System.Console.WriteLine(new Solution1().CheckIfExist(array));
    }
}