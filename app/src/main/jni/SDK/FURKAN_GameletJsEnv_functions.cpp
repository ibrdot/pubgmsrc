// WE SUPPORT FUN  (4.5.0) SDKGen by @ByAntiCheat 
// Send Message Me For SDKGen Tool  
// Generate on Wed Jul  8 15:41:28 2026
 
#include "../SDK.hpp"

namespace SDK
{
//---------------------------------------------------------------------------
//Functions
//---------------------------------------------------------------------------

// Function GameletJsEnv.GameletDynamicDelegateProxy.Fire
// (Final, Native, Public, BlueprintCallable)

void UGameletDynamicDelegateProxy::Fire()
{
	static UFunction *pFunc = 0;
	if (!pFunc)
		pFunc  = UObject::FindObject<UFunction>("Function GameletJsEnv.GameletDynamicDelegateProxy.Fire");

	UGameletDynamicDelegateProxy_Fire_Params params;

	auto flags = pFunc->FunctionFlags;
	pFunc->FunctionFlags |= 0x400;

	UObject *currentObj = (UObject *) this;
	currentObj->ProcessEvent(pFunc, &params);

	pFunc->FunctionFlags = flags;
}


}

