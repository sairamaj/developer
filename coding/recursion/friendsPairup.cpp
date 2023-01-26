/*
    Given n friends who want to go to party, each one can remain single or can be paired up with someo other friend.
    Each firend can be paired only once. Findo ut the total number of ways in which firends can remain single or can be paired up.

    ex:3 friends A,B,C
    Option-1: A,B,C (all single )
    Option-2: (AB)C
    Option-3: (AC)B
    Option-4: (A)BC

    with A going single of N friends
        there are N-1 ways  
            Total ways: 1 * f(N-1)
    with A pair up (N-1) is (N-1) ways 
        Then when A pair with one person there are (N-1) remaining
            Total ways is: (N-1)*f(N-2)
    
    Total : 1 * f(N-1) + (N-1)*f(N-2    )

    Base case
        n = 0  1 way
        n = 1  1 way
*/
#include <stdio.h>

int f(int n)
{
    if(n <= 0){
        return 1;
    }

    return f(n-1) + (n-1)*f(n-2);
}

void main()
{
    for(int i=1; i<4; i++){
        printf("%d-%d\n", i, f(i));
    }
}