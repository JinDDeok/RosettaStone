// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef HEARTHSTONEPP_CONSTANTS_H
#define HEARTHSTONEPP_CONSTANTS_H

#include <cstddef>

namespace Hearthstonepp
{
//! Hearthstone++ version.
constexpr float VERSION = 0.3f;

//! The number of player class.
//! \note Druid, Hunter, Mage, Paladin, Priest, Rogue, Shaman, Warlock, Warrior
constexpr std::size_t NUM_PLAYER_CLASS = 9;

//! The maximum number of cards that can be stored in the deck.
//! \note A deck is a collection of exactly 30 cards.
constexpr std::size_t MAXIMUM_NUM_CARDS_IN_DECK = 30;

//! The maximum number of minions that can be placed in the field.
//! \note Each player can normally have a maximum of 7 minions on the
//! battlefield at any time.
constexpr std::size_t FIELD_SIZE = 7;

//! The number of cards that the player going first will be given.
constexpr std::size_t NUM_DRAW_CARDS_AT_START_FIRST = 3;

//! The number of cards that the player going second will be given.
constexpr std::size_t NUM_DRAW_CARDS_AT_START_SECOND = 4;

//! The maximum number of cards in your hand.
constexpr std::size_t MAXIMUM_NUM_CARDS_IN_HAND = 10;

//! The number that represents player 1.
constexpr std::size_t PLAYER1 = 1;

//! The number that represents player 2.
constexpr std::size_t PLAYER2 = 2;

//! The number of menus in main phase.
//! \note We will refactor it soon.
constexpr std::size_t GAME_MAIN_MENU_SIZE = 3;
}  // namespace Hearthstonepp

#endif