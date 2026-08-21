#pragma once

// WE SUPPORT FUN  (4.5.0) SDKGen by @ByAntiCheat 
// Send Message Me For SDKGen Tool  
// Generate on Wed Jul  8 15:41:26 2026
 
namespace SDK
{
//---------------------------------------------------------------------------
//Enums
//---------------------------------------------------------------------------

// Enum Development.EImGuiWindowDisplayMode
enum class EImGuiWindowDisplayMode : uint8_t
{
	EImGuiWindowDisplayMode__Embedded = 0,
	EImGuiWindowDisplayMode__Standalone = 1,
	EImGuiWindowDisplayMode__EImGuiWindowDisplayMode_MAX = 2
};



//---------------------------------------------------------------------------
//Script Structs
//---------------------------------------------------------------------------

// ScriptStruct Development.PropertyItemData
// 0x0028
struct FPropertyItemData
{
	struct FString                                     PropertyName;                                             // 0x0000(0x0010) (ZeroConstructor)
	class UEditableTextBox*                            EditableTextBox;                                          // 0x0010(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UWidget*                                     ContainerWidget;                                          // 0x0018(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	class UButton*                                     NameButton;                                               // 0x0020(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
};

}

