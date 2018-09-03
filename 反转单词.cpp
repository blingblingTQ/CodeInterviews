#include <stdio.h>
#include <string.h>


void reverse(char *start, char *end) {
    if(start == NULL || end == NULL)
        return;
    while(start < end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start ++;
        end --;
    }
}

void reverse_words(char *str) {
    if (str == NULL)
        return;
    char *start = str;
    char *end = str;
    while(*end != '\0') {
        end ++;
    }
    end --;
    reverse(start, end);
    end = start;
    
    //反转每个单词
    while(*end != '\0') {
        if(*start == ' ') {
            start ++;
            end ++;
            continue;
        } else if(*end == ' ' || *end == '\0') {
            reverse(start, --end);
            start = ++ end;
        } else {
            end ++;
        }
    }
}


int main(int argc, char * argv[])
{
    char str[] = "I am     a  student.";
    reverse_words(str);
    printf("%s\n", str);
    return 0;
}
