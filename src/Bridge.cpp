#pragma once

#include "rust/cxx.h"
#include "Bridge.h"

// Actor
const RE::Actor* PlayerCharacter_GetSingleton() {
    return RE::PlayerCharacter::GetSingleton();
}

bool IsPlayer(const RE::Actor *actor) {
    return actor == RE::PlayerCharacter::GetSingleton();
}

Sex GetSex(const RE::Actor *actor) {
    auto npc = actor->GetNPC();
    if (npc == NULL)
    {
        return Sex::None;
    }

    auto sex = static_cast<std::uint32_t>( npc->GetSex() );
    if (sex == 1) {
        return Sex::Female;
    } else {
        return Sex::Male;
    }
}

const RE::TESRace* GetRace(const RE::Actor *actor) {
    if (actor == NULL || actor->race == NULL)
    {
        return NULL;
    }
    return actor->race;
}

bool ContainsKeyword(const RE::Actor *actor, rust::Str editorId) {
    auto isVibratingKeyword = RE::TESForm::GetFormByEditorID( (std::string) editorId);
    if (isVibratingKeyword && isVibratingKeyword->GetSavedFormType() == RE::ENUM_FORM_ID::kKYWD)
    {
        return actor->HasKeyword( (const RE::BGSKeyword *) isVibratingKeyword, nullptr);
    }
    return false;
}

float GetPlayerActorValue(rust::Str editorId) {
    std::string actorValueEditorId = (std::string) editorId;
    auto form = RE::TESForm::GetFormByEditorID(actorValueEditorId);
    if (form)
    {
        auto player = RE::PlayerCharacter::GetSingleton();
        RE::ENUM_FORM_ID formType = form->GetSavedFormType();
        if (formType == RE::ENUM_FORM_ID::kAVIF)
        {
            auto a_info = (RE::ActorValueInfo*) form;
            float actorValue = player->GetActorValue( (*a_info) );
            return actorValue;
        }
    }
    return 0;
}

const RE::TESForm* GetFormByID(int a_formID) {
    return RE::TESForm::GetFormByID( a_formID );
}

rust::String Form_GetEditorID(const RE::TESForm* form) {
    auto result = form->GetFormEditorID();
    if (result == NULL)
    {
        return "";
    }
    return result;
}

// Form
const RE::TESForm* RaceAsForm(const RE::TESRace* form) {
    return form;
}

const RE::TESForm* ActorAsForm(const RE::Actor* form) {
    return form;
}

const RE::TESForm* TESForm_GetFormByEditorID(rust::Str editorId) {
    std::string editorIdStr = (std::string) editorId;
    return RE::TESForm::GetFormByEditorID( editorIdStr );
}

std::uint32_t GetFormID(const RE::TESForm* form) {
    if (form == NULL)
    {
        return 0;
    }
    return form->GetFormID();
}
std::uint32_t GetSavedFormType(const RE::TESForm* form) {
    if (form == NULL)
    {
        return 0;
    }
    return static_cast<std::uint32_t>(form->GetSavedFormType());
}

// NiAVObject
const RE::NiAVObject* GetBone(const RE::Actor *actor, rust::Str bone) 
{
    if (actor == NULL || actor->Get3D() == NULL)
    {
        return NULL;
    }
    return actor->Get3D()->GetObjectByName( (std::string) bone );   
}
