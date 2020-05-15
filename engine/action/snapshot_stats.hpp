// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#pragma once

#include "config.hpp"
#include "action/sc_action.hpp"
#include "sc_enums.hpp"
#include <string>

struct attack_t;
struct player_t;
struct spell_t;

/**
 * Snapshot players stats during pre-combat to get raid-buffed stats values.
 *
 * This allows us to report "raid-buffed" player stats by collecting the values through this action,
 * which is executed by the player action system.
 */
struct snapshot_stats_t : public action_t
{
  bool completed;
  spell_t* proxy_spell;
  attack_t* proxy_attack;
  role_e role;

  snapshot_stats_t(player_t* player, const std::string& options_str);

  void init_finished() override;
  void execute() override;
  void reset() override;
  bool ready() override;
};