#include <iostream>
#include <string>
using namespace std;

void checkTokens(string s)
{
    string keywords[5] = {"int", "float", "char", "if", "cout"};

    char operators[8] = {'+', '-', '*', '/', '%', '=', '<', '>'};

    char punctuation[6] = {';', ',', '(', ')', '{', '}'};

    string word = "";

    for (int i = 0; i <= s.length(); i++)
    {
        char ch = s[i];

        bool op = false;
        bool punc = false;

        for (int j = 0; j < 8; j++)
        {
            if (ch == operators[j])
            {
                op = true;
                break;
            }
        }

        for (int j = 0; j < 6; j++)
        {
            if (ch == punctuation[j])
            {
                punc = true;
                break;
            }
        }

        if (ch == ' ' || ch == '\0' || op || punc)
        {
            if (word != "")
            {
                bool key = false;

                for (int j = 0; j < 5; j++)
                {
                    if (word == keywords[j])
                    {
                        cout << word << " -> Keyword" << endl;
                        key = true;
                        break;
                    }
                }

                if (!key)
                {
                    bool number = true;
                    int dot = 0;

                    for (int j = 0; j < word.length(); j++)
                    {
                        if (word[j] == '.')
                        {
                            dot++;
                            if (dot > 1)
                                number = false;
                        }
                        else if (!(word[j] >= '0' && word[j] <= '9'))
                        {
                            number = false;
                        }
                    }

                    if (number)
                    {
                        cout << word << " -> Number" << endl;
                    }
                    else
                    {
                        bool id = true;

                        if (!((word[0] >= 'a' && word[0] <= 'z') ||
                              (word[0] >= 'A' && word[0] <= 'Z') ||
                              word[0] == '_'))
                        {
                            id = false;
                        }

                        for (int j = 1; j < word.length(); j++)
                        {
                            if (!((word[j] >= 'a' && word[j] <= 'z') ||
                                  (word[j] >= 'A' && word[j] <= 'Z') ||
                                  (word[j] >= '0' && word[j] <= '9') ||
                                  word[j] == '_'))
                            {
                                id = false;
                            }
                        }

                        if (id)
                            cout << word << " -> Identifier" << endl;
                        else
                            cout << word << " -> Invalid Identifier" << endl;
                    }
                }

                word = "";
            }

            if (op)
            {
                cout << ch << " -> Operator" << endl;
            }

            if (punc)
            {
                cout << ch << " -> Punctuation" << endl;
            }
        }
        else
        {
            word = word + ch;
        }
    }
}

int main()
{
    string input;

    cout << "Enter statement: ";
    getline(cin, input);

    checkTokens(input);

    return 0;
}
