/*#include<bits/stdc++.h>
using namespace std;
class Stack
{
    public:
    char *arr;
    int top;
    int size;
    Stack(int size)
    {
        this -> size = size;
        arr = new char [size];
        top = -1;
    }

    void push(char val)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = val;
        }
        else
        {
            cout<<"stack overflowed"<<endl;
        }
    }

    void pop()
    {
        if(top!=-1)
        {
            top--;
        }
        else
        {
            cout<<"no element in stack"<<endl;
        }
    }

    void peek()
    {
        if(top!=-1)
        {
            cout<<arr[top]<<endl;
        }
        else
        {
            cout<<"stack is empty"<<endl;
        }
    }

    void reverse()
    {
        while(top--)
        {
            cout<<arr[top]<<" ";
        }
    }
};
int main()
{
    Stack st(5);
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('d');
    st.push('e');
    st.reverse();
}*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int>st;
    int s;
    cin>>s;
    int a;
    for(int i=0;i<s;i++)
    {
        cin>>a;
        st.push(a);
    }
    if(s%2==0)
    {
        int m = s/2;
        while(s--)
        {
            if(s==m)
            {
                st.pop();
            }
        }
    }
}