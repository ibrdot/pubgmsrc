
static bool callFunction;
bool colg;

float Dancevalue;
enum EAim
{
    Distance = 0,
    Croshhair = 1
};

enum EAimTarget
{
    Auto = 0,
    Head = 1,
    Chest = 2
};
int AutoChooseTarget = 1;
enum EAimTrigger {
    None = 0,
    Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};

struct SkinItem {
    int id;
    std::string name;
};

char searchBuffer[256] = "";

std::map<int, bool> Items;
std::map<int, float*> ItemColors;


bool MagicB;
struct sConfig
{

bool language;
    bool AutoTap;
    bool Alert;
    bool AimRecoil;
    int Marco1;
    int Marco2;
    bool IpadScope;
    bool Ipad;
    float IpadS;
    float IpadC;
    float Line;
    float Skeleton;
    bool Item;
    bool Fov;
    int SelectLanguage;
    struct sESPMenu
    {
        int Style;
        bool BlueZone;
        bool RedZone;
        bool Line = true;
        bool HideEsp;
        bool Box;
        bool Vehicleinfo;
        bool Skeleton;
        bool Health;
        bool Info;
        bool Grenade;
        bool Country;
        bool Name = true;
        bool Distance;
        bool TeamID;
        bool LineBelow;
        bool LineMid;
        bool NoBot;
        bool LootBoxItems;
        float LootboxD;
        bool LootBox;
        bool Vehicle;
        bool AutoFire;
        bool SungDich;
        bool Enemy;
        bool Instant;
        bool Recoil;
        bool LineNade;
        bool HUD;
    };
    sESPMenu ESPMenu;

    struct sMemory {
        bool BHopCSGO;
        bool JumpProne;
        bool FakeLag;
		bool LockedMagic;
		bool LockedBsilent;
        bool NeedMemory;
        bool FakeName = true;
        bool FPSUnlock = true;
        bool NoRecoil = false;
        bool IpadView = false;
        bool KillMsg;
        bool KillMsg2;
        float FovIpad;
        bool Recoil;
        bool Cross;
        bool GunSkin;
        bool Aimlock;
        bool ModSkin = false;
        bool SkinTest = false;
        bool _ModSkin = false;
        int set_skins = 0;
        float RCSize = 0.2f;
        bool Spin;
        int Spin360;
        bool BigW;
        float ScaleW;
        bool MagicSDK = false;
        int MagicValue;
        bool MagicBullet;
        int MagicType;
        bool BigPlayer;
        float ScaleP;
        float SpinWeapon;
        bool SpinW;
        bool Funny;
	   bool FastParachute;
	   bool FastParachutev2;
	   		bool SilentGodview;
		bool GodViewV3;
        bool Front;
		bool Flashv3;
		bool SdkFlash;
		bool Antiban;
        bool RainX = false;
        float Size = 2000.0f;
        bool Instant = false;
        bool Rainbow = false;
		bool MagicEnable;
        bool CarSpeed;
        bool WalkSpeed;
        bool XhitCostumColorRoyal;
        bool ShizuuFlash;
        bool ShizuuGpdView;
		bool Flashmenu;
        bool shizuu;
        bool RGBHIT;
		bool StuckFix;
		bool fixer;
		bool HighJump;
		bool AutoTap;
        bool xProfessor;
		bool AutoFire;
		bool WideView = false;
        bool AutoParachute;
		bool Crouchduck;
                bool Flash;
				bool FirstCount;
				bool SecCount;
				bool SpoofState;
        bool Flashv2;
		bool FlashOP;
		float SpeedC = 570.0f;;
        bool FixStuck;
        bool Helicopter = false;
float DanceValue = 0.0f; 
float DancerValue = 20.0f;
float DanceSpeed = 20.0f;
        bool WeaponSize;
        bool File;
        bool Crouch;
        bool SkyFly;
        bool AutoFlash;
        bool ManualFlash;
        bool ManualFlashOff;
        bool XHit;
        bool ShowDamage;
        bool GodView;
		 bool GodView2;
		bool Lobby;
		bool FixJump;
		bool Logo;
        bool FastShoot;
        bool Professor;
bool RainBowxhit;
bool ShizuuNew;
bool BigGun;
bool Fastshoot;
bool Teleport;
float BigWeaponSize = 1.0;
float SetZoomUp = 20.0f;
        float SetView;
        float XvalueMagic;
        float YvalueMagic;
        float ZvalueMagic;
		       float FLASH1 = 0.0f;
        float MagicBulletl = 250.0f;
		float MagicBullet2 = 250.0f;
        float Game = 22.2f;
        float SetSpeed = 0.085f;
        float Boost = 60.0f;
        float PornSpeed = 0.0f;
        float PornSpeedv3 = 0.0f;
        float Player = 0.0f;
        float GameSpeed = 22.2f;
        float PlayerSpeed = 22.300f;
        float XHitEffectSize = 10.0f;
        float ControlSpeed = 0.100f;
        float Gun_Size = 2.5;
		float PlayerSize = 1.0f;
     //  float SetView = 220.0f;
     float Professor1 = 999.99f;
        float Speed = 0.024f;
		float  BrutalMagicX = 200.0f;
     float   BrutalMagicY = 200.0f;
     float   BrutalMagicZ = 200.0f;
        float   IpadS = 4.0f;
     float   IpadC = 4.0f;
       // float ControlSpeed; // 0.024
        float Royal_color[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
        float PIROrainbowSpeedPIRO = 1.0f; 
        float MagicX = 120.0f;
        float MagicY = 180.0f;
        float MagicZ = 300.0f;
    };
    sMemory Memory{0};
struct sRagebot {
float Recoil;
float Speed;
float Distance;
float Cross;
bool Line;
int Bone;
EAimTrigger Trigger; 
EAimTarget Target;
int Aimtype; 
bool Enable;
bool IgnoreAi;
bool IgnoreKnock;
float Smooth;
bool Visible;
bool Switch;
bool DoanHuongBom;
bool Test;
int Test2;
bool GhostAimEnable;
bool GhostAimTarget;
bool GhostAimIgnoreAi;
bool GhostAimDistance;
bool GhostAimIgnoreKnock;
bool GhostAimVisible;
  bool SilentEnable;
        bool SilentIgnoreKnocked;
        bool SilentVisCheck;
		bool SilentIgnoreBot;
bool btEnable;
        bool btVisCheck;
        bool btIgnoreKnock;
        bool btIgnoreBot;
        float btRadius = 4000.0f;
        float btCross = 3000.0f;
        float btAimset;
        float btFov = 3000.0f;
        bool btRainbow;
        bool btPrediction = true;
        float btRange;
        bool btAutoFire = false;
		bool btAutoFireOff = false;
};
sRagebot Ragebot{0}; 

};

	
sConfig Config{ 0 };
