#include <memory.h>
#include <string>
using namespace std;

// strategy
// go char by char in source
// collect word (once space)
// copy to the destination at the end
// move the destination pointer
// check whether we have removed any spaces
// free that memory
// return destination pointer from the actual copied one.

char *reverseWords(char *s)
{
    auto len = strlen(s);
    char *reverseOne = (char *)malloc(len + 1);
    char *destinationPtr = reverseOne + len;
    *destinationPtr = '\0';
    char *ptr = s;
    int w_start = 0, w_end = 0;
    bool isStarted = false;
    int extraSpaces = 0;

    while (*ptr == ' ')
    {
        ptr++;
        w_start++;
        w_end++;
        extraSpaces++;
    }

    while (*ptr != '\0')
    {
        if (*ptr == ' ')
        {
            auto cur_word_lenth = w_end - w_start;
            // found word
            // append to destination.
            // w_start =0, w_end=3 . cur_word_length = 3
            // the sky
            // cur_word_lenth=6
            // reverse loc: 6-3 = 3  ------

            if (isStarted)
            {
                destinationPtr--;
                *destinationPtr = ' ';
            }
            destinationPtr -= cur_word_lenth;
            //printf("source:%s\n", ptr + w_start);
            //printf("cur_word_lenth:%d w_start:%d w_end:%d\n", cur_word_lenth, w_start, w_end);
            strncpy(destinationPtr, s + w_start, cur_word_lenth);
            //printf("destinationPtr->:|%s|\n", destinationPtr);
            w_start = w_end + 1;
            isStarted = true;

            // skip additional spaces.
            while (*(ptr + 1) == ' ')
            {
                ptr++;
                w_start++;
                w_end++;
                extraSpaces++;
            }
        }
        ptr++;
        w_end++;
    }

    auto cur_word_lenth = w_end - w_start;
    if (cur_word_lenth > 0)
    {
        //printf("destination:|%s|\n", destinationPtr);

        if (isStarted)
        {
            destinationPtr--;
            *destinationPtr = ' ';
        }

        //printf("destination:|%s|\n", destinationPtr);
        destinationPtr -= cur_word_lenth;
        //printf("end:source:|%s|\n", str + w_start);
        //printf("end: cur_word_lenth:%d w_start:%d w_end:%d\n", cur_word_lenth, w_start, w_end);
        strncpy(destinationPtr, s + w_start, cur_word_lenth);
    }

    return destinationPtr;
}

void assert(char *expected, char *actual, char *title)
{
    if (strcmp(expected, actual) == 0)
    {
        printf("success: expected:|%s| actual:|%s| %s\n", expected, actual, title);
    }
    else
    {
        printf("failed: expected:|%s| actual:|%s| %s\n", expected, actual, title);
    }
}

void main()
{
    assert("blue is sky the", reverseWords("the sky is blue"), "the sky is blue");
    assert("blue the", reverseWords("the          blue"), "the           blue");
    assert("world hello", reverseWords("hello world    "), "hello world    ");
    assert("world hello", reverseWords("      hello world    "), "    hello world    ");
    //free(reverseOne);
}
