#pragma once

// WE SUPPORT FUN  (4.5.0) SDKGen by @ByAntiCheat 
// Send Message Me For SDKGen Tool  
// Generate on Wed Jul  8 15:41:28 2026
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class iTOP.FBHelper
// 0x0000 (0x0028 - 0x0028)
class UFBHelper : public UObject
{
public:

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class iTOP.FBHelper");
		return pStaticClass;
	}


	static void DelayToSetAutoInitFacebookLog(bool IsAutoInit);
	static void DelayToInitFacebookSDK(bool IsAutoInit, bool WithLaunchOption);
};


}

