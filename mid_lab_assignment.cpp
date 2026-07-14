#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void checkTokens(string s, ofstream &out)
{
    string keywords[8] = {"int","float","char","if","return","cout","main","true"};

    char operators[8] = {'+','-','*','/','=','<','>','%'};

    char punctuation[6] = {';',',','(',')','{','}'};

    string word = "";

    for(int i=0;i<=s.length();i++)
    {
        char ch;

        if(i==s.length())
            ch=' ';
        else
            ch=s[i];

        bool op=false;
        bool punc=false;

        for(int j=0;j<8;j++)
        {
            if(ch==operators[j])
            {
                op=true;
                break;
            }
        }

        for(int j=0;j<6;j++)
        {
            if(ch==punctuation[j])
            {
                punc=true;
                break;
            }
        }

        if(ch==' ' || op || punc)
        {
            if(word!="")
            {
                bool key=false;

                for(int j=0;j<8;j++)
                {
                    if(word==keywords[j])
                    {
                        cout<<word<<" -> Keyword"<<endl;
                        out<<word<<" -> Keyword"<<endl;
                        key=true;
                        break;
                    }
                }

                if(!key)
                {
                    bool number=true;

                    for(int j=0;j<word.length();j++)
                    {
                        if(word[j]<'0' || word[j]>'9')
                        {
                            number=false;
                            break;
                        }
                    }

                    if(number)
                    {
                        cout<<word<<" -> Number"<<endl;
                        out<<word<<" -> Number"<<endl;
                    }
                    else
                    {
                        cout<<word<<" -> Identifier"<<endl;
                        out<<word<<" -> Identifier"<<endl;
                    }
                }

                word="";
            }

            if(op)
            {
                cout<<ch<<" -> Operator"<<endl;
                out<<ch<<" -> Operator"<<endl;
            }

            if(punc)
            {
                cout<<ch<<" -> Punctuation"<<endl;
                out<<ch<<" -> Punctuation"<<endl;
            }
        }
        else
        {
            if(ch!='"')
                word=word+ch;
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("Output.txt");

    if(!fin)
    {
        cout<<"File not found"<<endl;
        return 0;
    }

    string line;

    while(getline(fin,line))
    {
        checkTokens(line,fout);
    }

    fin.close();
    fout.close();

    cout<<"\nOutput is also saved in Output.txt"<<endl;

    return 0;
}
