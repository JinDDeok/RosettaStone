// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

// It is based on peter1591's hearthstone-ai repository.
// References: https://github.com/peter1591/hearthstone-ai

#ifndef ROSETTASTONE_GAME_STATE_HPP
#define ROSETTASTONE_GAME_STATE_HPP

#include <Rosetta/Models/Player.hpp>

namespace RosettaStone
{
//!
//! \brief GameState class.
//!
//! This class stores data related the game.
//!
class GameState
{
 public:
    //! Returns the player controlling the current turn.
    //! \return The player controlling the current turn.
    const Player* GetCurrentPlayer() const;
};
}  // namespace RosettaStone

#endif  // ROSETTASTONE_GAME_STATE_HPP
