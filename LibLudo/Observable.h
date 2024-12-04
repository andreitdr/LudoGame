#pragma once

#include "IObserver.h"

#include <vector>


class Observable
{
public:
    void AddObserver(IObserver* observer);
    void RemoveObserver(IObserver* observer);

    void NotifyOnMoveAction();
    void NotifyOnRollAction();

private:
    std::vector<IObserver*> m_observers;
};