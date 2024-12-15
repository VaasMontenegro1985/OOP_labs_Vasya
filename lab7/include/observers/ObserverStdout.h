#pragma once
#include <iostream>
#include "../Observer.h"
#include "../npc.h"

class ObserverStdout : public IObserver<Murder>
{
public:
    void notify (Murder event) override;
};
