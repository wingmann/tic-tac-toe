#ifndef MINIMAX_AGENT_H
#define MINIMAX_AGENT_H

#include "ai_agent.h"
#include "globals.h"

#include <cstdint>

/// @brief Handles all the logic of picking a cell based on the MiniMax algorithm.
/// @details It simulates all possible plays taking turns simulating an emulator turn then a player
/// turn until a final state is reached, then it scores the final state by giving a negative value
/// if the player wins and a positive value if it wins, then backtracks picking the minimum score if
/// it is the player turn and the max score if its the emulator turn.
class MiniMaxAgent final : public AIAgent
{
private:
    /// @brief Cutoff of the minimax algorithm's search tree.
    const std::uint16_t depth_{};

    /// @brief Mark (X or O) of the emulator.
    const Mark aiMark_;

    /// @brief Mark (X or O) of the human player.
    const Mark playerMark_;

    /// @brief Defines the score of the final board when the AI wins.
    static constexpr std::int16_t aiWinScore_{1};

    /// @brief Defines the score of the final board when the human player wins.
    static constexpr std::int16_t playerWinScore_{-1};

    /// @brief Defines the score of the final board when the the game is a tie.
    static constexpr std::int16_t tieScore_{};

public:
    /// @brief Constructor that creates the MiniMax agent.
    /// @param depth Cutoff of the minimax algorithm's search tree.
    /// @param aiMark The mark (X or O) of the AI.
    /// @param playerMark The mark (X or O) of the human player.
    MiniMaxAgent(std::uint16_t depth, Mark aiMark, Mark playerMark);

    /// @brief Start the minimax algorithm to choose a cell to play based on a given board.
    /// @param board Reference to the board.
    /// @return Chosen cell index (in a one-dimensional array) that the AI played.
    int play(Board& board) override;

private:
    /// @brief Simulates player choice.
    /// @details Simulates the player choice based on the final game states, as it wants to win
    /// it will choose the maximum score of each simulated move.
    /// @param board Reference to the board.
    /// @param depth The current depth of the search tree.
    /// @param alpha Minimum score that the maximizing player is assured of.
    /// @param beta Maximum score that the minimizing player is assured of.
    /// @return TODO
    std::int16_t maxMove(Board& board, std::uint16_t depth, std::int16_t alpha, std::int16_t beta) const;

    /// @brief Simulates player choice.
    /// @details Simulates the player choice based on the final game states, as it wants to win it
    /// will choose the minimum score of each simulated move.
    /// @param board Reference to the board board.
    /// @param depth Current depth of the search tree.
    /// @param alpha Minimum score that the maximizing player is assured of.
    /// @param beta Maximum score that the minimizing player is assured of.
    /// @return TODO
    std::int16_t minMove(Board& board, std::uint16_t depth, std::int16_t alpha, std::int16_t beta) const;

    /// @details Associates a score to the final states of the game.
    /// @param state Input parameter that specifies the state of the game.
    /// @return Score-based on the state of the game.
    [[nodiscard]] std::int16_t score(State state) const;
};

#endif // MINIMAX_AGENT_H
