#include "Observable.h"

void Observable::AddObserver(IObserver* observer)
{
    m_observers.push_back(observer);
}

void Observable::RemoveObserver(IObserver* observer)
{
    auto funct = [observer](IObserver* el)
        {
            return el == observer;
        };

    m_observers.erase(std::remove_if(m_observers.begin(), m_observers.end(), funct));
}

void Observable::NotifyOnMoveAction()
{
    for (auto it : m_observers)
    {
        it->OnMove();
    }
}

void Observable::NotifyOnRollAction()
{
    for (auto it : m_observers)
    {
        it->OnRoll();
    }
}