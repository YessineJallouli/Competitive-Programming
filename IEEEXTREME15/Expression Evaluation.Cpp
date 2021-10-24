//
// Created by ramizouari on 23/10/2021.
//
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
using natural=std::int64_t;
constexpr natural M=1e9+7;
using integer=natural;

template<long long n,bool is_prime=false>
class cyclic
{
public:
    cyclic(integer s=0):w((s+n)%n){}
    cyclic(long long k):w((k+n)%n){}
    cyclic& operator+=(const cyclic& b)
    {
        w += b.w;
        w%=n;
        return *this;
    }
    cyclic& operator++()
    {
        return *this+=1;
    }
    cyclic operator--()
    {
        return *this-=1;
    }
    cyclic& operator-=(const cyclic& a)
    {
        w += (n - a.w);
        w %= n;
        return *this;
    }
    cyclic& operator*=(const cyclic& a)
    {
        w *= a.w;
        w %= n;
        return *this;
    }


    cyclic& operator+=(int b)
    {
        return *this+=cyclic(b);
    }
    cyclic& operator-=(int a)
    {
        return *this-=cyclic(a);
    }
    cyclic& operator*=(int a)
    {
        return *this*=cyclic(a);
    }
    cyclic operator-() const
    {
        return cyclic(n - w);
    }
    operator integer& () { return w; }
    operator const integer& () const{ return w; }

    cyclic inv()const
    {
        if constexpr (is_prime)
            return pow(*this, n - 2);
        //  else return bezout<integer>(w, n).first;
    }

    cyclic operator/=(const cyclic& a)
    {
        return *this *= a.inv();
    }
private:
    integer w;
};
template<long long n,bool is_prime>
cyclic<n, is_prime> operator+(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c += b;
}
template<long long n,bool is_prime >
cyclic<n,is_prime> operator-(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c -= b;
}
template<long long n,bool is_prime>
cyclic<n, is_prime> operator*(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c *= b;
}

template<long long n, bool is_prime>
cyclic<n, is_prime> operator/(const cyclic<n, is_prime>& a, const cyclic<n, is_prime>& b)
{
    auto c(a);
    return c /= b;
}


std::set<char> O={'-','+','*'};
bool is_symbol(char c)
{
    return O.count(c) || (c=='(') || (c==')');
}

bool is_valid(const std::string &A)
{
    int c=0,n=A.size();
    for(int i=0;i<n;i++)
        if(A[i]=='(')
            c++;
        else if(A[i]==')') {
            c--;
            if(c<0)
                return false;
        }
    if(c>0)
        return false;
    for(int i=0;i<n;i++) if(i<n-1 && O.count(A[i]) && (O.count(A[i+1] )|| A[i+1]==')'))
        return false;
    for(int i=0;i<n-1;i++) if(A[i]=='(' && A[i+1]==')')
        return false;
    if(O.count(A.front()) || O.count(A.back()))
        return false;
    return true;
}



natural evaluate_no_paranthesis(const std::string &A)
{
    std::vector<natural> R(1,0);
    std::vector<char> O;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]<='9' && A[i]>='0')
            R.back()=10*R.back()+(A[i]-'0');
        else
        {
            O.push_back(A[i]);
            R.push_back(0);
        }
    }
    int n=O.size();
    std::vector<natural> S={R[0]};
    std::vector<char> Q;
    for(int i=0;i<n;i++)
        if(O[i]!='*')
        {
            Q.push_back(O[i]);
            S.push_back(R[i+1]);
        }
        else S.back()*=R[i+1];
    int m=Q.size();
    natural r=S[0];
    for(int i=0;i<m;i++)
        if(Q[i]=='+')
            r=(r+S[i+1])%M;
        else r=(r-S[i+1])%M;
    return r;
}

using IK=cyclic<M>;

using namespace std;

// Function to find precedence of
// operators.
int precedence(char op){
    if(op == '+'||op == '-')
        return 1;
    if(op == '*'||op == '/')
        return 2;
    return 0;
}

// Function to perform arithmetic operations.
IK applyOp(IK a, IK b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

// Function that returns value of
// expression after evaluation.
int evaluate(string tokens){
    int i;

    // stack to store integer values.
    stack <IK> values;

    // stack to store operators.
    stack <char> ops;

    for(i = 0; i < tokens.length(); i++){

        // Current token is a whitespace,
        // skip it.
        if(tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if(isdigit(tokens[i])){
            IK val;

            // There may be more than one
            // digits in number.
            while(i < tokens.length() &&
                  isdigit(tokens[i]))
            {
                val = (val*10) + (tokens[i]-'0');
                i++;
            }

            values.push(val);

            // right now the i points to
            // the character next to the digit,
            // since the for loop also increases
            // the i, we would skip one
            //  token position; we need to
            // decrease the value of i by 1 to
            // correct the offset.
            i--;
        }

            // Closing brace encountered, solve
            // entire brace.
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                IK val2 = values.top();
                values.pop();

                IK val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // pop opening brace.
            if(!ops.empty())
                ops.pop();
        }

            // Current token is an operator.
        else
        {
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while(!ops.empty() && precedence(ops.top())
                                  >= precedence(tokens[i])){
                IK val2 = values.top();
                values.pop();

                IK val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }

    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        IK val2 = values.top();
        values.pop();

        IK val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}


int main()
{
    int T;
    std::cin >> T;
    while(T--) {
        std::string E;
        std::cin >> E;
        if (!is_valid(E)) {
            std::cout << "invalid\n";
            continue;
        }
        std::cout << evaluate(E) << '\n';
    }
}
