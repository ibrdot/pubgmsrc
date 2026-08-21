namespace Data {
    SDK::ASTExtraPlayerCharacter *localPlayer = nullptr;
    SDK::ASTExtraPlayerController *localController = nullptr;

    namespace Cheat {
        float Velocityop = 0.f;
        float Altitute = 0.f;
        float travlled = 0;
        uintptr_t UE4;
        uintptr_t Anogs;
        android_app* App = 0;
    }
}

#define GNames_Offset 0x8939470
#define GUObject_Offset 0xef3b3f0
#define ShootBulletInner_Offset 0x6DFE100
#define GetMuzzleTransform_Offset 0x6E17390
#define ProcessEvent_Offset 0x8bac0a8
#define GetActorArray 0xa6ca440
#define GNativeAndroidApp_Offset 0xEC732A8
#define Actors_Offset 0xA0
#define PATCH_LIB
