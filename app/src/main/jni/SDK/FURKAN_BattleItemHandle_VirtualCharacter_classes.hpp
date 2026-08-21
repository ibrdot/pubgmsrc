#pragma once

// WE SUPPORT FUN  (4.5.0) SDKGen by @ByAntiCheat 
// Send Message Me For SDKGen Tool  
// Generate on Wed Jul  8 15:41:32 2026
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// BlueprintGeneratedClass BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C
// 0x0000 (0x0138 - 0x0138)
class UBattleItemHandle_VirtualCharacter_C : public UBattleItemHandle_VirtualItem_C
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("BlueprintGeneratedClass BattleItemHandle_VirtualCharacter.BattleItemHandle_VirtualCharacter_C");
		return pStaticClass;
	}


	struct FBattleItemData ExtractItemData();
};


}

