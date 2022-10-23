//90%
#include <iostream>
#include <array>
#include <regex>

enum class Hand
{
    Normal,Hip,Head
};

enum class Foot
{
    Normal,Hip
};

enum Position
{
    Left=0,Right
};



struct Person
{
    std::array<Hand,2> hands;
    std::array<Foot,2> foots;

    Person(): hands({Hand::Normal,Hand::Normal}),foots({Foot::Normal,Foot::Normal}){}
    void turn()
    {
        std::swap(hands[0],hands[1]);
        std::swap(foots[0],foots[1]);
    }

    void setHand(Position pos, Hand state)
    {
        hands[pos]=state;
    }

    void setFoot(Position pos, Foot foot)
    {
        foots[pos]=foot;
    }

    void parse(std::ostream &H,const std::string &S)
    {
        if(S=="turn")
        {
            turn();
            print(H);
        }
        std::regex sayRegEx(R"(say (.+))");
        std::smatch matcher;
        if(std::regex_match(S,matcher,sayRegEx))
        {
            H << matcher[1] << '\n';
            return;
        }

        std::regex stateRegex(R"((left|right) (hand|leg) (to hip|to head|in|out|to start))");
        std::smatch stateMatcher;
        if(std::regex_match(S,stateMatcher,stateRegex))
        {
            Position pos=stateMatcher[1]=="left"?Position::Left:Position::Right;
            if(stateMatcher[2]=="hand")
            {
                Hand hand=Hand::Normal;
                if(stateMatcher[3]=="to hip")
                    hand=Hand::Hip;
                else if(stateMatcher[3]=="to head")
                    hand=Hand::Head;
                setHand(pos,hand);
            }
            else
            {
                Foot foot=Foot::Normal;
                if(stateMatcher[3]=="in")
                    foot=Foot::Hip;
                setFoot(pos,foot);
            }
            print(H);
        }

    }

    void print(std::ostream &H) const
    {
        if(hands[Position::Right]==Hand::Head)
            H << '(';
        else H << ' ';
        H << 'o';
        if(hands[Position::Left]==Hand::Head)
            H << ')';
        else H << ' ';
        H << '\n';
        if(hands[Position::Right]==Hand::Normal)
            H << '/';
        else if(hands[Position::Right]==Hand::Hip) H << '<';
        else H << ' ';
        H << '|';
        if(hands[Position::Left]==Hand::Normal)
            H << '\\';
        else if(hands[Position::Left]==Hand::Hip) H << '>';
        else H << ' ';
        H << '\n';
        if(foots[Position::Right]==Foot::Normal)
            H << '/';
        else H << '<';
        H << ' ';
        if(foots[Position::Left]==Foot::Normal)
            H << '\\';
        else H << '>';
        H << '\n';
    }

};


int main()
{
    int T;
    std::cin >> T;
    while(T--)
    {
        Person person;
        int C;
        std::cin >> C;
        std::cin.ignore();
        while(C--)
        {
            std::string S;
            std::getline(std::cin,S);
            person.parse(std::cout,S);
        }
    }
}
