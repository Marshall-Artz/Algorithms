#include <iostream>
using namespace std;

int uniqueChar(string userStr)
{
    int ans = -1;
    bool flag = false;
    char search;
    char compare;

    for (int i = 0; i < userStr.size(); i++) {
        search = userStr[i];

        for (int j = (i+1); j < userStr.size(); j++) {
            compare = userStr[j];

            if (search == compare) {
                break;
            }
            else if (j == (userStr.size() - 1)) {
                ans = i;
                flag = true;
                break;
            }
        }

        if (flag == true) { break; }
    }

    return ans;
}

int main()
{
    string userWord;

    cout << "Enter a word: ";
    cin  >> userWord;

    cout << "The Index for the unique character is: " << endl;
    cout << uniqueChar(userWord) << endl;
}