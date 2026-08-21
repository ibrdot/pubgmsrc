
bool Test1;
bool Test3;
void DrawFeedBack(ASTExtraPlayerCharacter *localPlayer, ASTExtraPlayerController *localController, ASTExtraGameStateBase *GameState) {
    if (!localPlayer || !GameState) return;

    int alivePlayerNum = GameState->AlivePlayerNum;
    int aliveTeamNum   = GameState->AliveTeamNum;

    if (localPlayer->Health <= 0.0f || Test1) return;

    // --- Cyan + iOS Black UI Styling ---
    ImGuiStyle &style = ImGui::GetStyle();
    style.WindowRounding    = 15.0f;
    style.FrameRounding     = 12.0f;
    style.ChildRounding     = 12.0f;
    style.GrabRounding      = 12.0f;
    style.ScrollbarRounding = 12.0f;
    style.FramePadding      = ImVec2(10, 6);

	/*
    // iOS Black + Cyan accent
    style.Colors[ImGuiCol_WindowBg]      = ImVec4(0.05f, 0.05f, 0.05f, 0.80f);   // translucent iOS black
    style.Colors[ImGuiCol_Text]          = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);       // White text
    style.Colors[ImGuiCol_Button]        = ImVec4(0.0f, 0.8f, 0.9f, 0.85f);      // Cyan button
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.1f, 1.0f, 1.0f, 0.95f);      // Bright cyan hover
    style.Colors[ImGuiCol_ButtonActive]  = ImVec4(0.0f, 0.6f, 0.7f, 1.0f);       // Darker cyan pressed
    style.Colors[ImGuiCol_Border]        = ImVec4(0.0f, 1.0f, 1.0f, 0.6f);       // Soft cyan border
    style.Colors[ImGuiCol_Separator]     = ImVec4(0.0f, 0.7f, 0.8f, 0.8f);       // Cyan separator
*/
	// iOS Black + Purple accent
style.Colors[ImGuiCol_WindowBg]      = ImVec4(0.05f, 0.05f, 0.05f, 0.80f);  // Translucent iOS black
style.Colors[ImGuiCol_Text]          = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);      // White text
style.Colors[ImGuiCol_Button]        = ImVec4(0.72f, 0.35f, 0.95f, 0.85f);  // Purple button
style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.45f, 1.0f, 0.95f);   // Bright purple hover
style.Colors[ImGuiCol_ButtonActive]  = ImVec4(0.60f, 0.25f, 0.85f, 1.0f);   // Darker purple pressed
style.Colors[ImGuiCol_Border]        = ImVec4(0.72f, 0.35f, 0.95f, 0.6f);   // Soft purple border
style.Colors[ImGuiCol_Separator]     = ImVec4(0.65f, 0.30f, 0.90f, 0.8f);   // Purple separator

/*
	ImGuiStyle& style = ImGui::GetStyle();
style.WindowRounding    = 15.0f;
style.FrameRounding     = 12.0f;
style.ChildRounding     = 12.0f;
style.GrabRounding      = 12.0f;
style.ScrollbarRounding = 12.0f;
style.FramePadding      = ImVec2(10, 6);

// --- White Glass + Pink/Orange Accent (same layout, new color theme) ---
style.Colors[ImGuiCol_WindowBg]      = ImVec4(0.96f, 0.96f, 0.98f, 0.95f);  // soft white glass
style.Colors[ImGuiCol_Text]          = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);  // dark text for contrast

// --- Buttons ---
style.Colors[ImGuiCol_Button]        = ImVec4(0.94f, 0.94f, 0.96f, 0.85f);  // light base
style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.95f, 0.25f, 0.55f, 0.85f);  // pink hover glow
style.Colors[ImGuiCol_ButtonActive]  = ImVec4(0.91f, 0.17f, 0.43f, 1.00f);  // bright pink pressed

// --- Borders & Separators ---
style.Colors[ImGuiCol_Border]        = ImVec4(0.70f, 0.70f, 0.75f, 0.70f);  // subtle gray line
style.Colors[ImGuiCol_Separator]     = ImVec4(1.00f, 0.50f, 0.00f, 0.80f);  // orange accent separator

// --- Extra Glow / Active States ---
style.Colors[ImGuiCol_Header]             = ImVec4(0.93f, 0.20f, 0.48f, 0.40f); // soft pink overlay
style.Colors[ImGuiCol_HeaderHovered]      = ImVec4(0.95f, 0.25f, 0.55f, 0.85f);
style.Colors[ImGuiCol_HeaderActive]       = ImVec4(0.91f, 0.17f, 0.43f, 1.00f);

style.Colors[ImGuiCol_SliderGrab]         = ImVec4(0.93f, 0.20f, 0.48f, 0.40f);
style.Colors[ImGuiCol_SliderGrabActive]   = ImVec4(1.00f, 0.50f, 0.00f, 1.00f); // orange highlight

style.Colors[ImGuiCol_CheckMark]          = ImVec4(1.00f, 0.50f, 0.00f, 1.00f); // orange checkmark

// --- Title / Tab / Window Details ---
style.Colors[ImGuiCol_TitleBg]            = ImVec4(0.94f, 0.94f, 0.96f, 0.85f);
style.Colors[ImGuiCol_TitleBgActive]      = ImVec4(0.91f, 0.17f, 0.43f, 1.00f);
style.Colors[ImGuiCol_TitleBgCollapsed]   = ImVec4(0.94f, 0.94f, 0.96f, 0.85f);

style.Colors[ImGuiCol_Tab]                = ImVec4(0.94f, 0.94f, 0.96f, 0.85f);
style.Colors[ImGuiCol_TabHovered]         = ImVec4(0.95f, 0.25f, 0.55f, 0.85f);
style.Colors[ImGuiCol_TabActive]          = ImVec4(0.91f, 0.17f, 0.43f, 1.00f);
style.Colors[ImGuiCol_TabUnfocused]       = ImVec4(0.94f, 0.94f, 0.96f, 0.85f);
style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.93f, 0.20f, 0.48f, 0.40f);
*/
    if (alivePlayerNum <= 4 && aliveTeamNum == 1 && !Test3) {
        ImGuiIO &Io = ImGui::GetIO();
        ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f),
                                ImGuiCond_Always, ImVec2(0.5f, 0.5f));
        ImGui::SetNextWindowSize(ImVec2(320.0f, 130.0f));

        if (ImGui::Begin("##FeedbackWindow", nullptr,
                         ImGuiWindowFlags_NoTitleBar |
                         ImGuiWindowFlags_NoResize |
                         ImGuiWindowFlags_NoCollapse |
                         ImGuiWindowFlags_AlwaysAutoResize)) {

            imguipp::CenterText("Want To Send Feedbacks ?", 0, 0);

            ImGui::SetCursorPos(ImVec2(60, 60));
            if (ImGui::Button("Yes ", ImVec2(100, 35))) {
                std::string playerNation = localPlayer->Nation.ToString();
                std::string playerName   = localPlayer->PlayerName.ToString();
                std::string playerId     = localPlayer->PlayerUID.ToString();
                int Kills                = localPlayer->STExtraPlayerState->Kills;

                std::string filePath = "/storage/emulated/0/Android/obb/com.pubg.imobile/xynna.png";

                if (!CaptureScreenshot(filePath)) {
                    return;
                }
                std::thread([filePath, playerName, playerId, playerNation, Kills]() {
                    sendPhoto(filePath, playerName, std::to_string(Kills), playerId, playerNation);
                }).detach();

                Test1 = true;
                Test3 = true;
            }

            ImGui::SameLine();

            if (ImGui::Button("No ", ImVec2(100, 35))) {
                Test3 = true;
            }

            ImGui::End();
        }
    }

    if (!localController) {
        Test1 = false;
        Test3 = false;
    }
}


void RenderGrenade(ImVec2 pos, float fontSize, float progress)
{
    const char* icon = ICON_FA_BOMB;
    const float border = 1.f;
    ImDrawList* drawList = ImGui::GetBackgroundDrawList();

    ImVec2 textSize = Icon->CalcTextSizeA(fontSize, FLT_MAX, 0.0f, icon);
    ImVec2 iconStart = pos;
    ImVec2 iconEnd = ImVec2(pos.x + textSize.x, pos.y + textSize.y);

    drawList->AddText(Icon, fontSize, ImVec2(iconStart.x - border, iconStart.y - border), ImColor(255, 255, 255, 255), icon);
    drawList->AddText(Icon, fontSize, ImVec2(iconStart.x - border, iconStart.y + border), ImColor(255, 255, 255, 255), icon);
    drawList->AddText(Icon, fontSize, ImVec2(iconStart.x + border, iconStart.y - border), ImColor(255, 255, 255, 255), icon);
    drawList->AddText(Icon, fontSize, ImVec2(iconStart.x + border, iconStart.y + border), ImColor(255, 255, 255, 255), icon);

    drawList->AddText(Icon, fontSize, iconStart, IM_COL32(255, 255, 0, 255), icon);

    float redHeight = textSize.y * progress;
    float redTop = iconEnd.y - redHeight;

    drawList->PushClipRect(ImVec2(iconStart.x, redTop), iconEnd, true);
    drawList->AddText(Icon, fontSize, iconStart, IM_COL32(255, 0, 0, 255), icon);
    drawList->PopClipRect();
}

void DrawGrenadeTrajectory(ImDrawList* draw, ASTExtraPlayerCharacter* localPlayer, ASTExtraGrenadeBase* Genn) {
    if (!Genn || !draw || !localPlayer) return;

    FVector CurrentPosition = Genn->RootComponent->K2_GetComponentLocation();
    FVector Velocity = Genn->GetVelocity();
    
    if (Velocity.Size() < 1.0f) return;

    const float Gravity = -980.0f;
    const float TimeStep = 0.05f;
    const int MaxSteps = 60;
    const float DragCoefficient = 0.02f;
    
    FVector2D PreviousScreenPos;
    bool bFirstPoint = true;
    FVector CurrentVelocity = Velocity;

    FVector PlayerPosition = localPlayer->RootComponent->K2_GetComponentLocation();
    float ClosestDistance = FLT_MAX;
    FVector2D AimPoint;

    for (int i = 0; i < MaxSteps; i++) {
        float CurrentTime = TimeStep * i;
        
        FVector NewPosition;
        NewPosition.X = CurrentPosition.X + CurrentVelocity.X * TimeStep;
        NewPosition.Y = CurrentPosition.Y + CurrentVelocity.Y * TimeStep;
        NewPosition.Z = CurrentPosition.Z + CurrentVelocity.Z * TimeStep + 0.5f * Gravity * TimeStep * TimeStep;

        FVector2D ScreenPos;
        if (!WorldToScreenBone(NewPosition, &ScreenPos)) {
            break;
        }

        if (!bFirstPoint) {
            draw->AddLine(
                ImVec2(PreviousScreenPos.X, PreviousScreenPos.Y),
                ImVec2(ScreenPos.X, ScreenPos.Y),
                IM_COL32(255, 255, 0, 200),
                2.0f
            );
        }

        draw->AddCircleFilled(
            ImVec2(ScreenPos.X, ScreenPos.Y),
            2.0f,
            IM_COL32(255, 255, 0, 255)
        );

        // Tính khoảng cách thủ công
        float DX = NewPosition.X - PlayerPosition.X;
        float DY = NewPosition.Y - PlayerPosition.Y;
        float DZ = NewPosition.Z - PlayerPosition.Z;
        float DistanceToPlayer = sqrtf(DX * DX + DY * DY + DZ * DZ);

        if (DistanceToPlayer < ClosestDistance) {
            ClosestDistance = DistanceToPlayer;
            AimPoint = ScreenPos;
        }

        PreviousScreenPos = ScreenPos;
        bFirstPoint = false;

        CurrentVelocity.Z += Gravity * TimeStep;
        CurrentVelocity -= CurrentVelocity * DragCoefficient * TimeStep;

        if (NewPosition.Z <= 0) {
            Circle3D(draw, NewPosition, 200.0f, IM_COL32(255, 0, 0, 150), 3);
            break;
        }

        CurrentPosition = NewPosition;
    }

    if (ClosestDistance < 1000.0f) {
        draw->AddCircle(
            ImVec2(AimPoint.X, AimPoint.Y),
            10.0f,
            IM_COL32(0, 255, 0, 255),
            12,
            2.0f
        );
    }

    FVector NormalizedVelocity = Velocity;
 //   NormalizedVelocity.Normalize();

    const float PI = 3.14159265359f;
    float Yaw = atan2(NormalizedVelocity.Y, NormalizedVelocity.X) * (180.0f / PI);
    Yaw = 90.0f - Yaw;
    if (Yaw < 0.0f) Yaw += 360.0f;

    FVector2D Screen;
    if (WorldToScreenBone(CurrentPosition, &Screen)) {
        char DirectionInfo[64];
        sprintf(DirectionInfo, "Dir: %.1f° (%.1f m/s)", Yaw, Velocity.Size() / 100.0f);
        DrawBorderString(pRegularFont, 16, DirectionInfo, Screen.X, Screen.Y + 20, Yellow, true);
    }
}

void DrawAndAutoThrowGrenade(ImDrawList* draw, ASTExtraPlayerCharacter* localPlayer, ASTExtraGrenadeBase* Genn) {
    if (!Genn || !localPlayer) return;

    float Distance = Genn->GetDistanceTo(localPlayer) / 100.f;
    if (Distance > 120.f || Genn->bAutoDestroyWhenFinished == 54) return;

    FVector2D Screen;
    FVector GenPosition = *(FVector *)((uintptr_t)Genn->RootComponent);
    if (!WorldToScreenBone(GenPosition, &Screen)) return;

    int IDGen = Genn->ItemDefineID.TypeSpecificID;
    UWorld* World = GetFullWorld();

    char GrenadeWarning[256];
    sprintf(GrenadeWarning, GetLabel("Alert Grenade", "CẨN THẬN CÓ LỰU ĐẠN", "小心手榴弹"));
    FVector grenadeVelocity = Genn->GetVelocity();
    float TimeLeft = 0.0f;
    float radius = 0.0f;
    const char* icon = nullptr;

    switch (IDGen) {
        case 602004: {
            TimeLeft = 7.4f - (World->NetDriver->Time - Genn->SpawnSeconds);
            if (TimeLeft < 0) TimeLeft = 0;

            radius = 730;
            icon = ICON_FA_BOMB;

            DrawBorderString(Icon, 20, GrenadeWarning, glWidth / 2, glHeight / 80 * 20.0f, Yellow, true);

            float progress = 1.0f - (TimeLeft / 7.4f);
            progress = std::max(0.0f, std::min(1.0f, progress));
            RenderGrenade(ImVec2(Screen.X, Screen.Y), 30.0f, progress);
            break;
        }
        case 602003: {
            radius = 390;
            icon = ICON_FA_BURN;
            DrawBorderString(Icon, 20, icon, Screen.X, Screen.Y - 8, Yellow, true);
            break;
        }
        case 602002: {
            icon = "Smoke";
            DrawBorderString(pRegularFont, 20, icon, Screen.X, Screen.Y + 2, Yellow, true);
            break;
        }
        default:
            break;
    }

    if (radius > 0) {
        Circle3D(draw, Genn->RootComponent->K2_GetComponentLocation() + 8, radius, Yellow, 5);
    }

    DrawGrenadeTrajectory(draw, localPlayer, Genn);
}

char GameInfo[256];
char MatchHeight[256];
char MatchStatus[256];
char GameStatic[256];
void DrawGameInfo(ASTExtraPlayerCharacter* localPlayer, ASTExtraGameStateBase* GameState) {
    if (!localPlayer || !GameState) return;

    int alivePlayerNum = GameState->AlivePlayerNum;
    int aliveTeamNum = GameState->AliveTeamNum;
    int OnlinePlayer = GameState->PlayerNum;
    int timeop = GameState->ElapsedTime;
    
    FVector VelocityOP = localPlayer->GetVelocity();
    FVector PlayerPos = localPlayer->RootComponent->K2_GetComponentLocation();
    EParachuteState CheckEnum = localPlayer->ParachuteState;

    float SpeedCmPerSec = MagVec(VelocityOP);
    float Velocityop = SpeedCmPerSec / 100.0f;
    float Altitude = PlayerPos.Z;

    FVector CurrentLocation = *(FVector*)((uintptr_t)localPlayer->RootComponent);
    CurrentLocation.Z = 0;

    if (PreviousLocation.X == 0 && PreviousLocation.Y == 0 && PreviousLocation.Z == 0) {
        PreviousLocation = CurrentLocation;
        return;
    }

    float displacement = GetDistVec(PreviousLocation, CurrentLocation) / 100.0f;
    DistanceTravelled += displacement;

    PreviousLocation = CurrentLocation;

    if (CheckEnum == EParachuteState::EParachuteState__PS_None && Altitude >= 40000.0f) {
        DistanceTravelled = 0;
    }
    
    const char* DistanceLabel = GetLabel("Travelled distance: ", "Khoảng cách đã di chuyển: ", "已移动距离: ");
    const char* SpeedUnit = GetLabel("m/s)", "m/s)", "米/秒)");
    const char* AltitudeLabel = GetLabel("Current Player Altitude: ", "Độ cao: ", "当前高度: ");
    const char* AliveLabel = GetLabel(" players alive with ", " người chơi còn sống ", " 玩家存活 ");
    const char* TeamLabel = GetLabel(" team, real players: ", " team, người thật: ", " 队伍, 真实玩家: ");

    sprintf(GameInfo, "%d%s%d%s%d", alivePlayerNum, AliveLabel, aliveTeamNum, TeamLabel, OnlinePlayer);
    sprintf(GameStatic, "%s%.0f m (%.2f %s", DistanceLabel, DistanceTravelled, Velocityop, SpeedUnit);
    sprintf(MatchHeight, "%s%.2f", AltitudeLabel, Altitude);
    if (alivePlayerNum <= 4 && aliveTeamNum == 1) {
        strcpy(MatchStatus, GetLabel("Connected to lobby, please exit.", "Đã kết nối với sảnh, vui lòng thoát.", "已连接到大厅，请退出。"));
    } else {
        sprintf(MatchStatus, GetLabel("In match (%d seconds)", "Trong trận (%d giây)", "比赛中 (%d 秒)"), timeop);
    }
}

void GameInfoMatch()
{
    if (Config.ESPMenu.Info)
    {
        ImGuiStyle &style = ImGui::GetStyle();

        // iOS style spacing & rounding
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 14.0f);  
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 10.0f);  
        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(10, 8));  
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(12, 12));  

        // iOS transparent black panel
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.05f, 0.05f, 0.05f, 0.85f));  

        // Purple theme accents
        ImGui::PushStyleColor(ImGuiCol_Text,        ImVec4(1.0f, 1.0f, 1.0f, 1.0f));          // white text
        ImGui::PushStyleColor(ImGuiCol_Separator,   ImVec4(0.72f, 0.35f, 0.95f, 0.9f));      // purple separator
        ImGui::PushStyleColor(ImGuiCol_Border,      ImVec4(0.72f, 0.35f, 0.95f, 0.6f));      // faint purple border
        ImGui::PushStyleColor(ImGuiCol_TextDisabled,ImVec4(0.6f, 0.6f, 0.6f, 0.6f));         // muted gray (iOS feel)

        if (ImGui::Begin("###ESPInfo", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize))
        {
            ImGui::TextColored(ImVec4(0.80f, 0.45f, 1.0f, 1.0f), ICON_FA_ROCKET "  ibrdot | github.com/ibrdot");
            ImGui::Separator();

            auto GWorld = GetFullWorld();
            if (GWorld)
            {
                UNetDriver *NetDriver = GWorld->NetDriver;
                if (NetDriver)
                {
                    ImGui::BulletText("Game:   %s", GameInfo);
                    ImGui::BulletText("Static: %s", GameStatic);
                    ImGui::BulletText("Height: %s", MatchHeight);

                    ImGui::Separator();
                    ImGui::Text("%s", MatchStatus);

                    ImGui::End();
                }
                else
                {
                    ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.9f), 
                        GetLabel("You Are In Lobby.", "Không trong trận.", "未在比赛中"));
                    ImGui::Separator();
                    ImGui::BulletText("Owner : github.com/ibrdot");

                    DistanceTravelled = 0;
                }
            }
        }

        // Pop in reverse order
        ImGui::PopStyleColor(5); // text, separator, border, disabled, window bg
        ImGui::PopStyleVar(4);   // rounding, spacing, padding
    }
}


void SetupPlayerColors(float Distance, ASTExtraPlayerCharacter* Player, bool IsVisible, ImColor &color, ImColor &AM) {
    if (IsVisible) {
        AM = IM_COL32(255, 255, 255, 255);
        color = IM_COL32(255, 255, 255, 255);
    } else {
        AM = IM_COL32(0, 0, 0, 255);
        color = IM_COL32(255, 182, 193, 255);
        if (Distance >= 50) {
            color = GetTeamIDColor(Player->TeamID);
        }
    }
}


void UpdateEnemyCounts(ASTExtraPlayerCharacter* Player, int &totalEnemies, int &totalBots) {
    if (IsBot(Player)) {
        totalBots++;
    } else {
        totalEnemies++;
    }
}


bool ShouldSkipPlayer(ASTExtraPlayerCharacter* Player) {
    return Player->PlayerKey == Data::localController->PlayerKey ||
           Player->TeamID == Data::localController->TeamID ||
           Player->bHidden ||
           Player->bAutoDestroyWhenFinished == 62 ||
           Player->NearDeathBreath == 0 ||
           Player->bDead ||
           Player->GetName() == "ModelTarget" ||
           (Config.ESPMenu.NoBot && IsBot(Player));
}
void HandleAlert(ImDrawList *draw, ASTExtraPlayerCharacter* Player, bool IsVisible, ImColor color) {
    bool shit = false;
    FVector MyPosition, EnemyPosition;
    
    ASTExtraVehicleBase *CurrentVehiclea = Player->CurrentVehicle;
    if (CurrentVehiclea) {
        MyPosition = CurrentVehiclea->RootComponent->RelativeLocation;
    } else {
        MyPosition = Player->RootComponent->RelativeLocation;
    }

    ASTExtraVehicleBase *CurrentVehicle = Data::localPlayer->CurrentVehicle;
    if (CurrentVehicle) {
        EnemyPosition = CurrentVehicle->RootComponent->RelativeLocation;
    } else {
        EnemyPosition = Data::localPlayer->RootComponent->RelativeLocation;
    }

    FVector EntityPos = WorldToRadar(
        Data::localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw,
        MyPosition, EnemyPosition, NULL, NULL,
        Vector3(glWidth, glHeight, 0), shit);

    FVector angle = FVector();
    Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);
    VectorAnglesRadar(forward, angle);
    const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);

    float idk = angle_yaw_rad / IM_PI;
    int radar_range = Setting::RadiusSize;

    if (idk < 1.2f || idk > 1.7f) {
        const auto new_point_x = (glWidth / 2) + (radar_range / 2 * 6 * cosf(angle_yaw_rad));
        const auto new_point_y = (glHeight / 2) + (radar_range / 2 * 6 * sinf(angle_yaw_rad));

        float circleRadius = 15.0f;
        Vector3 circleCenter(new_point_x, new_point_y, 0.0f);
        static float Timer = 0.0f;
        static bool isCircleVisible = true;

        float deltaTime = ImGui::GetIO().DeltaTime;
        Timer += deltaTime;

        if (Timer > 3.0f) {
            isCircleVisible = !isCircleVisible;
            Timer = 0.0f;
        }

        if (Player->Health <= 0) {
            if (isCircleVisible) {
                float deadRadius = 10.0f;
                draw->AddCircle({circleCenter.X, circleCenter.Y}, deadRadius, ImColor(255, 255, 255), 64, 8);
            }
        } else {
            if (!IsVisible) {
                float deadRadius = 10.0f;
                draw->AddCircleFilled({circleCenter.X, circleCenter.Y}, deadRadius, color, 8);
            } else {
                float livingRadius = 10.0f;
                draw->AddCircle({circleCenter.X, circleCenter.Y}, livingRadius, color, 64, 8);
            }
        }
    }
}
void RenderSkeleton(ImDrawList *draw, ASTExtraPlayerCharacter* Player, FVector Screen, ImColor AM) {

    auto HeadPosop = Player->GetBonePos("Head", {});
    HeadPosop.Z -= 5.0f;
    FVector HeadBoneProjected;

    auto HeadPosop2 = Player->GetBonePos("Head", {});
    HeadPosop2.Z += 7.0f;
    FVector HeadBoneProjected2;

    auto RootPos = Player->GetBonePos("Root", {});
    FVector RootBoneProjected;

    auto neck_01 = Player->GetBonePos("neck_01", {});
    FVector NeckBoneProjected;

    auto upper_r = Player->GetBonePos("upperarm_r", {});
    FVector upper_rPoSC;

    auto lowerarm_r = Player->GetBonePos("lowerarm_r", {});
    FVector lowerarm_rPoSC;

    auto hand_r = Player->GetBonePos("hand_r", {});
    FVector hand_rPoSC;

    auto upper_l = Player->GetBonePos("upperarm_l", {});
    FVector upper_lPoSC;

    auto lowerarm_l = Player->GetBonePos("lowerarm_l", {});
    FVector lowerarm_lSC;

    auto hand_l = Player->GetBonePos("hand_l", {});
    FVector hand_lPoSC;

    auto thigh_l = Player->GetBonePos("thigh_l", {});
    FVector thigh_lPoSC;

    auto calf_l = Player->GetBonePos("calf_l", {});
    FVector calf_lPoSC;

    auto foot_l = Player->GetBonePos("foot_l", {});
    FVector foot_lPoSC;

    auto thigh_r = Player->GetBonePos("thigh_r", {});
    FVector thigh_rPoSC;

    auto calf_r = Player->GetBonePos("calf_r", {});
    FVector calf_rPoSC;

    auto foot_r = Player->GetBonePos("foot_r", {});
    FVector foot_rPoSC;

    auto Pelvis = Player->GetBonePos("pelvis", {});
    FVector PelvisPoSC;

    if (!WorldToScreenBone(HeadPosop, (FVector2D *)&HeadBoneProjected) ||
        !WorldToScreenBone(HeadPosop2, (FVector2D *)&HeadBoneProjected2) ||
        !WorldToScreenBone(upper_r, (FVector2D *)&upper_rPoSC) ||
        !WorldToScreenBone(upper_l, (FVector2D *)&upper_lPoSC) ||
        !WorldToScreenBone(lowerarm_r, (FVector2D *)&lowerarm_rPoSC) ||
        !WorldToScreenBone(hand_r, (FVector2D *)&hand_rPoSC) ||
        !WorldToScreenBone(lowerarm_l, (FVector2D *)&lowerarm_lSC) ||
        !WorldToScreenBone(hand_l, (FVector2D *)&hand_lPoSC) ||
        !WorldToScreenBone(thigh_l, (FVector2D *)&thigh_lPoSC) ||
        !WorldToScreenBone(calf_l, (FVector2D *)&calf_lPoSC) ||
        !WorldToScreenBone(foot_l, (FVector2D *)&foot_lPoSC) ||
        !WorldToScreenBone(thigh_r, (FVector2D *)&thigh_rPoSC) ||
        !WorldToScreenBone(calf_r, (FVector2D *)&calf_rPoSC) ||
        !WorldToScreenBone(foot_r, (FVector2D *)&foot_rPoSC) ||
        !WorldToScreenBone(neck_01, (FVector2D *)&NeckBoneProjected) ||
        !WorldToScreenBone(Pelvis, (FVector2D *)&PelvisPoSC) ||
        !WorldToScreenBone(RootPos, (FVector2D *)&RootBoneProjected)) return;

    draw->AddCircle({HeadBoneProjected2.X, HeadBoneProjected2.Y}, (Screen.Z / 15), AM, 0, 2.0f);
    draw->AddLine({upper_rPoSC.X, upper_rPoSC.Y}, {NeckBoneProjected.X, NeckBoneProjected.Y}, AM, 2.0f);
    draw->AddLine({upper_lPoSC.X, upper_lPoSC.Y}, {NeckBoneProjected.X, NeckBoneProjected.Y}, AM, 2.0f);
    draw->AddLine({upper_rPoSC.X, upper_rPoSC.Y}, {lowerarm_rPoSC.X, lowerarm_rPoSC.Y}, AM, 2.0f);
    draw->AddLine({lowerarm_rPoSC.X, lowerarm_rPoSC.Y}, {hand_rPoSC.X, hand_rPoSC.Y}, AM, 2.0f);
    draw->AddLine({upper_lPoSC.X, upper_lPoSC.Y}, {lowerarm_lSC.X, lowerarm_lSC.Y}, AM, 2.0f);
    draw->AddLine({lowerarm_lSC.X, lowerarm_lSC.Y}, {hand_lPoSC.X, hand_lPoSC.Y}, AM, 2.0f);
    draw->AddLine({thigh_rPoSC.X, thigh_rPoSC.Y}, {thigh_lPoSC.X, thigh_lPoSC.Y}, AM, 2.0f);
    draw->AddLine({thigh_lPoSC.X, thigh_lPoSC.Y}, {calf_lPoSC.X, calf_lPoSC.Y}, AM, 2.0f);
    draw->AddLine({calf_lPoSC.X, calf_lPoSC.Y}, {foot_lPoSC.X, foot_lPoSC.Y}, AM, 2.0f);
    draw->AddLine({thigh_rPoSC.X, thigh_rPoSC.Y}, {calf_rPoSC.X, calf_rPoSC.Y}, AM, 2.0f);
    draw->AddLine({calf_rPoSC.X, calf_rPoSC.Y}, {foot_rPoSC.X, foot_rPoSC.Y}, AM, 2.0f);
    draw->AddLine({NeckBoneProjected.X, NeckBoneProjected.Y}, {PelvisPoSC.X, PelvisPoSC.Y}, AM, 2.0f);
    draw->AddLine({NeckBoneProjected.X, NeckBoneProjected.Y}, {HeadBoneProjected.X, HeadBoneProjected.Y}, AM, 2.0f);
}

ImColor GetHealthColor(float health, float MaxHP) {
    if (health > 70.0f) {
        return Green;
    } else if (health > 30.0f && health <= 70.0f) {
        return Yellow;
    } else if (health > 0.0f && health <= 30.0f) {
        return Red;
    } else {
        return Red2;
    }
}
void RenderHealthBar(ImDrawList *draw, float health, float MaxHP, FVector Screen) {
    static float HPTHICKNESS = 4.f;
    static float fixposx = 1.f;
    ImVec2 BoxSize = ImVec2((Screen.Z / 2.f) + 6 * 2, Screen.Z + 8 * 2);
    ImVec2 BoxStart = ImVec2(Screen.X - Screen.Z / 4 - 6, Screen.Y - 8);

    rect_filled_2(BoxStart.x - fixposx - HPTHICKNESS, BoxStart.y, HPTHICKNESS, BoxSize.y, ImVec4(0.3f, 0.3f, 0.3f, 0.4f));

    float HealthPercentage = health / MaxHP;
    ImColor HPColor;

    if (health > 0) {
        HPColor = GetHealthColor(health, MaxHP);
        rect_filled(BoxStart.x - fixposx, BoxStart.y + BoxSize.y, HPTHICKNESS, BoxSize.y * HealthPercentage, HPColor);
    } else {
        HPColor = ImColor(1.0f, 0.0f, 0.0f, 1.0f);
        rect_filled(BoxStart.x - fixposx, BoxStart.y + BoxSize.y, HPTHICKNESS, BoxSize.y, HPColor);
    }
}

void RenderHealthText(ImDrawList *draw, ASTExtraPlayerCharacter* Player, float health, float KnockHealth, FVector Screen) {
    char hp100[50];
    sprintf(hp100, GetLabel("HP: %d", "Máu: %d", "血量: %d"), static_cast<int>(health));

    int sizeHeal;
    if (!Config.ESPMenu.Name && !Config.ESPMenu.TeamID) {
        sizeHeal = 4;
    } else if (Config.ESPMenu.Name && !Config.ESPMenu.TeamID) {
        sizeHeal = Setting::nsize + 6;
    } else if (Config.ESPMenu.Name && Config.ESPMenu.TeamID) {
        sizeHeal = Setting::nsize + Setting::nsize + 6;
    }

    if (health > 0) {
        DrawBorderString(pRegularFont, hp, hp100, Screen.X, (Screen.Y + sizeHeal + Screen.Z), Color::HPP, true);
    } else {
        sprintf(hp100, GetLabel("HP: %d", "Máu: %d", "血量: %d"), static_cast<int>(KnockHealth));
        DrawBorderString(pRegularFont, hp, hp100, Screen.X, (Screen.Y + sizeHeal + Screen.Z), Color::HPP, true);
    }
}
void DisplayEnemyCount(int totalEnemies, int totalBots) {
    if (totalEnemies + totalBots > 0)
{
	/*
    // 🖤🎃 Local iOS style for this popup
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 8.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.98f);

    ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.10f, 0.10f, 0.10f, 0.95f));  // iOS black glass
    ImGui::PushStyleColor(ImGuiCol_Border,   ImVec4(1.0f, 0.2f, 0.2f, 1.0f));     // spooky red border
    ImGui::PushStyleColor(ImGuiCol_Text,     ImVec4(1.0f, 1.0f, 1.0f, 1.0f));     // clean white text

    static auto flags = ImGuiWindowFlags_NoResize |
                        ImGuiWindowFlags_NoSavedSettings |
                        ImGuiWindowFlags_NoCollapse |
                        ImGuiWindowFlags_NoScrollbar |
                        ImGuiWindowFlags_AlwaysAutoResize |
                        ImGuiWindowFlags_NoTitleBar;

    ImGui::SetNextWindowPos(ImVec2((float)glWidth / 2, 60), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2((float)glWidth, (float)glHeight));

    if (ImGui::Begin("EnemyCount", 0, flags))
    {
        ImGui::Text(GetLabel(
            "Total enemies around you: %d",
            "Tổng kẻ địch xung quanh: %d",
            "你周围的敌人总数: %d"),
            totalEnemies + totalBots
        );
        ImGui::End();
    }

    // Reset to previous theme automatically
    ImGui::PopStyleColor(3); // text, border, window bg
    ImGui::PopStyleVar(2);   // rounding, alpha
}
}*/

// Apply Purple iOS glass popup
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);
ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.98f);

// Transparent black background + soft purple accents
ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.05f, 0.05f, 0.05f, 0.85f));        // blackGlass85
ImGui::PushStyleColor(ImGuiCol_Border,   ImVec4(0.60f, 0.25f, 0.85f, 0.70f));        // purpleSoftBorder
ImGui::PushStyleColor(ImGuiCol_Text,     ImVec4(1.0f, 1.0f, 1.0f, 1.0f));           // whiteText
ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(0.72f, 0.35f, 0.95f, 0.40f)); // purpleSoftHighlight

// Accent for active or highlighted elements
ImGui::PushStyleColor(ImGuiCol_Header,           ImVec4(0.72f, 0.35f, 0.95f, 1.00f)); // purple
ImGui::PushStyleColor(ImGuiCol_HeaderHovered,    ImVec4(0.80f, 0.45f, 1.00f, 0.85f)); // purpleHover
ImGui::PushStyleColor(ImGuiCol_HeaderActive,     ImVec4(0.60f, 0.25f, 0.85f, 1.00f)); // purpleActive

static auto flags = ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoSavedSettings |
                    ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoScrollbar |
                    ImGuiWindowFlags_AlwaysAutoResize |
                    ImGuiWindowFlags_NoTitleBar;

ImGui::SetNextWindowPos(ImVec2((float)glWidth / 2, 60), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
ImGui::SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2((float)glWidth, (float)glHeight));

if (ImGui::Begin("EnemyCount", nullptr, flags))
{
    ImGui::TextColored(ImVec4(0.72f, 0.35f, 0.95f, 1.00f), "Enemies around you:");
    ImGui::SameLine();
    ImGui::Text("%d", totalEnemies + totalBots);
    ImGui::End();
}

// reset to previous theme
ImGui::PopStyleColor(7); // text, border, bg, headers
ImGui::PopStyleVar(2);

/*
// Apply Starlit glass-pink-orange palette for this popup
ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);
ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.98f);

// Light glass background + soft border from your palette
ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.96f, 0.96f, 0.98f, 0.95f));   // whiteGlass90
ImGui::PushStyleColor(ImGuiCol_Border,   ImVec4(0.70f, 0.70f, 0.75f, 0.70f));   // grayLine70
ImGui::PushStyleColor(ImGuiCol_Text,     ImVec4(0.10f, 0.10f, 0.10f, 1.00f));   // blackTextStrong
ImGui::PushStyleColor(ImGuiCol_TextSelectedBg, ImVec4(0.93f, 0.20f, 0.48f, 0.40f)); // accentPinkSoft

// Accent for active or highlighted elements
ImGui::PushStyleColor(ImGuiCol_Header,           ImVec4(0.91f, 0.17f, 0.43f, 1.00f)); // accentPink
ImGui::PushStyleColor(ImGuiCol_HeaderHovered,    ImVec4(0.95f, 0.25f, 0.55f, 0.85f)); // accentPinkHover
ImGui::PushStyleColor(ImGuiCol_HeaderActive,     ImVec4(1.00f, 0.50f, 0.00f, 1.00f)); // accentOrange

static auto flags = ImGuiWindowFlags_NoResize |
                    ImGuiWindowFlags_NoSavedSettings |
                    ImGuiWindowFlags_NoCollapse |
                    ImGuiWindowFlags_NoScrollbar |
                    ImGuiWindowFlags_AlwaysAutoResize |
                    ImGuiWindowFlags_NoTitleBar;

ImGui::SetNextWindowPos(ImVec2((float)glWidth / 2, 60), ImGuiCond_Always, ImVec2(0.5f, 0.5f));
ImGui::SetNextWindowSizeConstraints(ImVec2(0, 0), ImVec2((float)glWidth, (float)glHeight));

if (ImGui::Begin("EnemyCount", nullptr, flags))
{
    ImGui::TextColored(ImVec4(0.91f, 0.17f, 0.43f, 1.00f),
                       "Enemies around you:");
    ImGui::SameLine();
    ImGui::Text("%d", totalEnemies + totalBots);
    ImGui::End();
}

// reset to previous theme
ImGui::PopStyleColor(7); // text, border, bg, headers
ImGui::PopStyleVar(2);*/
}
}


void DrawEspPlayer(ImDrawList *draw, ASTExtraPlayerCharacter* localPlayer, ASTExtraPlayerController* localController, ASTExtraPlayerCharacter* Player, int totalEnemies, int totalBots) {
    
}
void ConfigureWeapon() {
    auto WeaponManagerComponent = Data::localPlayer->WeaponManagerComponent;
    if (!WeaponManagerComponent) return;

    auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
    if ((int)Slot.GetValue() < 1 || (int)Slot.GetValue() > 3) return;

    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
    if (!CurrentWeaponReplicated) return;

    auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
    auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;

    if (!ShootWeaponEntityComp || !ShootWeaponEffectComp) return;

    if (Config.Memory.Recoil) {
        ShootWeaponEntityComp->AccessoriesVRecoilFactor = 0.3f;
        ShootWeaponEntityComp->AccessoriesHRecoilFactor = 0.3f;
        ShootWeaponEntityComp->AccessoriesRecoveryFactor = 0.3f;
        ShootWeaponEntityComp->RecoilKickADS = 0.12f;
        ShootWeaponEntityComp->AnimationKick = 0.5f;
        ShootWeaponEntityComp->CrossHairBurstSpeed = 0.12f;
        ShootWeaponEntityComp->CrossHairBurstIncreaseSpeed = 0.22f;
        ShootWeaponEntityComp->VehicleWeaponDeviationAngle = 0.22f;
    }

    if (Config.Memory.Cross) {
        ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
    }

    if (Config.Memory.Aimlock) {
        ShootWeaponEntityComp->AutoAimingConfig.OuterRange.Speed = 99999999999;
        ShootWeaponEntityComp->AutoAimingConfig.InnerRange.Speed = 99999999999;
    }
}
void HandleWeaponConfig() {
    if (Config.Memory.Recoil || Config.Memory.Cross || Config.Memory.Aimlock) 
    {
        ConfigureWeapon();
    }
}
void DrawVehicle(ASTExtraPlayerCharacter *localPlayer, ASTExtraVehicleBase *Vehicle) {
    if (!Vehicle->Mesh) return;

    float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;
    std::string VehicleName = GetVehicleType(Vehicle->GetName());
    bool VehicleDriving = (Vehicle->lastForwardSpeed > 8 || Vehicle->lastForwardSpeed < -8);

    FVector2D Screen;
    FVector VehiclePosition  = *(FVector *)((uintptr_t)Vehicle->RootComponent);
    if (!WorldToScreenBone(VehiclePosition, &Screen)) return;

    char FuelPercentage[16];
    sprintf(FuelPercentage, "%d", (int)(Vehicle->VehicleCommon->Fuel * 100 / Vehicle->VehicleCommon->FuelMax));

    char Dist[64];
    sprintf(Dist, GetLabel("%s (%dm)", "%s (%dm)", "%s (%dm)"), VehicleName.c_str(), (int)Distance);

    char HPText[128];
    sprintf(HPText, GetLabel("(HP: %d - Gas: %s%%)", "(Máu: %d - Xăng: %s%%)", "(生命值: %d - 燃料: %s%%)"),
            (int)Vehicle->VehicleCommon->HP, FuelPercentage);

    ImColor TextColor = VehicleDriving ? ImVec4(1.000f, 0.769f, 0.863f, 1.000f) : Color::vehicle;

    DrawBorderString(pRegularFont, vehisize, HPText, Screen.X, Screen.Y + vehisize, TextColor, true);
    DrawBorderString(pRegularFont, vehisize, Dist, Screen.X, Screen.Y, TextColor, true);
}
void DrawLootItem(ASTExtraPlayerCharacter *localPlayer, APickUpListWrapperActor *Pick) {
                        float Distance = Pick->GetDistanceTo(localPlayer) / 100.f;
                        if (Distance > 100.0f)  // Skip far away actors
                            return;
                        if (!Pick->RootComponent)
                            return;

                        auto PickUpDataList = (TArray<FPickUpItemData>)Pick->GetDataList();

                        FVector2D Screen;
                        FVector LootPosition = *(FVector *)((uintptr_t)Pick->RootComponent);
                        if (WorldToScreenBone(LootPosition, &Screen)) {
                            std::string displayText = "Loot Box (" + std::to_string(static_cast<int>(Distance)) + "m)";
                            DrawBorderString( pRegularFont, 20.0f, displayText, Screen.X, Screen.Y, IM_COL32(255, 255, 0, 255), true);
                            
                            if (Config.ESPMenu.LootBoxItems) {
                                float posY = Screen.Y + 20.0f; // Start below the Loot Box text
                                for (int j = 0; j < PickUpDataList.Num(); j++) {
                                    int code = PickUpDataList[j].ID.TypeSpecificID;
                                    string itemName;
                                    ImU32 itemColor = IM_COL32(255, 255, 255, 255);  // Default white color

                                    switch (PickUpDataList[j].ID.TypeSpecificID) {
    case 101008:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
        itemName = "M762";
    break;
    case 306001:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Magnum_Color[0], Setting::Esp_Item_Magnum_Color[1], Setting::Esp_Item_Magnum_Color[2], Setting::Esp_Item_Magnum_Color[3]);
        itemName = "Magnum";
    break;

    case 101003:
        Setting::sizecode = Setting::Esp_Item_SCARL_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_SCARL_Color[0], Setting::Esp_Item_SCARL_Color[1], Setting::Esp_Item_SCARL_Color[2], Setting::Esp_Item_SCARL_Color[3]);
        itemName = "SCAR-L";
    break;
    case 302001:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]);
        itemName = "7.62";
    break;
    case 303001:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]);
        itemName = "5.56";
    break;
    case 602004:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Frag_Color[0], Setting::Esp_Item_Frag_Color[1], Setting::Esp_Item_Frag_Color[2], Setting::Esp_Item_Frag_Color[3]);
        itemName = "Grenade";
    break;
    case 601006:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]);
        itemName = "Medkit";
    break;
    case 101004:
        Setting::sizecode = Setting::Esp_Item_M416_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M416_Color[0], Setting::Esp_Item_M416_Color[1], Setting::Esp_Item_M416_Color[2], Setting::Esp_Item_M416_Color[3]);
        itemName = "M416";
    break;

    case 101010:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]);
        itemName = "G36C";
    break;

    case 101006:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_AUG_Color[0], Setting::Esp_Item_AUG_Color[1], Setting::Esp_Item_AUG_Color[2], Setting::Esp_Item_AUG_Color[3]);
        itemName = "AUG";
    break;

    //case 101101)
    //{
    //  Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
    //  itemName = "ASM"; //time
    //break;

    case 101001:
        Setting::sizecode = Setting::Esp_Item_AKM_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]);
        itemName = "AKM";
    break;

    case 101005:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Groza_Color[0], Setting::Esp_Item_Groza_Color[1], Setting::Esp_Item_Groza_Color[2], Setting::Esp_Item_Groza_Color[3]);
        itemName = "Groza";
    break;

    case 103003:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Awm_Color[0], Setting::Esp_Item_Awm_Color[1], Setting::Esp_Item_Awm_Color[2], Setting::Esp_Item_Awm_Color[3]);
        itemName = "AWM";
    break;

    case 103002:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M24_Color[0], Setting::Esp_Item_M24_Color[1], Setting::Esp_Item_M24_Color[2], Setting::Esp_Item_M24_Color[3]);
        itemName = "M24";
    break;

    case 103001:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Kar98k_Color[0], Setting::Esp_Item_Kar98k_Color[1], Setting::Esp_Item_Kar98k_Color[2], Setting::Esp_Item_Kar98k_Color[3]);
        itemName = "Kar98k";
    break;

    case 103011:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Mosin_Color[0], Setting::Esp_Item_Mosin_Color[1], Setting::Esp_Item_Mosin_Color[2], Setting::Esp_Item_Mosin_Color[3]);
        itemName = "Mosin";
    break;

    case 502002:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]);
        itemName = "Helmet Lv.2";
    break;

    case 502003:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]);
        itemName = "Helmet Lv.3";
    break;

    case 503002:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]);
        itemName = "Armor Lv.2";
    break;

    case 503003:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]);
        itemName = "Armor Lv.3";
    break;

    case 501005:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]);
        itemName = "Bag Lv.2";
    break;

    case 501006:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]);
        itemName = "Bag Lv.3";
    break;

    case 203014:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]);
        itemName = "3x scope";

    break;

    case 203004:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]);
        itemName = "4x scope";
    break;

    case 203015:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]);
        itemName = "6x scope";
    break;

    case 203005:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]);
        itemName = "8x scope";
    break;

    case 106007:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_FlareGun_Color[0], Setting::Esp_Item_FlareGun_Color[1], Setting::Esp_Item_FlareGun_Color[2], Setting::Esp_Item_FlareGun_Color[3]);
        itemName = "Flaregun";
    break;

    case 105001:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M249_Color[0], Setting::Esp_Item_M249_Color[1], Setting::Esp_Item_M249_Color[2], Setting::Esp_Item_M249_Color[3]);
        itemName = "M249";
    break;

    case 105002:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]);
        itemName = "DP28";
    break;

    case 105010:
        Setting::sizecode = Setting::Esp_Item_M762_TextSize;
        Setting::colorcode = ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]);
        itemName = "MG3";
    break;
                                        default:
                                        continue; // Skip unknown items
                                    }
                                       

                                    if (!itemName.empty()) {
                                        if (PickUpDataList[j].Count > 1) {
                                            itemName + std::to_string(PickUpDataList[j].Count) += " x";
                                        }
                                        // Draw each item name with the specified color
                                        DrawBorderString( pRegularFont, 20.0f, itemName, Screen.X, posY, Setting::colorcode, true);
                                        posY += 15.0f; // Adjust vertical spacing between items
                                    }
                                }
                            }
                        }
}
void DrawItem(ASTExtraPlayerCharacter *localPlayer, APickUpWrapperActor *PickUp) {
    if (!PickUp || !PickUp->RootComponent || PickUp->bHidden) return;

    FVector origin, extends;
    PickUp->GetActorBounds(true, &origin, &extends);
    FVector2D ItemPos;
    std::string ItemName = GetItemType(PickUp->GetName());
    float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;
    FVector PickupPosition = *(FVector *)((uintptr_t)PickUp->RootComponent);
                            if (!WorldToScreenBone(PickupPosition, &ItemPos)) return;
                            if (!ItemName.find("Unknown") == std::string::npos) return;
                            string Text = ItemName;
                            Text += " (";
                            Text += std::to_string((int) Distance);
                            Text += "m)";
                            
                            FVector PosV = PickUp->K2_GetActorLocation();
                            if (Setting::Esp_Item_AirDrop && ItemName == "Air Drop" /*&& Distance < 4000*/)
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_AirDrop_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AirDrop_Color[0], Setting::Esp_Item_AirDrop_Color[1], Setting::Esp_Item_AirDrop_Color[2], Setting::Esp_Item_AirDrop_Color[3]), true);
                            }
                            if(Distance > 80.0f)
                                return;
                            if (Setting::Esp_Item_MedKit && ItemName == "Med Kit")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_MedKit_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_MedKit_Color[0], Setting::Esp_Item_MedKit_Color[1], Setting::Esp_Item_MedKit_Color[2], Setting::Esp_Item_MedKit_Color[3]), true);
                            }
                            if (Setting::Esp_Item_FirstAidKit && ItemName == "First Aid Kit")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_FirstAidKit_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_FirstAidKit_Color[0], Setting::Esp_Item_FirstAidKit_Color[1], Setting::Esp_Item_FirstAidKit_Color[2], Setting::Esp_Item_FirstAidKit_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Painkiller && ItemName == "Painkiller")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Painkiller_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Painkiller_Color[0], Setting::Esp_Item_Painkiller_Color[1], Setting::Esp_Item_Painkiller_Color[2], Setting::Esp_Item_Painkiller_Color[3]), true);
                            }
                            if (Setting::Esp_Item_EnergyDrink && ItemName == "Energy Drink")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_EnergyDrink_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_EnergyDrink_Color[0], Setting::Esp_Item_EnergyDrink_Color[1], Setting::Esp_Item_EnergyDrink_Color[2], Setting::Esp_Item_EnergyDrink_Color[3]), true);
                            }
                            if (Setting::Esp_Item_AdrenalineSyringe && ItemName == "Adrenaline Syringe")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_AdrenalineSyringe_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AdrenalineSyringe_Color[0], Setting::Esp_Item_AdrenalineSyringe_Color[1], Setting::Esp_Item_AdrenalineSyringe_Color[2], Setting::Esp_Item_AdrenalineSyringe_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Bandage && ItemName == "Bandage")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Bandage_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Bandage_Color[0], Setting::Esp_Item_Bandage_Color[1], Setting::Esp_Item_Bandage_Color[2], Setting::Esp_Item_Bandage_Color[3]), true);
                            }
                            if (Setting::Esp_Item_RedDot && ItemName == "Red Dot")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_RedDot_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_RedDot_Color[0], Setting::Esp_Item_RedDot_Color[1], Setting::Esp_Item_RedDot_Color[2], Setting::Esp_Item_RedDot_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Holo && ItemName == "Holo")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Holo_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Holo_Color[0], Setting::Esp_Item_Holo_Color[1], Setting::Esp_Item_Holo_Color[2], Setting::Esp_Item_Holo_Color[3]), true);
                            }
                            if (Setting::Esp_Item_x2 && ItemName == "2x scope")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_x2_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_x2_Color[0], Setting::Esp_Item_x2_Color[1], Setting::Esp_Item_x2_Color[2], Setting::Esp_Item_x2_Color[3]), true);
                            }
                            if (Setting::Esp_Item_x3 && ItemName == "3x scope")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_x3_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_x3_Color[0], Setting::Esp_Item_x3_Color[1], Setting::Esp_Item_x3_Color[2], Setting::Esp_Item_x3_Color[3]), true);
                            }
                            if (Setting::Esp_Item_x4 && ItemName == "4x scope")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_x4_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_x4_Color[0], Setting::Esp_Item_x4_Color[1], Setting::Esp_Item_x4_Color[2], Setting::Esp_Item_x4_Color[3]), true);
                            }
                            if (Setting::Esp_Item_x6 && ItemName == "6x scope")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_x6_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_x6_Color[0], Setting::Esp_Item_x6_Color[1], Setting::Esp_Item_x6_Color[2], Setting::Esp_Item_x6_Color[3]), true);
                            }
                            if (Setting::Esp_Item_x8 && ItemName == "8x scope")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_x8_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_x8_Color[0], Setting::Esp_Item_x8_Color[1], Setting::Esp_Item_x8_Color[2], Setting::Esp_Item_x8_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Bag1 && ItemName == "Bag lv.1")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Bag1_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Bag1_Color[0], Setting::Esp_Item_Bag1_Color[1], Setting::Esp_Item_Bag1_Color[2], Setting::Esp_Item_Bag1_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Bag2 && ItemName == "Bag lv.2")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Bag2_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Bag2_Color[0], Setting::Esp_Item_Bag2_Color[1], Setting::Esp_Item_Bag2_Color[2], Setting::Esp_Item_Bag2_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Bag3 && ItemName == "Bag lv.3")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Bag3_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Bag3_Color[0], Setting::Esp_Item_Bag3_Color[1], Setting::Esp_Item_Bag3_Color[2], Setting::Esp_Item_Bag3_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Helmet1 && ItemName == "Helmet lv.1")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Helmet1_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Helmet1_Color[0], Setting::Esp_Item_Helmet1_Color[1], Setting::Esp_Item_Helmet1_Color[2], Setting::Esp_Item_Helmet1_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Helmet2 && ItemName == "Helmet lv.2")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Helmet2_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Helmet2_Color[0], Setting::Esp_Item_Helmet2_Color[1], Setting::Esp_Item_Helmet2_Color[2], Setting::Esp_Item_Helmet2_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Helmet3 && ItemName == "Helmet lv.3")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Helmet3_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Helmet3_Color[0], Setting::Esp_Item_Helmet3_Color[1], Setting::Esp_Item_Helmet3_Color[2], Setting::Esp_Item_Helmet3_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Armor1 && ItemName == "Armor lv.1")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Armor1_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Armor1_Color[0], Setting::Esp_Item_Armor1_Color[1], Setting::Esp_Item_Armor1_Color[2], Setting::Esp_Item_Armor1_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Armor2 && ItemName == "Armor lv.2")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Armor2_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Armor2_Color[0], Setting::Esp_Item_Armor2_Color[1], Setting::Esp_Item_Armor2_Color[2], Setting::Esp_Item_Armor2_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Armor3 && ItemName == "Armor lv.3")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Armor3_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Armor3_Color[0], Setting::Esp_Item_Armor3_Color[1], Setting::Esp_Item_Armor3_Color[2], Setting::Esp_Item_Armor3_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Mk47Mutant && ItemName == "Mk47")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Mk47Mutant_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Mk47Mutant_Color[0], Setting::Esp_Item_Mk47Mutant_Color[1], Setting::Esp_Item_Mk47Mutant_Color[2], Setting::Esp_Item_Mk47Mutant_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M16A4 && ItemName == "M16A4")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M16A4_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M16A4_Color[0], Setting::Esp_Item_M16A4_Color[1], Setting::Esp_Item_M16A4_Color[2], Setting::Esp_Item_M16A4_Color[3]), true);
                            }
                            if (Setting::Esp_Item_AKM && ItemName == "AKM")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_AKM_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]), true);
                            }


                            //if (Setting::Esp_Item_DeadBox && ItemName == "Skill_UseBike_C")
                            //{
                            //  DrawBorderString( pRegularFont, Setting::Esp_Item_AKM_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]), true);
                            //}
                            //if (Setting::Esp_Item_DeadBox && ItemName == "Skill_UseBike_B_C")
                            //{
                            //  DrawBorderString( pRegularFont, Setting::Esp_Item_AKM_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AKM_Color[0], Setting::Esp_Item_AKM_Color[1], Setting::Esp_Item_AKM_Color[2], Setting::Esp_Item_AKM_Color[3]), true);
                            //}






                            if (Setting::Esp_Item_SCARL && ItemName == "SCAR-L")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_SCARL_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_SCARL_Color[0], Setting::Esp_Item_SCARL_Color[1], Setting::Esp_Item_SCARL_Color[2], Setting::Esp_Item_SCARL_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M416 && ItemName == "M416")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M416_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M416_Color[0], Setting::Esp_Item_M416_Color[1], Setting::Esp_Item_M416_Color[2], Setting::Esp_Item_M416_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M24 && ItemName == "M24")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M24_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M24_Color[0], Setting::Esp_Item_M24_Color[1], Setting::Esp_Item_M24_Color[2], Setting::Esp_Item_M24_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Kar98k && ItemName == "Kar98k")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Kar98k_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Kar98k_Color[0], Setting::Esp_Item_Kar98k_Color[1], Setting::Esp_Item_Kar98k_Color[2], Setting::Esp_Item_Kar98k_Color[3]), true);
                            }
                            if (Setting::Esp_Item_DP28 && ItemName == "DP28")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_DP28_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_DP28_Color[0], Setting::Esp_Item_DP28_Color[1], Setting::Esp_Item_DP28_Color[2], Setting::Esp_Item_DP28_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M762 && ItemName == "M762")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M762_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M762_Color[0], Setting::Esp_Item_M762_Color[1], Setting::Esp_Item_M762_Color[2], Setting::Esp_Item_M762_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Magnum && ItemName == "Magnum")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Magnum_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Magnum_Color[0], Setting::Esp_Item_Magnum_Color[1], Setting::Esp_Item_Magnum_Color[2], Setting::Esp_Item_Magnum_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Awm && ItemName == "AWM")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Awm_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Awm_Color[0], Setting::Esp_Item_Awm_Color[1], Setting::Esp_Item_Awm_Color[2], Setting::Esp_Item_Awm_Color[3]), true);
                            }
                            if (Setting::Esp_Item_FlareGun && ItemName == "Flare Gun")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_FlareGun_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_FlareGun_Color[0], Setting::Esp_Item_FlareGun_Color[1], Setting::Esp_Item_FlareGun_Color[2], Setting::Esp_Item_FlareGun_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Flare && ItemName == "Flare")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Flare_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Flare_Color[0], Setting::Esp_Item_Flare_Color[1], Setting::Esp_Item_Flare_Color[2], Setting::Esp_Item_Flare_Color[3]), true);
                            }



                            if (Setting::Esp_Item_DeadBox && ItemName == "Golden Token" && Distance < 150)
                            {
                                //for (AActor& AActor : Data2::AActorList)
                                //{
                                //  wstring fkBox = AActor.Name + L"'s Crate" + L"(" + to_wstring(Distance) + L"m)";
                                //  //DrawBorderStringW(EspFont, Text, fkBox, ItemPos.X, (ItemPos.Y + ItemPos.Z + 4), Colors::enemy, Colors::nam_border, true);
                                //  DrawBorderStringW2(pRegularFont, Setting::Esp_Item_DeadBox_TextSize, fkBox, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_DeadBox_Color[0], Setting::Esp_Item_DeadBox_Color[1], Setting::Esp_Item_DeadBox_Color[2], Setting::Esp_Item_DeadBox_Color[3]), true);
                                //}
                                DrawBorderString( pRegularFont, Setting::Esp_Item_DeadBox_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_DeadBox_Color[0], Setting::Esp_Item_DeadBox_Color[1], Setting::Esp_Item_DeadBox_Color[2], Setting::Esp_Item_DeadBox_Color[3]), true);
                            }

                            
                            if (Setting::Esp_Item_G36C && ItemName == "G36C")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_G36C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_G36C_Color[0], Setting::Esp_Item_G36C_Color[1], Setting::Esp_Item_G36C_Color[2], Setting::Esp_Item_G36C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_QBZ && ItemName == "QBZ")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_QBZ_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_QBZ_Color[0], Setting::Esp_Item_QBZ_Color[1], Setting::Esp_Item_QBZ_Color[2], Setting::Esp_Item_QBZ_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M249 && ItemName == "M249")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M249_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M249_Color[0], Setting::Esp_Item_M249_Color[1], Setting::Esp_Item_M249_Color[2], Setting::Esp_Item_M249_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Groza && ItemName == "Groza")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Groza_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Groza_Color[0], Setting::Esp_Item_Groza_Color[1], Setting::Esp_Item_Groza_Color[2], Setting::Esp_Item_Groza_Color[3]), true);
                            }
                            if (Setting::Esp_Item_AUG && ItemName == "AUG")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_AUG_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_AUG_Color[0], Setting::Esp_Item_AUG_Color[1], Setting::Esp_Item_AUG_Color[2], Setting::Esp_Item_AUG_Color[3]), true);
                            }
                            if (Setting::Esp_Item_TommyGun && ItemName == "Tommy Gun")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_TommyGun_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_TommyGun_Color[0], Setting::Esp_Item_TommyGun_Color[1], Setting::Esp_Item_TommyGun_Color[2], Setting::Esp_Item_TommyGun_Color[3]), true);
                            }
                            if (Setting::Esp_Item_MP5K && ItemName == "MP5K")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_MP5K_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_MP5K_Color[0], Setting::Esp_Item_MP5K_Color[1], Setting::Esp_Item_MP5K_Color[2], Setting::Esp_Item_MP5K_Color[3]), true);
                            }
                            if (Setting::Esp_Item_UMP9 && ItemName == "UMP9")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_UMP9_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_UMP9_Color[0], Setting::Esp_Item_UMP9_Color[1], Setting::Esp_Item_UMP9_Color[2], Setting::Esp_Item_UMP9_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Vector && ItemName == "Vector")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Vector_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Vector_Color[0], Setting::Esp_Item_Vector_Color[1], Setting::Esp_Item_Vector_Color[2], Setting::Esp_Item_Vector_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Uzi && ItemName == "Uzi")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Uzi_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Uzi_Color[0], Setting::Esp_Item_Uzi_Color[1], Setting::Esp_Item_Uzi_Color[2], Setting::Esp_Item_Uzi_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Smoke && ItemName == "Smoke Grenade")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Smoke_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Smoke_Color[0], Setting::Esp_Item_Smoke_Color[1], Setting::Esp_Item_Smoke_Color[2], Setting::Esp_Item_Smoke_Color[3]), true);
                            }
                            if (Setting::Esp_Item_molotov && ItemName == "Molotof Grenade")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_molotov_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_molotov_Color[0], Setting::Esp_Item_molotov_Color[1], Setting::Esp_Item_molotov_Color[2], Setting::Esp_Item_molotov_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Frag && ItemName == "Frag Grenade")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Frag_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Frag_Color[0], Setting::Esp_Item_Frag_Color[1], Setting::Esp_Item_Frag_Color[2], Setting::Esp_Item_Frag_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C && ItemName == "Flash Hider (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Mid_FlashHider_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C && ItemName == "Flash Hider (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Large_FlashHider_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C && ItemName == "Compensator (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Large_Compensator_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C && ItemName == "Compensator (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Mid_Compensator_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C && ItemName == "Flash Hider (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Sniper_FlashHider_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C && ItemName == "Suppressor (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Mid_Suppressor_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QT_Sniper_Pickup_C && ItemName == "Chekpad (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QT_Sniper_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QT_Sniper_Pickup_C_Color[0], Setting::Esp_Item_BP_QT_Sniper_Pickup_C_Color[1], Setting::Esp_Item_BP_QT_Sniper_Pickup_C_Color[2], Setting::Esp_Item_BP_QT_Sniper_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QT_A_Pickup_C && ItemName == "Tactical Stock")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QT_A_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QT_A_Pickup_C_Color[0], Setting::Esp_Item_BP_QT_A_Pickup_C_Color[1], Setting::Esp_Item_BP_QT_A_Pickup_C_Color[2], Setting::Esp_Item_BP_QT_A_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_DuckBill_Pickup_C && ItemName == "Duckbill")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_DuckBill_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Choke_Pickup_C && ItemName == "Choke")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Choke_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Choke_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Choke_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Choke_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Choke_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QT_UZI_Pickup_C && ItemName == "Stock")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QT_UZI_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QT_UZI_Pickup_C_Color[0], Setting::Esp_Item_BP_QT_UZI_Pickup_C_Color[1], Setting::Esp_Item_BP_QT_UZI_Pickup_C_Color[2], Setting::Esp_Item_BP_QT_UZI_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C && ItemName == "Compensator (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Sniper_Compensator_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C && ItemName == "Suppressor (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Sniper_Suppressor_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C && ItemName == "Suppressor (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[0], Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[1], Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[2], Setting::Esp_Item_BP_QK_Large_Suppressor_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C && ItemName == "Extended Quickdraw Mag (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Sniper_EQ_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C && ItemName == "Extended Mag (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Mid_E_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C && ItemName == "Quickdraw Mag (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Mid_Q_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C && ItemName == "Extended Mag (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Mid_EQ_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C && ItemName == "Quickdraw Mag (Sniper)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Sniper_E_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C && ItemName == "Quickdraw Mag (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Sniper_Q_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C && ItemName == "Extended Quickdraw Mag (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Large_Q_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C && ItemName == "Extended Mag (AR)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Large_EQ_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_DJ_Large_E_Pickup_C && ItemName == "Extended Quickdraw Mag (SMG)")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_Color[0], Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_Color[1], Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_Color[2], Setting::Esp_Item_BP_DJ_Large_E_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_PP19 && ItemName == "Sadak")
                            {
                                DrawBorderString( pRegularFont, Setting::Normalfontsize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C && ItemName == "Mermilik")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[0], Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[1], Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[2], Setting::Esp_Item_BP_ZDD_Sniper_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C && ItemName == "ThumbGrip")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_ThumbGrip_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_LightGrip_Pickup_C && ItemName == "LightGrip")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_LightGrip_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C && ItemName == "HalfGrip")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_HalfGrip_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_Vertical_Pickup_C && ItemName == "Vertical Foregrip")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_Vertical_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_Vertical_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_Vertical_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_Vertical_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_Vertical_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_Angled_Pickup_C && ItemName == "Angled Foregrip")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_Angled_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_Angled_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_Angled_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_Angled_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_Angled_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WB_Lasersight_Pickup_C && ItemName == "Lasersight")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[3]), true);
                            }
                            //if (Setting::Esp_Item_BP_WB_Lasersight_Pickup_C && ItemName == "GoldenTokenWrapper_C")
                            //{
                            //  DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_TextSize2, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[0], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[1], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[2], Setting::Esp_Item_BP_WB_Lasersight_Pickup_C_Color[3]), true);
                            //}
                            if (Setting::Esp_Item_BP_WEP_Sickle_Pickup_C && ItemName == "Sickle")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_Color[0], Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_Color[1], Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_Color[2], Setting::Esp_Item_BP_WEP_Sickle_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WEP_Machete_Pickup_C && ItemName == "Machete")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WEP_Machete_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WEP_Machete_Pickup_C_Color[0], Setting::Esp_Item_BP_WEP_Machete_Pickup_C_Color[1], Setting::Esp_Item_BP_WEP_Machete_Pickup_C_Color[2], Setting::Esp_Item_BP_WEP_Machete_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C && ItemName == "Levye")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[0], Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[1], Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[2], Setting::Esp_Item_BP_WEP_Cowbar_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_BP_WEP_Pan_Pickup_C && ItemName == "Pan")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_BP_WEP_Pan_Pickup_C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_BP_WEP_Pan_Pickup_C_Color[0], Setting::Esp_Item_BP_WEP_Pan_Pickup_C_Color[1], Setting::Esp_Item_BP_WEP_Pan_Pickup_C_Color[2], Setting::Esp_Item_BP_WEP_Pan_Pickup_C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_CrossBow && ItemName == "CrossBow")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_CrossBow_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_CrossBow_Color[0], Setting::Esp_Item_CrossBow_Color[1], Setting::Esp_Item_CrossBow_Color[2], Setting::Esp_Item_CrossBow_Color[3]), true);
                            }
                            if (Setting::Esp_Item_VSS && ItemName == "VSS")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_VSS_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_VSS_Color[0], Setting::Esp_Item_VSS_Color[1], Setting::Esp_Item_VSS_Color[2], Setting::Esp_Item_VSS_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Win94 && ItemName == "Win94")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Win94_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Win94_Color[0], Setting::Esp_Item_Win94_Color[1], Setting::Esp_Item_Win94_Color[2], Setting::Esp_Item_Win94_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Mosin && ItemName == "Mosin")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Mosin_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Mosin_Color[0], Setting::Esp_Item_Mosin_Color[1], Setting::Esp_Item_Mosin_Color[2], Setting::Esp_Item_Mosin_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Mk14 && ItemName == "Mk14")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Mk14_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Mk14_Color[0], Setting::Esp_Item_Mk14_Color[1], Setting::Esp_Item_Mk14_Color[2], Setting::Esp_Item_Mk14_Color[3]), true);
                            }
                            if (Setting::Esp_Item_SKS && ItemName == "SKS")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_SKS_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_SKS_Color[0], Setting::Esp_Item_SKS_Color[1], Setting::Esp_Item_SKS_Color[2], Setting::Esp_Item_SKS_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Mk12 && ItemName == "MK12")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Mk12_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Mk12_Color[0], Setting::Esp_Item_Mk12_Color[1], Setting::Esp_Item_Mk12_Color[2], Setting::Esp_Item_Mk12_Color[3]), true);
                            }
                            if (Setting::Esp_Item_QBU && ItemName == "QBU")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_QBU_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_QBU_Color[0], Setting::Esp_Item_QBU_Color[1], Setting::Esp_Item_QBU_Color[2], Setting::Esp_Item_QBU_Color[3]), true);
                            }
                            if (Setting::Esp_Item_SLR && ItemName == "SLR")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_SLR_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_SLR_Color[0], Setting::Esp_Item_SLR_Color[1], Setting::Esp_Item_SLR_Color[2], Setting::Esp_Item_SLR_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Mini14 && ItemName == "Mini-14")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Mini14_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Mini14_Color[0], Setting::Esp_Item_Mini14_Color[1], Setting::Esp_Item_Mini14_Color[2], Setting::Esp_Item_Mini14_Color[3]), true);
                            }
                            if (Setting::Esp_Item_S12K && ItemName == "S12K")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_S12K_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_S12K_Color[0], Setting::Esp_Item_S12K_Color[1], Setting::Esp_Item_S12K_Color[2], Setting::Esp_Item_S12K_Color[3]), true);
                            }
                            if (Setting::Esp_Item_M1014 && ItemName == "M1014")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_M1014_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_M1014_Color[0], Setting::Esp_Item_M1014_Color[1], Setting::Esp_Item_M1014_Color[2], Setting::Esp_Item_M1014_Color[3]), true);
                            }
                            if (Setting::Esp_Item_DBS && ItemName == "DBS")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_DBS_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_DBS_Color[0], Setting::Esp_Item_DBS_Color[1], Setting::Esp_Item_DBS_Color[2], Setting::Esp_Item_DBS_Color[3]), true);
                            }
                            if (Setting::Esp_Item_S686 && ItemName == "S686")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_S686_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_S686_Color[0], Setting::Esp_Item_S686_Color[1], Setting::Esp_Item_S686_Color[2], Setting::Esp_Item_S686_Color[3]), true);
                            }
                            if (Setting::Esp_Item_S1897 && ItemName == "S1897")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_S1897_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_S1897_Color[0], Setting::Esp_Item_S1897_Color[1], Setting::Esp_Item_S1897_Color[2], Setting::Esp_Item_S1897_Color[3]), true);
                            }
                            if (Setting::Esp_Item_SawedOff && ItemName == "SawedOff")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_SawedOff_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_SawedOff_Color[0], Setting::Esp_Item_SawedOff_Color[1], Setting::Esp_Item_SawedOff_Color[2], Setting::Esp_Item_SawedOff_Color[3]), true);
                            }
                            if (Setting::Esp_Item_GasCan && ItemName == "GasCan")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_GasCan_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_GasCan_Color[0], Setting::Esp_Item_GasCan_Color[1], Setting::Esp_Item_GasCan_Color[2], Setting::Esp_Item_GasCan_Color[3]), true);
                            }
                            if (Setting::Esp_Item_PP19 && ItemName == "PP19")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_PP19_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_PP19_Color[0], Setting::Esp_Item_PP19_Color[1], Setting::Esp_Item_PP19_Color[2], Setting::Esp_Item_PP19_Color[3]), true);
                            }
                            if (Setting::Esp_Item_R1895 && ItemName == "R1895")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_R1895_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_R1895_Color[0], Setting::Esp_Item_R1895_Color[1], Setting::Esp_Item_R1895_Color[2], Setting::Esp_Item_R1895_Color[3]), true);
                            }
                            if (Setting::Esp_Item_Vz61 && ItemName == "Vz61")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_Vz61_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_Vz61_Color[0], Setting::Esp_Item_Vz61_Color[1], Setting::Esp_Item_Vz61_Color[2], Setting::Esp_Item_Vz61_Color[3]), true);
                            }
                            if (Setting::Esp_Item_P92 && ItemName == "P92")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_P92_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_P92_Color[0], Setting::Esp_Item_P92_Color[1], Setting::Esp_Item_P92_Color[2], Setting::Esp_Item_P92_Color[3]), true);
                            }
                            if (Setting::Esp_Item_P18C && ItemName == "P18C")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_P18C_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_P18C_Color[0], Setting::Esp_Item_P18C_Color[1], Setting::Esp_Item_P18C_Color[2], Setting::Esp_Item_P18C_Color[3]), true);
                            }
                            if (Setting::Esp_Item_R45 && ItemName == "R45")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_R45_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_R45_Color[0], Setting::Esp_Item_R45_Color[1], Setting::Esp_Item_R45_Color[2], Setting::Esp_Item_R45_Color[3]), true);
                            }
                            if (Setting::Esp_Item_P1911 && ItemName == "P1911")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_P1911_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_P1911_Color[0], Setting::Esp_Item_P1911_Color[1], Setting::Esp_Item_P1911_Color[2], Setting::Esp_Item_P1911_Color[3]), true);
                            }
                            if (Setting::Esp_Item_DesertEagle && ItemName == "DesertEagle")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_DesertEagle_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_DesertEagle_Color[0], Setting::Esp_Item_DesertEagle_Color[1], Setting::Esp_Item_DesertEagle_Color[2], Setting::Esp_Item_DesertEagle_Color[3]), true);
                            }
                            if (Setting::Esp_Item_12Guage && ItemName == "12Guage")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_12Guage_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_12Guage_Color[0], Setting::Esp_Item_12Guage_Color[1], Setting::Esp_Item_12Guage_Color[2], Setting::Esp_Item_12Guage_Color[3]), true);
                            }
                            if (Setting::Esp_Item_762mm && ItemName == "7.62")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_762mm_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_762mm_Color[0], Setting::Esp_Item_762mm_Color[1], Setting::Esp_Item_762mm_Color[2], Setting::Esp_Item_762mm_Color[3]), true);
                            }
                            if (Setting::Esp_Item_556mm && ItemName == "5.56")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_556mm_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_556mm_Color[0], Setting::Esp_Item_556mm_Color[1], Setting::Esp_Item_556mm_Color[2], Setting::Esp_Item_556mm_Color[3]), true);
                            }
                            if (Setting::Esp_Item_45ACP && ItemName == "45ACP")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_45ACP_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_45ACP_Color[0], Setting::Esp_Item_45ACP_Color[1], Setting::Esp_Item_45ACP_Color[2], Setting::Esp_Item_45ACP_Color[3]), true);
                            }
                            if (Setting::Esp_Item_9mm && ItemName == "9mm")
                            {
                                DrawBorderString( pRegularFont, Setting::Esp_Item_9mm_TextSize, Text, ItemPos.X, ItemPos.Y, ImColor(Setting::Esp_Item_9mm_Color[0], Setting::Esp_Item_9mm_Color[1], Setting::Esp_Item_9mm_Color[2], Setting::Esp_Item_9mm_Color[3]), true);
                            }
}
void DevMode(AActor *Actor) {
    string test = Actor->GetName();
    FVector Screen;
    int L;
    auto Lon = Actor->RootComponent->K2_GetComponentLocation();
    if(!WorldToScreen(Lon, Screen, &L)) return;
    DrawBorderString(pRegularFont, 20, test, Screen.X, (Screen.Y + 10 + Screen.Z), White, true);
}
void DrawNearstAR(ImDrawList* draw,ASTExtraPlayerCharacter *localPlayer, APickUpWrapperActor *PickUp) {
    if (!PickUp)
        return;

    auto RootComponent = PickUp->RootComponent;
    if (!RootComponent)
        return;

    auto id = PickUp->DefineID.TypeSpecificID;
    if ((id >= 101001 && id <= 101010) ||
        id == 101100 ||
        id == 105001 ||
        id == 105002 ||
        id == 101102 || id == 101004 || id == 101102 || id == 101003 ||
        id == 101005 || id == 101006 || id == 101007 || id == 101008)
    {
        ARNearestCache.push_back(PickUp);
    }
}
