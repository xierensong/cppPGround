#include <iostream>
#include <string>
using namespace std;

int main()
{
    string my_str;
    int n;
    cin >> n;
    bool flag = false;
    int res;

    res = 0;
    flag = false;
    cin >> my_str;
    for (int j = 0; j < my_str.length(); j++)
    {
        if (my_str[j] >= 'a' && my_str[j] <= 'z' && flag == false)
        {
            res++;
        }
        else if (my_str[j] >= 'a' && my_str[j] <= 'z' && flag == true)
        {
            if (j + 1 < my_str.length())
            {
                if (my_str[j + 1] >= 'a' && my_str[j + 1] <= 'z')
                {
                    flag = false;
                    res += 2;
                }
                else
                    res += 2;
            }
            else
                res += 2;
        }
        else if (my_str[j] >= 'A' && my_str[j] <= 'Z' && flag == true)
        {
            res++;
        }
        else if (my_str[j] >= 'A' && my_str[j] <= 'Z' && flag == false)
        {
            if (j + 1 < my_str.length())
            {
                if (my_str[j + 1] >= 'A' && my_str[j + 1] <= 'Z')
                {
                    flag = true;
                    res += 2;
                }
                else
                    res += 2;
            }
            else
                res += 2;
        }
    }
    cout << res << endl;

    return 0;
}