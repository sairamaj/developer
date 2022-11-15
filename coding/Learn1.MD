### Looping new way
```cplus
#include <vector>
using namespace std;

void main()
{
    vector<int> map(101, 0);

    // Using new for loop
    for (int m : map)
    {
        printf("%d\n", m);
    }

    // defined in <climits>
    int x = INT_MIN;
    int y = INT_MAX;
}
```

### map
```cplus
// map
#include <map>
map<int, int> numMap;
if (numMap.find(i) == numMap.end())
```
### appending character
```cplus
    // prepending
    s.insert(pos, 1, (rem + 48));
```

### string trimming
```cplus
s.erase(0, s.find_first_not_of('0'));
```