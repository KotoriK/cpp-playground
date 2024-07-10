#include <string>
#include <algorithm>
#include <vector>

enum OperateType : unsigned char
{
    Null = 0xff,
    Plus = 0b0,
    Minus = 0b1,
    Multiply = 0b10,
    Divide = 0b11,
};
struct Op
{
    int oprand;
    OperateType type;
};
typedef std::vector<Op> Ops;
class Solution
{

private:
    Ops parseToOpsStream(std::string s)
    {
        OperateType type = OperateType::Null;
        std::string s_oprand;
        Ops ops;
        for (char c : s)
        {
            switch (c)
            {
            case ' ':
                continue;
            case '*':
                type = OperateType::Multiply;
                break;
            case '+':
                type = OperateType::Plus;
                break;
            case '-':
                type = OperateType::Minus;
                break;
            case '/':
                type = OperateType::Divide;
                break;
            default:
                s_oprand.push_back(c);
                continue;
            }

            int oprand = s_oprand.size() == 0 ? 0 : std::stoi(s_oprand);

            ops.push_back(Op{
                .oprand = oprand,
                .type = type});
            type = OperateType::Null;
            s_oprand.clear();
        }
        if (s_oprand.size())
        {
            ops.push_back(Op{
                .oprand = std::stoi(s_oprand),
                .type = OperateType::Plus,
            });
        }

        return ops;
    }
    int execute(Ops::iterator begin, Ops::iterator end)
    {
        auto it = begin;
        int result = it->oprand;
        OperateType currOp = it->type;
        while (++it < end)
        {
            auto op = (*it);
            auto oprand = op.oprand;
            if (currOp < OperateType::Multiply && op.type >= OperateType::Multiply && op.type > currOp)
            {
                // 更高优先级的计算序列，传出计算
                auto sub_begin = it;
                auto sub_end = end;
                while (++it < end)
                {
                    if (it->type < OperateType::Multiply)
                    {
                        sub_end = it + 1;
                        break;
                    }
                }
                oprand = execute(sub_begin, sub_end);
            }
            switch (currOp)
            {
            case OperateType::Plus:
                result += oprand;
                break;
            case OperateType::Minus:
                result -= oprand;
                break;
            case OperateType::Multiply:
                result *= oprand;
                break;
            case OperateType::Divide:
                result /= oprand;
                break;
            default:
                throw "invalid op";
            }
            currOp = it->type;
        }
        return result;
    }

public:
    int calculate(std::string s)
    {
        Ops ops = parseToOpsStream(s);
        return execute(ops.begin(), ops.end());
    }
};