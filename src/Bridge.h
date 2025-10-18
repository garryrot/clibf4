#pragma once

#include "rust/cxx.h"
#include "clibf4/src/bridge.rs.h"
#include "PCH.h"

// Actor
const RE::Actor* PlayerCharacter_GetSingleton();
bool IsPlayer(const RE::Actor *actor);
Sex GetSex(const RE::Actor *actor);
const RE::TESRace* GetRace(const RE::Actor *actor);

// Form
const RE::TESForm* RaceAsForm(const RE::TESRace* form);
const RE::TESForm* ActorAsForm(const RE::Actor* form);
const RE::TESForm* TESForm_GetFormByEditorID(rust::Str editorId);
std::uint32_t GetFormID(const RE::TESForm* form);
std::uint32_t GetSavedFormType(const RE::TESForm* form);

// Actor
const RE::NiAVObject* GetBone(const RE::Actor *actor, rust::Str bone);
bool ContainsKeyword(const RE::Actor *actor, rust::Str editorId);
float GetPlayerActorValue(rust::Str actorValueEditorId);

const RE::TESForm* GetFormByID(int formId);
rust::String Form_GetEditorID(const RE::TESForm* form);
