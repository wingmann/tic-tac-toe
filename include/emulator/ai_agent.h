#ifndef AI_AGENT_H
#define AI_AGENT_H

class Board;

/// @brief Interface describes the behaviour of any implemented AI agents.
class AIAgent
{
public:
    AIAgent() = default;
    virtual ~AIAgent() = default;

    /// @brief Play the algorithm to choose a cell to play based on a given board.
    /// @param board Reference to the board.
    /// @return Chosen cell index (in a one-dimensional array) that the emulator played.
    virtual int play(Board& board) = 0;

    /// @brief Reset the state of any search algorithm.
    virtual void reset()
    {
    }
};

#endif // AI_AGENT_H
