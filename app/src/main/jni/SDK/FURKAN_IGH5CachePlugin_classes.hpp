#pragma once

// WE SUPPORT FUN  (4.5.0) SDKGen by @ByAntiCheat 
// Send Message Me For SDKGen Tool  
// Generate on Wed Jul  8 15:41:28 2026
 
namespace SDK
{
//---------------------------------------------------------------------------
//Classes
//---------------------------------------------------------------------------

// Class IGH5CachePlugin.IGH5CachePluginSettings
// 0x0010 (0x0038 - 0x0028)
class UIGH5CachePluginSettings : public UObject
{
public:
	struct FString                                     Html5Url;                                                 // 0x0028(0x0010) (Edit, ZeroConstructor, Config)

	static UClass* StaticClass()
	{
        static UClass *pStaticClass = 0;
        if (!pStaticClass)
            pStaticClass = UObject::FindClass("Class IGH5CachePlugin.IGH5CachePluginSettings");
		return pStaticClass;
	}

};


}

