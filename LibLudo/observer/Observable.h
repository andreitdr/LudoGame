#pragma once

#include "IObserver.h"
#include <vector>

/**
 * @class Observable
 * @brief Represents an observable subject in the observer pattern.
 */
class Observable
{
public:
    /**
     * @brief Adds an observer to the list.
     * @param observer The observer to add.
     */
    void AddObserver(IObserver* observer);

    /**
     * @brief Removes an observer from the list.
     * @param observer The observer to remove.
     */
    void RemoveObserver(IObserver* observer);

    /**
     * @brief Notifies all observers of a move action.
     */
    void NotifyOnMoveAction();

    /**
     * @brief Notifies all observers of a roll action.
     */
    void NotifyOnRollAction();

private:
    std::vector<IObserver*> m_observers; ///< List of observers.
};