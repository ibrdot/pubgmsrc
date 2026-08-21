bool XEffecktv2;
float woltaj;
bool Bypass31 = true;
bool TextBorder = true;
int UpdateTick = 100;
bool NameCache = true;
bool WorlexLogo = true;
float Aimposss = 15.000;
bool loadConfig;
bool saveConfig;
bool AutoMagicBullet;
bool ShowLogo;
bool MeanHack;
void UpdateTitle();
void DrawMenu();
bool loadconfig = false;
static bool initialized = false;
bool unload = false;
static float nsize = 15.000f;
static float Ipad_manager = 360.000f;
static float SpeedFire = 360.000f;
static float Ipad_managerv2 = 360.000f;
static float scope_fov = 32.5f;
int weaponsize = 15.000f;
int botnsize = 15.000f;
static int skelee = 0;
static int linne = 0;
static int Test = 0;
static int Test2 = 0;
static int jump = 0;
static int Recmod = 0;
static int nograssmod = 0;
static int hpbt = 0;
static int boxe = 0;
static int aimbp = 0;
static int Speedv3Comp = 0;
int dissize = 15.000f;
int botdissize = 15.000f;
int hp = 17.000f;
float fragwarningsize = 2.0f;
float smokewarningsize = 2.0f;
float tunwarningsize = 2.0f;
float molotovwarningsize = 2.0f;
float flaresize = 15;
float deathboxsize = 15;
float airdropsize = 15;
float flaregunsize = 15;
int vehisize = 17;




//bool nothingm = true;
bool nothinga = false;
float Hight = 290.0f;

namespace weapon {

	extern ImVec4 holdColor;
	extern ImVec4 m16;
	extern ImVec4 AKM;
	extern ImVec4 AWM;
	extern ImVec4 magnum;
	extern ImVec4 scarl;
	extern ImVec4 m762;
	extern ImVec4 M24;
	extern ImVec4  GROZZA;
	extern ImVec4 scope8x;
	extern ImVec4 kar98;
	extern ImVec4  Airdrop;
	extern ImVec4 Flare;
	extern ImVec4 Flaregun;
}

namespace Color {

	extern ImVec4  dp;
	extern ImVec4  mg3;
	extern ImVec4  scope4x;
	extern ImVec4  scope3x;
	extern	ImVec4  bag;
	extern	ImVec4  armer;
	extern	ImVec4  helmat;
	extern	ImVec4  mosin;
	extern ImVec4  aug;
	extern ImVec4  g36;
	extern ImVec4  assm;

	extern	ImVec4  Grandes;
	extern	ImVec4  ammo7;
	extern	ImVec4  ammo5;
	extern ImVec4  madkit;

	/////////////////////////
	extern ImVec4 itemColor;
	// ARGB playr
	extern	ImVec4  playerline;
	extern	ImVec4  newline;
	extern	ImVec4  playerlineopenn;
	extern	ImVec4  playerlineopen;
	extern	ImVec4  playerlineSilent;
	extern	ImVec4  Enemy_Aiming_at_you;
	extern	ImVec4  playercorner;
	extern	ImVec4  playerbox;
	extern	ImVec4  lotbox;
	// ARGB
	extern ImVec4  helthbar;
	extern ImVec4  boxColor;
	extern ImVec4  cornerColor;
	extern ImVec4  crosshairColor;
	extern	ImVec4  bot;
	extern	ImVec4  botbone;
	extern	ImVec4  skelec;
	extern	ImVec4  smokewarning;
	extern	ImVec4  fragwarning;
	extern	ImVec4  molotovwarning;
	extern	ImVec4  tunwarning;
	extern	ImVec4  TESTTTTT;
	extern	ImVec4  text_color;
	extern	ImVec4  playerbone;
	extern	ImVec4  player;
	extern ImVec4  vehicle;
	//RGB
	extern ImVec4  botcorner;
	extern ImVec4  botline;
	extern ImVec4  botlineopen;
	extern ImVec4  botlinecover;
	extern	ImVec4 circle;
	extern	ImVec4  enemy;
	extern	ImVec4  HPP;
	extern	ImVec4  benemy;
	extern	ImVec4  botbox;
	extern	ImVec4  bone;
	extern	 ImVec4  fillrect;
	extern	 ImVec4  nam;
	extern	 ImVec4  nam222;
	extern	 ImVec4  nam_border;
	extern	 ImVec4  border;
	extern	 ImVec4  plr_wpn;
	extern	 ImVec4  nambar;
	extern	 ImVec4  bothealth;
	extern	ImVec4  botname;
	extern	ImVec4  botdown;
	extern	ImVec4  playerhealth;
	extern	ImVec4  textcolor;

	extern	ImVec4 Granades;
	extern	ImVec4 health;
	extern	ImVec4 deadbox;
	extern	ImVec4 deadboxitem;
	extern	ImVec4 airdrop;
	extern	ImVec4 airdropitem;
	extern	ImVec4 scopetextcolor;
	extern	ImVec4  allitem;
	extern	ImVec4  scope6x;
	extern	ImVec4  magicline;
	extern	ImVec4  magicline3;
	extern	ImVec4  bgcorner;
	extern	ImVec4  fovcirclecolor;
	extern	ImVec4 M249;
	extern	ImVec4 MK12;
	extern	ImVec4 hpt;
}

namespace Setting
{
    inline bool CrazyCar;
    inline bool CarSpin;
    inline float CarSpinValue;
    inline int CarC;
    inline int hpbt;
    inline int linne;
    inline bool Login = true;//false
	extern int BotCount;
	extern int macro3;
	extern int macro2;
	extern int PlayerCount;
	extern int TotalEnemyCount;
    inline ImVec4 LoginStatus_Color;
	extern float instantPower;
	extern float menu;
	extern float PlayerAiming;
	extern float fastRunPower;
	extern float ZoomValue;
	extern float view;
	extern float Ipad_manager;
	extern float ipadview;
	extern float BaseIpadView;
    extern float BaseIpadView1 = 1.0f;
	extern float SXZ;
	extern float FPS;
	extern int XFov;
	extern float speedCarPower;
	extern float flyCarPower;
	extern float Speed_Fire;

	extern bool knocked;
	extern bool RapidFireG;
	extern bool Skipbot;
	extern bool marco1;
	extern bool AUTO_FIRE;
	extern bool antiscreencapture;
	extern bool PlayerBytnak;
	extern bool CamView;
	extern bool carteleport;
	extern bool vislibfound;
	extern bool ShowPId;

	extern int EnableKey;
	extern int AimbotKey;
	std::vector<int> AimbotKeyV = { 0,0 };
	std::vector<int> aimknockV = { 0,0 };
	std::vector<int> fastrun2keyV = { 0,0 };
	std::vector<int> fastrun3keyV = { 0,0 };
	std::vector<int> fastrun5keyV = { 0,0 };
	std::vector<int> fastrun4keyV = { 0,0 };
	std::vector<int> dfghfgj = { 0,0 };
	std::vector<int> cvbcvnvb = { 0,0 };
	std::vector<int> cvbcvnvfgbnjfb = { 0,0 };
	std::vector<int> cfghgbnjfb = { 0,0 };
	std::vector<int> cfghgbnjfbb = { 0,0 };
	std::vector<int> cfghgbnjfbbb = { 0,0 };
	std::vector<int> cfghgbnjfbbbb = { 0,0 };
	std::vector<int> GodUpV = {0,0};
	std::vector<int> GodDownV = {0,0};
	std::vector<int> GodFRONTV = {0,0};
	std::vector<int> GodleftV = {0,0};
	std::vector<int> GodrightV = {0,0};
	extern int GodUp;
	extern int GodDown;
	extern int GodFRONT;
	extern int Godleft;
	extern int Godright;
	extern float speedfirrre;
	extern float Xspeedd;
	extern int Rec;
	extern int Magic_Range;




	extern float testfuckencolor[4];
	extern float testfuckencolor2[4];
	extern float Bar;

    inline bool EspPreview;
	extern int FknBorderMsgCol;
	extern int aimknock;
	extern bool ScopeZoomm;
	extern int fastrunkey;
	extern int fastrun2key;
	extern int fastrun3key;
	extern int fastrun4key;
	extern int fastrun5key;
	extern int GrassKeyy;
	extern int jmpkeyy;
	extern int instantkey;
	extern int topgodview;
	extern int uppergodview;
	extern int frontgodview;
	extern int leftgodview;
	extern int rightgodview;
	extern int selectkey;
	extern int teleportkey;
	extern int speedupkey;
	extern int reducespeedkey;
	extern int fastparakey;
	extern int Recoilkey;
	extern int PositionKey;
	extern int dots_type;
	extern	bool dots;
	extern	bool visibleesp;
	extern	bool RedZoneee;
	extern	bool bg;
	extern int  redioption;
	extern bool  redioption2;
	extern	bool IsMagicInitialize;
	extern int Aimspeed;
	extern float fovcircleredus;
	extern float predectionline;
	extern float sizecode;
	extern float possition;
	extern bool aimbotposition;
	extern bool Draw_fovcircle;
	extern bool Draw_peredectionline;
	extern bool fovcircle;
	extern ImVec4 colorcode;
	extern bool Magntic;
	extern int	curraim;
	extern int	Rec;
	extern int	engine;
	inline int	skele;
	inline int hp = 15.f;
	extern bool	No_Recoil;
	extern bool MAgicline;
	extern bool NearWeapon;
	extern bool locktarget;
	extern bool autofire;
	extern char filename[];
	extern float Normalfontsize;
	extern float fontsize;
	extern float plinesize;
	extern float pfullboxsize;
	extern float RadiusSize;
	extern float pcornersize;
	extern float pbonesize;

	extern float blinesize;
	extern float bfullboxsize;
	extern float bcornersize;
	extern float bbonesize;
	extern bool silent;
	extern bool bortext;



	extern bool style1;
	extern bool style2;
	extern bool ShowMenu;
	extern bool ExitLogin;
	extern bool ExitMain;
	extern bool profree;
	extern	bool botname, bothealth, botline, botfullbox, botblood, botcorner, botdistance;
	//playr
	extern	bool pline, phealth, pfullbox, pname, pblood, pcorner, deadbox, plr_wpn, plr_scp, Aiming /*, Warn_Aiming*/;
	extern bool fightmode;
	extern bool hotkeys;
	//extern bool nothingm;
	extern bool login;
	extern bool FkMenuDraw;
	extern bool aimpere;
	extern bool visibleeee;
	extern bool autoaimmm;
	extern bool autofireee;
	extern bool aimbottttt;
	extern bool autoreloaddd;
	extern bool onlybottt;
	extern bool Test_New_Cpu;
	extern bool nothinga;
	extern bool pweapon;
	extern bool botweapon;
	extern bool Distance;
	extern bool Distancee;
	extern bool TotalEnemy;
	extern bool Enenmyaim;
	extern bool AimingWarning;
	extern bool Line;
	extern bool Box;
	extern bool botBone;
	extern bool pcountry;
	extern bool enemyIdd;
	extern bool playerBone;
	extern bool knockedenemy;
	extern bool  Bone;
	extern bool Health;
	extern bool BombAlert;
	extern bool newdriving;
	extern bool Item;
	extern bool Itemsequences;
	extern bool Vehicle;
	extern bool feul;
	extern bool Warn_Aiming;
	inline int vehisize;
	inline int dissize = 14.f;
	inline int weaponsize = 14.f;
	inline float nsize = 14.f;

	extern bool impitems;
	extern bool Warning;
	extern bool healthitem;
	extern bool scope;
	extern bool allitemss;
	extern bool TestItemLine;
	extern bool BGMI;
	extern bool instanthit;
	extern bool fastrun;
	extern bool fastrun2;
	extern bool fastrun3;
	extern bool fastrun4;
	extern bool fastrun5;
	extern bool fly;
	extern bool godview;
	extern bool disaplememory;
	extern bool teleport;
	extern bool nograss;
	extern bool carfly;
	extern bool visible_check;
	extern bool fastpara;
	extern bool speedcar;
	extern bool recoil;
    inline int Test;
    inline int Test2;
	extern bool airdrop;
	extern bool airdropitem;
	extern bool playerdeadbox;
	extern bool itemrect;
	extern bool Bags;
	extern bool Helmat;
	extern bool Armer;
	extern bool SlowAni;
	extern bool FixfLASH;
	extern bool DangerMod;

	//extern	bool Esp_Item_M249 ;

	//extern	bool Esp_Item_Mk12;

	extern bool MagicX;
	extern bool GameInFo;
	extern bool slowmode;
	extern bool killmsg;
	extern bool macrospeed;
	extern bool paraassists;
	extern bool birdmodee;
	extern bool Knockkmode;
	extern bool nearstAR;
	extern bool autotcp;
	extern bool autoudp;
	extern bool balltcp;
	extern bool balludp;
	extern bool blobby;
	extern bool DangerM;
	extern bool Instant;
	extern bool norecoil;
	extern bool norecoilv1;
	extern bool norecoilv2;
	extern bool MagicBct;
	extern bool FastLoot;
	extern bool HookMg;
	extern bool FastSwitch;
	extern bool FastShoot;
	extern bool NoSpread;
	extern int totaldistance;
	extern float MoveSpeed;
	extern int gametime;
	extern int colortime;
	extern bool Antiscreen;
	extern bool plan;
	extern ImVec4 plancolor;
	extern ImVec4 dotss;
	extern bool vahicle_item;
    extern bool Esp_Item_Event;
    extern float Esp_Item_Event_Color[4];
	extern float Esp_Item_Event_TextSize;
	extern bool Esp_Item_AKM;
	extern float Esp_Item_AKM_Color[4];
	extern float Esp_Item_AKM_TextSize;

	extern bool Esp_Item_Mk12;
	extern float Esp_Item_Mk12_Color[4];
	extern float Esp_Item_Mk12_TextSize;

	extern bool Esp_Item_M762;
	extern float Esp_Item_M762_Color[4];
	extern float Esp_Item_M762_TextSize;

	extern bool Esp_Item_M249;
	extern float Esp_Item_M249_Color[4];
	extern float Esp_Item_M249_TextSize;



	extern bool check9, dest9;
	extern bool macro_checker;
	extern bool check6;
	extern int int_value_macro_speed;

	extern bool Esp_Item_Mk47Mutant;
	extern float Esp_Item_Mk47Mutant_Color[4];
	extern float Esp_Item_Mk47Mutant_TextSize;

	extern bool Esp_Item_DP28;
	extern float Esp_Item_DP28_Color[4];
	extern float Esp_Item_DP28_TextSize;

	extern bool Esp_Item_SCARL;
	extern float Esp_Item_SCARL_Color[4];
	extern float Esp_Item_SCARL_TextSize;



	extern bool Esp_Item_Mosin;
	extern float Esp_Item_Mosin_Color[4];
	extern float Esp_Item_Mosin_TextSize;

	extern bool Esp_Item_Win94;
	extern float Esp_Item_Win94_Color[4];
	extern float Esp_Item_Win94_TextSize;

	extern bool Esp_Item_Groza;
	extern float Esp_Item_Groza_Color[4];
	extern float Esp_Item_Groza_TextSize;

	extern bool Esp_Item_AUG;
	extern float Esp_Item_AUG_Color[4];
	extern float Esp_Item_AUG_TextSize;

	extern bool Esp_Item_S12K;
	extern float Esp_Item_S12K_Color[4];
	extern float Esp_Item_S12K_TextSize;

	extern bool Esp_Item_M1014;
	extern float Esp_Item_M1014_Color[4];
	extern float Esp_Item_M1014_TextSize;


	extern bool Esp_Item_DBS;
	extern float Esp_Item_DBS_Color[4];
	extern float Esp_Item_DBS_TextSize;

	extern bool Esp_Item_S686;
	extern float Esp_Item_S686_Color[4];
	extern float Esp_Item_S686_TextSize;

	extern bool Esp_Item_S1897;
	extern float Esp_Item_S1897_Color[4];
	extern float Esp_Item_S1897_TextSize;

	extern bool Esp_Item_SawedOff;
	extern float Esp_Item_SawedOff_Color[4];
	extern float Esp_Item_SawedOff_TextSize;



	extern bool Esp_Item_VSS;
	extern float Esp_Item_VSS_Color[4];
	extern float Esp_Item_VSS_TextSize;



	extern bool Esp_Item_CrossBow;
	extern float Esp_Item_CrossBow_Color[4];
	extern float Esp_Item_CrossBow_TextSize;









	extern bool Esp_Item_M416;
	extern float Esp_Item_M416_Color[4];
	extern float Esp_Item_M416_TextSize;

	extern bool Esp_Item_M16A4;
	extern float Esp_Item_M16A4_Color[4];
	extern float Esp_Item_M16A4_TextSize;

	extern bool Esp_Item_G36C;
	extern float Esp_Item_G36C_Color[4];
	extern float Esp_Item_G36C_TextSize;

	extern bool Esp_Item_QBZ;
	extern float Esp_Item_QBZ_Color[4];
	extern float Esp_Item_QBZ_TextSize;

	extern bool Esp_Item_QBU;
	extern float Esp_Item_QBU_Color[4];
	extern float Esp_Item_QBU_TextSize;

	extern bool Esp_Item_SLR;
	extern float Esp_Item_SLR_Color[4];
	extern float Esp_Item_SLR_TextSize;

	extern bool Esp_Item_SKS;
	extern float Esp_Item_SKS_Color[4];
	extern float Esp_Item_SKS_TextSize;

	extern bool Esp_Item_Mini14;
	extern float Esp_Item_Mini14_Color[4];
	extern float Esp_Item_Mini14_TextSize;

	extern bool Esp_Item_M24;
	extern float Esp_Item_M24_Color[4];
	extern float Esp_Item_M24_TextSize;

	extern float fovcolor[4];

	extern bool Esp_Item_Awm;
	extern bool Esp_Item_Awmimo;
	extern bool Esp_Item_Kar98k;

	extern float Esp_Item_Awm_Color[4];
	extern float Esp_Item_Awm_TextSize;


	extern float Esp_Item_Kar98k_Color[4];
	extern float Esp_Item_Kar98k_TextSize;

	extern bool Esp_Item_PP19;
	extern float Esp_Item_PP19_Color[4];
	extern float Esp_Item_PP19_TextSize;

	extern bool Esp_Item_TommyGun;
	extern float Esp_Item_TommyGun_Color[4];
	extern float Esp_Item_TommyGun_TextSize;

	extern bool Esp_Item_MP5K;
	extern float Esp_Item_MP5K_Color[4];
	extern float Esp_Item_MP5K_TextSize;

	extern bool Esp_Item_UMP9;
	extern float Esp_Item_UMP9_Color[4];
	extern float Esp_Item_UMP9_TextSize;

	extern bool Esp_Item_Vector;
	extern float Esp_Item_Vector_Color[4];
	extern float Esp_Item_Vector_TextSize;

	extern bool Esp_Item_Uzi;
	extern float Esp_Item_Uzi_Color[4];
	extern float Esp_Item_Uzi_TextSize;

	extern bool Esp_Item_R1895;
	extern float Esp_Item_R1895_Color[4];
	extern float Esp_Item_R1895_TextSize;

	extern bool Esp_Item_Vz61;
	extern float Esp_Item_Vz61_Color[4];
	extern float Esp_Item_Vz61_TextSize;

	extern bool Esp_Item_P92;
	extern float Esp_Item_P92_Color[4];
	extern float Esp_Item_P92_TextSize;

	extern bool Esp_Item_P18C;
	extern float Esp_Item_P18C_Color[4];
	extern float Esp_Item_P18C_TextSize;

	extern bool Esp_Item_R45;
	extern float Esp_Item_R45_Color[4];
	extern float Esp_Item_R45_TextSize;

	extern bool Esp_Item_P1911;
	extern float Esp_Item_P1911_Color[4];
	extern float Esp_Item_P1911_TextSize;

	extern bool Esp_Item_DesertEagle;
	extern float Esp_Item_DesertEagle_Color[4];
	extern float Esp_Item_DesertEagle_TextSize;

	extern bool Esp_Item_Mk14;
	extern float Esp_Item_Mk14_Color[4];
	extern float Esp_Item_Mk14_TextSize;

	extern bool Esp_Item_762mm;
	extern float Esp_Item_762mm_Color[4];
	extern float Esp_Item_762mm_TextSize;

	extern bool Esp_Item_556mm;
	extern float Esp_Item_556mm_Color[4];
	extern float Esp_Item_556mm_TextSize;

	extern bool Esp_Item_9mm;
	extern float Esp_Item_9mm_Color[4];
	extern float Esp_Item_9mm_TextSize;


	extern bool Esp_Item_12Guage;
	extern float Esp_Item_12Guage_Color[4];
	extern float Esp_Item_12Guage_TextSize;

	extern bool Esp_Item_45ACP;
	extern float Esp_Item_45ACP_Color[4];
	extern float Esp_Item_45ACP_TextSize;

	extern bool Esp_Item_Holo;
	extern float Esp_Item_Holo_Color[4];
	extern float Esp_Item_Holo_TextSize;

	extern bool Esp_Item_RedDot;
	extern float Esp_Item_RedDot_Color[4];
	extern float Esp_Item_RedDot_TextSize;

	extern bool Esp_Item_x2;
	extern float Esp_Item_x2_Color[4];
	extern float Esp_Item_x2_TextSize;

	extern bool Esp_Item_x3;
	extern float Esp_Item_x3_Color[4];
	extern float Esp_Item_x3_TextSize;

	extern bool Esp_Item_x4;
	extern float Esp_Item_x4_Color[4];
	extern float Esp_Item_x4_TextSize;

	extern bool Esp_Item_x6;
	extern float Esp_Item_x6_Color[4];
	extern float Esp_Item_x6_TextSize;

	extern bool Esp_Item_x8;
	extern float Esp_Item_x8_Color[4];
	extern float Esp_Item_x8_TextSize;

	extern bool Esp_Item_Bag1;
	extern float Esp_Item_Bag1_Color[4];
	extern float Esp_Item_Bag1_TextSize;

	extern bool Esp_Item_Bag2;
	extern float Esp_Item_Bag2_Color[4];
	extern float Esp_Item_Bag2_TextSize;

	extern bool Esp_Item_Bag3;
	extern float Esp_Item_Bag3_Color[4];
	extern float Esp_Item_Bag3_TextSize;

	extern bool Esp_Item_Armor1;
	extern float Esp_Item_Armor1_Color[4];
	extern float Esp_Item_Armor1_TextSize;

	extern bool Esp_Item_Armor2;
	extern float Esp_Item_Armor2_Color[4];
	extern float Esp_Item_Armor2_TextSize;

	extern bool Esp_Item_Armor3;
	extern float Esp_Item_Armor3_Color[4];
	extern float Esp_Item_Armor3_TextSize;

	extern bool Esp_Item_Helmet1;
	extern float Esp_Item_Helmet1_Color[4];
	extern float Esp_Item_Helmet1_TextSize;

	extern bool Esp_Item_Helmet2;
	extern float Esp_Item_Helmet2_Color[4];
	extern float Esp_Item_Helmet2_TextSize;

	extern bool Esp_Item_Helmet3;
	extern float Esp_Item_Helmet3_Color[4];
	extern float Esp_Item_Helmet3_TextSize;

	extern bool Esp_Item_Magnum;
	extern float Esp_Item_Magnum_Color[4];
	extern float Esp_Item_Magnum_TextSize;

	extern bool Esp_Item_Frag;
	extern float Esp_Item_Frag_Color[4];
	extern float Esp_Item_Frag_TextSize;

	extern bool Esp_Item_Smoke;
	extern float Esp_Item_Smoke_Color[4];
	extern float Esp_Item_Smoke_TextSize;

	extern bool Esp_Item_molotov;
	extern float Esp_Item_molotov_Color[4];
	extern float Esp_Item_molotov_TextSize;

	extern bool Esp_Item_tun;
	extern float Esp_Item_tun_Color[4];
	extern float Esp_Item_tun_TextSize;


	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;


	extern bool Esp_Item_DeadBox;
	extern float Esp_Item_DeadBox_Color[4];
	extern float Esp_Item_DeadBox_TextSize;


	extern bool Esp_Item_Molotof;
	extern float Esp_Item_Molotof_Color[4];
	extern float Esp_Item_Molotof_TextSize;

	extern bool Esp_Item_MedKit;
	extern float Esp_Item_MedKit_Color[4];
	extern float Esp_Item_MedKit_TextSize;

	extern bool Esp_Item_FirstAidKit;
	extern float Esp_Item_FirstAidKit_Color[4];
	extern float Esp_Item_FirstAidKit_TextSize;

	extern bool Esp_Item_Painkiller;
	extern float Esp_Item_Painkiller_Color[4];
	extern float Esp_Item_Painkiller_TextSize;

	extern bool Esp_Item_EnergyDrink;
	extern float Esp_Item_EnergyDrink_Color[4];
	extern float Esp_Item_EnergyDrink_TextSize;

	extern bool Esp_Item_AdrenalineSyringe;
	extern float Esp_Item_AdrenalineSyringe_Color[4];
	extern float Esp_Item_AdrenalineSyringe_TextSize;

	extern bool Esp_Item_Bandage;
	extern float Esp_Item_Bandage_Color[4];
	extern float Esp_Item_Bandage_TextSize;

	extern bool Esp_Item_FlareGun;
	extern float Esp_Item_FlareGun_Color[4];
	extern float Esp_Item_FlareGun_TextSize;

	extern bool Esp_Item_Flare;
	extern float Esp_Item_Flare_Color[4];
	extern float Esp_Item_Flare_TextSize;


	extern bool Esp_Item_AirDrop;
	extern float Esp_Item_AirDrop_Color[4];
	extern float Esp_Item_AirDrop_TextSize;


	extern bool  Esp_Item_GasCan;
	extern float Esp_Item_GasCan_Color[4];
	extern float Esp_Item_GasCan_TextSize;

	///// test new
	extern bool Esp_Item_BP_QK_Mid_FlashHider_Pickup_C;
	extern float Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Large_FlashHider_Pickup_C;
	extern float Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Large_FlashHider_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Large_Compensator_Pickup_C;
	extern float Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Large_Compensator_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Mid_Compensator_Pickup_C;
	extern float Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Mid_Compensator_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C;
	extern float Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Mid_Suppressor_Pickup_C;
	extern float Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QT_Sniper_Pickup_C;
	extern float Esp_Item_BP_QT_Sniper_Pickup_C_Color[4];
	extern float Esp_Item_BP_QT_Sniper_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QT_A_Pickup_C;
	extern float Esp_Item_BP_QT_A_Pickup_C_Color[4];
	extern float Esp_Item_BP_QT_A_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_DuckBill_Pickup_C;
	extern float Esp_Item_BP_QK_DuckBill_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_DuckBill_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Choke_Pickup_C;
	extern float Esp_Item_BP_QK_Choke_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Choke_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QT_UZI_Pickup_C;
	extern float Esp_Item_BP_QT_UZI_Pickup_C_Color[4];
	extern float Esp_Item_BP_QT_UZI_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Sniper_Compensator_Pickup_C;
	extern float Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C;
	extern float Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_TextSize;

	extern bool Esp_Item_BP_QK_Large_Suppressor_Pickup_C;
	extern float Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[4];
	extern float Esp_Item_BP_QK_Large_Suppressor_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Sniper_EQ_Pickup_C;
	extern float Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Mid_E_Pickup_C;
	extern float Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Mid_E_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Mid_Q_Pickup_C;
	extern float Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Mid_Q_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Mid_EQ_Pickup_C;
	extern float Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Mid_EQ_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Sniper_E_Pickup_C;
	extern float Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Sniper_E_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Sniper_Q_Pickup_C;
	extern float Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Sniper_Q_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Large_Q_Pickup_C;
	extern float Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Large_Q_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Large_EQ_Pickup_C;
	extern float Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Large_EQ_Pickup_C_TextSize;

	extern bool Esp_Item_BP_DJ_Large_E_Pickup_C;
	extern float Esp_Item_BP_DJ_Large_E_Pickup_C_Color[4];
	extern float Esp_Item_BP_DJ_Large_E_Pickup_C_TextSize;

	extern bool Esp_Item_BP_ZDD_Sniper_Pickup_C;
	extern float Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[4];
	extern float Esp_Item_BP_ZDD_Sniper_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_ThumbGrip_Pickup_C;
	extern float Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_ThumbGrip_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_LightGrip_Pickup_C;
	extern float Esp_Item_BP_WB_LightGrip_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_LightGrip_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_HalfGrip_Pickup_C;
	extern float Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_HalfGrip_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_Vertical_Pickup_C;
	extern float Esp_Item_BP_WB_Vertical_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_Vertical_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_Angled_Pickup_C;
	extern float Esp_Item_BP_WB_Angled_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_Angled_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WB_Lasersight_Pickup_C;
	extern float Esp_Item_BP_WB_Lasersight_Pickup_C_Color[4];
	extern float Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize;
	extern float Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize2;

	extern bool Esp_Item_BP_WEP_Sickle_Pickup_C;
	extern float Esp_Item_BP_WEP_Sickle_Pickup_C_Color[4];
	extern float Esp_Item_BP_WEP_Sickle_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WEP_Machete_Pickup_C;
	extern float Esp_Item_BP_WEP_Machete_Pickup_C_Color[4];
	extern float Esp_Item_BP_WEP_Machete_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WEP_Cowbar_Pickup_C;
	extern float Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[4];
	extern float Esp_Item_BP_WEP_Cowbar_Pickup_C_TextSize;

	extern bool Esp_Item_BP_WEP_Pan_Pickup_C;
	extern float Esp_Item_BP_WEP_Pan_Pickup_C_Color[4];
	extern float Esp_Item_BP_WEP_Pan_Pickup_C_TextSize;

	extern bool Esp_Item_test34;
	extern float Esp_Item_test34_Color[4];
	extern float Esp_Item_test34_TextSize;





#include <unordered_map>
#define rev
#define targetLibName OBFUSCATE("libanogs.so")
#define targetLibName OBFUSCATE("libhdmpve.so")
#define targetLibName OBFUSCATE("libanort.so")
#define targetLibName OBFUSCATE("libTBlueData.so")
#define targetLibName OBFUSCATE("libCrashKit.so")
#define targetLibName OBFUSCATE("libRoosterNN.so")
#define targetLibName OBFUSCATE("libUE4.so")
#define targetLibName OBFUSCATE("libanogs.so")
#define targetLibName OBFUSCATE("libanort.so")
#define targetLibName OBFUSCATE("libTBlueData.so")
#define targetLibName OBFUSCATE("libRoosterNN.so")
#define targetLibName OBFUSCATE("libhdmpve.so")
#define targetLibName OBFUSCATE("libAntsVoice.so")

#define ARM64_SYSREG_S3_3_C13_C0_2 "S3_3_C13_C0_2"
#define _ReadStatusReg(reg) ({ uint64_t val; __asm__ volatile("mrs %0, " reg : "=r" (val)); val; })
#define READ_STATUS_REG() ({ uint64_t val; __asm__ volatile("mrs %0, S3_3_C13_C0_2" : "=r" (val)); val; })
char *Offset;
#define ret_zero
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD __int64
#define _OWORD uint64_t
#define _QWORD uint64_t
#define _BOOL8 uint64_t

#define j_j__free
#define log_suspicious_activity
#define apply_cheat_penalty
#define check_memory_integrity
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define HIWORD
#define JUMPOUT
#define byte_4
#include <random>
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define sub_95A8204
#define IsMemoryReadable
#define BYTE1
#define BYTE3
#define MEMORY_BASIC_INFORMATION mbi
#define BYTE2
#define ARM64_SYSREG
#define _WriteStatusReg
#define targetLibName oxorany("libUE4.so")
#define targetLibName oxorany("libhdmpve.so")
#define targetLibName oxorany("libAntsVoice.so")
#define targetLibName oxorany("libanogs.so")

#define targetLibName OBFUSCATE("libUE4.so")
#define targetLibName OBFUSCATE("libanogs.so")
#define targetLibName OBFUSCATE("libanort.so")
#define targetLibName OBFUSCATE("libhdmpve.so")
#define targetLibName ("libTBlueData.so")
#define targetLibName ("libRoosterNN.so")
#define targetLibName ("libhdmpve.so")
#define targetLibName ("libCrashKit.so")
#define targetLibName ("libITOP.so")
#define targetLibName ("libAntsVoice.so")

typedef long long int64; 
typedef short int16;
DWORD TBlueBase = 0;
DWORD AntBase = 0;
DWORD BufferBase = 0;
DWORD libcBase = 0;
DWORD HdmpveBase = 0;
DWORD libanogsBase = 0;
DWORD libUE4Base = 0;
DWORD UE4Base = 0;
DWORD libanortBase = 0;
DWORD libEGLBase = 0;
DWORD libanogsAlloc = 0;
DWORD libUE4Alloc = 0;
DWORD libEGLAlloc = 0;
unsigned int libanogsSize  = 0;
unsigned int libUE4Size  = 0;
DWORD NewBase = 0;
#define HOOK




// HOOKING
//#define ret = 0xFFFFFFFFLL;
//============×========×[MAIN HOOKING]×============×=========////
#define ARM64_SYSREG_S3_3_C13_C0_2 "S3_3_C13_C0_2"
#define _ReadStatusReg(reg) ({ uint64_t val; __asm__ volatile("mrs %0, " reg : "=r" (val)); val; })
#define READ_STATUS_REG() ({ uint64_t val; __asm__ volatile("mrs %0, S3_3_C13_C0_2" : "=r" (val)); val; })

#define ret_zero
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD __int64
#define _OWORD uint64_t
#define _QWORD uint64_t
#define _BOOL8 uint64_t

#define j_j__free
#define log_suspicious_activity
#define apply_cheat_penalty
#define check_memory_integrity
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define HIWORD
#define JUMPOUT
#define byte_4
#include <random>
#define _ReadStatusReg
#define BYTE5
#define BYTE4
#define HIBYTE
#define BYTE6
#define sub_95A8204
#define IsMemoryReadable
#define BYTE1
#define BYTE3
#define MEMORY_BASIC_INFORMATION mbi
#define BYTE2
#define ARM64_SYSREG
#define _WriteStatusReg
typedef long long int64; 
typedef short int16;

#define HOOK

#define BYTE1
#define BYTE5
#define BYTE4
#define BYTE3
#define BYTE2
#define BYTE6
#define BYTE2
#define HIBYTE
#define _BYTE  uint8_t
#define _WORD  uint16_t
#define _DWORD uint32_t
#define _QWORD uint64_t
#define j_j__free
#define __OFSUB__
#define AnoSDKIoctlOld_0
#define pkgName "com.pubg.imobile"
#pragma pack(1)
struct patch_t
{
  _BYTE nPatchType;
   DWORD dwAddress;
};

#define LOG_TAG "RIYAZXERO HERE "
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
///
constexpr const char DefineStr1[] = "00 00 80 D2 C0 03 5F D6"; // MOV X0, #0; RET
constexpr const char RET[] = "C0 03 5F D6";              // RET
constexpr const char NOP[] = "1F 20 03 D5";              // NOP
constexpr const char RET1[] = "01 00 80 D2 C0 03 5F D6"; // MOV X0, #1; RET


void chRestore(){
    char mode[] = "0777";
    char *path = "/data/data/com.pubg.imobile/files/ano_tmp";
    char *path2 = "/data/data/com.pubg.imobile/files";
    int m = strtol(mode,0,8);
    chmod(path,m);
    chmod(path2,m);
    LOGI(OBFUSCATE("permissions restored"));
}










	extern bool Esp_Item_test35;
	extern float Esp_Item_test35_Color[4];
	extern float Esp_Item_test35_TextSize;

	extern bool Esp_Item_test36;
	extern float Esp_Item_test36_Color[4];
	extern float Esp_Item_test36_TextSize;

	extern bool Esp_Item_test37;
	extern float Esp_Item_test37_Color[4];
	extern float Esp_Item_test37_TextSize;

	extern bool Esp_Item_test38;
	extern float Esp_Item_test38_Color[4];
	extern float Esp_Item_test38_TextSize;

	extern bool Esp_Item_test39;
	extern float Esp_Item_test39_Color[4];
	extern float Esp_Item_test39_TextSize;

	extern bool Esp_Item_test40;
	extern float Esp_Item_test40_Color[4];
	extern float Esp_Item_test40_TextSize;

	extern bool Esp_Item_test41;
	extern float Esp_Item_test41_Color[4];
	extern float Esp_Item_test41_TextSize;

	extern bool Esp_Item_test42;
	extern float Esp_Item_test42_Color[4];
	extern float Esp_Item_test42_TextSize;

	extern bool Esp_Item_test43;
	extern float Esp_Item_test43_Color[4];
	extern float Esp_Item_test43_TextSize;

	extern bool Esp_Item_test44;
	extern float Esp_Item_test44_Color[4];
	extern float Esp_Item_test44_TextSize;

	extern bool Esp_Item_test45;
	extern float Esp_Item_test45_Color[4];
	extern float Esp_Item_test45_TextSize;

	extern bool Esp_Item_test46;
	extern float Esp_Item_test46_Color[4];
	extern float Esp_Item_test46_TextSize;


	extern bool Esp_Item_Bow;
	extern float Esp_Item_Bow_Color[4];
	extern float Esp_Item_Bow_TextSize;


	extern bool Esp_Item_test47;
	extern float Esp_Item_test47_Color[4];
	extern float Esp_Item_test47_TextSize;

	extern bool Esp_Item_test48;
	extern float Esp_Item_test48_Color[4];
	extern float Esp_Item_test48_TextSize;

	extern bool Esp_Item_test49;
	extern float Esp_Item_test49_Color[4];
	extern float Esp_Item_test49_TextSize;

	extern bool Esp_Item_test50;
	extern float Esp_Item_test50_Color[4];
	extern float Esp_Item_test50_TextSize;

	//////////////////////////////////////////
	extern bool Esp_Item_test51;
	extern float Esp_Item_test51_Color[4];
	extern float Esp_Item_test51_TextSize;


	extern bool Esp_Item_test52;
	extern float Esp_Item_test52_Color[4];
	extern float Esp_Item_test52_TextSize;


	extern bool Esp_Item_test53;
	extern float Esp_Item_test53_Color[4];
	extern float Esp_Item_test53_TextSize;

	extern bool Esp_Item_test54;
	extern float Esp_Item_test54_Color[4];
	extern float Esp_Item_test54_TextSize;

	extern bool Esp_Item_test55;
	extern float Esp_Item_test55_Color[4];
	extern float Esp_Item_test55_TextSize;

	extern bool Esp_Item_test56;
	extern float Esp_Item_test56_Color[4];
	extern float Esp_Item_test56_TextSize;

	extern bool Esp_Item_test57;
	extern float Esp_Item_test57_Color[4];
	extern float Esp_Item_test57_TextSize;

	extern bool Esp_Item_test58;
	extern float Esp_Item_test58_Color[4];
	extern float Esp_Item_test58_TextSize;

	extern bool Esp_Item_test59;
	extern float Esp_Item_test59_Color[4];
	extern float Esp_Item_test59_TextSize;

	extern bool Esp_Item_test60;
	extern float Esp_Item_test60_Color[4];
	extern float Esp_Item_test60_TextSize;

	extern bool Esp_Item_test61;
	extern float Esp_Item_test61_Color[4];
	extern float Esp_Item_test61_TextSize;

	extern bool Esp_Item_test62;
	extern float Esp_Item_test62_Color[4];
	extern float Esp_Item_test62_TextSize;

	extern bool Esp_Item_test63;
	extern float Esp_Item_test63_Color[4];
	extern float Esp_Item_test63_TextSize;

	extern bool Esp_Item_test64;
	extern float Esp_Item_test64_Color[4];
	extern float Esp_Item_test64_TextSize;

	extern bool Esp_Item_test65;
	extern float Esp_Item_test65_Color[4];
	extern float Esp_Item_test65_TextSize;

	extern bool Esp_Item_test66;
	extern float Esp_Item_test66_Color[4];
	extern float Esp_Item_test66_TextSize;

	extern bool Esp_Item_test67;
	extern float Esp_Item_test67_Color[4];
	extern float Esp_Item_test67_TextSize;

	extern bool Esp_Item_test68;
	extern float Esp_Item_test68_Color[4];
	extern float Esp_Item_test68_TextSize;

	extern bool Esp_Item_test69;
	extern float Esp_Item_test69_Color[4];
	extern float Esp_Item_test69_TextSize;

	extern bool Esp_Item_test70;
	extern float Esp_Item_test70_Color[4];
	extern float Esp_Item_test70_TextSize;

	extern bool Esp_Item_test71;
	extern float Esp_Item_test71_Color[4];
	extern float Esp_Item_test71_TextSize;

	extern bool Esp_Item_test72;
	extern float Esp_Item_test72_Color[4];
	extern float Esp_Item_test72_TextSize;

	extern bool Esp_Item_test73;
	extern float Esp_Item_test73_Color[4];
	extern float Esp_Item_test73_TextSize;


	extern bool Esp_Item_test74;
	extern float Esp_Item_test74_Color[4];
	extern float Esp_Item_test74_TextSize;

	extern bool Esp_Item_test75;
	extern float Esp_Item_test75_Color[4];
	extern float Esp_Item_test75_TextSize;

	extern bool Esp_Item_test76;
	extern float Esp_Item_test76_Color[4];
	extern float Esp_Item_test76_TextSize;

	extern bool Esp_Item_test77;
	extern float Esp_Item_test77_Color[4];
	extern float Esp_Item_test77_TextSize;

	extern bool Esp_Item_test78;
	extern float Esp_Item_test78_Color[4];
	extern float Esp_Item_test78_TextSize;

	extern bool Esp_Item_test79;
	extern float Esp_Item_test79_Color[4];
	extern float Esp_Item_test79_TextSize;

	extern bool Esp_Item_test80;
	extern float Esp_Item_test80_Color[4];
	extern float Esp_Item_test80_TextSize;


	extern bool Esp_Item_test81;
	extern float Esp_Item_test81_Color[4];
	extern float Esp_Item_test81_TextSize;


	extern bool Esp_Item_test82;
	extern float Esp_Item_test82_Color[4];
	extern float Esp_Item_test82_TextSize;

	extern bool Esp_Item_test83;
	extern float Esp_Item_test83_Color[4];
	extern float Esp_Item_test83_TextSize;

	extern bool Esp_Item_test84;
	extern float Esp_Item_test84_Color[4];
	extern float Esp_Item_test84_TextSize;

	extern bool Esp_Item_test85;
	extern float Esp_Item_test85_Color[4];
	extern float Esp_Item_test85_TextSize;


	extern bool Esp_Item_test86;
	extern float Esp_Item_test86_Color[4];
	extern float Esp_Item_test86_TextSize;


	extern bool Esp_Item_test87;
	extern float Esp_Item_test87_Color[4];
	extern float Esp_Item_test87_TextSize;


	extern bool Esp_Item_test88;
	extern float Esp_Item_test88_Color[4];
	extern float Esp_Item_test88_TextSize;


	extern bool Esp_Item_test89;
	extern float Esp_Item_test89_Color[4];
	extern float Esp_Item_test89_TextSize;

	extern bool Esp_Item_test90;
	extern float Esp_Item_test90_Color[4];
	extern float Esp_Item_test90_TextSize;

	extern bool Esp_Item_test91;
	extern float Esp_Item_test91_Color[4];
	extern float Esp_Item_test91_TextSize;

	extern bool Esp_Item_test92;
	extern float Esp_Item_test92_Color[4];
	extern float Esp_Item_test92_TextSize;

	extern bool Esp_Item_test93;
	extern float Esp_Item_test93_Color[4];
	extern float Esp_Item_test93_TextSize;

	extern bool Esp_Item_test94;
	extern float Esp_Item_test94_Color[4];
	extern float Esp_Item_test94_TextSize;

	extern bool Esp_Item_test95;
	extern float Esp_Item_test95_Color[4];
	extern float Esp_Item_test95_TextSize;

	extern bool Esp_Item_test96;
	extern float Esp_Item_test96_Color[4];
	extern float Esp_Item_test96_TextSize;

	extern bool Esp_Item_test97;
	extern float Esp_Item_test97_Color[4];
	extern float Esp_Item_test97_TextSize;


	extern bool Esp_Item_test98;
	extern float Esp_Item_test98_Color[4];
	extern float Esp_Item_test98_TextSize;


	extern bool Esp_Item_test99;
	extern float Esp_Item_test99_Color[4];
	extern float Esp_Item_test99_TextSize;


	extern bool Esp_Item_test100;
	extern float Esp_Item_test100_Color[4];
	extern float Esp_Item_test100_TextSize;


	extern bool Esp_Item_test101;
	extern float Esp_Item_test101_Color[4];
	extern float Esp_Item_test101_TextSize;










int Setting::macro3 = 50;
int Setting::macro2 = 0;
bool Setting::marco1 = false;




    extern std::string Login_Status;
    extern std::string Login_OK;
    extern std::string WeaponStatus;
    extern ImVec4 LoginStatus_Color;
    extern ImVec4 WeaponStatusColor;
    extern ImVec4 WeaponStatusColor2;
	extern ImVec4 WeaponColor;



	extern bool Aimbot;
	extern bool Aimbullet;

	extern bool MagicBullet;
	extern bool CameraCache;
	extern bool BypassFovLimit;


	extern bool textborder;
	extern bool fake;

	extern bool CameraCatch;

	extern bool fragwarning;
	extern bool smokewarning;
	extern bool apple;
	extern bool SpeedFire2;
	extern bool molotovwarning;
	extern bool tunwarning;
	extern bool BodyRandom;
	extern bool HeadRandom;
	extern bool GrassLobby;

    extern int  GrandeDamgae;
    extern int  SmokeDamgae;
    extern int  BurnDamgae;
    extern int  FlashDamgae;
	extern int	RedZoneDamgae;

	//extern float hpt;
	extern float	magicv;
	extern float	flycarv;
	extern float	instantv;
	extern float	SpeedFire;
	extern float	highjump;
	extern float	carsv;
	extern float    fastrv;
	extern float	fastrv_2;
	extern float	fastrv_3;
	extern float	fastrv_4;
	extern float	fastrv_5;
	extern float	jumpvalue;
	extern float	fastrv_5M;
	extern float	testXeffectt;
	extern int	fastparaaa;
	extern int	disaplememorytime;
	extern int	      Test55;
	extern int	      SpeedShoot;
	extern int	      NoGrassValue;
	extern int Magic_Bullet;
	extern int SelectorV3;
	extern int SelectorV5;
	extern int SelectorGrass;
	extern int RecSelector;
	extern int RecSelector2;
	extern int Headselctor;
	extern int jmp;
	extern bool magicb;
}

//std::string Setting::Login_Status = " press login button to start respone"

    int Setting::GrandeDamgae = 700;
    int Setting::SmokeDamgae = 500;
    int Setting::BurnDamgae = 500;
    int Setting::FlashDamgae = 500;
	int	Setting::RedZoneDamgae = 500;
ImVec4 weapon::holdColor = { 1.0f, 1.0f, 1.0f, 1.5f };

ImVec4 weapon::m16 = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 weapon::AKM = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 weapon::AWM = { 1.000f, 0.089f, 0.089f, 1.000f };
ImVec4 weapon::magnum = { 0.942f, 0.300f, 0.073f, 1.000f };

ImVec4 weapon::scarl = { 0.000f, 1.000, 0.318, 1.000f };
ImVec4 weapon::m762 = { 0.118f, 0.76f, 0.788f, 1.000f };
ImVec4 weapon::M24 = { 0.844f, 0.066f, 1.000f, 1.000f };
ImVec4 weapon::GROZZA = { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4 weapon::scope8x = { 0.866f, 0.128f, 0.081f, 1.000f };
ImVec4 weapon::kar98 = { 1.0f, 0.60f,0.05f, 1.0f };
ImVec4 weapon::Airdrop = { 0.279f, 0.990f, 0.812f, 1.000f };
ImVec4 weapon::Flare = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 weapon::Flaregun = { 1.000f, 0.000f, 0.000f, 1.000f };

/////////////////////////drop//////////////////////////

ImVec4 Color::dp = { 1.000f, 0.760f, 0.150f, 1.000f };
ImVec4 Color::mg3 = { 0.373f, 0.966f, 0.391f, 1.000f };
ImVec4 Color::scope4x = { 0.937f, 0.063f, 0.937f, 1.000f };
ImVec4 Color::scope3x = { 0.874f, 0.484f, 0.106f, 1.000f };
ImVec4 Color::bag = { 0.529f, 0.127f, 0.903f, 1.000f };
ImVec4 Color::armer = { 0.591f, 1.000f, 0.237f, 1.000f };
ImVec4 Color::helmat = { 0.726f, 0.070f, 0.908f, 1.000f };
ImVec4 Color::mosin = { 0.258f, 0.971f, 0.775f, 1.000f };
ImVec4 Color::aug = { 0.442f, 0.971f, 0.122f, 1.000f };

ImVec4 Color::g36 = { 0.671f, 0.217f, 1.000f, 1.000f };
ImVec4 Color::assm = { 1.000f, 0.217f, 0.762f, 1.000f };
extern	ImVec4 Color::Grandes = { 1.000f, 0.396f, 0.357f, 1.000f };
extern	ImVec4 Color::ammo7 = { 0.957f, 0.353f, 0.226f, 1.000f };
extern	ImVec4 Color::ammo5 = { 0.000f, 1.000f, 0.000f, 1.000f };
extern ImVec4 Color::madkit = { 0.952f, 0.558f, 0.129f, 1.000f };

// Color

ImVec4 Color::itemColor;
ImVec4 Color::playerline = { 1.000f, 1.000f, 1.000f, 1.000f };

ImVec4 Color::newline = { 0.000f, 0.867f, 1.000f, 1.000f };

ImVec4 Color::playerlineopenn = { 0.000f, 1.000f, 0.150f, 1.000f };

ImVec4 Setting::WeaponColor = ImVec4(1.000f, 1.000f, 0.000f, 1.000f);


ImVec4 Color::playerlineopen = { 0.000f, 1.000f, 0.387f, 1.000f };
ImVec4 Color::playerlineSilent = { 0.000f, 0.549f, 1.000f, 1.000f };

ImVec4 Color::Enemy_Aiming_at_you = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::playercorner = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::playerbox = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::lotbox = { 1.0f, 1.0f,0.0f, 1.0f };
// ARGB
ImVec4 Color::helthbar = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::boxColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::cornerColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::crosshairColor = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::bot = { 0.900f, 0.025f, 0.025f, 1.0f };
ImVec4 Color::player = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::vehicle = { 1.000f, 1.000f, 0.000f, 1.000f };
//ImVec4 Color::vehicle = { 1.000f, 1.000f, 0.000f, 1.000f };
//RGB(1.000f, 1.000f, 0.000f, 1.000f)
//ImVec4 Color::botcorner = { 0.050f, 0.025f, 0.925f, 1.0f };////////////
ImVec4 Color::botcorner = { 0.000f, 0.973f, 1.000f, 1.000f };////////////
ImVec4 Color::botline = { 0.000f, 0.973f, 1.000f, 1.000f };
ImVec4 Color::botlineopen = { 0.000f, 1.000f, 0.469f, 1.000f };
ImVec4 Color::botlinecover = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 Color::circle = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::enemy = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::HPP = { 1.000f, 1.000f, 0.000f, 1.000f };
ImVec4 Color::benemy = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::botbox = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::bone = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::fillrect = { 0.950f, 0.125f, 0.125f, 1.0f };
ImVec4 Color::nam = { 1.000f, 1.000f, 0.000f, 1.000f };
ImVec4 Color::nam222 = { 1.000f, 1.000f, 0.000f, 1.000f };
ImVec4 Color::nam_border = { 0.000f, 0.000f, 0.000f, 1.000f };
ImVec4 plr_wpn = { 0.965f, 1.000f, 0.000f, 1.000f };
//ImVec4 Color::nam = /*{ 247, 255, 0, 255 };*/ {1.000f, 1.000f, 0.000f, 1.000f};
ImVec4 Color::nambar = { 0.880f, 0.185f, 0.25f, 1.0f };
ImVec4 Color::bothealth = { 0.95f, 0.125f, 0.825f, 1.0f };
ImVec4 Color::botname = { 0.000f, 0.590f, 1.000f, 1.000f };/////////
//ImVec4 Color::botname = { 0.000f, 0.600f, 1.000f, 1.000f };/////////
ImVec4 Color::botdown = { 1.000f, 0.000f, 0.000f, 1.000f };/////////(255, 30, 30);
//ImVec4 Color::botname = { 0.0f, 0.682f, 1.0f, 1.0f };/////////
ImVec4 Color::playerhealth = { 0.50f, 0.725f, 0.105f, 1.0f };
ImVec4 Color::textcolor = { 0.500f, 0.150f, 0.125f, 1.0f };

ImVec4 Color::Granades = { 0.990f, 0.995f, 0.995f, 1.0f };
ImVec4 Color::health = { 0.108f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::deadbox = { 0.737f, 1.000f, 0.000f, 1.000f };
ImVec4 Color::deadboxitem = { 1.000f, 0.100f, 0.401f, 1.000f };
ImVec4 Color::airdrop = { 1.000f, 0.695f, 0.323f, 1.000f };
ImVec4 Color::airdropitem = { 0.300f, 0.695f, 0.323f, 1.000f };
ImVec4 Color::scopetextcolor = { 0.000f, 0.995f, 0.995f, 1.000f };
ImVec4 Color::allitem = { 0.034f, 1.000f, 0.040f, 1.000f };
ImVec4 Color::scope6x = { 0.120f, 0.955f, 0.125f, 1.0f };

ImVec4 Color::botbone = { 0.000f, 0.973f, 1.000f, 1.000f };


ImVec4 Color::playerbone = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::magicline = { 255, 0, 0, 255 };
ImVec4 Color::magicline3 = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::bgcorner = { 0.000f, 1.000f, 0.964f, 1.000f };
ImVec4 Color::fovcirclecolor = { 1.000f, 1.000f, 1.000f, 1.000f };
//ImVec4 Setting::fovcolor = { 0.000f, 0.894f, 1.000f, 1.000f };

ImVec4 Color::skelec = { 1.000f, 1.000f, 1.000f, 1.000f };


ImVec4 Setting::WeaponStatusColor = ImVec4(0.000f, 1.000f, 0.071f, 1.000f);
ImVec4 Setting::WeaponStatusColor2 = ImVec4(0.000f, 1.000f, 0.071f, 1.000f);



ImVec4 Color::hpt = { 255, 255, 255, 255 };


int Setting::BotCount = 0;
int Setting::PlayerCount = 0;
int Setting::TotalEnemyCount = 0;

int Setting::AimbotKey = 69;

int Setting::GodUp = 0;
int Setting::GodDown = 0;
int Setting::GodFRONT = 0;
int Setting::Godleft = 0;
int Setting::Godright = 0;





int Setting::aimknock = 0;

int Setting::fastrunkey = 0;
int Setting::fastrun2key = 0;
int Setting::fastrun3key = 0;
int Setting::fastrun4key = 0;
int Setting::fastrun5key = 0;
int Setting::GrassKeyy = 0;
int Setting::jmpkeyy = 0;
int Setting::instantkey = 0;
int Setting::topgodview = 0;
int Setting::uppergodview = 0;
int Setting::frontgodview = 0;
int Setting::leftgodview = 0;
int Setting::rightgodview = 0;
int Setting::selectkey = 0;
int Setting::teleportkey = 0;
int Setting::speedupkey = 0;
int Setting::reducespeedkey = 0;
int Setting::fastparakey = 0;
int Setting::Recoilkey = 0;
int Setting::PositionKey = 0;
int Setting::dots_type = 0;
int Setting::EnableKey = 0;
bool  Setting::plan = false;
ImVec4  Setting::plancolor = { 0.737f, 1.000f, 0.000f, 1.000f };
ImVec4  Setting::dotss = { 0.950f, 0.125f, 0.925f, 1.0f };

bool Setting::dots = false;
bool Setting::visibleesp = false;
bool Setting::RedZoneee = false;
//bool Setting::PlayerAiming = true;
int Setting::redioption = 1;
bool Setting::redioption2 = false;
bool Setting::IsMagicInitialize = false;
bool Setting::Magntic = false;
int Setting::Aimspeed = 14;
int	Setting::curraim = 0;
int	Setting::Rec = 0;
int	Setting::Magic_Range = 350;
char  Setting::filename[] = "C:\Avengers.ini";
float Setting::fontsize = 0;
float Setting::Normalfontsize = 0;

bool Setting::vislibfound = false;
bool Setting::ShowPId = false;
extern float Setting::plinesize = 1.000f;
extern float Setting::pfullboxsize = 1.000f;
//extern float Setting::RadiusSize = 150.000f;
extern float Setting::RadiusSize = 82.500f;
extern float Setting::pcornersize = 1.000f;
extern float Setting::pbonesize = 1.000f;
extern float Setting::blinesize = 1.000f;
extern float Setting::bfullboxsize = 1.000f;
extern float Setting::bcornersize = 1.000f;
extern float Setting::bbonesize = 1.000f;

bool Setting::MagicX = false;
bool Setting::GameInFo = false;
bool Setting::slowmode = false;
bool Setting::killmsg = false;
bool Setting::macrospeed = false;
bool Setting::paraassists = false;
bool Setting::birdmodee = false;
bool Setting::Knockkmode = false;
bool Setting::nearstAR = false;
bool Setting::balltcp = false;
bool Setting::balludp = false;
bool Setting::autoudp = false;
bool Setting::autotcp = false;
bool Setting::blobby = false;
bool Setting::DangerM = false;
bool Setting::SlowAni = false;
bool Setting::FixfLASH = false;
bool Setting::DangerMod = false;
bool Setting::Instant = false;
bool Setting::norecoil = false;
bool Setting::norecoilv1 = false;
bool Setting::norecoilv2 = false;
bool Setting::antiscreencapture = false;
//bool Setting::fastcar = false;
//bool Setting::flycr = false;
bool Setting::MagicBct = false;



bool Setting::check9 = 1, Setting::dest9 = 0;
bool Setting::macro_checker = false;
bool Setting::check6 = false;
int Setting::int_value_macro_speed = 100;







bool Setting::FastLoot = false;
bool Setting::FastShoot = false;
bool Setting::Skipbot = false;
bool Setting::AUTO_FIRE = false;
bool Setting::CamView = false;
bool Setting::carteleport = false;
bool Setting::PlayerBytnak = false;
bool Setting::FastSwitch = false;
bool Setting::NoSpread = false;

int Setting::totaldistance = 0;
float Setting::MoveSpeed = 0;

int Setting::gametime = 0;
int Setting::colortime = 0;

bool Setting::HookMg = false;
bool Setting::Antiscreen = false;

bool Setting::bortext = false;

bool Setting::knocked = false;
bool Setting::RapidFireG = false;
bool Setting::aimbotposition = false;

float Setting::fovcircleredus = 0.000f;
float Setting::predectionline = 1.000f;
float Setting::possition = 0.000f;
float Setting::speedfirrre = 0.100f;
bool Setting::Draw_fovcircle = false;
bool Setting::Draw_peredectionline = false;
bool Setting::fovcircle = false;
ImVec4 Setting::colorcode;
float Setting::sizecode;
bool Setting::botname = false;
bool Setting::botdistance = false;
bool Setting::bothealth = false;
bool Setting::botfullbox = false;
bool Setting::botblood = false;
bool Setting::botcorner = false;
//playr
bool Setting::pline = false;
bool Setting::Aiming = false;
bool Setting::Warn_Aiming = false;
bool Setting::botline = false;
bool Setting::phealth = false;
bool Setting::pcountry = false;
bool Setting::enemyIdd = false;
bool Setting::bg = false;

bool Setting::pfullbox = false;
bool Setting::pname = false;
bool Setting::plr_wpn = false;
bool Setting::plr_scp = false;
bool Setting::pblood = false;
bool Setting::pcorner = false;
bool Setting::deadbox = false;
bool Setting::MAgicline = false;
bool Setting::ScopeZoomm = false;
bool Setting::NearWeapon = false;
bool Setting::SpeedFire2 = false;
bool Setting::locktarget = false;
bool Setting::autofire = false;
bool Setting::fightmode = false;
bool Setting::hotkeys = false;
//bool Setting::nothingm = false;
bool Setting::nothinga = false;
bool Setting::aimpere = false;
bool Setting::visibleeee = false;
bool Setting::autoaimmm = false;
bool Setting::autofireee = false;
bool Setting::aimbottttt = false;
bool Setting::autoreloaddd = false;
bool Setting::onlybottt = false;
bool Setting::Test_New_Cpu = false;

bool Setting::feul = false;

bool Setting::style1 = false;
bool Setting::style2 = true;
bool Setting::botBone = false;

bool Setting::Bags = false;
bool Setting::Armer = false;
bool Setting::Helmat = false;

bool Setting::playerBone = false;
bool Setting::knockedenemy = false;

bool  Setting::airdrop = false;
bool  Setting::airdropitem = false;
bool  Setting::playerdeadbox = false;
bool  Setting::itemrect = false;
bool Setting::ShowMenu = false;
bool Setting::ExitLogin = false;
bool Setting::ExitMain = false;
bool Setting::profree = false;

bool Setting::login = false;
bool Setting::FkMenuDraw = false;
bool Setting::pweapon = false;
bool Setting::botweapon = false;
bool Setting::Distance = false;
bool Setting::Distancee = false;
bool Setting::TotalEnemy = true;
bool Setting::Enenmyaim = true;
bool Setting::AimingWarning = false;
bool Setting::Line = false;
bool Setting::Box = false;
bool Setting::Bone = false;
bool Setting::Health = false;

bool Setting::BombAlert = false;
bool Setting::newdriving = false;
bool Setting::Item = false;
bool Setting::Itemsequences = false;
bool Setting::Vehicle = false;
bool Setting::BGMI = false;
int Setting::engine = 0;
bool Setting::impitems = false;
bool Setting::scope = false;
bool Setting::Warning = false;
bool Setting::healthitem = false;
bool Setting::allitemss = false;
bool Setting::TestItemLine = false;
bool Setting::instanthit = false;
bool Setting::fastrun = false;
bool Setting::fastrun2 = false;
bool Setting::fastrun3 = false;
bool Setting::fastrun4 = false;
bool Setting::fastrun5 = false;
bool Setting::fly = false;
bool Setting::godview = false;
bool Setting::disaplememory = false;
bool Setting::teleport = false;
bool Setting::nograss = false;
bool Setting::carfly = false;
bool Setting::visible_check = false;
bool Setting::fastpara = false;
bool Setting::speedcar = false;
bool Setting::recoil = false;
bool Setting::No_Recoil = false;
bool Setting::vahicle_item = false;

float Setting::Speed_Fire = 0.0f;



bool Setting::Esp_Item_Mk12 = false;
float Setting::Esp_Item_Mk12_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Mk12_TextSize = 22.0f;


bool Setting::Esp_Item_M762 = false;
float Setting::Esp_Item_M762_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_M762_TextSize = 22.0f;

bool Setting::Esp_Item_M249 = false;
float Setting::Esp_Item_M249_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_M249_TextSize = 22.0f;

bool Setting::Esp_Item_Mk47Mutant = false;
float Setting::Esp_Item_Mk47Mutant_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Mk47Mutant_TextSize = 22.0f;

bool Setting::Esp_Item_DP28 = false;
float Setting::Esp_Item_DP28_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_DP28_TextSize = 22.0f;

bool Setting::Esp_Item_SCARL = false;
float Setting::Esp_Item_SCARL_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_SCARL_TextSize = 22.0f;
////////

bool Setting::Esp_Item_AKM = false;
float Setting::Esp_Item_AKM_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_AKM_TextSize = 22.0f;

bool Setting::Esp_Item_Event = false;
float Setting::Esp_Item_Event_Color[4] = { 1.000f, 1.000f, 0.000f, 1.000f };
float Setting::Esp_Item_Event_TextSize = 22.0f;

bool Setting::Esp_Item_Mosin = false;
float Setting::Esp_Item_Mosin_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Mosin_TextSize = 22.0f;


bool Setting::Esp_Item_Win94 = false;
float Setting::Esp_Item_Win94_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Win94_TextSize = 22.0f;

bool Setting::Esp_Item_VSS = false;
float Setting::Esp_Item_VSS_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_VSS_TextSize = 22.0f;



bool Setting::Esp_Item_Groza = false;
float Setting::Esp_Item_Groza_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Groza_TextSize = 22.0f;

bool Setting::Esp_Item_AUG = false;
float Setting::Esp_Item_AUG_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_AUG_TextSize = 22.0f;



bool Setting::Esp_Item_S12K = false;
float Setting::Esp_Item_S12K_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_S12K_TextSize = 22.0f;

bool Setting::Esp_Item_M1014 = false;
float Setting::Esp_Item_M1014_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_M1014_TextSize = 22.0f;


bool Setting::Esp_Item_DBS = false;
float Setting::Esp_Item_DBS_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_DBS_TextSize = 22.0f;

bool Setting::Esp_Item_S686 = false;
float Setting::Esp_Item_S686_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_S686_TextSize = 22.0f;

bool Setting::Esp_Item_S1897 = false;
float Setting::Esp_Item_S1897_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_S1897_TextSize = 22.0f;

bool Setting::Esp_Item_SawedOff = false;
float Setting::Esp_Item_SawedOff_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_SawedOff_TextSize = 22.0f;


bool Setting::Esp_Item_CrossBow = false;
float Setting::Esp_Item_CrossBow_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_CrossBow_TextSize = 22.0f;

bool Setting::Esp_Item_M416 = false;
float Setting::Esp_Item_M416_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_M416_TextSize = 22.0f;

bool Setting::Esp_Item_M16A4 = false;
float Setting::Esp_Item_M16A4_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_M16A4_TextSize = 22.0f;

bool Setting::Esp_Item_G36C = false;
float Setting::Esp_Item_G36C_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_G36C_TextSize = 22.0f;

bool Setting::Esp_Item_QBZ = false;
float Setting::Esp_Item_QBZ_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_QBZ_TextSize = 22.0f;

bool Setting::Esp_Item_QBU = false;
float Setting::Esp_Item_QBU_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_QBU_TextSize = 22.0f;

bool Setting::Esp_Item_SLR = false;
float Setting::Esp_Item_SLR_Color[4] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Setting::Esp_Item_SLR_TextSize = 22.0f;

bool Setting::Esp_Item_SKS = false;
float Setting::Esp_Item_SKS_Color[4] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Setting::Esp_Item_SKS_TextSize = 22.0f;

bool Setting::Esp_Item_Mini14 = false;
float Setting::Esp_Item_Mini14_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Mini14_TextSize = 22.0f;

bool Setting::Esp_Item_M24 = false;
float Setting::Esp_Item_M24_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_M24_TextSize = 22.0f;


bool Setting::Esp_Item_Awm = false;
float Setting::Esp_Item_Awm_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Awm_TextSize = 22.0f;
bool Setting::Esp_Item_Awmimo = false;

float Setting::fovcolor[4] = { 1.000f, 1.000f, 1.000f, 1.000f };

bool Setting::Esp_Item_Kar98k = false;
float Setting::Esp_Item_Kar98k_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Kar98k_TextSize = 22.0f;

bool Setting::Esp_Item_PP19 = false;
float Setting::Esp_Item_PP19_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_PP19_TextSize = 22.0f;

bool Setting::Esp_Item_TommyGun = false;
float Setting::Esp_Item_TommyGun_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_TommyGun_TextSize = 22.0f;

bool Setting::Esp_Item_MP5K = false;
float Setting::Esp_Item_MP5K_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_MP5K_TextSize = 22.0f;

bool Setting::Esp_Item_UMP9 = false;
float Setting::Esp_Item_UMP9_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_UMP9_TextSize = 22.0f;

bool Setting::Esp_Item_Vector = false;
float Setting::Esp_Item_Vector_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Vector_TextSize = 22.0f;

bool Setting::Esp_Item_Uzi = false;
float Setting::Esp_Item_Uzi_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_Uzi_TextSize = 22.0f;

bool Setting::Esp_Item_Vz61 = false;
float Setting::Esp_Item_Vz61_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_Vz61_TextSize = 22.0f;

bool Setting::Esp_Item_P92 = false;
float Setting::Esp_Item_P92_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_P92_TextSize = 22.0f;

bool Setting::Esp_Item_P18C = false;
float Setting::Esp_Item_P18C_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_P18C_TextSize = 22.0f;

bool Setting::Esp_Item_R45 = false;
float Setting::Esp_Item_R45_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_R45_TextSize = 22.0f;

bool Setting::Esp_Item_P1911 = false;
float Setting::Esp_Item_P1911_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_P1911_TextSize = 22.0f;

bool Setting::Esp_Item_DesertEagle = false;
float Setting::Esp_Item_DesertEagle_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_DesertEagle_TextSize = 22.0f;

bool Setting::Esp_Item_Mk14 = false;
float Setting::Esp_Item_Mk14_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Mk14_TextSize = 22.0f;

bool Setting::Esp_Item_R1895 = false;
float Setting::Esp_Item_R1895_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_R1895_TextSize = 22.0f;



bool Setting::Esp_Item_762mm = false;
float Setting::Esp_Item_762mm_Color[4] = { 0.984f, 0.871f, 0.043f, 1.000f };
float Setting::Esp_Item_762mm_TextSize = 22.0f;

bool Setting::Esp_Item_556mm = false;
float Setting::Esp_Item_556mm_Color[4] = { 0.000f, 1.000f, 0.318f, 1.000f };
float Setting::Esp_Item_556mm_TextSize = 22.0f;

bool Setting::Esp_Item_9mm = false;
float Setting::Esp_Item_9mm_Color[4] = { 1.000f, 0.000f, 0.337f, 1.000f };
float Setting::Esp_Item_9mm_TextSize = 22.0f;


bool Setting::Esp_Item_12Guage = false;
float Setting::Esp_Item_12Guage_Color[4] = { 1.000f, 0.000f, 0.337f, 1.000f };
float Setting::Esp_Item_12Guage_TextSize = 22.0f;


bool Setting::Esp_Item_45ACP = false;
float Setting::Esp_Item_45ACP_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_45ACP_TextSize = 22.0f;

bool Setting::Esp_Item_Holo = false;
float Setting::Esp_Item_Holo_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_Holo_TextSize = 22.0f;

bool Setting::Esp_Item_RedDot = false;
float Setting::Esp_Item_RedDot_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_RedDot_TextSize = 22.0f;


bool Setting::Esp_Item_x2 = false;
float Setting::Esp_Item_x2_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_x2_TextSize = 22.0f;

bool Setting::Esp_Item_x3 = false;
float Setting::Esp_Item_x3_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_x3_TextSize = 22.0f;

bool Setting::Esp_Item_x4 = false;
float Setting::Esp_Item_x4_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_x4_TextSize = 22.0f;

bool Setting::Esp_Item_x6 = false;
float Setting::Esp_Item_x6_Color[4] = { 1.000f, 0.000f, 0.000f, 1.000f };
float Setting::Esp_Item_x6_TextSize = 22.0f;

bool Setting::Esp_Item_x8 = false;
float Setting::Esp_Item_x8_Color[4] = { 1.000f, 0.000f, 0.000f, 1.000f };
float Setting::Esp_Item_x8_TextSize = 22.0f;

bool Setting::Esp_Item_Bag1 = false;
float Setting::Esp_Item_Bag1_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_Bag1_TextSize = 22.0f;

bool Setting::Esp_Item_Bag2 = false;
float Setting::Esp_Item_Bag2_Color[4] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Setting::Esp_Item_Bag2_TextSize = 22.0f;

bool Setting::Esp_Item_Bag3 = false;
float Setting::Esp_Item_Bag3_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Bag3_TextSize = 22.0f;

bool Setting::Esp_Item_Armor1 = false;
float Setting::Esp_Item_Armor1_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_Armor1_TextSize = 22.0f;

bool Setting::Esp_Item_Armor2 = false;
float Setting::Esp_Item_Armor2_Color[4] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Setting::Esp_Item_Armor2_TextSize = 22.0f;

bool Setting::Esp_Item_Armor3 = false;
float Setting::Esp_Item_Armor3_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Armor3_TextSize = 22.0f;

bool Setting::Esp_Item_Helmet1 = false;
float Setting::Esp_Item_Helmet1_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_Helmet1_TextSize = 22.0f;

bool Setting::Esp_Item_Helmet2 = false;
float Setting::Esp_Item_Helmet2_Color[4] = { 0.627f, 0.102f, 0.941f, 1.000f };
float Setting::Esp_Item_Helmet2_TextSize = 22.0f;

bool Setting::Esp_Item_Helmet3 = false;
float Setting::Esp_Item_Helmet3_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Helmet3_TextSize = 22.0f;

bool Setting::Esp_Item_Magnum = false;
float Setting::Esp_Item_Magnum_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_Magnum_TextSize = 22.0f;


/////////// grenade item
bool Setting::Esp_Item_Frag = false;
float Setting::Esp_Item_Frag_Color[4] = { 1.000f, 1.000f, 0.000f, 1.000f };
float Setting::Esp_Item_Frag_TextSize = 22.0f;

bool Setting::Esp_Item_Smoke = false;
float Setting::Esp_Item_Smoke_Color[4] = { 1.000f, 1.000f, 0.000f, 1.000f };
float Setting::Esp_Item_Smoke_TextSize = 22.0f;

bool Setting::Esp_Item_molotov = false;
float Setting::Esp_Item_molotov_Color[4] = { 1.000f, 1.000f, 0.000f, 1.000f };
float Setting::Esp_Item_molotov_TextSize = 22.0f;

bool Setting::Esp_Item_tun = false;
float Setting::Esp_Item_tun_Color[4] = { 1.000f, 1.000f, 0.000f, 1.000f };
float Setting::Esp_Item_tun_TextSize = 22.0f;
////////////////////////////////////////////////////////////////////////////////////////









bool Setting::Esp_Item_AirDrop = false;
float Setting::Esp_Item_AirDrop_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_AirDrop_TextSize = 22.0f;

bool Setting::Esp_Item_GasCan = false;
float Setting::Esp_Item_GasCan_Color[4] = { 1.000f, 0.000f, 0.000f, 1.000f };
float Setting::Esp_Item_GasCan_TextSize = 22.0f;

bool Setting::Esp_Item_DeadBox = false;
float Setting::Esp_Item_DeadBox_Color[4] = { 1.000f, 0.000f, 1.000f, 1.000f };
float Setting::Esp_Item_DeadBox_TextSize = 22.0f;

//bool Setting::Esp_Item_Molotof = false;
//float Setting::Esp_Item_Molotof_Color[4] = { 1.00f, 0.20f, 0.70f, 1.0f };
//float Setting::Esp_Item_Molotof_TextSize = 20.0f;

bool Setting::Esp_Item_MedKit = false;
float Setting::Esp_Item_MedKit_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_MedKit_TextSize = 22.0f;

bool Setting::Esp_Item_FirstAidKit = false;
float Setting::Esp_Item_FirstAidKit_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_FirstAidKit_TextSize = 22.0f;

bool Setting::Esp_Item_Painkiller = false;
float Setting::Esp_Item_Painkiller_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_Painkiller_TextSize = 22.0f;

bool Setting::Esp_Item_EnergyDrink = false;
float Setting::Esp_Item_EnergyDrink_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_EnergyDrink_TextSize = 22.0f;

bool Setting::Esp_Item_AdrenalineSyringe = false;
float Setting::Esp_Item_AdrenalineSyringe_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_AdrenalineSyringe_TextSize = 22.0f;

bool Setting::Esp_Item_Bandage = false;
float Setting::Esp_Item_Bandage_Color[4] = { 1.000f, 0.753f, 0.796f, 1.000f };
float Setting::Esp_Item_Bandage_TextSize = 22.0f;

bool Setting::Esp_Item_FlareGun = false;
float Setting::Esp_Item_FlareGun_Color[4] = { 1.000f, 0.000f, 0.000f, 1.000f };
float Setting::Esp_Item_FlareGun_TextSize = 22.0f;

bool Setting::Esp_Item_Flare = false;
float Setting::Esp_Item_Flare_Color[4] = { 1.000f, 0.000f, 0.000f, 1.000f };
float Setting::Esp_Item_Flare_TextSize = 22.0f;

/////
bool Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QT_Sniper_Pickup_C = false;
float Setting::Esp_Item_BP_QT_Sniper_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QT_Sniper_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QT_A_Pickup_C = false;
float Setting::Esp_Item_BP_QT_A_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QT_A_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_DuckBill_Pickup_C = false;
float Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Choke_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Choke_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Choke_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QT_UZI_Pickup_C = false;
float Setting::Esp_Item_BP_QT_UZI_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QT_UZI_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C = false;
float Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_DJ_Large_E_Pickup_C = false;
float Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C = false;
float Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C = false;
float Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_LightGrip_Pickup_C = false;
float Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C = false;
float Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_Vertical_Pickup_C = false;
float Setting::Esp_Item_BP_WB_Vertical_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_WB_Vertical_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_Angled_Pickup_C = false;
float Setting::Esp_Item_BP_WB_Angled_Pickup_C_Color[4] = { 0.000f, 1.000f, 0.389f, 1.000f };
float Setting::Esp_Item_BP_WB_Angled_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WB_Lasersight_Pickup_C = false;
float Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[4] = { 0.000f, 0.682f, 1.000f, 1.000f };
float Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize = 22.0f;
float Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize2 = 30.0f;


bool Setting::Esp_Item_BP_WEP_Sickle_Pickup_C = false;
float Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WEP_Machete_Pickup_C = false;
float Setting::Esp_Item_BP_WEP_Machete_Pickup_C_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_BP_WEP_Machete_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C = false;
float Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_TextSize = 22.0f;

bool Setting::Esp_Item_BP_WEP_Pan_Pickup_C = false;
float Setting::Esp_Item_BP_WEP_Pan_Pickup_C_Color[4] = { 1.000f, 0.647f, 0.000f, 1.000f };
float Setting::Esp_Item_BP_WEP_Pan_Pickup_C_TextSize = 22.0f;











bool Setting::Esp_Item_test35 = false;
float Setting::Esp_Item_test35_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test35_TextSize = 22.0f;

bool Setting::Esp_Item_test36 = false;
float Setting::Esp_Item_test36_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test36_TextSize = 22.0f;

bool Setting::Esp_Item_test37 = false;
float Setting::Esp_Item_test37_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test37_TextSize = 22.0f;

bool Setting::Esp_Item_test38 = false;
float Setting::Esp_Item_test38_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test38_TextSize = 22.0f;

bool Setting::Esp_Item_test39 = false;
float Setting::Esp_Item_test39_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test39_TextSize = 22.0f;

bool Setting::Esp_Item_test40 = false;
float Setting::Esp_Item_test40_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test40_TextSize = 22.0f;

bool Setting::Esp_Item_test41 = false;
float Setting::Esp_Item_test41_Color[4] = { 1.00f, 0.96f, 0.56f, 1.0f };
float Setting::Esp_Item_test41_TextSize = 22.0f;

bool Setting::Esp_Item_test42 = false;
float Setting::Esp_Item_test42_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test42_TextSize = 22.0f;

bool Setting::Esp_Item_test43 = false;
float Setting::Esp_Item_test43_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test43_TextSize = 20.0f;

bool Setting::Esp_Item_test44 = false;
float Setting::Esp_Item_test44_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test44_TextSize = 22.0f;

bool Setting::Esp_Item_test45 = false;
float Setting::Esp_Item_test45_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test45_TextSize = 22.0f;



bool Setting::Esp_Item_Bow = false;
float Setting::Esp_Item_Bow_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_Bow_TextSize = 22.0f;



bool Setting::Esp_Item_test46 = false;
float Setting::Esp_Item_test46_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test46_TextSize = 22.0f;

bool Setting::Esp_Item_test47 = false;
float Setting::Esp_Item_test47_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test47_TextSize = 22.0f;

bool Setting::Esp_Item_test48 = false;
float Setting::Esp_Item_test48_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test48_TextSize = 22.0f;

bool Setting::Esp_Item_test49 = false;
float Setting::Esp_Item_test49_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test49_TextSize = 22.0f;

bool Setting::Esp_Item_test50 = false;
float Setting::Esp_Item_test50_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test50_TextSize = 22.0f;


/////////////////////////////////////////////////


bool Setting::Esp_Item_test51 = false;
float Setting::Esp_Item_test51_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test51_TextSize = 22.0f;

bool Setting::Esp_Item_test52 = false;
float Setting::Esp_Item_test52_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test52_TextSize = 22.0f;

bool Setting::Esp_Item_test53 = false;
float Setting::Esp_Item_test53_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test53_TextSize = 22.0f;

bool Setting::Esp_Item_test54 = false;
float Setting::Esp_Item_test54_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test54_TextSize = 22.0f;

bool Setting::Esp_Item_test55 = false;
float Setting::Esp_Item_test55_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test55_TextSize = 22.0f;

bool Setting::Esp_Item_test56 = false;
float Setting::Esp_Item_test56_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test56_TextSize = 22.0f;

bool Setting::Esp_Item_test57 = false;
float Setting::Esp_Item_test57_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test57_TextSize = 22.0f;

bool Setting::Esp_Item_test58 = false;
float Setting::Esp_Item_test58_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test58_TextSize = 22.0f;

bool Setting::Esp_Item_test59 = false;
float Setting::Esp_Item_test59_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test59_TextSize = 22.0f;

bool Setting::Esp_Item_test60 = false;
float Setting::Esp_Item_test60_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test60_TextSize = 22.0f;

bool Setting::Esp_Item_test61 = false;
float Setting::Esp_Item_test61_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test61_TextSize = 22.0f;

bool Setting::Esp_Item_test62 = false;
float Setting::Esp_Item_test62_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test62_TextSize = 22.0f;

bool Setting::Esp_Item_test63 = false;
float Setting::Esp_Item_test63_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test63_TextSize = 22.0f;

bool Setting::Esp_Item_test64 = false;
float Setting::Esp_Item_test64_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test64_TextSize = 22.0f;

bool Setting::Esp_Item_test65 = false;
float Setting::Esp_Item_test65_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test65_TextSize = 22.0f;

bool Setting::Esp_Item_test66 = false;
float Setting::Esp_Item_test66_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test66_TextSize = 22.0f;

bool Setting::Esp_Item_test67 = false;
float Setting::Esp_Item_test67_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test67_TextSize = 22.0f;

bool Setting::Esp_Item_test68 = false;
float Setting::Esp_Item_test68_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test68_TextSize = 22.0f;

bool Setting::Esp_Item_test69 = false;
float Setting::Esp_Item_test69_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test69_TextSize = 22.0f;

bool Setting::Esp_Item_test70 = false;
float Setting::Esp_Item_test70_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test70_TextSize = 22.0f;

bool Setting::Esp_Item_test71 = false;
float Setting::Esp_Item_test71_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test71_TextSize = 22.0f;


bool Setting::Esp_Item_test72 = false;
float Setting::Esp_Item_test72_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test72_TextSize = 22.0f;


bool Setting::Esp_Item_test73 = false;
float Setting::Esp_Item_test73_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test73_TextSize = 22.0f;


bool Setting::Esp_Item_test74 = false;
float Setting::Esp_Item_test74_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test74_TextSize = 22.0f;


bool Setting::Esp_Item_test75 = false;
float Setting::Esp_Item_test75_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test75_TextSize = 22.0f;


bool Setting::Esp_Item_test76 = false;
float Setting::Esp_Item_test76_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test76_TextSize = 22.0f;


bool Setting::Esp_Item_test77 = false;
float Setting::Esp_Item_test77_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test77_TextSize = 22.0f;


bool Setting::Esp_Item_test78 = false;
float Setting::Esp_Item_test78_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test78_TextSize = 22.0f;


bool Setting::Esp_Item_test79 = false;
float Setting::Esp_Item_test79_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test79_TextSize = 22.0f;

bool Setting::Esp_Item_test80 = false;
float Setting::Esp_Item_test80_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test80_TextSize = 22.0f;


bool Setting::Esp_Item_test81 = false;
float Setting::Esp_Item_test81_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test81_TextSize = 22.0f;


bool Setting::Esp_Item_test82 = false;
float Setting::Esp_Item_test82_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test82_TextSize = 22.0f;

bool Setting::Esp_Item_test83 = false;
float Setting::Esp_Item_test83_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test83_TextSize = 22.0f;

bool Setting::Esp_Item_test84 = false;
float Setting::Esp_Item_test84_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test84_TextSize = 22.0f;

bool Setting::Esp_Item_test85 = false;
float Setting::Esp_Item_test85_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test85_TextSize = 22.0f;

bool Setting::Esp_Item_test86 = false;
float Setting::Esp_Item_test86_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test86_TextSize = 22.0f;

bool Setting::Esp_Item_test87 = false;
float Setting::Esp_Item_test87_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test87_TextSize = 22.0f;

bool Setting::Esp_Item_test88 = false;
float Setting::Esp_Item_test88_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test88_TextSize = 22.0f;

bool Setting::Esp_Item_test89 = false;
float Setting::Esp_Item_test89_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test89_TextSize = 22.0f;

bool Setting::Esp_Item_test90 = false;
float Setting::Esp_Item_test90_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test90_TextSize = 22.0f;

bool Setting::Esp_Item_test91 = false;
float Setting::Esp_Item_test91_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test91_TextSize = 22.0f;

bool Setting::Esp_Item_test92 = false;
float Setting::Esp_Item_test92_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test92_TextSize = 22.0f;

bool Setting::Esp_Item_test93 = false;
float Setting::Esp_Item_test93_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test93_TextSize = 22.0f;


bool Setting::Esp_Item_test94 = false;
float Setting::Esp_Item_test94_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test94_TextSize = 22.0f;

bool Setting::Esp_Item_test95 = false;
float Setting::Esp_Item_test95_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test95_TextSize = 22.0f;

bool Setting::Esp_Item_test96 = false;
float Setting::Esp_Item_test96_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test96_TextSize = 22.0f;

bool Setting::Esp_Item_test97 = false;
float Setting::Esp_Item_test97_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test97_TextSize = 22.0f;

bool Setting::Esp_Item_test98 = false;
float Setting::Esp_Item_test98_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test98_TextSize = 22.0f;

bool Setting::Esp_Item_test99 = false;
float Setting::Esp_Item_test99_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test99_TextSize = 22.0f;

bool Setting::Esp_Item_test100 = false;
float Setting::Esp_Item_test100_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test100_TextSize = 20.0f;

bool Setting::Esp_Item_test101 = false;
float Setting::Esp_Item_test101_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
float Setting::Esp_Item_test101_TextSize = 22.0f;

//bool Setting::Esp_Item_test102 = false;
//float Setting::Esp_Item_test102_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
//float Setting::Esp_Item_test102_TextSize = 20.0f;
//
//bool Setting::Esp_Item_test103 = false;
//float Setting::Esp_Item_test103_Color[4] = { 1.000f, 1.000f, 1.000f, 1.000f };
//float Setting::Esp_Item_test103_TextSize = 20.0f;






















///Color_1

bool Setting::Aimbot = false;
bool Setting::Aimbullet = false;

float Setting::instantPower = 1000.0f;
float Setting::fastRunPower = 100.0f;
float Setting::speedCarPower = 320.0f;
float Setting::flyCarPower = 28000.0f;
//float Setting::SXZ = 1.0f;
float Setting::ZoomValue = 1;
float Setting::view = 220.0f;
float Setting::Ipad_manager = 360.0f;
float Setting::FPS = 120;

float Setting::ipadview = 1.0f;
float Setting::BaseIpadView = 1.0f;

float Setting::SXZ = 1.0f;
int Setting::XFov = 220;

bool Setting::MagicBullet = false;
bool Setting::CameraCache = false;
bool Setting::BypassFovLimit = false;
//bool Setting::Magic_Bullet = false;
bool Setting::silent = false;

bool Setting::textborder = false;
bool Setting::fake = false;
bool Setting::CameraCatch = false;

//bool plr_wpn = false;


bool Setting::fragwarning = false;
bool Setting::smokewarning = false;
bool Setting::apple = false;
bool Setting::molotovwarning = false;
bool Setting::tunwarning = false;

bool Setting::BodyRandom = false;
bool Setting::HeadRandom = false;
bool Setting::GrassLobby = false;

ImVec4 Color::smokewarning = { 1.000f, 1.000f, 1.000f, 1.000f };
ImVec4 Color::fragwarning = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 Color::molotovwarning = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 Color::tunwarning = { 1.000f, 0.000f, 0.000f, 1.000f };
ImVec4 Color::TESTTTTT;//{ 255, 255, 255, 255 };
ImVec4 text_color;
bool Setting::magicb = false;

//int     Setting::magicv = 7;
float   Setting::flycarv = 300.0f;
float   Setting::instantv = 1.0f;


float Setting::testfuckencolor[4] = { 1.0f, 0.0f ,0.0f ,1.0f };
float Setting::testfuckencolor2[4] = { 1.0f, 1.0f ,1.0f ,1.0f };

float Setting::Xspeedd = 5.0f;
int   Setting::disaplememorytime = 1;
float   Setting::SpeedFire = 100.0f;
float   Setting::highjump = 048.0f;
float   Setting::carsv = 280.0f;
float	Setting::fastrv = 479.500f;
int	Setting::fastparaaa = 650;
float	Setting::fastrv_2 = 12.000f;
float	Setting::fastrv_3 = 0.005;
float	Setting::fastrv_4 = 1.000f;
float	Setting::fastrv_5 = 23.0f;
float	Setting::jumpvalue = 30.0f;
float	Setting::fastrv_5M = 0.300f;
float	Setting::testXeffectt = 1.0f;
float Setting::Bar = 0.0f;
int FknBorderMsgCol = 0;
int Setting::SpeedShoot = 0;
int Setting::NoGrassValue = 10;

int	Setting::Test55 = 10;
int	Setting::Magic_Bullet = 1;
int Setting::SelectorV3 = 0;
int Setting::SelectorV5 = 0;
int Setting::SelectorGrass = 0;
int Setting::RecSelector = 0;
int Setting::RecSelector2 = 0;
int Setting::Headselctor = 0;
int Setting::jmp = 0;

std::string GetBoxItems(int code)
{
    if (code == 101008)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
        return "M762";
    }
    else if (code == 306001)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Magnum_Color[0], Setting::Esp_Item_Magnum_Color[1], Setting::Esp_Item_Magnum_Color[2], Setting::Esp_Item_Magnum_Color[3]);
        return "Magnum";
    }

    else if (code == 101003)
    {
        Setting::sizecode = Setting::Esp_Item_SCARL_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_SCARL_Color[0], Setting::Esp_Item_SCARL_Color[1], Setting::Esp_Item_SCARL_Color[2], Setting::Esp_Item_SCARL_Color[3]);
        return "SCAR-L";
    }
    else if (code == 302001)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]);
        return "7.62";
    }
    else if (code == 303001)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]);
        return "5.56";
    }
    else if (code == 602004)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Frag_Color[0], Setting::Esp_Item_Frag_Color[1], Setting::Esp_Item_Frag_Color[2], Setting::Esp_Item_Frag_Color[3]);
        return "Grenade";
    }
    else if (code == 601006)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]);
        return "Medkit";
    }
    else if (code == 101004)
    {
        Setting::sizecode = Setting::Esp_Item_M416_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M416_Color[0], Setting::Esp_Item_M416_Color[1], Setting::Esp_Item_M416_Color[2], Setting::Esp_Item_M416_Color[3]);
        return "M416";
    }

    else if (code == 101010)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]);
        return "G36C";
    }

    else if (code == 101006)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_AUG_Color[0], Setting::Esp_Item_AUG_Color[1], Setting::Esp_Item_AUG_Color[2], Setting::Esp_Item_AUG_Color[3]);
        return "AUG";
    }

    //else if (code == 101101)
    //{
    //  Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
    //  return "ASM"; //time
    //}

    else if (code == 101001)
    {
        Setting::sizecode = Setting::Esp_Item_AKM_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]);
        return "AKM";
    }

    else if (code == 101005)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Groza_Color[0], Setting::Esp_Item_Groza_Color[1], Setting::Esp_Item_Groza_Color[2], Setting::Esp_Item_Groza_Color[3]);
        return "Groza";
    }

    else if (code == 103003)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Awm_Color[0], Setting::Esp_Item_Awm_Color[1], Setting::Esp_Item_Awm_Color[2], Setting::Esp_Item_Awm_Color[3]);
        return "AWM";
    }

    else if (code == 103002)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M24_Color[0], Setting::Esp_Item_M24_Color[1], Setting::Esp_Item_M24_Color[2], Setting::Esp_Item_M24_Color[3]);
        return "M24";
    }

    else if (code == 103001)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Kar98k_Color[0], Setting::Esp_Item_Kar98k_Color[1], Setting::Esp_Item_Kar98k_Color[2], Setting::Esp_Item_Kar98k_Color[3]);
        return "Kar98k";
    }

    else if (code == 103011)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Mosin_Color[0], Setting::Esp_Item_Mosin_Color[1], Setting::Esp_Item_Mosin_Color[2], Setting::Esp_Item_Mosin_Color[3]);
        return "Mosin";
    }

    else if (code == 502002)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]);
        return "Helmet Lv.2";
    }

    else if (code == 502003)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]);
        return "Helmet Lv.3";
    }

    else if (code == 503002)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]);
        return "Armor Lv.2";
    }

    else if (code == 503003)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]);
        return "Armor Lv.3";
    }

    else if (code == 501005)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]);
        return "Bag Lv.2";
    }

    else if (code == 501006)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]);
        return "Bag Lv.3";
    }

    else if (code == 203014)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]);
        return "3x scope";

    }

    else if (code == 203004)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]);
        return "4x scope";
    }

    else if (code == 203015)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]);
        return "6x scope";
    }

    else if (code == 203005)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]);
        return "8x scope";
    }

    else if (code == 106007)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_FlareGun_Color[0], Setting::Esp_Item_FlareGun_Color[1], Setting::Esp_Item_FlareGun_Color[2], Setting::Esp_Item_FlareGun_Color[3]);
        return "Flaregun";
    }

    else if (code == 105001)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M249_Color[0], Setting::Esp_Item_M249_Color[1], Setting::Esp_Item_M249_Color[2], Setting::Esp_Item_M249_Color[3]);
        return "M249";
    }

    else if (code == 105002)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]);
        return "DP28";
    }

    else if (code == 105010)
    {
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
        return "MG3";
    }

    return "tatti";
}

string GetItemType(string Name)
{
    if (Setting::Esp_Item_Awm) if (Name.find("BP_Sniper_AWM_Wrapper_C") != string::npos) return "AWM";
    if (Setting::Esp_Item_QBU) if (Name.find("BP_Sniper_QBU_Wrapper_C") != string::npos) return "QBU";
    if (Setting::Esp_Item_SLR) if (Name.find("BP_Sniper_SLR_Wrapper_C") != string::npos) return "SLR";
    if (Setting::Esp_Item_SKS) if (Name.find("BP_Sniper_SKS_Wrapper_C") != string::npos) return "SKS";
    if (Setting::Esp_Item_Mini14) if (Name.find("BP_Sniper_Mini14_Wrapper_C") != string::npos) return "Mini-14";
    if (Setting::Esp_Item_M24) if (Name.find("BP_Sniper_M24_Wrapper_C") != string::npos) return "M24";
    if (Setting::Esp_Item_Kar98k) if (Name.find("BP_Sniper_Kar98k_Wrapper_C") != string::npos) return "Kar98k";
    if (Setting::Esp_Item_VSS) if (Name.find("BP_Sniper_VSS_Wrapper_C") != string::npos) return "VSS";
    if (Setting::Esp_Item_Win94) if (Name.find("BP_Sniper_Win94_Wrapper_C") != string::npos) return "Win94";
    if (Setting::Esp_Item_Mosin) if (Name.find("BP_Sniper_Mosin_Wrapper_C") != string::npos) return "Mosin";
    if (Setting::Esp_Item_M762) if (Name.find("BP_Rifle_M762_Wrapper_C") != string::npos) return "M762";
    if (Setting::Esp_Item_SCARL) if (Name.find("BP_Rifle_SCAR_Wrapper_C") != string::npos) return "SCAR-L";
    if (Setting::Esp_Item_M416) if (Name.find("BP_Rifle_M416_Wrapper_C") != string::npos) return "M416";
    if (Setting::Esp_Item_M16A4) if (Name.find("BP_Rifle_M16A4_Wrapper_C") != string::npos) return "M16A4";
    if (Setting::Esp_Item_Mk47Mutant) if (Name.find("BP_Rifle_Mk47_Wrapper_C") != string::npos) return "Mk47";
    if (Setting::Esp_Item_G36C) if (Name.find("BP_Rifle_G36_Wrapper_C") != string::npos) return "G36C";
    if (Setting::Esp_Item_QBZ) if (Name.find("BP_Rifle_QBZ_Wrapper_C") != string::npos) return "QBZ";
    if (Setting::Esp_Item_AKM) if (Name.find("BP_Rifle_AKM_Wrapper_C") != std::string::npos) return "AKM";
    if (Setting::Esp_Item_Groza) if (Name.find("BP_Rifle_Groza_Wrapper_C") != std::string::npos) return "Groza";
    if (Setting::Esp_Item_AUG) if (Name.find("BP_Rifle_AUG_Wrapper_C") != std::string::npos) return "AUG";
    if (Setting::Esp_Item_S12K) if (Name.find("BP_ShotGun_S12K_Wrapper_C") != std::string::npos) return "S12K";
    if (Setting::Esp_Item_M1014) if (Name.find("BP_ShotGun_M1014_Wrapper_C") != std::string::npos) return "M1014";
    if (Setting::Esp_Item_DBS) if (Name.find("BP_ShotGun_DP12_Wrapper_C") != std::string::npos) return "DBS";
    if (Setting::Esp_Item_S686) if (Name.find("BP_ShotGun_S686_Wrapper_C") != std::string::npos) return "S686";
    if (Setting::Esp_Item_S1897) if (Name.find("BP_ShotGun_S1897_Wrapper_C") != std::string::npos) return "S1897";
    if (Setting::Esp_Item_SawedOff) if (Name.find("BP_ShotGun_SawedOff_Wrapper_C") != std::string::npos) return "SawedOff";
    if (Setting::Esp_Item_PP19) if (Name.find("BP_MachineGun_PP19_Wrapper_C") != string::npos) return "PP19";
    if (Setting::Esp_Item_TommyGun) if (Name.find("BP_MachineGun_TommyGun_Wrapper_C") != string::npos) return "Tommy Gun";
    if (Setting::Esp_Item_MP5K) if (Name.find("BP_MachineGun_MP5K_Wrapper_C") != string::npos) return "MP5K";
    if (Setting::Esp_Item_UMP9) if (Name.find("BP_MachineGun_UMP9_Wrapper_C") != string::npos) return "UMP9";
    if (Setting::Esp_Item_Vector) if (Name.find("BP_MachineGun_Vector_Wrapper_C") != string::npos) return "Vector";
    if (Setting::Esp_Item_Uzi) if (Name.find("BP_MachineGun_Uzi_Wrapper_C") != string::npos) return "Uzi";
    if (Setting::Esp_Item_R1895) if (Name.find("BP_Pistol_R1895_Wrapper_C") != string::npos) return "R1895";
    if (Setting::Esp_Item_Vz61) if (Name.find("BP_Pistol_Vz61_Wrapper_C") != string::npos) return "Vz61";
    if (Setting::Esp_Item_P92) if (Name.find("BP_Pistol_P92_Wrapper_C") != string::npos) return "P92";
    if (Setting::Esp_Item_P18C) if (Name.find("BP_Pistol_P18C_Wrapper_C") != string::npos) return "P18C";
    if (Setting::Esp_Item_R45) if (Name.find("BP_Pistol_R45_Wrapper_C") != string::npos) return "R45";
    if (Setting::Esp_Item_P1911) if (Name.find("BP_Pistol_P1911_Wrapper_C") != string::npos) return "P1911";
    if (Setting::Esp_Item_DesertEagle) if (Name.find("BP_Pistol_DesertEagle_Wrapper_C") != string::npos) return "DesertEagle";
    if (Setting::Esp_Item_Mk14) if (Name.find("BP_WEP_Mk14_Pickup_C") != string::npos) return "Mk14";
    if (Setting::Esp_Item_762mm) if (Name.find("BP_Ammo_762mm_Pickup_C") != string::npos) return "7.62";
    if (Setting::Esp_Item_45ACP) if (Name.find("BP_Ammo_45ACP_Pickup_C") != string::npos) return "45ACP";
    if (Setting::Esp_Item_556mm) if (Name.find("BP_Ammo_556mm_Pickup_C") != string::npos) return "5.56";
    if (Setting::Esp_Item_9mm) if (Name.find("BP_Ammo_9mm_Pickup_C") != string::npos) return "9mm";
    if (Setting::Esp_Item_Magnum) if (Name.find("BP_Ammo_300Magnum_Pickup_C") != std::string::npos) return "Magnum";
    if (Setting::Esp_Item_12Guage) if (Name.find("BP_Ammo_12Guage_Pickup_C") != std::string::npos) return "12Guage";
    if (Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C) if (Name.find("BP_QK_Mid_FlashHider_Pickup_C") != std::string::npos) return "Flash Hider (SMG)";
    if (Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C) if (Name.find("BP_QK_Large_FlashHider_Pickup_C") != std::string::npos) return "Flash Hider (AR)";
    if (Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C) if (Name.find("BP_QK_Large_Compensator_Pickup_C") != std::string::npos) return "Compensator (AR)";
    if (Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C) if (Name.find("BP_QK_Mid_Compensator_Pickup_C") != std::string::npos) return "Compensator (SMG)";
    if (Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C) if (Name.find("BP_QK_Sniper_FlashHider_Pickup_C") != std::string::npos) return "Flash Hider (Sniper)";
    if (Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C) if (Name.find("BP_QK_Mid_Suppressor_Pickup_C") != std::string::npos) return "Suppressor (SMG)";
    if (Setting::Esp_Item_BP_QT_Sniper_Pickup_C) if (Name.find("BP_QT_Sniper_Pickup_C") != std::string::npos) return "Chekpad (Sniper)";
    if (Setting::Esp_Item_BP_QT_A_Pickup_C) if (Name.find("BP_QT_A_Pickup_C") != std::string::npos) return "Tactical Stock";
    if (Setting::Esp_Item_BP_QK_DuckBill_Pickup_C) if (Name.find("BP_QK_DuckBill_Pickup_C") != std::string::npos) return "Duckbill";
    if (Setting::Esp_Item_BP_QK_Choke_Pickup_C) if (Name.find("BP_QK_Choke_Pickup_C") != std::string::npos) return "Choke";
    if (Setting::Esp_Item_BP_QT_UZI_Pickup_C) if (Name.find("BP_QT_UZI_Pickup_C") != std::string::npos) return "Stock";
    if (Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C) if (Name.find("BP_QK_Sniper_Compensator_Pickup_C") != std::string::npos) return "Compensator (Sniper)";
    if (Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C) if (Name.find("BP_QK_Sniper_Suppressor_Pickup_C") != std::string::npos) return "Suppressor (Sniper)";
    if (Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C) if (Name.find("BP_QK_Large_Suppressor_Pickup_C") != std::string::npos) return "Suppressor (AR)";
    if (Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C) if (Name.find("BP_DJ_Sniper_EQ_Pickup_C") != std::string::npos) return "Extended Quickdraw Mag (Sniper)";
    if (Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C) if (Name.find("BP_DJ_Mid_E_Pickup_C") != std::string::npos) return "Extended Mag (SMG)";
    if (Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C) if (Name.find("BP_DJ_Mid_Q_Pickup_C") != std::string::npos) return "Quickdraw Mag (SMG)";
    if (Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C) if (Name.find("BP_DJ_Mid_EQ_Pickup_C") != std::string::npos) return "Extended Quickdraw Mag (SMG)";
    if (Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C) if (Name.find("BP_DJ_Sniper_E_Pickup_C") != std::string::npos) return "Extended Mag (Sniper)";
    if (Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C) if (Name.find("BP_DJ_Sniper_Q_Pickup_C") != std::string::npos) return "Quickdraw Mag (Sniper)";
    if (Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C) if (Name.find("BP_DJ_Large_Q_Pickup_C") != std::string::npos) return "Quickdraw Mag (AR)";
    if (Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C) if (Name.find("BP_DJ_Large_EQ_Pickup_C") != std::string::npos) return "Extended Quickdraw Mag (AR)";
    if (Setting::Esp_Item_BP_DJ_Large_E_Pickup_C) if (Name.find("BP_DJ_Large_E_Pickup_C") != std::string::npos) return "Extended Mag (AR)";
    if (Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C) if (Name.find("BP_ZDD_Sniper_Pickup_C") != std::string::npos) return "Mermilik";
    if (Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C) if (Name.find("BP_WB_ThumbGrip_Pickup_C") != std::string::npos) return "ThumbGrip";
    if (Setting::Esp_Item_BP_WB_LightGrip_Pickup_C) if (Name.find("BP_WB_LightGrip_Pickup_C") != std::string::npos) return "LightGrip";
    if (Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C) if (Name.find("BP_WB_HalfGrip_Pickup_C") != std::string::npos) return "HalfGrip";
    if (Setting::Esp_Item_BP_WB_Vertical_Pickup_C) if (Name.find("BP_WB_Vertical_Pickup_C") != std::string::npos) return "Vertical Foregrip";
    if (Setting::Esp_Item_BP_WB_Angled_Pickup_C) if (Name.find("BP_WB_Angled_Pickup_C") != std::string::npos) return "Angled Foregrip";
    if (Setting::Esp_Item_BP_WB_Lasersight_Pickup_C) if (Name.find("BP_WB_Lasersight_Pickup_C") != string::npos) return "Lasersight";

   // if (Setting::Esp_Item_BP_WB_Lasersight_Pickup_C) if (Name.find("GoldenTokenWrapper_C") != string::npos) return "GoldenTokenWrapper_C";

    if (Setting::Esp_Item_BP_WEP_Sickle_Pickup_C) if (Name.find("BP_WEP_Sickle_Pickup_C") != string::npos) return "Sickle";
    if (Setting::Esp_Item_BP_WEP_Machete_Pickup_C) if (Name.find("BP_WEP_Machete_Pickup_C") != string::npos) return "Machete";
    if (Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C) if (Name.find("BP_WEP_Cowbar_Pickup_C") != string::npos) return "Levye";
    if (Setting::Esp_Item_BP_WEP_Pan_Pickup_C) if (Name.find("BP_WEP_Pan_Pickup_C") != string::npos) return "Pan";


    if (Setting::Esp_Item_Holo) if (Name.find("BP_MZJ_QX_Pickup_C") != string::npos) return "Holo";
    if (Setting::Esp_Item_RedDot) if (Name.find("BP_MZJ_HD_Pickup_C") != string::npos) return "Red Dot";
    if (Setting::Esp_Item_x2) if (Name.find("BP_MZJ_2X_Pickup_C") != string::npos) return "2x scope";
    if (Setting::Esp_Item_x3) if (Name.find("BP_MZJ_3X_Pickup_C") != string::npos) return "3x scope";
    if (Setting::Esp_Item_x4) if (Name.find("BP_MZJ_4X_Pickup_C") != string::npos) return "4x scope";
    if (Setting::Esp_Item_x6) if (Name.find("BP_MZJ_6X_Pickup_C") != string::npos) return "6x scope";
    if (Setting::Esp_Item_x8) if (Name.find("BP_MZJ_8X_Pickup_C") != string::npos) return "8x scope";


    if (Setting::Esp_Item_DP28) if (Name.find("BP_Other_DP28_Wrapper_C") != string::npos) return "DP28";
    if (Setting::Esp_Item_CrossBow) if (Name.find("BP_Other_CrossBow_Wrapper_C") != string::npos) return "CrossBow";
    if (Setting::Esp_Item_M249) if (Name.find("BP_Other_M249_Wrapper_C") != std::string::npos)return "M249";


    if (Setting::Esp_Item_Helmet1) if (Name.find("PickUp_BP_Helmet_Lv1") != string::npos) return "Helmet lv.1";
    if (Setting::Esp_Item_Helmet2) if (Name.find("PickUp_BP_Helmet_Lv2") != string::npos) return "Helmet lv.2";
    if (Setting::Esp_Item_Helmet3) if (Name.find("PickUp_BP_Helmet_Lv3") != string::npos) return "Helmet lv.3";


    if (Setting::Esp_Item_Armor1) if (Name.find("PickUp_BP_Armor_Lv1") != string::npos) return "Armor lv.1";
    if (Setting::Esp_Item_Armor2) if (Name.find("PickUp_BP_Armor_Lv2") != string::npos) return "Armor lv.2";
    if (Setting::Esp_Item_Armor3) if (Name.find("PickUp_BP_Armor_Lv3") != string::npos) return "Armor lv.3";



    if (Setting::Esp_Item_Bag1) if (Name.find("PickUp_BP_Bag_Lv1") != string::npos) return "Bag lv.1";
    if (Setting::Esp_Item_Bag2) if (Name.find("PickUp_BP_Bag_Lv2") != string::npos) return "Bag lv.2";
    if (Setting::Esp_Item_Bag3) if (Name.find("PickUp_BP_Bag_Lv3") != string::npos) return "Bag lv.3";



    if (Setting::Esp_Item_Mk12) if (Name.find("BP_Other_MK12_Wrapper_C") != std::string::npos)return "MK12";
    if (Setting::Esp_Item_FlareGun) if (Name.find("BP_Pistol_Flaregun_Wrapper_C") != string::npos) return "Flare Gun";
    if (Setting::Esp_Item_Flare) if (Name.find("BP_Ammo_Flare_Pickup_C") != string::npos) return "Flare";



    if (Setting::Esp_Item_MedKit) if (Name.find("FirstAidbox_Pickup_C") != string::npos) return "Med Kit";
    if (Setting::Esp_Item_FirstAidKit) if (Name.find("Firstaid_Pickup_C") != string::npos) return "First Aid Kit";
    if (Setting::Esp_Item_Painkiller) if (Name.find("Pills_Pickup_C") != string::npos) return "Painkiller";
    if (Setting::Esp_Item_EnergyDrink) if (Name.find("Drink_Pickup_C") != string::npos) return "Energy Drink";
    if (Setting::Esp_Item_AdrenalineSyringe) if (Name.find("Injection_Pickup_C") != string::npos) return "Adrenaline Syringe";
    if (Setting::Esp_Item_Bandage) if (Name.find("Bandage_Pickup_C") != string::npos) return "Bandage";



    if (Setting::Esp_Item_Frag) if (Name.find("BP_Grenade_Shoulei_Weapon_Wrapper_C") != string::npos) return "Frag Grenade";
    if (Setting::Esp_Item_molotov) if (Name.find("BP_Grenade_Burn_Weapon_Wrapper_C") != string::npos) return "Molotof Grenade";
    if (Setting::Esp_Item_Smoke) if (Name.find("BP_Grenade_Smoke_Weapon_Wrapper_C") != string::npos) return "Smoke Grenade";
    if (Setting::Esp_Item_tun) if (Name.find("BP_Grenade_tun_Weapon_Wrapper_C") != string::npos) return "Tun Grenade";

    //if (Setting::smokewarning) if (Name.find("BP_Grenade_Smoke_C") != string::npos) return "Smoke_Grenade";
    //if (Setting::molotovwarning)  if (Name.find("BP_Grenade_Burn_C") != std::string::npos)return "Burn_Grenade";
    //if (Setting::fragwarning) if (Name.find("BP_Grenade_Shoulei_C") != string::npos) return "Frag_Grenade";
    //if (Setting::tunwarning) if (Name.find("BP_Grenade_tun_C") != string::npos) return "Tun_Grenade";

    //if (Setting::apple)   if (Name.find("BP_Grenade_Apple_Weapon_Wrapper_C") != std::string::npos)return "Apple";
    if (Setting::Esp_Item_GasCan) if (Name.find("GasCan_Destructible_Pickup_C") != string::npos) return "GasCan";
    if (Setting::Esp_Item_AirDrop) if (Name.find("BP_AirDropBox_C") != string::npos) return "Air Drop";
    if (Setting::Esp_Item_AirDrop) if (Name.find("BP_AirDropBox_New_C") != string::npos) return "Air Drop";
    if (Setting::Esp_Item_DeadBox) if (Name.find("GoldenTokenWrapper_C") != string::npos) return "Golden Token";
    if (Config.ESPMenu.RedZone) if (Name.find("BP_AirAttack_C") != string::npos) return "RedZone";
    if (Config.ESPMenu.RedZone) if (Name.find("AirAttackBomb_Livik_C") != string::npos) return "RedZone";
    if (Config.ESPMenu.BlueZone) if (Name.find("BP_radiation") != string::npos) return "SafeZone";



    if (Setting::Esp_Item_Event) if (Name.find("BP_RiteTreasureBox_") || Name.find("BP_Halloween4_Chest_Baltic_BigPoi_") || Name.find("BP_TreasureBox_Level3_") != string::npos) return "Treasure Box";



    return "Unknown";
}
