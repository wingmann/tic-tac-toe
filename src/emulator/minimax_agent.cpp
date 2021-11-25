#include "board.h"
#include "minimax_agent.h"

#include <QPair>

#include <limits>

MiniMaxAgent::MiniMaxAgent(std::uint16_t depth, Mark aiMark, Mark playerMark)
    : depth_{depth}, aiMark_{aiMark}, playerMark_{playerMark}
{
}

std::int16_t MiniMaxAgent::maxMove(Board& board, std::uint16_t depth, std::int16_t alpha, std::int16_t beta) const
{
    auto state = board.evaluateBoard();
    auto bestScore = std::numeric_limits<std::int16_t>::min();

    // If game over return score.
    if (depth == 0 || state != State::NoWinner)
        return score(state);

    // Choose the best score given all empty cell choices.
    for (std::size_t row = 0; row < board.size(); ++row)
    {
        for (std::size_t column = 0; column < board.size(); ++column)
        {
            if (board.at(row, column) == Mark::Empty)
            {
                // Try the move.
                board.setPlayerInput(row, column, aiMark_);

                // Compare result of this move with respect to AI.
                std::int16_t score = minMove(board, depth - 1, alpha, beta);

                // Reset the move done.
                board.resetCell(row, column);

                // Update the best score.
                bestScore = std::max(bestScore, score);

                // Update alpha.
                alpha = std::max(alpha, score);

                // Prune the rest of cells after this one.
                if (beta <= alpha)
                    break;
            }
        }
    }
    return bestScore;
}

std::int16_t MiniMaxAgent::minMove(Board& board, std::uint16_t depth, std::int16_t alpha, std::int16_t beta) const
{
    auto state = board.evaluateBoard();
    auto bestScore = std::numeric_limits<std::int16_t>::max();

    // If game over return score.
    if (depth == 0 || state != State::NoWinner)
        return score(state);

    for (std::size_t row = 0; row < board.size(); ++row)
    {
        for (std::size_t column = 0; column < board.size(); ++column)
        {
            if (Mark::Empty == board.at(row, column))
            {
                // Try the move.
                board.setPlayerInput(row, column, playerMark_);

                // Compare result of this move with respect to player.
                std::int16_t score = maxMove(board, depth - 1, alpha, beta);

                // Reset the move done.
                board.resetCell(row, column);

                // Update the best score.
                bestScore = std::min(bestScore, score);

                // Update beta.
                beta = std::min(beta, score);

                // Prune the rest of cells after this one.
                if (beta <= alpha)
                    break;
            }
        }
    }
    return bestScore;
}

std::int16_t MiniMaxAgent::score(const State state) const
{
    // AI win score.
    if ((aiMark_ == Mark::O && state == State::OWins) || (aiMark_ == Mark::X && state == State::XWins))
        return aiWinScore_;

    // Player win score.
    if ((aiMark_ == Mark::O && state == State::XWins) || (aiMark_ == Mark::X && state == State::OWins))
        return playerWinScore_;

    // Tie or a non-final state score.
    return tieScore_;
}

int MiniMaxAgent::play(Board& board)
{
    // No play if the board is at a final state.
    if (State::NoWinner != board.evaluateBoard())
        return Defaults::invalidCell;

    QPair<std::size_t, std::size_t> bestEntry;
    auto bestScore = std::numeric_limits<int>::min();

    // Start of the minimax algorithm and choose the best score of all available cells.
    for (std::size_t row = 0; row < board.size(); ++row)
    {
        for (std::size_t column = 0; column < board.size(); ++column)
        {
            if (board.at(row, column) == Mark::Empty)
            {
                // Try the move.
                board.setPlayerInput(row, column, aiMark_);

                // Update the best score and the best cell location.
                int moveScore = minMove(board,
                                        depth_ - 1,
                                        std::numeric_limits<std::int16_t>::min(),
                                        std::numeric_limits<std::int16_t>::max());

                if (moveScore > bestScore)
                {
                    bestScore = moveScore;
                    bestEntry.first = row;
                    bestEntry.second = column;
                }

                // Reset the move done.
                board.resetCell(row, column);
            }
        }
    }

    // Set the AI choice on the board.
    board.setPlayerInput(bestEntry.first, bestEntry.second, aiMark_);

    // Return the one-dimensional index of the cell to delegate any other updates needed.
    return static_cast<int>(bestEntry.first * board.size() + bestEntry.second);
}
