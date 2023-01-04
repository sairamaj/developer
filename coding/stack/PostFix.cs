/*
    Convert infix to postfix
    ex:
        a*b => ab*
        a*b*c => ab*c*
        a+b+c => ab+c+
*/

/*
    - walk the expression from left right
    - If operator push
    - If non operator 
    - emit the operand
    - check if there is item on stack 
    - if yes
       - bring it.
    ex:
        a*b
            - out: a
            -   no stack item
            - * - push *
            - out: ab
            - check stack
            - yes
              - ab*
*/
using System;
using System.Collections.Generic;

public class Expression
{
    public Expression(string expression)
    {
        this.PostFix = this.Parse(expression);
    }

    public string PostFix { get; }

    private string Parse(string expression)
    {
        Stack<char> s = new Stack<char>();
        var postFix = string.Empty;
        foreach (var ch in expression)
        {
            if (ch == '*' || ch == '+')
            {
                s.Push(ch);
            }
            else
            {
                // assumed as regular char.
                postFix += ch;
                // check anything on stack
                if (s.Count > 0 )
                {
                    var op = s.Pop();
                    postFix += op;
                }
            }
        }

        return postFix;
    }
}

public class Test
{
    public static void Main(String[] args)
    {
        var exp = new Expression("a*b*c");
        System.Console.WriteLine(exp.PostFix);
    }
}
