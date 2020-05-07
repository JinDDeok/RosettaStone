// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <Rosetta/Actions/CastSpell.hpp>
#include <Rosetta/Actions/Choose.hpp>
#include <Rosetta/Cards/Cards.hpp>
#include <Rosetta/Games/Game.hpp>
#include <Rosetta/Models/Spell.hpp>
#include <Rosetta/Tasks/SimpleTasks/CastRandomSpellTask.hpp>
#include <Rosetta/Zones/GraveyardZone.hpp>
#include <Rosetta/Zones/SecretZone.hpp>

#include <effolkronium/random.hpp>

using Random = effolkronium::random_static;

namespace RosettaStone::SimpleTasks
{
TaskStatus CastRandomSpellTask::Impl(Player* player)
{
    player->SetGameTag(GameTag::CAST_RANDOM_SPELLS, 1);

    std::vector<Card*> result;

    const auto cards = m_source->game->GetFormatType() == FormatType::STANDARD
                           ? Cards::GetAllStandardCards()
                           : Cards::GetAllWildCards();

    for (const auto& card : cards)
    {
        if (card->GetCardType() == CardType::SPELL && !card->IsQuest())
        {
            // NOTE: Puzzle Box of Yogg-Saron can cast any collectible spell
            // except another Puzzle Box of Yogg-Saron.
            // References:
            // https://twitter.com/Celestalon/status/1158895101537607681
            if (m_source->card->dbfID == 53442 && card->dbfID == 53442)
            {
                continue;
            }

            result.emplace_back(card);
        }
    }

    const auto randIdx = Random::get<std::size_t>(0, result.size() - 1);
    auto spellToCast =
        dynamic_cast<Spell*>(Entity::GetFromCard(player, result[randIdx]));

    if (spellToCast->IsSecret() && player->GetSecretZone()->IsFull())
    {
        player->GetGraveyardZone()->Add(spellToCast);
        return TaskStatus::COMPLETE;
    }

    const auto randTarget = spellToCast->GetRandomValidTarget();
    const int randChooseOne = Random::get<int>(1, 2);

    const auto choiceTemp = player->choice;
    player->choice = nullptr;

    player->game->taskQueue.StartEvent();
    Generic::CastSpell(player, spellToCast, randTarget, randChooseOne);
    player->game->ProcessDestroyAndUpdateAura();
    player->game->taskQueue.EndEvent();

    while (player->choice != nullptr)
    {
        const auto idx =
            Random::get<std::size_t>(0, player->choice->choices.size() - 1);

        player->game->taskQueue.StartEvent();
        Generic::ChoicePick(player, player->choice->choices[idx]);
        player->game->ProcessTasks();
        player->game->taskQueue.EndEvent();
        player->game->ProcessDestroyAndUpdateAura();
    }

    player->choice = choiceTemp;

    player->SetGameTag(GameTag::CAST_RANDOM_SPELLS, 0);

    return TaskStatus::COMPLETE;
}

std::unique_ptr<ITask> CastRandomSpellTask::CloneImpl()
{
    return std::make_unique<CastRandomSpellTask>();
}
}  // namespace RosettaStone::SimpleTasks
