#include<bits/stdc++.h>

using namespace std;

    bool match(char* str, char* pattern)
    {
        printf("%s - %s\n", str, pattern);
        if(*str=='\0' && *pattern=='\0') return true;
        if(*str!='\0' && *pattern=='\0') return false;
        bool firstMatch = (str[0]!='\0') 
                          && ((str[0]==pattern[0]) || (pattern[0]=='.'));
        //cout << "firstMatch" << firstMatch << endl;
        if(pattern[1]!='\0' && pattern[1]=='*') {
                if (firstMatch && match(1+str, pattern)) {
                    return true;
                    }
                //pattern++;
                return match(str,2+pattern);//重复
        }
        else {
            return firstMatch && match(1+str, 1+pattern);
        }
    }

int main()
{
    char* str="bbbba";
    char* pattern=".*a*a";
    cout << match(str,pattern) << endl;
}