#pragma once
#include <string>

class ItemBase
{
public:
    ItemBase(std::string n) : name(std::move(n)) {}
    virtual ~ItemBase() = default;

    virtual void ItemEffect() const
    {
    }

    std::string GetName() const
    {
        return name;
    }
private:
    std::string name;
};
