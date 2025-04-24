#pragma once
#include "ItemBase.h"

class FocusSash : public ItemBase
{
public:
    FocusSash() : ItemBase("Focus Sash")
    {
    }

    ~FocusSash() override;

    void ItemEffect() const override
    {
        
        ItemBase::ItemEffect();
    }
};
