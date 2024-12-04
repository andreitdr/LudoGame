#pragma once
#include <string>

class IObserver {
public:
    virtual void OnMove() = 0;
    virtual void OnRoll() = 0;

    virtual ~IObserver() = default;
};