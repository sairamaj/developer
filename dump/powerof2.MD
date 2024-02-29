To determine whether a given number is a power of 2, you can use several approaches. Let's explore a few of them:

1. **Using Logarithms**:
   - Take the **logarithm (base 2)** of the number.
   - If the result is an **integer**, then the number is a power of 2.
   - Example (in C++):
     ```cpp
     #include <bits/stdc++.h>
     using namespace std;

     bool isPowerOfTwo(int n) {
         if (n == 0)
             return false;
         return (ceil(log2(n)) == floor(log2(n)));
     }

     int main() {
         isPowerOfTwo(31) ? cout << "Yes" << endl : cout << "No" << endl;
         isPowerOfTwo(64) ? cout << "Yes" << endl : cout << "No" << endl;
         return 0;
     }
     ```
   - **Output**: No (31 is not a power of 2), Yes (64 is a power of 2) ¹.

2. **Using Division and Modulo**:
   - Keep dividing the number by 2 iteratively (i.e., `n = n / 2`).
   - If `n % 2` becomes non-zero and `n` is not 1, then `n` is not a power of 2.
   - If `n` becomes 1, then it is a power of 2.
   - Example (in C++):
     ```cpp
     #include <bits/stdc++.h>
     using namespace std;

     bool isPowerOfTwo(int n) {
         if (n == 0)
             return false;
         while (n != 1) {
             if (n % 2 != 0)
                 return false;
             n = n / 2;
         }
         return true;
     }

     int main() {
         isPowerOfTwo(31) ? cout << "Yes\n" : cout << "No\n";
         isPowerOfTwo(64) ? cout << "Yes\n" : cout << "No\n";
         return 0;
     }
     ```
   - **Output**: No (31 is not a power of 2), Yes (64 is a power of 2) ¹.

3. **Counting Set Bits**:
   - All power of two numbers have only one bit set.
   - Count the number of set bits (using bitwise operations).
   - If the count is 1, the number is a power of 2.
   - Example (in C++):
     ```cpp
     #include <bits/stdc++.h>
     using namespace std;

     bool isPowerOfTwo(int n) {
         int cnt = 0;
         while (n > 0) {
             if ((n & 1) == 1) {
                 cnt++;
             }
             n = n >> 1;
         }
         return cnt == 1;
     }

     int main() {
         isPowerOfTwo(31) ? cout << "Yes\n" : cout << "No\n";
         isPowerOfTwo(64) ? cout << "Yes\n" : cout << "No\n";
         return 0;
     }
     ```
   - **Output**: No (31 is not a power of 2), Yes (64 is a power of 2) ¹.

4. **Using Bitwise AND**:
   - If we subtract a power of 2 number by 1, all unset bits after the only set bit become set, and the set bit becomes unset.
   - If `n & (n - 1)` equals 0, then `n` is a power of 2.
   - Example (in C++):
     ```cpp
     #include <bits/stdc++.h>
     using namespace std;

     bool isPowerOfTwo(int n) {
         return n && !(n & (n - 1));
     }

     int main() {
         isPowerOfTwo(31) ? cout << "Yes\n" : cout << "No\n";
         isPowerOfTwo(64) ? cout << "Yes\n" : cout << "No\n";
         return 0;
     }
     ```
   - **Output**: No (31 is not a power of 2), Yes (64 is a power of 2) ¹.

Choose the method that suits your needs best! 🤓

Source: Conversation with Bing, 2/7/2024
(1) Program to find whether a given number is power of 2. https://www.geeksforgeeks.org/program-to-find-whether-a-given-number-is-power-of-2/.
(2) How to check if a given number is a power of two?. https://stackoverflow.com/questions/57025836/how-to-check-if-a-given-number-is-a-power-of-two.
(3) Given a HUGE number check if it’s a power of two.. https://www.geeksforgeeks.org/given-huge-number-check-power-two/.
(4) How can I test whether a number is a power of 2?. https://stackoverflow.com/questions/108318/how-can-i-test-whether-a-number-is-a-power-of-2.
(5) undefined. https://www.geeksforgeeks.org/program-to-find-whether-a-no-is-power-of-two/Mohammad.
(6) github.com. https://github.com/kothariji/competitive-programming/tree/7328537a6af3e593ea72a31aee359a4fbc017c35/Bit-Manipulations%2F%28GFG%29Power%20of%20Two.cpp.
(7) github.com. https://github.com/samfubuki/striver-sde-solutions/tree/8ae67f7d9995ca8a3af7067fba0631183bc53400/Day%2012%2FwhethernumberisapoweroftwoO%281%29.cpp.