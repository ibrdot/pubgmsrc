
FRotator VectorToRotator(FVector rotation)
{
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float)3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float)3.14159265358979323846);
    newViewAngle.Roll = (float)0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}
int32_t ToColor(float* col)
{
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4*)(col));
}
ImVec4 to_vec4(float r, float g, float b, float a)
{
    return ImVec4(r / 255.0, g / 255.0, b / 255.0, a / 255.0);
}

FVector SubVec(FVector Src, FVector Dst)
{
    FVector Result;
    Result.X = Src.X - Dst.X;
    Result.Y = Src.Y - Dst.Y;
    Result.Z = Src.Z - Dst.Z;
    return Result;
}
float MagVec(FVector Vec)
{
    return sqrtf(Vec.X * Vec.X + Vec.Y * Vec.Y + Vec.Z * Vec.Z);
}
float GetDistVec(FVector Src, FVector Dst)
{
    FVector Result = SubVec(Src, Dst);
    return MagVec(Result);
}
float GetDistVec2(const FVector &Point1, const FVector &Point2)
    {
        FVector Difference = SubVec(Point1, Point2);
        return sqrt(Difference.X * Difference.X + Difference.Y * Difference.Y + Difference.Z * Difference.Z);
    }
float DistanceTravelled = 0;
float GameInfovelocity = 0;
SDK::FVector PreviousLocation;
void Box4Line(ImDrawList* draw, float startX, float startY, float width, float height, float lineWidth, float cornerRadius, ImU32 color)
{
    ImVec2 topLeft(startX, startY);
    ImVec2 bottomRight(startX + width, startY + height);
    draw->AddLine(topLeft, ImVec2(topLeft.x + width, topLeft.y), color, lineWidth);  
    draw->AddLine(ImVec2(topLeft.x + width, topLeft.y), ImVec2(bottomRight.x, bottomRight.y), color, lineWidth);
    draw->AddLine(ImVec2(bottomRight.x, bottomRight.y), ImVec2(bottomRight.x - width, bottomRight.y), color, lineWidth);
    draw->AddLine(ImVec2(bottomRight.x - width, bottomRight.y), topLeft, color, lineWidth);
}
static int total = 0;
static int skipped = 0;
static int doing = 0;
void *SkinDump(void *)
{
    doing = 0;
    total = 0;
    skipped = 0;
    std::wofstream file(skCrypt("/storage/emulated/0/Android/data/com.pubg.imobile/files/log/Dump.txt"));
    auto backpack = (UBackpackUtils *)UBackpackUtils::StaticClass();
    TArray<int> items = backpack->GetItemIDs();
    total = items.Num();
    for (int i = 0; i < items.Num(); i++)
    {
        auto data = backpack->GetItemRecord(items[i]);
        if (data.BPID == 0)
        {
            skipped++;
            continue;
        }
        // file << "[" << items[i] << "] "
        // file     << "Type : " << data.itemType << '\n';
        // file << "- Name: " << std::wstring(data.ItemName.ToWString()) << '\n';
        // file << "- Description: " << std::wstring(data.ItemDesc.ToWString()) << '\n';
        file << items[i] << " | " << std::wstring(data.ItemName.ToWString()) << '\n';

        doing++;
    }
    file.close();
    LOGI(skCrypt("Dump to com.pubg.imobile/files/logs/Dump.txt"));
    return 0;
}
static vector<APickUpWrapperActor *> ARNearestCache = {};
static vector<APickUpWrapperActor *> ARNearestList = {};
FVector CalculateWeaponMuzzlePosition(const FVector &weaponLocation, const FRotator &weaponRotation, float weaponBodyLength)
{

    float radPitch = weaponRotation.Pitch * (3.14159265358979323846 / 180.0f);
    float radYaw = weaponRotation.Yaw * (3.14159265358979323846 / 180.0f);

    float forwardX = std::cos(radPitch) * std::cos(radYaw);
    float forwardY = std::cos(radPitch) * std::sin(radYaw);
    float forwardZ = std::sin(radPitch);

    FVector muzzlePosition = {
        weaponLocation.X + forwardX * weaponBodyLength,
        weaponLocation.Y + forwardY * weaponBodyLength,
        weaponLocation.Z + forwardZ * weaponBodyLength};

    return muzzlePosition;
}
void VectorAnglesRadar(Vector3 &forward, FVector &angles)
{
    if (forward.X == 0.f && forward.Y == 0.f)
    {
        angles.X = forward.Z > 0.f ? -90.f : 90.f;
        angles.Y = 0.f;
    }
    else
    {
        angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
        angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
    }
    angles.Z = 0.f;
}

void RotateTriangle(std::array<Vector3, 3> &points, float rotation)
{
    const auto points_center = (points.at(0) + points.at(1) + points.at(2)) / 3;
    for (auto &point : points)
    {
        point = point - points_center;
        const auto temp_x = point.X;
        const auto temp_y = point.Y;
        const auto theta = DEG2RAD(rotation);
        const auto c = cosf(theta);
        const auto s = sinf(theta);
        point.X = temp_x * c - temp_y * s;
        point.Y = temp_x * s + temp_y * c;
        point = point + points_center;
    }
}
FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff)
{
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cosf(num2);
    float num4 = (float)std::sinf(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    FVector Xector;
    Xector.X = (num6 * num3 - num5 * num4) / 150.f;
    Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    FVector Xector2;
    Xector2.X = Xector.X + PosX + Size.X / 2.f;
    Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
    bool flag2 = Xector2.X > PosX + Size.X;
    if (flag2)
    {
        Xector2.X = PosX + Size.X;
    }
    else
    {
        bool flag3 = Xector2.X < PosX;
        if (flag3)
        {
            Xector2.X = PosX;
        }
    }
    bool flag4 = Xector2.Y > PosY + Size.Y;
    if (flag4)
    {
        Xector2.Y = PosY + Size.Y;
    }
    else
    {
        bool flag5 = Xector2.Y < PosY;
        if (flag5)
        {
            Xector2.Y = PosY;
        }
    }
    bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
    if (flag6)
    {
        flag = true;
    }
    outbuff = flag;
    return Xector2;
}

//=======================//
//#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(Data::localController, w, true, s)
//===========AIMBOTDEFINE======////
void Circle3D(ImDrawList *draw, FVector origin, float radius, ImColor color, float thinkless)
{
    const int doan_thang = 50;
    float step = 2 * IM_PI / doan_thang;
    FVector2D prev;
    Vector3 curValid3 = Vector3(origin.X + radius, origin.Y, origin.Z);
    FVector curValidF;
    curValidF.X = curValid3.X;
    curValidF.Y = curValid3.Y;
    curValidF.Z = curValid3.Z;
    bool curValid = WorldToScreenBone(curValidF, &prev);

    for (int i = 1; i <= doan_thang; ++i)
    {
        float angle = i * step;
        FVector2D cur;
        Vector3 nextValid3 = Vector3(origin.X + radius * cos(angle), origin.Y + radius * sin(angle), origin.Z);
        FVector nextValidF;
        nextValidF.X = nextValid3.X;
        nextValidF.Y = nextValid3.Y;
        nextValidF.Z = nextValid3.Z;
        bool nextValid = WorldToScreenBone(nextValidF, &cur);
        if (curValid && nextValid)
        {
            draw->AddLine(ImVec2(prev.X, prev.Y), ImVec2(cur.X, cur.Y), color, thinkless);
        }
        curValid = nextValid;
        prev = cur;
    }
}

string hptext = "";
string hptext1 = "";
// ==================================== //

string GetVehicleType(string Name)
{
    if (Name.find("BRDM") != std::string::npos)
        return "BRDM";
    if (Name.find("Scooter") != std::string::npos)
        return "Scooter";
    if (Name.find("Snowmobile") != std::string::npos)
        return "Snowmobile";
    if (Name.find("Tuk") != std::string::npos)
        return "Tuk";
    if (Name.find("Buggy") != std::string::npos)
        return "Buggy";
    if (Name.find("Dacia")!= std::string::npos)
        return "Dacia";
    if (Name.find("Rony") != std::string::npos)
        return "Rony";
    if (Name.find("MiniBus") != std::string::npos)
        return "MiniBus";
    if (Name.find("PG117") != std::string::npos)
        return "PG117";
    if (Name.find("AquaRail") != std::string::npos)
        return "AquaRail";
    if (Name.find("Bigfoot") != std::string::npos)
        return "Bigfoot";
    if (Name.find("Mirado_open") != std::string::npos)
        return "Mirado";
    if (Name.find("VH_Snowbike_C") != std::string::npos)
        return "SnowBike";
    if (Name.find("BP_VH_Bigfoot_") != std::string::npos)
        return "Monster Track";
    if (Name.find("PickUp_07_C") != std::string::npos)
        return "PickUp";
    if (Name.find("wing_Vehicle_SI_C") != std::string::npos)
        return "Helicopter";
    if (Name.find("VH_UTV_C") != std::string::npos)
        return "UTV";
    if (Name.find("VH_ATV") != std::string::npos)
        return "Quad";
    if (Name.find("UAZ") != std::string::npos)
        return "UAZ";
    if (Name.find("LadaNiva_") != std::string::npos)
        return "Lada Niva";
    if (Name.find("VH_MotorcycleCart_") != std::string::npos)
        return "MotorcycleCart";
    if (Name.find("VH_Motorcycle_") != std::string::npos)
        return "Motorcycle";
    if (Name.find("BP_Bike_WithRack_") != std::string::npos)
        return "Bike";
    if (Name.find("CoupeRB") != std::string::npos)
        return "Coupe RB";
    if (Name.find("ModelY") != std::string::npos)
        return "Tesla";
    if (Name.find("VH_StoreBus_C") != std::string::npos)
        return "Bus";
    if (Name.find("BP_TigerVehicle_") != std::string::npos)
        return "Tiger";
    if(Name.find("BP_MammothVehicle_C") != std::string::npos)
        return "Mammoth";
	if (Name.find("BP_AirDropPlane_C") != std::string::npos) 
       return "Plane";
    if (Name.find("VH_Motorglider_") != std::string::npos) 
       return "Glider";
    return "Unknown";
}

FVector Subtract_VectorVector(const FVector &A, const FVector &B)
{
    FVector Result;
    Result.X = A.X - B.X;
    Result.Y = A.Y - B.Y;
    Result.Z = A.Z - B.Z;
    return Result;
}

FRotator Conv_VectorToRotator(const FVector &InVec)
{
    FRotator Result;

    Result.Yaw = atan2(InVec.Y, InVec.X) * 180.f / (float)3.14159265358979323846;

    Result.Pitch = atan2(InVec.Z, sqrt(InVec.X * InVec.X + InVec.Y * InVec.Y)) * 180.f / (float)3.14159265358979323846;

    Result.Roll = 0;

    return Result;
}
SDK::FVector SubtractVectors(SDK::FVector a, SDK::FVector b)
{
    SDK::FVector result;
    result.X = a.X - b.X;
    result.Y = a.Y - b.Y;
    result.Z = a.Z - b.Z;
    return result;
}

SDK::FVector AddVectors(SDK::FVector a, SDK::FVector b)
{
    SDK::FVector result;
    result.X = a.X + b.X;
    result.Y = a.Y + b.Y;
    result.Z = a.Z + b.Z;
    return result;
}

SDK::FVector MultiplyVectors(SDK::FVector a, SDK::FVector b)
{
    SDK::FVector result;
    result.X = a.X * b.X;
    result.Y = a.Y * b.Y;
    result.Z = a.Z * b.Z;
    return result;
}

SDK::FVector DivideVectors(SDK::FVector a, SDK::FVector b)
{
    SDK::FVector result;
    result.X = a.X / b.X;
    result.Y = a.Y / b.Y;
    result.Z = a.Z / b.Z;
    return result;
}

SDK::FVector MultiplyVectorFloat(SDK::FVector a, float scalar)
{
    SDK::FVector result;
    result.X = a.X * scalar;
    result.Y = a.Y * scalar;
    result.Z = a.Z * scalar;
    return result;
}

FVector Minus_VectorVector(const FVector &A, const FVector &B)
{
    return FVector{A.X - B.X, A.Y - B.Y, A.Z - B.Z};
}

FVector Add_VectorVector(const FVector &A, const FVector &B)
{
    return FVector{A.X + B.X, A.Y + B.Y, A.Z + B.Z};
}

FVector Multiply_VectorFloat(const FVector &A, float Scalar)
{
    return FVector{A.X * Scalar, A.Y * Scalar, A.Z * Scalar};
}

// Imgui
bool isInsideFOV(int x, int y)
{
    if (!Config.Ragebot.Enable)
        return true;
    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = Config.Ragebot.Cross;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

bool isInsideFOVNearest(int x, int y, float fov)
{
    if (!Config.Ragebot.Cross)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = fov;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

FRotator ClampAngles(FRotator inRot)
{
    FRotator outRot = inRot;
    if (outRot.Pitch > 180)
        outRot.Pitch -= 360;
    if (outRot.Pitch < -180)
        outRot.Pitch += 360;

    if (outRot.Pitch < -75.f)
        outRot.Pitch = -75.f;
    else if (outRot.Pitch > 75.f)
        outRot.Pitch = 75.f;

    while (outRot.Yaw < -180.0f)
        outRot.Yaw += 360.0f;
    while (outRot.Yaw > 180.0f)
        outRot.Yaw -= 360.0f;
    return outRot;
}


std::string scopes(int fov) {
    if (fov == 70)
        return "Iron";
    else if (fov == 55)
        return "RedDot";
    else if (fov == 44)
        return "X2";
    else if (fov == 26) // 27
        return "X3";
    else if (fov == 20)
        return "X4";
    else if (fov == 13)
        return "X6";
    else if (fov == 11)
        return "X8";
    else
        return "None";

    return "";
}
std::string playerstatus(int GetEnemyState)
{
    switch (GetEnemyState)
    {
    case 0:
        return "AFK";
        break;
    case 1:
        return "In Water";
        break;
    case 268435464:
        return "Play Emotion";
        break;
    case 8:
        return "Stand";
        break;
    case 520:
    case 544:
    case 656:
    case 521:
    case 528:
        return "Aiming";
        break;
    case 1680:
    case 1672:
    case 1673:
    case 1032:
    case 1544:
    case 1545:
    case 1033:
        return "Peek";
        break;
    case 9:
        return "Walking";
        break;
    case 11:
        return "Running";
        break;
    case 4194304:
        return "Swimming";
        break;
    case 32784:
        return "Reviving";
        break;
    case 16777224:
        return "Climbing";
        break;
    case 8200:
    case 8208:
        return "Punching";
        break;
    case 16:
    case 17:
    case 19:
        return "Crouch";
        break;
    case 32:
    case 33:
    case 35:
    case 5445:
    case 762:
        return "Snake";
        break;
    case 72:
    case 73:
    case 75:
        return "Jumping";
        break;
    case 264:
    case 272:
    case 273:
    case 288:
    case 265:
    case 329:
        return "Reloading";
        break;
    case 137:
    case 144:
    case 201:
    case 145:
    case 160:
    case 649:
    case 648:
    case 1160:
    case 1161:
    case 1169:
        return "Firing";
        break;
    case 131070:
    case 131071:
    case 131072:
    case 131073:
    case 131075:
    case 131074:
        return "Knocked";
        break;
    case 33554440:
    case 524296:
    case 1048584:
    case 524288:
        return "Driving";
        break;
    case 16392:
    case 16393:
    case 16401:
    case 16416:
    case 16417:
    case 16457:
    case 16400:
    case 17401:
    case 17417:
    case 17425:
    case 17424:
        return "Throwing Bomb";
        break;
    default:
        return "";
        break;
    }
}

std::string PlayerState(int GetEnemyState)
{
    switch (GetEnemyState)
    {
    case 0:
        return "AFK";

    case 1032:
        return "TILT HEAD";

    case 268435464:
        return "PLAY EMOTION";

    case 1552:
        return "AIMING";

    case 8388616:
        return "PARACHUTE";

    case 131072:
        return "KNOCKED";

    case 33554440:
        return "PLANE";

    case 8205:
        return "SHOT";

    case 32:
        return "SIT";

    case 4194303:
        return "SWIMMING";

    case 72:
        return "JUMPING";

    case 8388608:
        return "PARACHUTE";

    case 16392:
        return "THROW SOMETHING";

    case 262:
        return "RELOADING";

    case 1048584:
        return "RIDE";

    case 8200:
        return "FIST";

    case 2056:
        return "CUT GUN";

    case 4194302:
        return "SWIMMING";

    case 269:
        return "RELOADING";

    case 16777224:
        return "CLIMBING";

    case 10:
        return "RUN";

    case 263:
        return "RELOADING";

    case 65568 || 65544:
        return "FIGHT MEDICINE";

    case 4194308:
        return "SWIMMING";

    case 268:
        return "RELOADING";

    case 35:
        return "GET SIT";

    case 8388617:
        return "PARACHUTE";

    case 33:
        return "AIMING";

    case 75:
        return "JUMPING";

    case 8201:
        return "FIST";

    case 266:
        return "RELOADING";

    case 32776:
        return "KNOCKED";

    case 270:
        return "RELOADING";

    case 4194301:
        return "SWIMMING";

    case 1033:
        return "RUN";

    case 131073:
        return "KNOCKED";

    case 524296:
        return "DRIVING";

    case 1114120:
        return "FIGHT MEDICINE";

    case 265:
        return "RELOADING";

    case 9:
        return "RUN";

    case 262144:
        return "SMOKE";

    case 8203:
        return "FIST";

    case 8202:
        return "SHOT";

    case 262152:
        return "DEATH";

    case 17416:
        return "THROW SOMETHING";

    case 17:
        return "SIT";

    case 11:
        return "RUN";

    case 65545:
        return "FIGHT MEDICINE";

    case 33554432:
        return "PLANE";

    case 19:
        return "SQUAT";

    case 8208:
        return "SHOT";

    case 520:
        return "AIMING";

    case 8206:
        return "SHOT";

    case 8:
        return "STAND";

    case 16:
        return "SIT";

    case 13180:
        return "KNOCKED";

    case 4194310:
        return "SWIMMING";

    case 16393:
        return "THROW SOMETHING";

    case 4194309:
        return "SWIMMING";

    case 264:
        return "RELOADING";

    case 4194305:
        return "SWIMMING";

    case 8207:
        return "SHOT";

    case 4194307:
        return "SWIMMING";
    }
    return "";
}

FRotator Torotatorr(FVector local, FVector target)
{
    float xDif = target.X - local.X;
    float yDif = target.Y - local.Y;
    float zDif = target.Z - local.Z;

    FRotator AimRotation = { 0 };
    float Hyp = sqrt(xDif * xDif + yDif * yDif);
    AimRotation.Yaw = atan2(zDif, Hyp) * 180.0f / 3.1415926535897f;
    AimRotation.Pitch = atan2(yDif, xDif) * 180.0f / 3.1415926535897f;

    return AimRotation;
}
FRotator ToRotator(FVector start, FVector target)
{
    FVector direction = Minus_VectorVector(target, start);
    float hyp = sqrt(direction.X * direction.X + direction.Y * direction.Y);
    FRotator newViewAngle;
    newViewAngle.Pitch = -atan2(direction.Z, hyp) * (180.f / 3.1415926535897f);
    newViewAngle.Yaw = atan2(direction.Y, direction.X) * (180.f / 3.1415926535897f);
    newViewAngle.Roll = 0.0f;
    return newViewAngle;
}
FQuat RotatorToQuat(FRotator rotator)
{
    float DEG_TO_RAD = M_PI / 180.f;
    float pitch = rotator.Pitch * DEG_TO_RAD * 0.5f;
    float yaw = rotator.Yaw * DEG_TO_RAD * 0.5f;
    float roll = rotator.Roll * DEG_TO_RAD * 0.5f;

    float sinPitch = sin(pitch);
    float cosPitch = cos(pitch);
    float sinYaw = sin(yaw);
    float cosYaw = cos(yaw);
    float sinRoll = sin(roll);
    float cosRoll = cos(roll);

    FQuat quat;
    quat.X = sinRoll * cosPitch * cosYaw - cosRoll * sinPitch * sinYaw;
    quat.Y = cosRoll * sinPitch * cosYaw + sinRoll * cosPitch * sinYaw;
    quat.Z = cosRoll * cosPitch * sinYaw - sinRoll * sinPitch * cosYaw;
    quat.W = cosRoll * cosPitch * cosYaw + sinRoll * sinPitch * sinYaw;

    return quat;
}
static void MetricsHelpMarker(const char *desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}


inline bool IsBot(ASTExtraPlayerCharacter *player)
{
  std::string UID = player->PlayerUID.ToString();
  return UID.length() < 7;
}

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(Data::localController, w, true, s)


float anodist = 150.0f;

auto GetTargetByCrossDist() {
      ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
      const auto Actors = GetNecessaryActors();
    const auto localPlayer = Data::localPlayer;
    const auto LocalController = Data::localController;
    if (localPlayer){
        for (auto Actor : Actors){
            if (isObjectInvalid(Actor))
                continue;

                    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                        auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;

                float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
                if (dist > anodist)
                    continue;
					


                        if (Player->PlayerKey == localPlayer->PlayerKey)
                            continue;

                        if (Player->TeamID == localPlayer->TeamID)
                            continue;

                        if (Player->bDead)
                            continue;

                        if (Config.Ragebot.SilentIgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }

                        if (Config.Ragebot.SilentVisCheck) {
                            if (!LocalController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }

                        auto Root = Player->GetBonePos("Root", {});
                        auto Head = Player->GetBonePos("Head", {});

                        FVector2D RootSc, HeadSc;
                        if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                            float height = abs(HeadSc.Y - RootSc.Y);
                            float width = height * 0.65f;

                            FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                            if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                                FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                                FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
                           //  if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {
                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                        }
                    }
                }
            }
         }
    return result;
}

auto GetTargetForBulletTrack()
{
    ASTExtraPlayerCharacter *result = nullptr;
    float max = std::numeric_limits<float>::infinity();
     const auto Actors = GetNecessaryActors();
	const auto localPlayer = Data::localPlayer;
    const auto LocalController = Data::localController;
    if (Data::localPlayer) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {

                auto Player = (ASTExtraPlayerCharacter *) Actor;
                float distx = localPlayer->GetDistanceTo(Player) / 100.0f;

                if (distx > 500.0f)
                    continue;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Player->bHidden)
                    continue;

                if (Config.Ragebot.btIgnoreKnock) {
                    if (Player->Health == 0.0f)
                        continue;
                }
     if (Config.Ragebot.btVisCheck) {

    auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)localPlayer->WeaponManagerComponent->CurrentWeaponReplicated;

    if (CurrentWeaponReplicated) {

        FVector weaponlocation = CurrentWeaponReplicated->K2_GetActorLocation();

        FRotator weaponRotation = CurrentWeaponReplicated->K2_GetActorRotation();

        float weaponBodyLength = CurrentWeaponReplicated->GetWeaponBodyLength();

        FVector muzzlePosition = CalculateWeaponMuzzlePosition(weaponlocation, weaponRotation, weaponBodyLength / 1.5);

        if (!LocalController->LineOfSightTo(Player, muzzlePosition, true))
            continue;

    }
    
    
}     /*  if (Cheat::BulletTrack::VisCheck)
                {
                    if (!Cheat::localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }*/
                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});
                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.20f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) &&
                            (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

     //               if(IsInsideFov((int)middlePoint.X, (int)middlePoint.Y)) {
                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                        }
                    }
                }
            }
        }
    }
    return result;
}


ASTExtraPlayerCharacter *GetBestLineTarget()
{
    ASTExtraPlayerCharacter *Target = 0;
    float max = std::numeric_limits<float>::infinity();
    const auto localPlayer = Data::localPlayer;
    const auto LocalController = Data::localController;

    auto GWorld = GetFullWorld();
    if (!GWorld)
    {
        return 0;
    }
    if (!GWorld->PersistentLevel)
    {
        return 0;
    }

    
    if (localPlayer)
    {
    const auto Actors = GetNecessaryActors();

    for (const auto Actor : Actors)

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
            {
             const  auto Player = (ASTExtraPlayerCharacter *)Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.Ragebot.IgnoreAi)
                {
                    if (IsBot(Player))
                        continue;
                }

                if (Config.Ragebot.IgnoreKnock)
                {
                    if (Player->Health == 0.0f)
                        continue;
                }
                
                float dist = localPlayer->GetDistanceTo(Player) / 100.0f;
                if (dist > Config.Ragebot.Distance)
                    continue;
                
					  bool bVisible = true;
                if (Config.Ragebot.Visible)
                {
                    bool bSkip = true;
                    if (LocalController->LineOfSightTo(Player, {0, 0, 0}, true))
                    {
                        bSkip = false;
                    }
                    bVisible = !bSkip;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;

                if (bVisible)
                {

                        if (WorldToScreenBone(Root, &RootSc) && WorldToScreenBone(Head, &HeadSc))
                        {
                            float height = abs(HeadSc.Y - RootSc.Y);
                            float width = height * 0.65f;

                            FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};

                            FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
                            FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                            float distance = FVector2D::Distance(v2Middle, v2Loc);

                            if (isInsideFOV((int)middlePoint.X, (int)middlePoint.Y))
                            {
                                if (distance < max)
                                {
                                    max = distance;
                                    Target = Player;
                                }
                            }
                        }
                    }
                }
            }
    return Target;
}

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2, float a6, float a7, float a8) = 0;
void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1, float a6, float a7, float a8)
{
   if (Config.Ragebot.btEnable) {
        ASTExtraPlayerCharacter *Target = GetTargetForBulletTrack();
        if (Target)
        {
                
            FVector targetAimPos = Target->GetHeadLocation(true);
            Data::localController->PlayerCameraManager->CameraCache.POV.Location = targetAimPos;

targetAimPos.Z -= -Aimposss;
            
            rot = ToRotator(start, targetAimPos);
    }}
    return orig_shoot_event(thiz, start, rot, weapon, unk1, a6, a7, a8);
}


static void MetricsHelpMarker1(const char *desc)
{
    ImGui::TextDisabled("(*)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}
bool dbrr = false;
bool OpenVolume = false;
bool OpenMenu = false;


                
// ==================================================
int aimcalled = 0;
bool aimisyellow = false;
void CallEnemyAimWarning()
{
    string aimingtext;
    aimingtext = GetLabel("ENEMY IS AIMING AT YOU", "ĐỊCH ĐANG NGẮM BẮN BẠN", "敌人正在瞄准你");
    if (!aimisyellow)
    {
        if (aimcalled >= 50)
        {
            aimcalled = 0;
            aimisyellow = true;
        }
        string excl = ICON_FA_EXCLAMATION_TRIANGLE;
        DrawBorderString(Icon, 45, excl, glWidth / 2 - 270.0f, glHeight / 100 * 20.0f, Red, true);
        DrawBorderString(Icon, 45, aimingtext, glWidth / 2, glHeight / 100 * 20.0f, Red, true);
        DrawBorderString(Icon, 45, excl, glWidth / 2 + 270.0f, glHeight / 100 * 20.0f, Red, true);
    }
    else
    {
        if (aimcalled >= 50)
        {
            aimcalled = 0;
            aimisyellow = false;
        }
        string excl = ICON_FA_EXCLAMATION_TRIANGLE;
        DrawBorderString(Icon, 45, excl, glWidth / 2 - 270.0f, glHeight / 100 * 20.0f, Yellow, true);
        DrawBorderString(Icon, 45, aimingtext, glWidth / 2, glHeight / 100 * 20.0f, Yellow, true);
        DrawBorderString(Icon, 45, excl, glWidth / 2 + 270.0f, glHeight / 100 * 20.0f, Yellow, true);
    }
    aimcalled++;
}
std::string GetPackage()
{
    FILE *f = fopen("/proc/self/cmdline", "rb");
    if (f)
    {
        char *buf = new char[64];
        fread(buf, sizeof(char), 64, f);
        fclose(f);
        return buf;
    }
    return 0;
}


inline bool exists(const std::string &name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}
