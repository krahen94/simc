// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#pragma once

#include "config.hpp"
#include "util/generic.hpp"
#include <vector>

struct action_t;
struct player_t;

struct action_callback_t : private noncopyable
{
  player_t* listener;
  bool active;
  bool allow_self_procs;
  bool allow_procs;

  action_callback_t(player_t* l, bool ap = false, bool asp = false);
  virtual ~action_callback_t() {}
  virtual void trigger(action_t*, void* call_data) = 0;
  virtual void reset() {}
  virtual void initialize() { }
  virtual void activate() { active = true; }
  virtual void deactivate() { active = false; }

  static void trigger(const std::vector<action_callback_t*>& v, action_t* a, void* call_data = nullptr);

  static void reset(const std::vector<action_callback_t*>& v);
};