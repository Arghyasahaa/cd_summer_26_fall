#include <iostream>
using namespace std;

//Task-1 Numeric checking
void checkNumeric()
{
    string s;
    int flag = 1;

    cout << "Enter Input: ";
    cin >> s;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]<'0' || s[i]>'9')
        {
            flag = 0;
            break;
        }
    }

    if(flag == 1)
        cout << "Numeric Constant";
    else
        cout << "Not Numeric Constant";
}


//Task-2 operator checking
void checkOperator()
{
    string s;
    int c = 1;

    cout << "Enter Expression: ";
    cin >> s;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' ||
           s[i]=='/' || s[i]=='%' || s[i]=='=')
        {
            cout << "Operator" << c << " : " << s[i] << endl;
            c++;
        }
    }
}

//Task-3 comment checking
void checkComment()
{
   string s;

    cin.ignore();

    cout << "Enter Line: ";
    getline(cin,s);

    if(s[0]=='/' && s[1]=='/')
    {
        cout << "Single Line Comment";
    }
    else if(s[0]=='/' && s[1]=='*')
    {
        cout << "Multi Line Comment";
    }
    else
    {
        cout << "Not Comment";
    }
}

//Task-4 comment checking
void checkIdentifier()
{
    string s;
    int flag = 1;

    cout<<"Enter string : ";
    cin>>s;

    if(!((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z') || s[0]=='_'))
    {
        flag = 0;
    }

    for(int i=1; i<s.length(); i++)
    {
        if(!((s[i]>='a' && s[i]<='z') ||
             (s[i]>='A' && s[i]<='Z') ||
             (s[i]>='0' && s[i]<='9') ||
             s[i]=='_'))
        {
            flag = 0;
        }
    }

    if(flag==1)
        cout<<"Valid Identifier";
    else
        cout<<"Not Identifier";
}


//Task - 5 check avg
void arrayAverage()
{
    int n;
    int sum = 0;

    cout << "Enter Size: ";
    cin >> n;

    int arr[100];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
    }

    cout << "Average = " << (float)sum/n;
}


//Task-6 Min Max
void arrayMinMax()
{
    int n;

    cout << "Enter Size: ";
    cin >> n;

    int arr[100];

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int mn = arr[0];
    int mx = arr[0];

    for(int i=1; i<n; i++)
    {
        if(arr[i] < mn)
            mn = arr[i];

        if(arr[i] > mx)
            mx = arr[i];
    }

    cout << "Minimum = " << mn << endl;
    cout << "Maximum = " << mx << endl;
}

// Task-7 concatenation
void concatenateName()
{
    string firstName;
    string lastName;

    cout << "Enter First Name: ";
    cin >> firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;

    string fullName;

    fullName = firstName + " " + lastName;

    cout << "Full Name = " << fullName;
}

//Main cpp
int main()
{
      int ch;

    cout << "1. Numeric Constant" << endl;
    cout << "2. Operator" << endl;
    cout << "3. Comment" << endl;
    cout << "4. Identifier" << endl;
    cout << "5. Array Average" << endl;
    cout << "6. Array Min Max" << endl;
    cout << "7. Concatenate Name" << endl;

    cout << "Enter Choice: ";
    cin >> ch;

    if(ch == 1)
        checkNumeric();

    else if(ch == 2)
        checkOperator();

    else if(ch == 3)
        checkComment();

    else if(ch == 4)
        checkIdentifier();

    else if(ch == 5)
        arrayAverage();

    else if(ch == 6)
        arrayMinMax();

    else if(ch == 7)
        concatenateName();

    else
        cout << "Wrong Input";

    return 0;
}


