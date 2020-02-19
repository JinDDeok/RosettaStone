// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on peter1591's hearthstone-ai repository.
// References: https://github.com/peter1591/hearthstone-ai

#include <Rosetta/Games/GameState.hpp>

namespace RosettaStone
{
void GameState::SetCurrentPlayer(PlayerType playerType)
{
    m_currentPlayer = playerType;
}

PlayerType GameState::GetCurrentPlayer() const
{
    return m_currentPlayer;
}

int GameState::GetTurn() const
{
    return m_turn;
}

void GameState::SetTurn(int turn)
{
    m_turn = turn;
}

void GameState::IncreaseTurn()
{
    ++m_turn;
}
}  // namespace RosettaStone
