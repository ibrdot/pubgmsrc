
//
// Created by Administrator on 3/4/2024.
//

#ifndef MRTHANG_SKIN_DATA_H
#define MRTHANG_SKIN_DATA_H
#pragma once
#include <iostream>
#include <vector>
#include <string>

typedef unsigned long DWORD;

class CModBase {};

class CWeapAttack : public CModBase {
public:
    DWORD Default = 0;
};

class CGunSkinSetting : public CModBase {
public:
    DWORD AKM = 1101001213, M16A4 = 1101002081, SCARL = 1101003188, M416 = 1101004046, GROZA = 1101005052,
          AUG = 1101006062, QBZ = 1101007046, M762 = 1101008126, HONEY = 0, ACE32 = 1101102017,
          UZI = 1102001024, UMP45 = 1102002136, VECTOR = 1102003080, TOMMY = 1102004018, PP19 = 1102005057,
          KAR98 = 1103001179, M24 = 1103002087, AWM = 1103003062, MINI14 = 1103006030, MK14 = 1103007020,
          AMR = 1103012010, M249 = 1105001048, DP28 = 1105002063, MG3 = 1101102017, DBS = 1104101001,
          S12K = 1104003027, XM1014 = 1104101001, PAN = 1108004356, KNIFE = 1108001057, KNIFE1 = 1108005050,
          P90 = 1102105012;
};

class CClothSetting : public CModBase {
public:
    DWORD SHIRT = 1405628, HAT = 0, PANT = 0, SHOE = 0, PARACHUTE = 0, HELMET1 = 1502001023,
          BACKPACK1 = 1501001220, HELMET2 = 1502002023, BACKPACK2 = 1501002220, HELMET3 = 1502003023,
          BACKPACK3 = 1501003220, GLIDER = 0;
};

class CVehicleSetting : public CModBase {
public:
    DWORD MOTOR = 1901047, COUPE = 1961015, UAZ = 1908067, DACIA = 1903075, MIRADO = 1915010, BUGGY = 1907054;
};

class CModSkinSetting {
public:
    DWORD dwPassword = 0xBEEF;
    bool bEnable = false, bGunSkin = false, bClothSkin = false, bVehicleSkin = false, bKillMsg = false, bDeadbox = false;
    CGunSkinSetting* gun;
    CClothSetting* cloth;
    CVehicleSetting* vehicle;

    CModSkinSetting() {
        gun = new CGunSkinSetting();
        cloth = new CClothSetting();
        vehicle = new CVehicleSetting();
    }

    ~CModSkinSetting() {
        delete gun;
        delete cloth;
        delete vehicle;
    }
};

static CModSkinSetting skin;

struct FSkinItem {
    std::string name;
    DWORD value;
    FSkinItem(std::string n, DWORD v) : name(std::move(n)), value(v) {}
    std::string ToStructString() const { return std::to_string(value); }
};

class CSkinsInfo {
public:
    DWORD* out = nullptr;
    bool bFirstInit = false;
    int current_index = 0;
    std::vector<FSkinItem> items;

    CSkinsInfo() = default;

    void Init(std::vector<FSkinItem> _items, DWORD* _out) {
        out = _out;
        items = std::move(_items);
        if (out && !items.empty()) {
            *out = items[0].value;
        }
    }

    DWORD At(int index) const { return (index < items.size()) ? items[index].value : 0; }
    DWORD Get() const { return At(current_index); }
};

class SkinData {
public:
    CSkinsInfo m416, m16, akm, scarl, aug, m762, groza, ace32, honey, qbz,
               ump45, vector, tommy, uzi, pp19, kar98, m24, awm, amr, mk14,
               mini14, m249, dp28, mg3, pan, s12k, xm1014, dbs, cloth, hat,
               pant, shoe, parachute, glider, backpack1, helmet1, backpack2,
               helmet2, backpack3, helmet3, coupe, uaz, dacia, motor, buggy,
               mirado, knife, knife1;

    SkinData() {
        // Hàm khởi tạo danh sách skin chung
        auto initSkin = [this](CSkinsInfo& skinInfo, DWORD* out, const std::vector<FSkinItem>& items) {
            skinInfo.Init(items, out);
        };

        // Clothes
        initSkin(cloth, &skin.cloth->SHIRT, {
    {"Default", 0},
    {"Golden Pharaoh Divine Armor (6-Star)", 1405628},
    {"Golden Pharaoh Divine Armor (7-Star)", 1406469},
    {"Celestial Spirit Goddess Divine Armor (7-Star)", 1407366},
    {"Cyber Feline Outfit", 1407286},
    {"Cupid Guardian Outfit", 1407276},
    {"Entertainment Queen Outfit", 1407079},
    {"Mystic Saintess Outfit", 1407329},
    {"Blood Fang Divine Armor (6-Star)", 1405870},
    {"Poseidon Divine Armor (6-Star)", 1405983},
    {"Frost Divine Armor (6-Star)", 1406152},
    {"Elf Divine Armor (6-Star)", 1406311},
    {"Golden Cleopatra Divine Armor (6-Star)", 1406475},
    {"Mysterious Jester Divine Armor (6-Star)", 1406641},
    {"Blood God Calamity Divine Armor (7-Star)", 1406872},
    {"Water Goddess Divine Armor (7-Star)", 1406971},
    {"Road to Hell Outfit", 1405623},
    {"Ancient Fire God Outfit", 1407277},
    {"Divine Phantom Outfit", 1407275},
    {"Mummy Spirit Outfit", 1406891},
    {"Nurse Mummy Outfit", 1400687},
    {"Zanmang Loopy Vacation Outfit", 1601048},
    {"Eternal Flower Spirit Divine Armor (7-Star)", 1407103},
    {"Azure Serpent Outfit", 1407161},
    {"Infernal Flame Demon Armor Outfit", 1406398},
    {"Phantom Admiral Outfit", 1407330},
    {"Glass Fairy Outfit", 1407225},
    {"Supreme Fire Spirit Divine Armor (7-Star)", 1407219},
    {"Seductive Bride Outfit", 1405174},
    {"Purple Diva Outfit", 1407174},
    {"Ephialtes Dinosaur Outfit", 1406897},
    {"Apeachy Outfit", 1405208},
    {"Captain Ryan Outfit", 1405207},
    {"BAPE x PUBG Shark Hoodie (Camo)", 1404049},
    {"Serpent Reaper Outfit", 1407387},
    {"Ice Lord Outfit", 1407440},
    {"Scarlet Empress Outfit", 1407391},
    {"Stellar Snow Star Outfit", 1407441},
    {"Heavenly Jade Wolf Outfit", 1407471},
    {"Blue Lion of Death Outfit", 1407470}
});

        initSkin(hat, &skin.cloth->HAT, {
    {"None", 0}, 
    {"BAPE X PUBGM CAMO Hat", 1402162}, 
    {"Purple Diva Hat", 1410585},
    {"Twin Bun Hairstyle", 40605012}, 
    {"Salted Coffee Hair", 40605014}, 
    {"Phantom Admiral Hat", 1410686},
    {"Bridal Hairpin", 1402145}, 
    {"Beloved Guardian Hat", 1410647}, 
    {"Fairy Glass Hair", 12220054}
});

        initSkin(pant, &skin.cloth->PANT, {
    {"None", 0}, {"BAPE X PUBGM CAMO Pants", 1404050}
});

initSkin(shoe, &skin.cloth->SHOE, {
    {"None", 0}, {"BAPE X PUBGM CAMO Shoes", 1404051}, {"BAPE STA MID", 1400651}, {"Swimming Flippers", 1400371}
});

initSkin(parachute, &skin.cloth->PARACHUTE, {
    {"Pharaoh Guardian Parachute", 1401619}, {"Blood Fang Parachute", 1401621}, {"LINE FRIENDS Parachute", 1401622},
    {"Horus God Parachute", 1401615}, {"Adarna Phoenix Illusion Parachute", 1401628}, {"Blue Star Glide", 4151092}
});

initSkin(glider, &skin.cloth->GLIDER, {
    {"Glider 1", 4151048}, {"Flying Device By Chíu", 4151010}, {"Love God of War Glider", 4151019}
});

// Backpacks and Helmets (combined)
auto initLevelItems = [&](CSkinsInfo& info, DWORD* out, int level) {
    std::vector<FSkinItem> items = {
        {"Blood Fang Backpack (Level " + std::to_string(level) + ")", 1501001220 + (level - 1) * 1000},
        {"Mystic Neon Backpack (Level " + std::to_string(level) + ")", 1501001582 + (level - 1) * 1000},
        {"Butterfly Backpack (Level " + std::to_string(level) + ")", 1501001047 + (level - 1) * 1000},
        {"Pharaoh Backpack (Level " + std::to_string(level) + ")", 1501001174 + (level - 1) * 1000},
        {"Electronic Cat Backpack (Level " + std::to_string(level) + ")", 1501001496 + (level - 1) * 1000},
        {"Love Bunny Backpack (Level " + std::to_string(level) + ")", 1501001495 + (level - 1) * 1000},
        {"Clown Backpack (Level " + std::to_string(level) + ")", 1501001051 + (level - 1) * 1000},
        {"Wind Spirit Backpack (Level " + std::to_string(level) + ")", 1501001588 + (level - 1) * 1000},
        {"Captain Ryan Backpack", 1501000057},
        {"Godzilla Backpack (Level " + std::to_string(level) + ")", 1501001061 + (level - 1) * 1000},
        {"BAPE X PUBGM CAMO Backpack (Level " + std::to_string(level) + ")", 1501001058 + (level - 1) * 1000},
        {"Shark Backpack (Level " + std::to_string(level) + ")", 1501001069 + (level - 1) * 1000},
        {"Snow Sword Backpack (Level " + std::to_string(level) + ")", 1501001618 + (level - 1) * 1000},
        {"Poet’s Pact Backpack (Level " + std::to_string(level) + ")", 1501001628 + (level - 1) * 1000}
    };
    info.Init(items, out);
};


        initLevelItems(backpack1, &skin.cloth->BACKPACK1, 1);
        initLevelItems(backpack2, &skin.cloth->BACKPACK2, 2);
        initLevelItems(backpack3, &skin.cloth->BACKPACK3, 3);

        auto initHelmet = [&](CSkinsInfo& info, DWORD* out, int level) {
    info.Init({
        {"Glacier Helmet (Level " + std::to_string(level) + ")", 1502001023 + (level - 1) * 1000},
        {"Inferno Knight Helmet (Level " + std::to_string(level) + ")", 1502001014 + (level - 1) * 1000}
    }, out);
};

        initHelmet(helmet1, &skin.cloth->HELMET1, 1);
        initHelmet(helmet2, &skin.cloth->HELMET2, 2);
        initHelmet(helmet3, &skin.cloth->HELMET3, 3);

        // Vehicles
        initSkin(uaz, &skin.vehicle->UAZ, {
    {"None", 0}, {"Bentley Betayga Azure (Flower Rain)", 1908094}, {"Bentley Betayga Azure (Silent Night)", 1908095},
    {"Godzilla Super Beast UAZ (Level 3)", 1908032}, {"Spooky Pumpkin UAZ (Level 3)", 1908036},
    {"Lamborghini Urus Pink", 1908066}, {"Lamborghini Urus Giallo Inti", 1908067},
    {"Maserati Levante Blu Emozione", 1908075}, {"Maserati Luce Arancione", 1908076},
    {"Maserati Levante Neon Urbano", 1908077}, {"Maserati Levante Firmamento", 1908078},
    {"Aston Martin DBX707 (Neon Purple)", 1908084}, {"Aston Martin DBX707 (Quasar Blue)", 1908085},
    {"Dodge Hornet - Scarlet Sting", 1908086}, {"Dodge Hornet GLH Concept - Redline", 1908088},
    {"Dodge Hornet - Sunburst", 1908089}
});

initSkin(motor, &skin.vehicle->MOTOR, {
    {"None", 0}, {"Ghost Motorcycle (Level 7)", 1901047}, {"Roaring Tiger Motorcycle (Level 3)", 1901027},
    {"MWT-9", 1901050}, {"MWT-9 (Yellow)", 1901052}, {"DUCATI Panigale V4S", 1901073},
    {"Ducati Panigale V4S Black Phantom", 1901074}, {"Ducati Panigale V4S Crimson Storm", 1901075},
    {"Ducati Panigale V4S Swift Mirage", 1901076}
});

initSkin(mirado, &skin.vehicle->MIRADO, {
    {"None", 0}, {"VW Beetle Convertible (Pink)", 1915010}, {"VW Beetle Convertible (Monster)", 1915012},
    {"Aston Martin DBS Volante (Deep Cosmos)", 1915005}, {"Aston Martin DBS Volante (Celestial Pink)", 1915006},
    {"Aston Martin DBS Volante (Black-Bronze Satin)", 1915007},
    {"Bentley Continental GTC Mulliner (Shimmering Dream)", 1915009}
});

initSkin(dacia, &skin.vehicle->DACIA, {
    {"None", 0}, {"Bentley Flying Spur Mulliner (Blue Nebula)", 1903200},
    {"Bentley Flying Spur Mulliner (Bay Flow)", 1903201}, {"Koenigsegg Gemera (Rainbow)", 1903075},
    {"Tesla Roadster (Diamond)", 1903071}, {"Tesla Roadster (Purple Crystal)", 1903072},
    {"Tesla Roadster (Ocean Blue)", 1903073}, {"Koenigsegg Gemera (Silver Gray)", 1903074},
    {"Koenigsegg Gemera (Sunrise)", 1903076}
});

initSkin(buggy, &skin.vehicle->BUGGY, {
    {"None", 0}, {"McLaren F1 Race Team (Electronic)", 1907054}, {"McLaren F1 Race Team", 1907058},
    {"McLaren F1 Race Team (Victory)", 1907059}
});

initSkin(coupe, &skin.vehicle->COUPE, {
    {"None", 0}, {"McLaren P1 (Starry Sky)", 1961147}, {"McLaren P1 (Bright Pink)", 1961148},
    {"McLaren P1 (Volcanic Yellow)", 1961149}, {"Bentley Betayga Azure (Magic Kingdom)", 1961139},
    {"Lamborghini Invencible Rosso Efesto", 1961144}, {"Lamborghini Invencible Nebula Drift", 1961145},
    {"Bentley Batur (Holoprism)", 1961137}, {"Bentley Batur (Solar Pulse)", 1961138},
    {"Bentley Batur (Bonneville Pearlescent Silver)", 1961139}, {"Warp Green", 1961033},
    {"Warp Dawn", 1961034}, {"Warp Universe", 1961035}, {"McLaren 570S (Black)", 1961007},
    {"McLaren 570S (White)", 1961010}, {"McLaren 570S (Pink)", 1961012}, {"McLaren 570S (Yellow White)", 1961013},
    {"McLaren 570S (Yellow Black)", 1961014}, {"McLaren 570S (Metallic)", 1961015},
    {"Koenigsegg Jesko (Silver Gray)", 1961016}, {"Koenigsegg Jesko (Rainbow)", 1961017},
    {"Koenigsegg Jesko (Sunrise)", 1961018}, {"Lamborghini Aventador SVJ Verde Alceo", 1961020},
    {"Lamborghini Centenario Galassia", 1961021}, {"Lamborghini Aventador SVJ Blue", 1961024},
    {"Lamborghini Centenario Carbon Fiber", 1961025}, {"Koenigsegg One:1 Gilt", 1961029},
    {"Koenigsegg One:1 Cyber Nebula", 1961030}, {"Koenigsegg One:1 Jade", 1961031},
    {"Bugatti Veyron 16.4 (Colorful)", 1961041}, {"Bugatti Veyron 16.4 (Yellow)", 1961042},
    {"Bugatti La Voiture Noire", 1961044}, {"Aston Martin Valkyrie (Luminous Diamond)", 1961048},
    {"Dodge Challenger SRT Hellcat Jailbreak - Hellfire", 1961050}, {"Pagani Zonda R (Tricolore Carbon)", 1961051}
});

 initSkin(m16, &skin.gun->M16A4, {{"Skeletal Core - M16A4 (Level 7)", 1101002081}});

initSkin(m416, &skin.gun->M416, {
    {"Frost - M416 (Level 7)", 1101004046}, {"Life Stealer - M416 (Level 8)", 1101004236},
    {"Shadow Seal - M416 (Level 8)", 1101004226}, {"Clown - M416 (Level 7)", 1101004062},
    {"Roaring Reptile - M416 (Level 7)", 1101004086}, {"Royal Glory - M416 (Level 8)", 1101004163},
    {"White Unicorn - M416 (Level 8)", 1101004201}, {"Rising Tide - M416 (Level 8)", 1101004209},
    {"Ghost - M416 (Level 8)", 1101004218}
});

initSkin(akm, &skin.gun->AKM, {
    {"Admiral Seadragon - AKM (Level 8)", 1101001213}, {"Mischievous Bunny - AKM (Level 7)", 1101001231},
    {"Judgment Day - AKM (Level 8)", 1101001242}, {"Holy Light (Golden Feathers) - AKM (Lv7)", 1101001256},
    {"Holy Light (Moon God) - AKM (Lv7)", 1101001249}
});

initSkin(scarl, &skin.gun->SCARL, {
    {"Blood Soul Overlord - SCAR-L (Level 8)", 1101003167}, {"Clown's Embrace - SCAR-L (Level 7)", 1101003181},
    {"Mystic Saintess - SCAR-L (Level 7)", 1101003195}, {"Magic Kingdom - SCAR-L (Level 7)", 1101003208}
});

initSkin(aug, &skin.gun->AUG, {{"Ice Spirit - AUG (Level 8)", 1101006062}, {"Fire Song - AUG (Level 7)", 1101006075}});

initSkin(m762, &skin.gun->M762, {
    {"Blood Dragon - M762 (Level 7)", 1101008126}, {"Fairy Crystal - M762 (Level 7)", 1101008136},
    {"White Bone Shadow - M762 (Level 8)", 1101008146}, {"Bone Frame - M762 (Level 8)", 1101008154}
});

initSkin(groza, &skin.gun->GROZA, {{"Dark Fire - Groza (Level 7)", 1101005052}, {"Ancient Relic - Groza (Level 5)", 1101005090}});
initSkin(honey, &skin.gun->HONEY, {{"Mystic Colors - Honey Badger (Level 5)", 1101012009}});
initSkin(ace32, &skin.gun->ACE32, {
    {"Kamehameha - ACE32 (Level 7)", 1101102007}, {"Jade - ACE32 (Level 7)", 1101102017},
    {"Sea Monster - ACE32 (Level 8)", 1101102025}
});
initSkin(qbz, &skin.gun->QBZ, {
    {"Dark Princess - QBZ (Level 7)", 1101007046}, {"Flower Sword Critical - QBZ (Level 7)", 1101007062},
    {"Mandate of Heaven - QBZ (Level 7)", 1101007071}
});

initSkin(ump45, &skin.gun->UMP45, {{"Frost - UMP45 (Level 7)", 1102002136}});
initSkin(uzi, &skin.gun->UZI, {
    {"Fresh Orange - UZI (Level 5)", 1102001103}, {"Seal - UZI (Level 3)", 1102001112},
    {"Savagery - UZI (Level 5)", 1102001998}, {"Juicer - UZI (Level 5)", 1102001102},
    {"Frost - UZI (Level 8)", 1102001120}
});
initSkin(vector, &skin.gun->VECTOR, {{"Dragon Wing - Vector (Level 7)", 1102003080}});
initSkin(pp19, &skin.gun->PP19, {{"Lion-Dog - PP-19 Bizon (Level 5)", 1102005057}});
initSkin(tommy, &skin.gun->TOMMY, {{"Candy - Thompson (Level 5)", 1102004018}});

       initSkin(kar98, &skin.gun->KAR98, {{"Purple Lightning - Kar98K (Level 7)", 1103001179}, {"Pink Fire - Kar98 (Level 7)", 1103001191}});
initSkin(m24, &skin.gun->M24, {{"Perfect Rhythm - M24 (Level 7)", 1103002087}, {"High-Tech - M24 (Level 5)", 1103002094}});
initSkin(awm, &skin.gun->AWM, {{"Thanh Hoa Snake - AWM (Level 7)", 1103003087}});
initSkin(amr, &skin.gun->AMR, {
    {"Ephialtes Dinosaur - AMR (Level 8)", 1103012010}, {"Fire God - AMR (Level 7)", 1103012019},
    {"Onyx Crystal - AMR (Level 5)", 1103012024}, {"Silent Farewell - AMR (Level 7)", 1103012031}
});
initSkin(mk14, &skin.gun->MK14, {{"Dragon Kingdom - Mk14 (Level 8)", 1103007028}});
initSkin(mini14, &skin.gun->MINI14, {{"Glacier - Mini14 (Level 7)", 1103006030}});

        // LMG
        initSkin(m249, &skin.gun->M249, {{"Empress of Light - M249 (Level 7)", 1105001048}, {"Street Graffiti - M249 (Level 5)", 1105001062}});
initSkin(dp28, &skin.gun->DP28, {
    {"Shenron Dragon - DP-28 (Level 5)", 1105002063}, {"Armored Warrior - DP-28 (Level 5)", 1105002071},
    {"Digital Cat - DP-28 (Level 5)", 1105002076}
});
initSkin(mg3, &skin.gun->MG3, {{"Sky Frame - MG3 (Level 5)", 1105010008}, {"Sky Warrior - MG3 (Level 7)", 1105010019}});
initSkin(pan, &skin.gun->PAN, {
    {"Fried Chicken Pan (Level 3)", 1108004356}, {"Captain Ryan Pan", 1108004060},
    {"Apeachy Pan", 1108004061}, {"BAPE X PUBGM CAMO Pan", 1108004062}
});
initSkin(knife, &skin.gun->KNIFE, {
    {"Dragon Hunt - Knife (Level 3)", 1108001057}, {"Yor SPY×FAMILY Short Sword (Lv3)", 1108001064},
    {"Ki Sword (Level 3)", 1108001069}
});
initSkin(knife1, &skin.gun->KNIFE1, {{"Frost Dragon - Dagger (Level 3)", 1108005050}});

       initSkin(s12k, &skin.gun->S12K, {{"Golden Eagle - S12K", 1104003027}, {"Atomic Activation - S12K (Level 5)", 1104003037}});
initSkin(dbs, &skin.gun->DBS, {{"Colorful Leopard - DBS (Level 3)", 1104004024}, {"Beast Armor - DBS (Level 5)", 1104004035}});
initSkin(xm1014, &skin.gun->XM1014, {{"Festival of Death - M1014", 1104101001}});
    }
};

static SkinData skindata;

#endif // MRTHANG_SKIN_DATA_H
