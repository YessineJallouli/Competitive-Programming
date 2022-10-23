//12%
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <regex>
#include <numeric>
#include <iomanip>

struct Hashable
{
    std::uint64_t hash=0;
    bool operator==(const Hashable & other) const=default;
    auto operator<=>(const Hashable & other) const= default;
protected:
};

struct Symbol : public Hashable
{
    std::uint64_t id;
    explicit Symbol(std::uint64_t id=0);
    bool operator==(const Symbol & other) const = default;
    auto operator<=>(const Symbol & other) const = default;
    std::uint64_t initHash();
private:
    inline static constexpr std::hash<std::uint64_t> hasher{};
};


template<typename T>
concept isHashable =  std::is_base_of_v<Hashable, std::remove_cvref_t<T>>;

template<isHashable H >
struct std::hash<H>
{
    std::size_t operator()(const H & h) const
    {
        return h.hash;
    }
};

template<typename T>
struct std::hash<std::vector<T>>
{
    inline static constexpr std::hash<T> hasher{};
    std::size_t operator()(const std::vector<T> & v) const
    {
        std::size_t hash=0;
        for(auto & e : v)
            hash^=hasher(e);
        return hash;
    }
};

template<typename A,typename B>
struct std::hash<std::pair<A,B>>
{
    inline static constexpr std::hash<A> hasherA{};
    inline static constexpr std::hash<B> hasherB{};
    std::size_t operator()(const std::pair<A,B> & v) const
    {
        return hasherA(v.first)^hasherB(v.second);
    }
};

template<typename T>
struct std::hash<std::unordered_set<T>>
{
    inline static constexpr std::hash<T> hasher{};
    std::size_t operator()(const std::unordered_set<T> & v) const
    {
        std::size_t hash=0;
        for(auto & e : v)
            hash^=hasher(e);
        return hash;
    }
};

struct Rule : public Hashable
{
    Symbol left;
    std::vector<Symbol> right;
    Rule(Symbol left, const std::vector<Symbol>& right);
    Rule(Symbol left, std::vector<Symbol>&& right);
    bool operator==(const Rule & other) const = default;
    auto operator<=>(const Rule & other) const = default;
    std::uint64_t initHash();
private:
    inline static constexpr std::hash<std::vector<Symbol>> hasher{};

};

class Grammar
{
protected:
    std::vector<Rule>  rules;
    Symbol axiom;
    std::vector<Symbol> symbols;
    std::vector<std::vector<std::uint64_t>> ruleIdsBySymbolId;
public:
    void addRule(const Rule &rule);
    void addRule(Rule &&rule);
    void setAxiom(const Symbol &_axiom);
    virtual ~Grammar() = default;

    template<typename Left, typename... Right>
    void emplaceRule(Left &&left,Right &&... right)
    {
        rules.template emplace_back(std::forward(left),{std::forward(right)...});
    }
    template<typename Left,typename Right>
    void addRule(Left &&left,Right &&right)
    {
        rules.template emplace_back(std::forward(left),std::forward(right));
    }
    [[nodiscard]] const std::vector<Rule> & getRules() const;
};

enum SpecialCharacter : std::uint64_t
{
    Epsilon=std::numeric_limits<std::uint64_t>::max()-2,
    EndOfString,
    Empty=Epsilon,
    EndOfFile=EndOfString
};

class GrammarWithFirstFollow : virtual public Grammar
{
protected:
    std::vector<std::unordered_set<std::uint64_t>> firstIds,followIds;
    virtual void buildFirst();
    virtual void buildFollow();
};



template<typename CharType,typename Traits=std::char_traits<CharType>>
class StringParser : virtual protected Grammar
{


protected:
    using stringType=std::basic_string<CharType,Traits>;
    static std::vector<stringType> split(const stringType &S,const stringType &regex)
    {
        std::basic_regex<CharType,std::regex_traits<CharType>> rgx(regex);
        std::regex_token_iterator<typename stringType::const_iterator> iter(S.begin(),
                                                                            S.end(),
                                                                            rgx,
                                                                            -1),
                end;
        std::vector<stringType> result(iter, end);
        if(result.front().empty())
            return {};
        return result;
    }
    std::unordered_map<Symbol,std::uint64_t> symbolId;
    std::unordered_map<stringType,std::uint64_t> symbolMap;
    Symbol& addSymbol(const stringType & s)
    {
        auto it=symbolMap.find(s);
        if(it==symbolMap.end())
        {
            Symbol S{symbolId.size()};
            symbols.push_back(S);
            symbolMap[s]=symbolId.size();
            symbolId[S]=S.id;
            return symbols.back();
        }
        else return symbols[it->second];
    }

public:

    void addRuleList(const stringType &left,const std::vector<stringType> &right)
    {
        Symbol  L=addSymbol(left);
        std::vector<Symbol> R;
        for(const auto & s : right)
            R.push_back(addSymbol(s));
        Rule rule{L,R};
        Grammar::addRule(std::move(rule));
    }

    template<typename Left,typename... Right>
    void addRuleList(Left && left, Right && ... right)
    {
        auto S=addSymbol(std::forward<Left>(left));
        std::vector<Symbol> rightVec{addSymbol(std::forward<Right>(right))...};
        Rule rule(S,rightVec);
        Grammar::addRule(std::move(rule));
    }

    virtual void addRule(const std::basic_string<CharType,Traits> &line)
    {
        std::basic_regex<CharType,std::regex_traits<CharType>> ruleRegex(R"(\s*([^\s]+)\s*(?:->|:|:==)\s*((?:[^\s]\s+)*(?:[^\s]+)|)\s*)");
        std::match_results<typename stringType::const_iterator> ruleMatch;

        if(std::regex_match(line,ruleMatch,ruleRegex))
        {
            std::vector<Symbol>  rightSymbols;
            Symbol leftSymbol=addSymbol(ruleMatch[1]);
            std::cout << ruleMatch[2] << std::endl;
            for(const auto &s : split(ruleMatch[2],R"(\s+)"))
                rightSymbols.push_back(addSymbol(s));
            Rule rule(leftSymbol,rightSymbols);
            Grammar::addRule(std::move(rule));
        }
        else
            throw std::runtime_error("Invalid rule");
    }

    //virtual void addRule(std::basic_string<CharType,Traits> &&line) = 0;
    virtual bool parse(const std::basic_string<CharType,Traits> &line)=0;
};




namespace parser {

    struct LR0Item : public Hashable
    {
        std::uint64_t ruleId;
        std::uint64_t dot;
        explicit LR0Item(std::uint64_t ruleId,std::uint64_t dot);
        bool operator==(const LR0Item & other) const = default;
        auto operator<=>(const LR0Item & other) const = default;
        std::uint64_t initHash();
    private:
        inline static constexpr std::hash<std::uint64_t> hasher{};
    };

    struct LR1Item : public Hashable
    {
        std::uint64_t ruleId;
        std::uint64_t dot;
        std::uint64_t lookahead;
        explicit LR1Item(std::uint64_t ruleId,std::uint64_t dot,std::uint64_t lookahead);
        bool operator==(const LR1Item & other) const = default;
        auto operator<=>(const LR1Item & other) const = default;
        std::uint64_t initHash();
    private:
        inline static constexpr std::hash<std::uint64_t> hasher{};
    };

    struct LALR1Item : public Hashable
    {
        std::uint64_t ruleId;
        std::uint64_t dot;
        mutable std::unordered_set<std::uint64_t> lookahead;
        explicit LALR1Item(std::uint64_t ruleId,std::uint64_t dot,std::unordered_set<std::uint64_t>&& lookahead);
        explicit LALR1Item(std::uint64_t ruleId,std::uint64_t dot,const std::unordered_set<std::uint64_t>& lookahead);
        bool operator==(const LALR1Item & other) const;
        std::uint64_t initHash();
    };

    namespace LRFamily
    {
        struct Action
        {
            enum Type
            {
                Shift,
                Reduce,
                Accept,
                Error
            };
            Type type;
            std::uint64_t value;
            Action(Type type,std::uint64_t value);
        };

        struct LALR1ItemContext
        {
            std::uint64_t id;
            std::unordered_set<std::uint64_t> lookaheads;
            explicit LALR1ItemContext(std::uint64_t id,std::unordered_set<std::uint64_t> &&lookaheads);
            explicit LALR1ItemContext(std::uint64_t id,const std::unordered_set<std::uint64_t> &lookaheads);

        };
    }

    class ShiftReduceParser :public StringParser<char>
    {
    protected:
        using Action=LRFamily::Action;
        std::unordered_map<std::pair<std::uint64_t,std::uint64_t>,Action> gotoIds;
    public:
        void printTable(std::ostream &H) const;
        bool parse(const std::string &s) override;
        //bool parse(std::uint64_t symbolId);
    };

    class LR0ParserBuilder final: public ShiftReduceParser
    {

        std::unordered_map<std::unordered_set<LR0Item>,int> lr0ItemsIds;
        std::vector<std::unordered_set<LR0Item>> lr0Items;
        std::vector<bool> isTerminal;
        std::unordered_set<LR0Item> closure(const std::unordered_set<LR0Item> &item);
    public:
        LR0ParserBuilder& build() &;
    };

    class SLRParserBuilder final: protected  GrammarWithFirstFollow, public ShiftReduceParser
    {

        using Action=LRFamily::Action;
        std::unordered_map<std::unordered_set<LR0Item>,int> lr0ItemsIds;
        std::vector<std::unordered_set<LR0Item>> lr0Items;
        std::vector<bool> isTerminal;
        std::unordered_set<LR0Item> closure(const std::unordered_set<LR0Item> &item);
    public:
        SLRParserBuilder& build() &;
    };

    class LRParserBuilder: protected  GrammarWithFirstFollow, public ShiftReduceParser
    {

        using Action=LRFamily::Action;
        std::unordered_map<std::unordered_set<LR1Item>,int> lr1ItemsIds;
        std::vector<std::unordered_set<LR1Item>> lr1Items;
        std::vector<bool> isTerminal;
        std::unordered_set<LR1Item> closure(const std::unordered_set<LR1Item> &item);
    public:
        //bool parse(const std::string &s) override;
        LRParserBuilder& build() &;
    };

    class LALRParserBuilder final: protected  GrammarWithFirstFollow, public ShiftReduceParser
    {

        using Action=LRFamily::Action;
        using LRLALR1ItemContext=LRFamily::LALR1ItemContext;
        std::unordered_map<std::unordered_set<LALR1Item>,std::uint64_t> lr1ItemsIds;
        std::vector<std::unordered_set<LALR1Item>> lr1Items;
        std::vector<bool> isTerminal;
        std::unordered_set<LALR1Item> closure(const std::unordered_set<LALR1Item> &item);
    public:
        LALRParserBuilder& build() &;
    };

    class ArithmeticParser : public LRParserBuilder
    {

    public:
    };

} // parser



std::uint64_t Symbol::initHash() {
    return hasher(id);
}

Symbol::Symbol(std::uint64_t id): id(id)
{
    initHash();
}

Rule::Rule(Symbol left, const std::vector<Symbol> &right):left(left),right(right)
{
    initHash();
}

std::uint64_t Rule::initHash()  {
    std::uint64_t hash=left.hash;
    hash^=hasher(right);
    return hash;
}

Rule::Rule(Symbol left, std::vector<Symbol> &&right) : left(left), right(std::move(right))
{
    initHash();
}

void Grammar::addRule(const Rule &rule) {
    if(rule.left.id>=ruleIdsBySymbolId.size())
        ruleIdsBySymbolId.resize(2*rule.left.id+1);
    ruleIdsBySymbolId[rule.left.id].push_back(rules.size());
    rules.push_back(rule);
}

const std::vector<Rule> &Grammar::getRules() const {
    return rules;
}

void Grammar::addRule(Rule &&rule) {
    if(rule.left.id>=ruleIdsBySymbolId.size())
        ruleIdsBySymbolId.resize(2*rule.left.id+1);
    ruleIdsBySymbolId[rule.left.id].push_back(rules.size());
    rules.push_back(std::move(rule));
}

void Grammar::setAxiom(const Symbol & _axiom) {
    this->axiom=_axiom;
}


void GrammarWithFirstFollow::buildFirst() {
    firstIds.resize(symbols.size());
    bool insertion;
    /*
     * Suppose every symbol is terminal, so that each symbol S has the singleton {S} as symbol set.
     * */
    for(int i=0;i<firstIds.size();i++)
        firstIds[i]={ static_cast<std::uint64_t>(i)};
    /*
     * For every non-terminal symbol, set the empty set as symbol its first set.
     * */
    for(auto &rule:getRules())
        firstIds[rule.left.id]={};

    do
    {
        insertion=false;
        for(auto & rule : getRules())
        {
            auto &leftSymbol=symbols[rule.left.id];
            auto &leftFirstIds=firstIds[leftSymbol.id];
            int i;
            for(i=0;i<rule.right.size();i++)
            {
                auto &rightSymbol = rule.right[i];
                auto &rightFirstIds = this->firstIds[rightSymbol.id];
                for(auto &firstId : rightFirstIds)
                    if(firstId != SpecialCharacter::Epsilon && leftFirstIds.insert(firstId).second)
                        insertion=true;
                if(!rightFirstIds.contains(SpecialCharacter::Epsilon))
                    break;
            }
            if(i==rule.right.size() && leftFirstIds.insert(SpecialCharacter::Epsilon).second)
                insertion=true;
        }
    } while(insertion);
}

void GrammarWithFirstFollow::buildFollow()
{
    followIds.resize(symbols.size());
    bool insertion;
    followIds[axiom.id].insert(SpecialCharacter::EndOfFile);
    do
    {
        insertion=false;
        for(auto & rule : getRules())
        {
            auto &leftSymbol=symbols[rule.left.id];
            auto &leftFirstIds=firstIds[leftSymbol.id];
            for(int i=0;i<rule.right.size();i++)
            {
                bool allRightsHaveEpsilon = true;
                auto &S1 = rule.right[i];
                for (int j = i + 1; j < rule.right.size(); j++)
                {
                    auto &S2 = rule.right[j];
                    for(auto &id:firstIds[S2.id]) if(id != SpecialCharacter::Epsilon)
                        {
                            auto [_,inserted]=followIds[S1.id].insert(id);
                            insertion=insertion||inserted;
                        }
                    if (!firstIds[S2.id].contains(SpecialCharacter::Epsilon))
                    {
                        allRightsHaveEpsilon = false;
                        break;
                    }
                }
                if(allRightsHaveEpsilon)
                {
                    for(auto &id:followIds[leftSymbol.id])
                    {
                        auto [_,inserted]=followIds[S1.id].insert(id);
                        insertion=insertion||inserted;
                    }
                }
            }
        }
    } while(insertion);
}



namespace parser
{
    SLRParserBuilder& SLRParserBuilder::build() &
    {
        Symbol augmentedSymbol=addSymbol("");
        Grammar::addRule(Rule(augmentedSymbol,{axiom}));
        setAxiom(augmentedSymbol);
        auto augmentedRuleId=rules.size()-1;
        ruleIdsBySymbolId.resize(symbols.size());
        buildFirst();
        buildFollow();
        isTerminal.resize(symbols.size(),true);

        for(const auto & rule : rules)
            isTerminal[rule.left.id]=false;
        LR0Item I0{rules.size()-1,0};
        lr0Items.push_back(std::move(closure({I0})));
        lr0ItemsIds.emplace(lr0Items.back(),lr0Items.size()-1);
        int k=0,n=1;
        do
        {
            std::unordered_map<std::uint64_t,std::unordered_set<LR0Item>> nextItemsSets;
            for(const auto & item : lr0Items[k])
            {
                if(item.dot<rules[item.ruleId].right.size())
                    nextItemsSets[rules[item.ruleId].right[item.dot].id].emplace(item.ruleId,item.dot+1);
            }
            for(auto &[symbolId,itemsSet]: nextItemsSets)
            {
                itemsSet = std::move(closure(itemsSet));
                auto it=lr0ItemsIds.find(itemsSet);
                if(it==lr0ItemsIds.end())
                {
                    lr0Items.push_back(std::move(itemsSet));
                    std::tie(it,std::ignore)=lr0ItemsIds.emplace(lr0Items.back(),lr0Items.size()-1);
                    n++;
                }
                gotoIds.emplace(std::make_pair(k,symbolId),Action(Action::Shift,it->second));
            }
        } while(++k<n);
        for(int i=0;i<n;i++) for(const auto &item: lr0Items[i]) if(rules[item.ruleId].right.size()==item.dot)
                    for(auto &F:followIds[rules[item.ruleId].left.id])
                    {
                        if (item.ruleId == augmentedRuleId)
                            gotoIds.emplace(std::make_pair(i,SpecialCharacter::EndOfString),Action(Action::Accept,0));
                        else    gotoIds.emplace(std::make_pair(i,F),Action(Action::Reduce,item.ruleId));
                    }
        return *this;
    }

    std::unordered_set<LR0Item> SLRParserBuilder::closure(const std::unordered_set<LR0Item> &items)
    {
        std::unordered_set<LR0Item> newItems;
        std::stack<std::uint64_t> stack;
        for(const auto& item:items)
        {
            newItems.insert(item);
            if(item.dot < rules[item.ruleId].right.size())
            {
                if(isTerminal[rules[item.ruleId].right[item.dot].id])
                    continue;
                stack.push(rules[item.ruleId].right[item.dot].id);
            }
            while(!stack.empty())
            {
                auto id=stack.top();
                stack.pop();
                for(const auto & ruleId : ruleIdsBySymbolId[id])
                {
                    auto [_,inserted]=newItems.insert(LR0Item{ruleId,0});
                    if(inserted && !rules[ruleId].right.empty() && !isTerminal[rules[ruleId].right.front().id])
                        stack.push(rules[ruleId].right.front().id);
                }
            }
        }
        return newItems;
    }

}


namespace parser {

    LR0Item::LR0Item(std::uint64_t ruleId, std::uint64_t dot) : ruleId(ruleId), dot(dot)
    {
        initHash();
    }

    std::uint64_t LR0Item::initHash() {
        std::uint64_t hash=ruleId;
        hash^=hasher(dot);
        return hash;
    }

    LRFamily::Action::Action(LRFamily::Action::Type type, std::uint64_t value) : type(type), value(value)
    {
    }


    LRParserBuilder &LRParserBuilder::build() &
    {
        Symbol augmentedSymbol=addSymbol("");
        Grammar::addRule(Rule(augmentedSymbol,{axiom}));
        setAxiom(augmentedSymbol);
        auto augmentedRuleId=rules.size()-1;
        ruleIdsBySymbolId.resize(symbols.size());
        buildFirst();
        buildFollow();
        isTerminal.resize(symbols.size(),true);

        for(const auto & rule : rules)
            isTerminal[rule.left.id]=false;
        LR1Item I0{rules.size()-1,0,{SpecialCharacter::EndOfString}};
        lr1Items.push_back(std::move(closure({I0})));
        lr1ItemsIds.emplace(lr1Items.back(), lr1Items.size() - 1);
        int k=0,n=1;
        do
        {
            std::unordered_map<std::uint64_t,std::unordered_set<LR1Item>> nextItemsSets;
            for(const auto & item : lr1Items[k])
            {
                if(item.dot<rules[item.ruleId].right.size())
                    nextItemsSets[rules[item.ruleId].right[item.dot].id].emplace(item.ruleId,item.dot+1,item.lookahead);
            }
            for(auto &[symbolId,itemsSet]: nextItemsSets)
            {
                itemsSet = std::move(closure(itemsSet));
                auto it=lr1ItemsIds.find(itemsSet);
                if(it == lr1ItemsIds.end())
                {
                    lr1Items.push_back(std::move(itemsSet));
                    std::tie(it,std::ignore)=lr1ItemsIds.emplace(lr1Items.back(), lr1Items.size() - 1);
                    n++;
                }
                gotoIds.emplace(std::make_pair(k,symbolId),Action(Action::Shift,it->second));
            }
        } while(++k<n);
        for(int i=0;i<n;i++) for(const auto &item: lr1Items[i]) if(rules[item.ruleId].right.size() == item.dot)
                {
                    if (item.ruleId == augmentedRuleId)
                        gotoIds.emplace(std::make_pair(i, SpecialCharacter::EndOfString), Action(Action::Accept, 0));
                    else gotoIds.emplace(std::make_pair(i, item.lookahead), Action(Action::Reduce, item.ruleId));
                }
        return *this;
    }

    std::unordered_set<LR1Item> LRParserBuilder::closure(const std::unordered_set<LR1Item> &items) {
        std::unordered_set<LR1Item> newItems;
        struct context
        {
            std::uint64_t symbolId;
            std::unordered_set<std::uint64_t> firstIds;
        };
        std::stack<context> stack;
        for(const auto& item:items)
        {
            newItems.insert(item);
            if(item.dot < rules[item.ruleId].right.size())
            {
                if(isTerminal[rules[item.ruleId].right[item.dot].id])
                    continue;
                context ctx;
                ctx.symbolId=rules[item.ruleId].right[item.dot].id;
                if(item.dot+1==rules[item.ruleId].right.size())
                    ctx.firstIds.insert(item.lookahead);
                else for(auto k=item.dot+1;k<rules[item.ruleId].right.size();k++)
                    {
                        ctx.firstIds.insert(firstIds[rules[item.ruleId].right[k].id].begin(),firstIds[rules[item.ruleId].right[k].id].end());
                        if(!firstIds[rules[item.ruleId].right[k].id].contains(SpecialCharacter::Epsilon))
                            break;
                    }
                ctx.firstIds.erase(SpecialCharacter::Epsilon);
                stack.push(ctx);
            }
            while(!stack.empty())
            {
                auto [id,lookaheads]=stack.top();
                stack.pop();
                bool anyInsertion=false;
                for(const auto & ruleId : ruleIdsBySymbolId[id])
                {
                    context ctx;
                    if(!rules[ruleId].right.empty())
                        ctx.symbolId = rules[ruleId].right.front().id;
                    for (auto lookahead: lookaheads)
                    {
                        auto [newItemIterator, inserted] = newItems.insert(LR1Item{ruleId, 0, lookahead});
                        anyInsertion = anyInsertion || inserted;
                        if (inserted && !rules[ruleId].right.empty() && !isTerminal[rules[ruleId].right.front().id])
                        {
                            int k;
                            for (k = 1; k < rules[ruleId].right.size(); k++)
                            {
                                ctx.firstIds.insert(firstIds[rules[ruleId].right[k].id].begin(),
                                                    firstIds[rules[ruleId].right[k].id].end());
                                if (!firstIds[rules[ruleId].right[k].id].contains(SpecialCharacter::Epsilon))
                                    break;
                            }
                            if(k==rules[ruleId].right.size())
                                ctx.firstIds.insert(lookahead);
                            ctx.firstIds.erase(SpecialCharacter::Epsilon);
                        }
                    }
                    if(anyInsertion)
                        stack.push(ctx);
                }
            }
        }
        return newItems;
    }

    bool ShiftReduceParser::parse(const std::string &S) {
        std::stack<std::pair<std::uint64_t,std::uint64_t>> stack;
        stack.emplace(0,-1);
        char character[2]{0,0};
        for(int i=0;i<S.size();)
        {
            auto &s=S[i];
            auto [state,ruleId]=stack.top();
            character[0]=s;
            auto symbolId=symbolMap.at(character);
            auto it=gotoIds.find(std::make_pair(state,symbolId));
            if(it==gotoIds.end())
                return false;
            auto [type,value]=it->second;
            switch(type)
            {
                case Action::Shift:
                    i++;
                    stack.emplace(value,symbolId);
                    break;
                case Action::Reduce:
                {
                    if (stack.size() < rules[value].right.size())
                        return false;
                    for (int j = 0; j < rules[value].right.size(); j++)
                        stack.pop();
                    auto newState = gotoIds.find(std::make_pair(stack.top().first, rules[value].left.id));
                    if (newState == gotoIds.end())
                        return false;
                    stack.emplace(newState->second.value,rules[value].left.id);
                    break;
                }
                case Action::Accept:
                    return true;

            }
        }
        while(!stack.empty())
        {
            auto [state,ruleId]=stack.top();
            auto it=gotoIds.find(std::make_pair(state,SpecialCharacter::EndOfString));
            if(it==gotoIds.end())
                return false;
            auto [type,value]=it->second;
            switch(type)
            {
                case Action::Reduce:
                {
                    if (stack.size() < rules[value].right.size())
                        return false;
                    for (int j = 0; j < rules[value].right.size(); j++)
                        stack.pop();
                    auto newState = gotoIds.find(std::make_pair(stack.top().first, rules[value].left.id));
                    if (newState == gotoIds.end())
                        return false;
                    stack.emplace(newState->second.value,rules[value].left.id);
                    break;
                }
                case Action::Accept:
                    return true;
            }
        }
        return false;
    }

    LR1Item::LR1Item(std::uint64_t ruleId, std::uint64_t dot, std::uint64_t lookahead) : ruleId(ruleId), dot(dot), lookahead(lookahead)
    {
    }

    LRFamily::LALR1ItemContext::LALR1ItemContext(std::uint64_t id, std::unordered_set<std::uint64_t> &&lookaheads):id(id),lookaheads(std::move(lookaheads))
    {
    }

    LRFamily::LALR1ItemContext::LALR1ItemContext(std::uint64_t id,
                                                 const std::unordered_set<std::uint64_t> &lookaheads) : id(id),
                                                                                                        lookaheads(lookaheads)
    {

    }
    LALR1Item::LALR1Item(std::uint64_t ruleId, std::uint64_t dot,const std::unordered_set<std::uint64_t> &lookahead) : ruleId(ruleId), dot(dot), lookahead(lookahead)
    {
    }

    LALR1Item::LALR1Item(std::uint64_t ruleId, std::uint64_t dot, std::unordered_set<std::uint64_t> &&lookahead) : ruleId(ruleId), dot(dot), lookahead(std::move(lookahead))
    {
    }

    bool LALR1Item::operator==(const LALR1Item &other) const {
        return ruleId == other.ruleId && dot == other.dot;
    }


    void ShiftReduceParser::printTable(std::ostream &H) const{
        std::vector<std::vector<Action>> table;
        auto mapSymbol=[count=symbolId.size()-1](auto x) -> decltype(x){
            if(x==SpecialCharacter::EndOfString)
                return count;
            return x;
        };
        for(auto [cell,action]:gotoIds)
        {
            if(table.size()<cell.first+1)
                table.resize(cell.first+1,std::vector<Action>(symbolMap.size(),Action{Action::Error,0}));
            table[cell.first][mapSymbol(cell.second)]=action;
        }
        std::vector<std::string> symbolNames(symbolMap.size());
        for(auto &[symbol,id]:symbolMap)
            symbolNames[id]=symbol;
        symbolNames.back()="$";
        H << std::setw(5) << "" <<"\t";
        for(const auto& name:symbolNames)
            H << std::setw(5) << name << "\t";
        H << std::endl;
        for(int state=0;state<table.size();state++)
        {
            H  << std::setw(5) << "S" << state << '\t';
            for (int symbol = 0; symbol < table[state].size(); symbol++)
            {
                switch (table[state][mapSymbol(symbol)].type)
                {
                    case Action::Shift:
                        H << std::setw(5) << "s" + std::to_string(table[state][mapSymbol(symbol)].value) << '\t';
                        break;
                    case Action::Reduce:
                        H << std::setw(5) << "r" << std::to_string(table[state][mapSymbol(symbol)].value) << '\t';
                        break;
                    case Action::Accept:
                        H << std::setw(5) << "acc" << '\t';
                        break;
                    case Action::Error:
                        H << std::setw(5) << "err" << '\t';
                }
            }
            H << std::endl;
        }
    }
} // parser

using integer=std::int64_t;

class TreeNode
{
public:
    inline static integer K=10;
    char val;
    TreeNode *left, *right;
    std::vector<integer> D;
    int C;
    TreeNode():D(K)
    {
        this->left = nullptr;
        this->right = nullptr;
    }
    // Constructor Method
    TreeNode(char val):D(K)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(char val,TreeNode*a,TreeNode*b):D(K)
    {
        this->val = val;
        this->left = a;
        this->right = b;
    }

    int sum()
    {
        if(left && right) {

            C = D[0] +  left->sum()+right->sum();
        }
        else
            C=D[0];
        return C;
    }

    int build()
    {
        if(left && right) {
            left->build();
            right->build();
            if (this->val=='+') for(int i=0;i<K;i++) for(int j=0;j<K;j++)
                        D[(i+j)%K]+=left->D[i]*right->D[j];
            else if (this->val=='*') for(int i=0;i<K;i++) for(int j=0;j<K;j++)
                        D[(i*j)%K]+=left->D[i]*right->D[j];
            else if (this->val=='-') for(int i=0;i<K;i++) for(int j=0;j<K;j++)
                        D[(K+i-j)%K]+=left->D[i]*right->D[j];
        }
        else
            D[val-'0']=1;
        return sum();
    }
};
// Stack to hold the latest node
class Stack
{
public:
    TreeNode *treeNode;
    Stack *next;
    // Constructor Method
    Stack(TreeNode *treeNode)
    {
        this->treeNode = treeNode;
        next = NULL;
    }

    int build()
    {
        return treeNode->build();
    }
};
class ExpressionTree
{
private:
    Stack *top;
public:
    // Constructor Method
    ExpressionTree()
    {
        top = NULL;
    }
    // function to push a node in stack
    void push(TreeNode *ptr)
    {
        if (top == NULL)
            top = new Stack(ptr);
        else
        {
            Stack *nptr = new Stack(ptr);
            nptr->next = top;
            top = nptr;
        }
    }
    TreeNode *pop()
    {
        TreeNode *ptr = top->treeNode;
        top = top->next;
        return ptr;
    }
    TreeNode *peek()
    {
        return top->treeNode;
    }
    // function to insert character
    void insert(char val)
    {
        // If the encountered character is Number make a node an push it on stack
        if (isOperand(val))
        {
            TreeNode *nptr = new TreeNode(val);
            push(nptr);
        }
            // else if it is operator then make a node and left and
        else if (isOperator(val))
        {
            TreeNode *nptr = new TreeNode(val);
            nptr->left = pop();
            nptr->right = pop();
            push(nptr);
        }
    }
    // function to check if operand
    bool isOperand(char ch)
    {
        return ch >= '0' && ch <= '9' || ch>='A' && ch<='Z' || ch>='a' && ch<='z';
    }
    // function to check if operator
    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    // function to construct expression Tree
    void construct(std::string eqn)
    {
        for (int i = eqn.length() - 1; i >= 0; i--)
            insert(eqn[i]);
    }
    void inOrder(TreeNode *ptr)
    {
        if (ptr != NULL)
        {
            inOrder(ptr->left);
            std::cout<<ptr->val;
            inOrder(ptr->right);
        }
    }

    int generate()
    {
        return top->build();
    }

    int counter()
    {
        return top->treeNode->D[0];
    }
};


std::pair<TreeNode*,int> build(std::string& X,int a,int b)
{
    std::stack<TreeNode*> S;
    std::stack<char> C;
    for(int i=a;i<b;i++)
    {
        if(std::isdigit(X[i]))
            S.push(new TreeNode(X[i]));
        if(!C.empty() && C.top()=='*' && S.size()>=2)
        {
            auto p=S.top();
            S.pop();
            auto q=S.top();
            auto c=C.top();
            C.pop();
            S.push(new TreeNode(c,p,q));
        }
        if(X[i]=='(')
        {
            auto [p,j]=build(X, i + 1, b);
            S.push(p);
            i=j;
        }
        else if(X[i]=='+' || X[i]=='-' || X[i]=='*')
            C.push(X[i]);
        else if(X[i]==')') {
            while(!C.empty())
            {
                auto p=S.top();
                S.pop();
                auto q=S.top();
                auto c=C.top();
                C.pop();
                S.push(new TreeNode(c,p,q));
            }
            return std::make_pair(S.top(), i);
        }

    }
    while(!C.empty())
    {
        auto p=S.top();
        S.pop();
        auto q=S.top();
        auto c=C.top();
        C.pop();
        S.push(new TreeNode(c,p,q));
    }
    return std::make_pair(S.top(),b);
}

TreeNode *build(std::string& X)
{
    auto Q=build(X,0,X.size());
    return Q.first;
}



std::string preprocess(const std::string &A,int K)
{
    std::string S;
    int i=0,j=0;
    std::string x;
    for(auto a:A) {
        if (std::isdigit(a)) {
            x.push_back(a);
            continue;
        }
        else if(!x.empty())
        {
            int r=0;
            for(auto s:x)
                r=(10*r+s-'0')%K;
            S.push_back(r+'0');
            x.clear();
        }
        S.push_back(a);
    }
    if(!x.empty())
    {
        int r=0;
        for(auto s:x)
            r=(10*r+s-'0')%K;
        S.push_back(r+'0');
    }
    return S;
}

int main()
{
    int n;
    auto &K=TreeNode::K;
    std::cin >> K >> n;
    std::string E;
    std::cin >> E;
    E=preprocess(E,K);
    auto T=build(E);
    std::cout << T->build();

}
