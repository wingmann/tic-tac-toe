#ifndef NO_AGENT_H
#define NO_AGENT_H

#include "ai_agent.h"
#include "globals.h"

#include <QtGlobal>

/// @brief AI mode disabled.
/// @details Empty class that does not play, it specifies the null object behaviour, so it
/// represents the lack of an AI agent, which is useful to avoid using if conditions in code when
/// checking on the existence of an AI agent. This class has no .cpp file as it does not have any
/// implementation details.
class NoAgent final : public AIAgent
{
public:
    NoAgent() = default;
    ~NoAgent() override = default;

    /// @brief Play does nothing to simulate a null agent behaviour.
    /// @param board Reference to the board.
    /// @return Invalid cell location to not trigger any kind of updates.
    int play(Board& board) override
    {
        return Defaults::invalidCell;
    }
};

#endif // NO_AGENT_H
