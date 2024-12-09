#pragma once

/**
 * @class IObserver
 * @brief Interface for observer classes that respond to game events.
 */
class IObserver {
public:
    /**
     * @brief Called when a move is made.
     */
    virtual void OnMove() = 0;

    /**
     * @brief Called when the dice is rolled.
     */
    virtual void OnRoll() = 0;

    /**
     * @brief Destroys the IObserver object.
     */
    virtual ~IObserver() = default;
};