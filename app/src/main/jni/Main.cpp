#include "WOLTAJ/Helper/Includes.h"
#include "WOLTAJ/Main/Main.h"
#include "WOLTAJ/Main/ESP/Draw.cpp"
#include "WOLTAJ/Main/Skin/SkinMain.h"
#include "WOLTAJ/Main/ESP/Font.h"
//#include "Menu.h"
#define _GNU_SOURCE
#include <dlfcn.h>


uintptr_t anogs;
#define anogs OBFUSCATE("libanogs.so")

EGLBoolean(*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

    if (glWidth <= 0 || glHeight <= 0)
        return orig_eglSwapBuffers(dpy, surface);

    if (!Data::Cheat::App)
        return orig_eglSwapBuffers(dpy, surface);

    if (!initImGui) {
        screenWidth = ANativeWindow_getWidth(Data::Cheat::App->window);
        screenHeight = ANativeWindow_getHeight(Data::Cheat::App->window);
        density = AConfiguration_getDensity(Data::Cheat::App->config);

        ImGui::CreateContext();
        Theme();
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImGuiIO& io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;

        static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
        ImFontConfig icons_config;
        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;
        
        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;

        // Türkçe Karakter Aralıkları
        static const ImWchar turkish_ranges[] = {
            0x0020, 0x00FF, // Temel Latin + Latin-1 (Ç, ç, Ö, ö, Ü, ü içerir)
            0x011E, 0x011F, // Ğ, ğ
            0x0130, 0x0131, // İ, ı
            0x015E, 0x015F, // Ş, ş
            0,
        };

        // Vietnam aralığı (GetGlyphRangesVietnamese) yerine turkish_ranges bağlandı:
        io.Fonts->AddFontFromMemoryTTF(LiteFont_char, sizeof(LiteFont_char), 15.0f, NULL, turkish_ranges);
        io.Fonts->AddFontFromMemoryTTF((void *)font_awesome_6, sizeof(font_awesome_6), 15.0f, &icons_config, icons_ranges);

        pRegularFont = io.Fonts->AddFontFromMemoryTTF(LiteFont_char, sizeof(LiteFont_char), 12.0f, NULL, turkish_ranges);
        Icon = io.Fonts->AddFontFromMemoryTTF((void *)font_awesome_6, sizeof(font_awesome_6), 15.0f, &icons_config, icons_ranges);
		
        memset(&Config, 0, sizeof(sConfig));
        Config.IpadS = 100.0f;
        Config.Ragebot.Smooth = 1.0f;
        Config.Line = 1.7f;
        Config.IpadC = 1.0f;
        Config.IpadS = 5.0f;
        Config.Memory.MagicValue = 300.0f;
        Config.Memory.MagicX = 120.0f;
        Config.Memory.MagicY = 180.0f;
        Config.Memory.MagicZ = 300.0f;
        User = CreateTexture(user, sizeof(user));

        initImGui = true;
    }

    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();

    ImGui::RenderNotifications();
DrawESP(ImGui::GetBackgroundDrawList());

UpdateTitle();
DrawMenu();

ImGui::End();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return orig_eglSwapBuffers(dpy, surface);
}

   

char title[128];                 // Kích thước đủ lớn để chứa chuỗi định dạng
void UpdateTitle()
{
    static std::time_t lastUpdate = 0;
    static char lastTimeStr[64] = "";

    std::time_t now = std::time(nullptr);
    char timeStr[64];

    if (now != lastUpdate)
    {
        lastUpdate = now;
        std::tm *localTime = std::localtime(&now);
        std::strftime(timeStr, sizeof(timeStr), "%H:%M:%S %b %d %Y", localTime);

        if (std::strcmp(timeStr, lastTimeStr) != 0)
        {
            sprintf(title, "ibrdot", timeStr);
            std::strcpy(lastTimeStr, timeStr);
        }
    }
}


void DrawMenu()
{
    if (unload)
    {
        ImGuiIO &Io = ImGui::GetIO();
        ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));

        if (ImGui::Begin("####11", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
        {
            imguipp::CenterText("   Hazır mısınız?", 0, 0);
            ImGui::SetCursorPos(ImVec2(8, 40));
            if (ImGui::Button("Evet", {104.3f, 22.f}))
            {
                unload = false;
                VR = false;
            }
            ImGui::SameLine();
            if (ImGui::Button("Hayır", {104.3f, 22.f}))
            {
                unload = false;
            }
            ImGui::End();
        }
    }

    if (!dbrr)
    {
        static bool isLogin = true;
        static std::string err = "";
        static char keyInput[64] = "";
        static int option = 0;
        static int version = 0;
        static bool showPassword = false; // Şifre görünürlüğü takibi

        if (!isLogin)
        {
            const char* optionList[] = { "Lite", "Full" };
            const char* versionList[] = { "BGMI", "PUBG", "KR" };

            ImGui::SetNextWindowSize(ImVec2(360, 300)); // Butonlar eklendiği için yükseklik 300 yapıldı
            ImGui::SetNextWindowPos(ImVec2(ImGui::GetIO().DisplaySize.x / 2, ImGui::GetIO().DisplaySize.y / 2), ImGuiCond_Always, ImVec2(0.5f, 0.5f));

            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 12.0f);
            ImGui::PushStyleColor(ImGuiCol_WindowBg, ImColor(25, 25, 25, 240).Value);
            ImGui::PushStyleColor(ImGuiCol_Border, ImColor(60, 60, 60, 255).Value);

            if (ImGui::Begin("##LoginWindow", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_AlwaysAutoResize))
            {
                ImGui::SetCursorPosY(20);
                ImGui::SetCursorPosX((ImGui::GetWindowSize().x - ImGui::CalcTextSize("pubgmsrc | ibrdot").x) / 2);
                ImGui::TextColored(ImColor(255, 255, 255, 255), "pubgmsrc | ibrdot");

                ImGui::Spacing(); ImGui::Spacing();

                ImGui::SetCursorPosX(40);
                ImGui::Text("Seçenek");
                ImGui::SameLine(120);
                ImGui::SetNextItemWidth(180);
                ImGui::Combo("##option", &option, optionList, IM_ARRAYSIZE(optionList));

                ImGui::SetCursorPosX(40);
                ImGui::Text("Versiyon");
                ImGui::SameLine(120);
                ImGui::SetNextItemWidth(180);
                ImGui::Combo("##version", &version, versionList, IM_ARRAYSIZE(versionList));

                ImGui::Spacing(); ImGui::Spacing();

                // --- LİSANS ANAHTARI BÖLÜMÜ ---
                ImGui::SetCursorPosX(40);
                ImGui::Text("Lisans Anahtarı");

                ImGui::SetCursorPosX(40);
                ImGui::PushItemWidth(200); // Input genişliği
                
                // Şifre maskeleme flag'i
                ImGuiInputTextFlags inputFlags = showPassword ? 0 : ImGuiInputTextFlags_Password;
                ImGui::InputText("##KeyInput", keyInput, sizeof(keyInput), inputFlags);
                ImGui::PopItemWidth();

                // Şifre Göster/Gizle Butonu
                ImGui::SameLine();
                if (ImGui::Button(showPassword ? "Gizle" : "Göster", ImVec2(72, 0)))
                {
                    showPassword = !showPassword;
                }

                // Yapıştır (Paste) Butonu
                ImGui::SetCursorPosX(40);
                if (ImGui::Button("Yapıştır", ImVec2(280, 26)))
                {
                    const char* clipText = ImGui::GetClipboardText();
                    if (clipText)
                    {
                        snprintf(keyInput, sizeof(keyInput), "%s", clipText);
                    }
                }

                ImGui::Spacing();

                // Giriş Yap Butonu
                ImGui::SetCursorPosX(40);
                ImGui::PushStyleColor(ImGuiCol_Button, ImColor(160, 110, 255).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(190, 140, 255).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor(130, 80, 230).Value);

                if (ImGui::Button("Giriş Yap", ImVec2(180, 32)))
                {
                    err = Login(keyInput);
                    if (err == "OK")
                        isLogin = true;
                }
                ImGui::PopStyleColor(3);

                // Kanal Butonu
                ImGui::SameLine();
                ImGui::PushStyleColor(ImGuiCol_Button, ImColor(40, 160, 220).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImColor(60, 180, 240).Value);
                ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImColor(20, 140, 200).Value);
                
                if (ImGui::Button("GitHub", ImVec2(92, 32)))
                {
                    // https://github.com/ibrdot
                }
                ImGui::PopStyleColor(3);

                if (!err.empty())
                {
                    ImGui::SetCursorPosX(40);
                    ImGui::TextColored(ImVec4(1, 0, 0, 1), err.c_str());
                }

                ImGui::Spacing();
                ImGui::SetCursorPosX(40);
                ImGui::TextColored(ImColor(200, 200, 200, 180), "Yükleme tamamlandı, bu pencereyi kapatmayın");

                ImGui::End();
            }
            ImGui::PopStyleColor(2);
            ImGui::PopStyleVar();
        }
        else 
        {   
            ImGuiIO &Io = ImGui::GetIO();
            ImGui::SetNextWindowPos(ImVec2(Io.DisplaySize.x * 0.5f, Io.DisplaySize.y * 0.5f), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
            if (ImGui::Begin("##dbrr11", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize))
            {
                imguipp::CenterText(" Welcome To ibrdot", 0, 0);
                ImGui::SetCursorPos(ImVec2(8, 40));
                if (ImGui::Button("Volume Based", {104.3f, 22.f}))
                {
                    OpenVolume = true;
                    dbrr = true;
                    Setting::textborder = true;
                }
                ImGui::SameLine();
                if (ImGui::Button("Button based", {104.3f, 22.f}))
                {
                    OpenMenu = true;
                    dbrr = true;
                    Setting::textborder = true;
                }
                ImGui::End();
            }
        }
    }

        
    if (OpenMenu)
    {
    }
    UpdateTitle();

    static auto Flags1 = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
    static ImVec4 active = to_vec4(158, 158, 158, 158);
    static ImVec4 inactive = to_vec4(66, 66, 66, 66);

    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(783, 603)); 

    if (VR)
    {
        if (ImGui::Begin(title, &VR, Flags1))
        {
            g_window = ImGui::GetCurrentWindow();
            ImGuiStyle &style = ImGui::GetStyle();
            style.FrameRounding = 4.0f;

            // Varsayılan Tab kontrolü (Home silindiği için varsayılan Tab 1 = ESP)
            if (Settings::Tab < 1 || Settings::Tab > 5) Settings::Tab = 1;

            // ── ÜST TAB BUTONLARI (ESP, Auto Aim, Skin, Memory, Settings) ──
            ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
            if (ImGui::Button(GetLabel(ICON_FA_EYE " ESP", ICON_FA_EYE " ESP"), ImVec2(145, 25))) { Settings::Tab = 1; }
            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
            if (ImGui::Button(GetLabel(ICON_FA_CROSSHAIRS " Auto Aim", ICON_FA_CROSSHAIRS " Otomatik Nişan"), ImVec2(145, 25))) { Settings::Tab = 2; }
            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
            if (ImGui::Button(GetLabel(ICON_FA_TSHIRT " Skin", ICON_FA_TSHIRT " Kostüm"), ImVec2(145, 25))) { Settings::Tab = 3; }
            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
            if (ImGui::Button(GetLabel(ICON_FA_EDIT " Memory", ICON_FA_EDIT " Hafıza"), ImVec2(145, 25))) { Settings::Tab = 4; }
            ImGui::SameLine();

            ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 5 ? active : inactive);
            if (ImGui::Button(GetLabel(ICON_FA_COG " Settings", ICON_FA_COG " Ayarlar"), ImVec2(145, 25))) { Settings::Tab = 5; }

            style.FrameRounding = 0.0f;
            ImGui::PopStyleColor(5);
            ImGui::Separator();

            // =========================================================================
            // TAB 1: ESP
            // =========================================================================
            if (Settings::Tab == 1)
            {
                ImGui::BeginChild("##ESPMainContainer", ImVec2(766, 534), true, 0);
                {
                    ImGui::Columns(2);
                    ImGui::SetColumnOffset(1, 257);
                    
                    // SOL CHILD: Checkbox Listesi
                    ImGui::SetCursorPos(ImVec2(8, 8));
                    ImGui::BeginChild("###ESPLeftChild", ImVec2(242, 518), true, 0);
                    {
                        ImGui::PushStyleColor(ImGuiCol_CheckMark, IM_COL32(255, 0, 0, 255));
                        ImGui::Checkbox(GetLabel("Draw enemy line",     "Düşman Çizgisi"),     &Config.ESPMenu.Line);
                        ImGui::Checkbox(GetLabel("Draw enemy box",      "Düşman Kutusu"),      &Config.ESPMenu.Box);
                        ImGui::Checkbox(GetLabel("Show enemy name",     "Düşman İsmi"),        &Config.ESPMenu.Name);
                        ImGui::Checkbox(GetLabel("Show enemy uid",       "Düşman UID"),         &Config.ESPMenu.TeamID);                       
                        ImGui::Checkbox(GetLabel("Show enemy team",      "Takım Numarası"),     &Config.ESPMenu.TeamID);                       
                        ImGui::Checkbox(GetLabel("Show enemy health",   "Can Barı"),           &Config.ESPMenu.Health);
                        ImGui::Checkbox(GetLabel("Show enemy distance", "Mesafe"),             &Config.ESPMenu.Distance);
                        ImGui::Checkbox(GetLabel("Show enemy weapon",  "Silah Bilgisi"),      &Config.ESPMenu.SungDich);                        
                        ImGui::Checkbox(GetLabel("Show enemy aiming",  "Nişan Uyarısı"),      &Config.ESPMenu.Enemy);
                        ImGui::Checkbox(GetLabel("Draw enemy skeleton", "İskelet"),            &Config.ESPMenu.Skeleton);
                        ImGui::Checkbox(GetLabel("Show enemy nation",   "Bayrak / Ülke"),      &Config.ESPMenu.Country);
                        ImGui::Checkbox(GetLabel("Show bullet position","Mermi Pozisyonu"),    &BulletPosition);
                        ImGui::Checkbox(GetLabel("Show aiming warning", "Bomba Uyarısı"),      &Config.ESPMenu.Grenade);
                        ImGui::Checkbox(GetLabel("Draw enemy alert",    "360° Radar Uyarısı"), &Config.Alert);
                        ImGui::Checkbox(GetLabel("Hide Bots",           "Botları Gizle"),      &Config.ESPMenu.NoBot);
                        ImGui::Checkbox(GetLabel("Vehicle",             "Araçlar"),            &Config.ESPMenu.Vehicle);
                        ImGui::Checkbox(GetLabel("Player Loot Box",     "Ölüm Kutuları"),      &Config.ESPMenu.LootBox);
                        ImGui::PopStyleColor();
                    }
                    ImGui::EndChild();

                    ImGui::NextColumn();

                    // SAĞ CHILD: ESP Ayarları
                    ImGui::SetCursorPos(ImVec2(265, 8));
                    ImGui::BeginChild("###ESPRightChild", ImVec2(492, 518), true, 0);
                    {
                        if (ImGui::BeginTabBar("EspSetting")) 
                        {
                            if (Config.ESPMenu.Name)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Name", "İsim")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    ImGui::ColorEdit4("###Text color", (float *)&Color::nam, ImGuiColorEditFlags_NoLabel);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text color", "Yazı Rengi"));
                                    ImGui::PushItemWidth(380);
                                    ImGui::ColorEdit4("###Border color", (float *)&Color::nam_border, ImGuiColorEditFlags_NoLabel);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Border color", "Kenarlık Rengi"));
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderFloat("###4", &Setting::nsize, 0, 20);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text size", "Yazı Boyutu"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.SungDich)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Weapon", "Silah")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    ImGui::ColorEdit4("###Weapon color", (float *)&Setting::WeaponColor, ImGuiColorEditFlags_NoLabel);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text color", "Yazı Rengi"));
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderInt("###Weapon", &Setting::weaponsize, 0, 20);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text size", "Yazı Boyutu"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.Skeleton)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Skeleton", "İskelet")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    const char *Emu[] = {GetLabel("Default", "Varsayılan"), GetLabel("TeamID", "Takım ID")};
                                    const char *combo_label = Emu[Setting::skele];
                                    if (ImGui::BeginCombo("###SkeletonType", combo_label, ImGuiComboFlags_HeightSmall))
                                    {
                                        for (int n = 0; n < IM_ARRAYSIZE(Emu); n++)
                                        {
                                            const bool is_selected = (Setting::skele == n);
                                            if (ImGui::Selectable(Emu[n], is_selected))
                                                Setting::skele = n;
                                            if (is_selected)
                                                ImGui::SetItemDefaultFocus();
                                        }
                                        ImGui::EndCombo();
                                    }
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Color mode", "Renk Modu"));
                                    if (Setting::skele == 0)
                                    {
                                        ImGui::PushItemWidth(380);
                                        ImGui::ColorEdit4("###color", (float *)&Color::skelec, ImGuiColorEditFlags_NoLabel);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel("Skeleton color", "İskelet Rengi"));
                                    }
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderFloat("###Bone size", &Setting::pbonesize, 1.0f, 5.0f);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Thickness", "Kalınlık"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.Line)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Line", "Çizgi")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    const char *Emu1[] = {GetLabel("Default", "Varsayılan"), GetLabel("TeamID", "Takım ID")};
                                    const char *combo_label = Emu1[Setting::linne];
                                    if (ImGui::BeginCombo("##Line Type", combo_label, ImGuiComboFlags_HeightSmall))
                                    {
                                        for (int n = 0; n < IM_ARRAYSIZE(Emu1); n++)
                                        {
                                            const bool is_selected = (Setting::linne == n);
                                            if (ImGui::Selectable(Emu1[n], is_selected))
                                                Setting::linne = n;
                                            if (is_selected)
                                                ImGui::SetItemDefaultFocus();
                                        }
                                        ImGui::EndCombo();
                                    }
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Color mode", "Renk Modu"));
                                    if (Setting::linne == 0)
                                    {
                                        ImGui::PushItemWidth(380);
                                        ImGui::ColorEdit4(" ###color1", (float *)&Color::playerline, ImGuiColorEditFlags_NoLabel);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel("Line color", "Çizgi Rengi"));
                                    }
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderFloat("###Line size", &Setting::plinesize, 1.0f, 5.00f);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Thickness", "Kalınlık"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.Distance)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Distance", "Mesafe")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    ImGui::ColorEdit4("###Distance Color", (float *)&Color::enemy, ImGuiColorEditFlags_NoLabel);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text color", "Yazı Rengi"));
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderInt("###Distance size", &Setting::dissize, 0, 20);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text size", "Yazı Boyutu"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.Health)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Health", "Can")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    const char *Emu2[] = {GetLabel("Show as BAR", "Bar Olarak Göster"), GetLabel("Show as TEXT", "Yazı Olarak Göster")};
                                    const char *combo_label = Emu2[Setting::hpbt];
                                    if (ImGui::BeginCombo("###Hekth", combo_label, ImGuiComboFlags_HeightSmall))
                                    {
                                        for (int n = 0; n < IM_ARRAYSIZE(Emu2); n++)
                                        {
                                            const bool is_selected = (Setting::hpbt == n);
                                            if (ImGui::Selectable(Emu2[n], is_selected))
                                                Setting::hpbt = n;
                                            if (is_selected)
                                                ImGui::SetItemDefaultFocus();
                                        }
                                        ImGui::EndCombo();
                                    }
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Display mode", "Görünüm Modu"));
                                    if (Setting::hpbt == 1)
                                    {
                                        ImGui::Separator();
                                        ImGui::PushItemWidth(380);
                                        ImGui::ColorEdit4("### colorhp", (float *)&Color::HPP, ImGuiColorEditFlags_NoLabel);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel("Text color", "Yazı Rengi"));
                                        ImGui::PushItemWidth(380);
                                        ImGui::SliderInt("###Health size", &Setting::hp, 0, 20);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel("Text size", "Yazı Boyutu"));
                                    }
                                    ImGui::EndTabItem();
                                }
                            }                        
                            if (Config.ESPMenu.Box)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Box", "Kutu")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    const char *newemu[] = {GetLabel("4 edges", "Köşelikler"), GetLabel("Rectangle", "Tam Kutu")};
                                    const char *testcombo_label = newemu[Setting::Test];
                                    if (ImGui::BeginCombo(" ###lo5ll", testcombo_label, ImGuiComboFlags_HeightSmall))
                                    {
                                        for (int n = 0; n < IM_ARRAYSIZE(newemu); n++)
                                        {
                                            const bool is_selected = (Setting::Test == n);
                                            if (ImGui::Selectable(newemu[n], is_selected))
                                                Setting::Test = n;
                                            if (is_selected)
                                                ImGui::SetItemDefaultFocus();
                                        }
                                        ImGui::EndCombo();
                                    }
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Display mode", "Görünüm Modu"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.ESPMenu.Vehicle)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Vehicle", "Araç")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    ImGui::ColorEdit4(" vehiclec", (float *)&Color::vehicle, ImGuiColorEditFlags_NoLabel);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text color", "Yazı Rengi"));
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderInt("###vehicle size", &vehisize, 0, 20);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Text size", "Yazı Boyutu"));
                                    ImGui::EndTabItem();
                                }
                            }
                            if (Config.Alert)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Radar", "Radar")))
                                {
                                    ImGui::Separator();
                                    ImGui::PushItemWidth(380);
                                    ImGui::SliderFloat("###2", &Setting::RadiusSize, 10.0f, 300.0f);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Radius", "Yarıçap"));
                                    ImGui::EndTabItem();
                                }
                            }
                            ImGui::EndTabBar();
                        }
                    }
                    ImGui::EndChild();
                }
                ImGui::EndChild();
            }

            // =========================================================================
            // TAB 2: AUTO AIM
            // =========================================================================
            if (Settings::Tab == 2)
            {
                ImGui::BeginChild("##AutoAimChild", ImVec2(766, 534), true, 0);
                {
                    ImGui::Columns(2);
                    ImGui::SetColumnOffset(1, 257);
                    ImGui::SetCursorPos(ImVec2(8, 8));
                    
                    ImGui::BeginChild("###AimLeft", ImVec2(242, 518), true, 0);
                    {
                        ImGui::PushStyleColor(ImGuiCol_CheckMark, IM_COL32(255, 0, 0, 255));
                        ImGui::Checkbox(GetLabel("Ghost Aim", "Ghost Aim"), &Config.Ragebot.Enable);
                        ImGui::Checkbox("Bullet", &Config.Ragebot.btEnable);
                        ImGui::Checkbox(GetLabel("Marco", "Makro"), &Marcoo);
                        ImGui::PopStyleColor();
                    }
                    ImGui::EndChild();

                    ImGui::NextColumn();

                    ImGui::SetCursorPos(ImVec2(265, 8));
                    ImGui::BeginChild("###AimRight", ImVec2(492, 518), true, 0);
                    {
                        if (ImGui::BeginTabBar(" Aim"))
                        {
                            if (Config.Ragebot.Enable)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Aimbot", "Aimbot")))
                                {
                                    ImGui::PushItemWidth(300);
                                    const char *Boneeeee[] = {GetLabel("Auto", "Otomatik"), GetLabel("Head", "Kafa"), GetLabel("Chest", "Göğüs")};
                                    ImGui::Combo("###Boe", (int *)&Config.Ragebot.Target, Boneeeee, IM_ARRAYSIZE(Boneeeee));
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel("Ghost Aim bone", "Hedef Bölge"));

                                    const char *types[] = {GetLabel("None", "Yok"), GetLabel("Shoot", "Ateş Etme"), GetLabel("Scope", "Dürbün"), GetLabel("Both", "Her İkisi"), GetLabel("Any", "Herhangi Biri")};
                                    ImGui::Combo("##aimtrig", (int *)&Config.Ragebot.Trigger, types, 5, -1);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel(" Aim key", "Tetikleyici Tuş"));

                                    const char *AimCombbooo[] = {GetLabel("Touch Button", "Dokunmatik Buton"), GetLabel("Silent Aim", "Sessiz Aimbot")};
                                    ImGui::Combo("##Lozne", &Config.Ragebot.Aimtype, AimCombbooo, IM_ARRAYSIZE(AimCombbooo));
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel(" Aim method", "Aimbot Metodu"));

                                    if (Config.Ragebot.Aimtype == 0)
                                    {
                                        ImGui::PushItemWidth(300);
                                        ImGui::SliderFloat("##Speed", &Config.Ragebot.Smooth, 1.0f, 10.0f);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel(" Aim Speed", "Aimbot Hızı"));
                                        ImGui::Separator();
                                    }
                                    ImGui::PushItemWidth(300);
                                    ImGui::SliderFloat("###fovFOVsize", &Config.Ragebot.Cross, 0.0f, 1000.0f);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel(" Aim FOV", "Aimbot Açısı (FOV)"));
                                    ImGui::Checkbox(GetLabel("Show FOV circle", "FOV Dairesini Göster"), &Config.Fov);
                                    if (Config.Fov)
                                    {
                                        ImGui::PushItemWidth(300);
                                        ImGui::ColorEdit4(" ###Fov", (float *)&Setting::fovcolor, ImGuiColorEditFlags_NoLabel);
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel("FOV circle color", "FOV Daire Rengi"));
                                    }

                                    ImGui::PushItemWidth(300);
                                    ImGui::SliderFloat("###dist", &Config.Ragebot.Distance, 0.0f, 300.0f);
                                    ImGui::SameLine();
                                    ImGui::Text(GetLabel(" Aim Distance", "Aimbot Mesafesi"));
                                    ImGui::Separator();
                                    ImGui::Checkbox(GetLabel(" Aim prediction", "Hareket Tahmini"), &Config.AimRecoil);

                                    if (Config.AimRecoil)
                                    {
                                        ImGui::PushItemWidth(300);
                                        ImGui::SliderFloat("###predectionline", &Config.Ragebot.Recoil, 1.25, 3.00f, "x%.3f");
                                        ImGui::SameLine();
                                        ImGui::Text(GetLabel(" Aim Pred", "Tahmin Çarpanı"));
                                        ImGui::Separator();
                                    }
                                    ImGui::Checkbox(GetLabel("Draw current aiming enemy's line", "Hedeflenen Düşmana Çizgi Çiz"), &MethodAimLine);
                                    ImGui::Separator();

                                    ImGui::Checkbox(GetLabel(" Aim Visible", "Sadece Görünür Düşmanlar"), &Config.Ragebot.Visible);
                                    ImGui::Checkbox(GetLabel("Ignore AI", "Botları Yok Say"), &Config.Ragebot.IgnoreAi);
                                    ImGui::Checkbox(GetLabel("Ignore Knocked", "Düşmüş Rakibi Yok Say"), &Config.Ragebot.IgnoreKnock);

                                    ImGui::EndTabItem();
                                }
                            }
							if (Config.Ragebot.btEnable)
                            {
                                if (ImGui::BeginTabItem(GetLabel("360 Bullet", "Sihirli Mermi")))
                                {
                                                                       

                                    ImGui::Checkbox(GetLabel(" Aim Visible", "Sadece Görünür Düşmanlar"), &Config.Ragebot.Visible);
                                    ImGui::Checkbox(GetLabel("Ignore AI", "Botları Yok Say"), &Config.Ragebot.IgnoreAi);
                                    ImGui::Checkbox(GetLabel("Ignore Knocked", "Düşmüş Rakibi Yok Say"), &Config.Ragebot.IgnoreKnock);
                                    ImGui::Separator();
                                    ImGui::Checkbox(GetLabel("Draw current aiming enemy's line", "Hedeflenen Düşmana Çizgi Çiz"), &MethodAimLine);
                                    ImGui::Separator();

                                    ImGui::EndTabItem();
                                }
                            }
                            if (Marcoo)
                            {
                                if (ImGui::BeginTabItem(GetLabel("Macro", "Makro")))
                                {
                                    ImGui::Text(GetLabel("Macro value", "Makro Değeri"));
                                    ImGui::SameLine();
                                    ImGui::PushItemWidth(300);
                                    ImGui::SliderInt("###marco", &Config.Marco1, 0, 10);
                                    ImGui::Checkbox(GetLabel("Auto tap", "Otomatik Tıklama"), &Config.AutoTap);
                                    if (Config.AutoTap)
                                    {
                                        ImGui::Text(GetLabel("Delay when using Auto Tap(ms)", "Otomatik Tıklama Gecikmesi(ms)"));
                                        ImGui::SameLine();
                                        ImGui::PushItemWidth(200);
                                        ImGui::DragInt("###autofire", &Config.Marco2, 0, 100);
                                    }
                                    ImGui::EndTabItem();
                                }
                            }
                            ImGui::EndTabBar();
                        }
                    }
                    ImGui::EndChild();
                }
                ImGui::EndChild();
            }

            // =========================================================================
            // TAB 3: SKIN
            // =========================================================================
            if (Settings::Tab == 3)
            {
                ImGui::BeginChild("##SkinTabChild", ImVec2(766, 534), true, 0);
                {
                    static int skinSubTab = 0;
                    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
                    if (ImGui::Button(GetLabel("Player", "Karakter"), ImVec2(240, 30)))  { skinSubTab = 0; } ImGui::SameLine();
                    if (ImGui::Button(GetLabel("Weapon", "Silah"), ImVec2(240, 30)))  { skinSubTab = 1; } ImGui::SameLine();
                    if (ImGui::Button(GetLabel("Vehicle", "Araç"), ImVec2(240, 30))) { skinSubTab = 2; }
                    ImGui::PopStyleVar();

                    ImGui::Separator();

                    if (ImGui::BeginTable("###SkinTable", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
                    {
                        ImGui::TableSetupColumn(GetLabel("Combo", "Seçim"), ImGuiTableColumnFlags_WidthStretch, 0.6f);
                        ImGui::TableSetupColumn(GetLabel("Name", "İsim"), ImGuiTableColumnFlags_WidthFixed, 100.0f);
                        ImGui::TableSetupColumn("ID", ImGuiTableColumnFlags_WidthFixed, 120.0f);
                        ImGui::TableHeadersRow();

                        if (skinSubTab == 0)
                        {
                            RenderSkinItem(GetLabel("Cloth", "Kıyafet"), skindata.cloth);
                            RenderSkinItem(GetLabel("Hat", "Şapka"), skindata.hat);
                            RenderSkinItem(GetLabel("Pant", "Pantolon"), skindata.pant);
                            RenderSkinItem(GetLabel("Shoe", "Ayakkabı"), skindata.shoe);
                            RenderSkinItem(GetLabel("Parachute", "Paraşüt"), skindata.parachute);
                            RenderSkinItem(GetLabel("Glider", "Planör"), skindata.glider);
                            RenderSkinItem(GetLabel("Helmet Lv1", "Kask Sv1"), skindata.helmet1);
                            RenderSkinItem(GetLabel("Helmet Lv2", "Kask Sv2"), skindata.helmet2);
                            RenderSkinItem(GetLabel("Helmet Lv3", "Kask Sv3"), skindata.helmet3);
                            RenderSkinItem(GetLabel("Backpack Lv1", "Çanta Sv1"), skindata.backpack1);
                            RenderSkinItem(GetLabel("Backpack Lv2", "Çanta Sv2"), skindata.backpack2);
                            RenderSkinItem(GetLabel("Backpack Lv3", "Çanta Sv3"), skindata.backpack3);
                        }
                        else if (skinSubTab == 1)
                        {
                            RenderSkinItem(GetLabel("AKM", "AKM", "AKM"), skindata.akm);
                                                RenderSkinItem(GetLabel("M416", "M416", "M416"), skindata.m416);
                                                RenderSkinItem(GetLabel("SCAR-L", "SCAR-L", "SCAR-L"), skindata.scarl);
                                                RenderSkinItem(GetLabel("M16A4", "M16A4", "M16A4"), skindata.m16);
                                                RenderSkinItem(GetLabel("AUG", "AUG", "AUG"), skindata.aug);
                                                RenderSkinItem(GetLabel("M762", "M762", "M762"), skindata.m762);
                                                RenderSkinItem(GetLabel("GROZA", "GROZA", "GROZA"), skindata.groza);
                                                RenderSkinItem(GetLabel("ACE32", "ACE32", "ACE32"), skindata.ace32);
                                                RenderSkinItem(GetLabel("QBZ", "QBZ", "QBZ"), skindata.qbz);
                                                RenderSkinItem(GetLabel("HONEY", "HONEY", "HONEY"), skindata.honey);
                                                RenderSkinItem(GetLabel("UMP45", "UMP45", "UMP45"), skindata.ump45);
                                                RenderSkinItem(GetLabel("VECTOR", "VECTOR", "VECTOR"), skindata.vector);
                                                RenderSkinItem(GetLabel("PP-19 BIZON", "PP-19 BIZON", "PP-19 BIZON"), skindata.pp19);
                                                RenderSkinItem(GetLabel("Tommy Gun", "Tommy Gun", "汤普森冲锋枪"), skindata.tommy);
                                                RenderSkinItem(GetLabel("UZI", "UZI", "UZI"), skindata.uzi);
                                                RenderSkinItem(GetLabel("KAR-98", "KAR-98", "KAR-98"), skindata.kar98);
                                                RenderSkinItem(GetLabel("M24", "M24", "M24"), skindata.m24);
                                                RenderSkinItem(GetLabel("AWM", "AWM", "AWM"), skindata.awm);
                                                RenderSkinItem(GetLabel("AMR", "AMR", "AMR"), skindata.amr);
                                                RenderSkinItem(GetLabel("MK14", "MK14", "MK14"), skindata.mk14);
                                                RenderSkinItem(GetLabel("MINI14", "MINI14", "MINI14"), skindata.mini14);
                                                RenderSkinItem(GetLabel("M249", "M249", "M249"), skindata.m249);
                                                RenderSkinItem(GetLabel("DP-28", "DP-28", "DP-28"), skindata.dp28);
                                                RenderSkinItem(GetLabel("MG-3", "MG-3", "MG-3"), skindata.mg3);
                                                RenderSkinItem(GetLabel("XM1014", "XM1014", "XM1014"), skindata.xm1014);
                                                RenderSkinItem(GetLabel("S12K", "S12K", "S12K"), skindata.s12k);
                                                RenderSkinItem(GetLabel("PAN", "PAN", "平底锅"), skindata.pan);
                        }
                        else if (skinSubTab == 2)
                        {
                            RenderSkinItem("Coupe-RB", skindata.coupe);
                            RenderSkinItem("UAZ", skindata.uaz);
                            RenderSkinItem("DACIA", skindata.dacia);
                            RenderSkinItem("MOTOR", skindata.motor);
                            RenderSkinItem("MIRADO", skindata.mirado);
                            RenderSkinItem("BUGGY", skindata.buggy);
                        }
                        ImGui::EndTable();
                    }
                }
                ImGui::EndChild();
            }

            // =========================================================================
            // TAB 4: MEMORY
            // =========================================================================
            if (Settings::Tab == 4)
            {
                ImGui::BeginChild("##MemoryTabChild", ImVec2(766, 534), true, 0);
                {
                    ImGui::Columns(2);
                    ImGui::SetColumnOffset(1, 257);
                    ImGui::SetCursorPos(ImVec2(8, 8));

                    ImGui::BeginChild("###MemLeft", ImVec2(242, 518), true, 0);
                    {
                        ImGui::PushStyleColor(ImGuiCol_CheckMark, IM_COL32(255, 0, 0, 255));
                        ImGui::Checkbox(GetLabel("Less Recoil", "Sarsıntı Azaltma"), &Config.Memory.Recoil);
                        ImGui::Checkbox(GetLabel("SmallCross", "Küçük Nişangah"), &Config.Memory.Cross);
                        ImGui::Checkbox("XEffeckt ", &XEffecktv2);
                       // ImGui::Checkbox("Fly  ", &PlayerFlyFunc);
                        ImGui::Checkbox(GetLabel("Aimlock 80M", "Otomatik Kilitleme 80M"), &Config.Memory.Aimlock);
                        ImGui::Checkbox(GetLabel("Crazy Car", "Çılgın Araç"), &Setting::CrazyCar);
                        ImGui::PopStyleColor();
                    }
                    ImGui::EndChild();

                    ImGui::NextColumn();

                    ImGui::SetCursorPos(ImVec2(265, 8));
                    ImGui::BeginChild("###MemRight", ImVec2(492, 518), true, 0);
                    {
                        if (XEffecktv2) {
                            if (ImGui::CollapsingHeader("MHitbox X")) {
                                ImGui::SliderFloat("##HitboxVal", &hitboxRadius, 10.0f, 9999.0f);
                            }
                        }
                        if (Setting::CrazyCar)
                        {
                            if (ImGui::CollapsingHeader(GetLabel("Crazy Car", "Çılgın Araç")))
                            {
                                ImGui::Checkbox(GetLabel("Car Spin", "Araç Döndürme"), &Setting::CarSpin);
                                ImGui::Checkbox(GetLabel("Crazy Car Noclip", "Araç Duvardan Geçme"), &WallHackCar);
                                ImGui::SameLine();
                                ImGui::Checkbox(GetLabel("Infinity Car", "Sınırsız Araç"), &infinitycar);
                                ImGui::SameLine();
                                ImGui::Checkbox(GetLabel("Spring Car", "Zıplayan Araç"), &carspring);
                                ImGui::SliderFloat("##Bitch", &SpinCar360, 0, 200, "%.f");
                            }
                        }
                    }
                    ImGui::EndChild();
                }
                ImGui::EndChild();
            }

            // =========================================================================
            // TAB 5: SETTINGS
            // =========================================================================
            if (Settings::Tab == 5)
           {
                // Tüm içeriği kapsayan ana Child
ImGui::BeginChild("###MainContainerChild", ImVec2(-1.0f, -1.0f), true, 0);
{
    // Üst çocuk pencereler için genişliği kapsayıcıya göre dinamik hesaplama
    float avail_width = ImGui::GetContentRegionAvail().x;
    float half_width = (avail_width - ImGui::GetStyle().ItemSpacing.x) * 0.5f;

    ImGui::BeginChild("###ConfigsChild", ImVec2(half_width, 130), true, 0);
    {
        float item_width = ImGui::GetContentRegionAvail().x;

        ImGui::Checkbox("Text border", &TextBorder);
        ImGui::SameLine(item_width * 0.45f);
        ImGui::Text("Update tick:");
        ImGui::SameLine(item_width * 0.70f);
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::SliderInt("###UpdateTick", &UpdateTick, 10, 100, "%.0fms");

        ImGui::Separator();

        ImGui::Checkbox("Enable name cache", &NameCache);
        ImGui::SameLine(item_width * 0.50f);
        if (ImGui::Button("Flush name cache", ImVec2(-1.0f, 24)))
        {

        }

        ImGui::Separator();

        float btn_width = (item_width - ImGui::GetStyle().ItemSpacing.x) * 0.5f;
        if (ImGui::Button("Save menu", ImVec2(btn_width, 24)))
        {
            ImGui::InsertNotification({ImGuiToastType_Success, 3000, "Save Menu Successfull."});
            
        }
        ImGui::SameLine();
        if (ImGui::Button("Load menu", ImVec2(btn_width, 24)))
        {
            ImGui::InsertNotification({ImGuiToastType_Success, 3000, "Load Menu Successfull."});
            
        }

        ImGui::Separator();
        ImGui::TextDisabled("Express after 27434 hours 4 minutes");
    }
    ImGui::EndChild();

    ImGui::SameLine();

    ImGui::BeginChild("###UnloadChild", ImVec2(half_width, 130), true, 0);
    {
        ImGui::SetCursorPos(ImVec2(8, 8));
        ImVec2 avail = ImGui::GetContentRegionAvail();
        if (ImGui::Button("Unload hack", ImVec2(avail.x, avail.y)))
        {
            ImGui::InsertNotification({ImGuiToastType_Success, 3000, "Unload Menu Successfull."});
            
        }
    }
    ImGui::EndChild();

    ImGui::Spacing();
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize("Special features").x) * 0.5f);
    ImGui::TextUnformatted("Special features");
    ImGui::Spacing();

    // Alt pencere (kalan tüm dikey alanı kaplar)
    ImGui::BeginChild("###SpecialFaturesChild", ImVec2(-1.0f, -1.0f), true, 0);
    {
        ImGui::Checkbox(GetLabel("Show Nearest AR", "En Yakın Taarruz Silahını Göster"), &Setting::nearstAR);
        ImGui::SameLine(200);
        ImGui::Checkbox(GetLabel("Show Game Info", "Oyun Bilgilerini Göster"), &Config.ESPMenu.Info);
        ImGui::SameLine(400);
        ImGui::Checkbox(GetLabel("Developer Mode", "Geliştirici Modu"), &DeveloperMode);
        ImGui::SameLine(570);
        ImGui::Checkbox(GetLabel("Auto Feedback", "Otomatik Geri Bildirim"), &Config.Memory.Funny);

        ImGui::Checkbox(GetLabel("Show Damage", "Hasar Göstergesi"), &Config.ESPMenu.Instant);
        ImGui::SameLine(200);
        ImGui::Checkbox(GetLabel("Magic Bullet", "Sihirli Mermi"), &Config.Memory.MagicBullet);

  
        ImGui::Separator();

        // FPS Limit - Tam Boy
        ImGui::Text("FPS Limit:");
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::DragFloat("###FPS", &Setting::FPS, 60, 90, 120, "%.0f FPS");

        // iPad Modu
        ImGui::Text("iPad Modu:");
        float ipad_half = (ImGui::GetContentRegionAvail().x - ImGui::GetStyle().ItemSpacing.x) * 0.5f;
        ImGui::SetNextItemWidth(ipad_half);
        ImGui::SliderFloat("##FFov", &Config.IpadS, 0.5f, 10.0f, "Genel: %.1fx");
        
        ImGui::SameLine();
        ImGui::SetNextItemWidth(ipad_half);
        if (ImGui::SliderFloat("##ScopeFFov", &Config.IpadC, 1.0f, 6.0f, "Dürbün: %.1fx"))
        {
            if (Data::localPlayer)
            {
                if (Config.IpadC != 1.0f)
                {
                    Setting::BaseIpadView1 = Config.IpadC * 10;
                    Data::localPlayer->ScopeCameraComp->SetFieldOfView(Setting::BaseIpadView1);
                }
            }
        }

        // Kamera Açısı - Tam Boy
        ImGui::Text("Kamera Açısı:");
        ImGui::SetNextItemWidth(-1.0f);
        if (ImGui::SliderInt("##FFov2", &Setting::XFov, 220, 100000))
        {
            if (Setting::XFov != 220 && Data::localPlayer)
            {
                auto ThirdPerson = (uintptr_t)Data::localPlayer->SpringArmComp;
                if (ThirdPerson)
                {
                    *(float *)(ThirdPerson) = Setting::XFov;
                }
            }
        }
		
		if (Config.Memory.MagicBullet)
        {
            ImGui::Indent();
            ImGui::SetNextItemWidth(120);
            ImGui::SliderFloat("##MagicX", &Config.Memory.MagicX, 0, 500, "Hit: %.0f"); ImGui::SameLine();
            ImGui::SetNextItemWidth(120);
            ImGui::SliderFloat("##MagicY", &Config.Memory.MagicY, 0, 500, "Dmg: %.0f"); ImGui::SameLine();
            ImGui::SetNextItemWidth(120);
            ImGui::SliderFloat("##MagicZ", &Config.Memory.MagicZ, 0, 500, "Rng: %.0f");
            ImGui::Unindent();
        }

        ImGui::Separator();

        // Dil Seçimi - Tam Boy
        const char* tr_en_languages[] = { "English", "Türkçe" };
        ImGui::SetNextItemWidth(-1.0f);
        ImGui::Combo("##languageee", (int *)&Config.SelectLanguage, tr_en_languages, IM_ARRAYSIZE(tr_en_languages));
    }
    ImGui::EndChild();
}
ImGui::EndChild(); // Kapsayıcı Ana Child Kapanışı


                }
                ImGui::EndChild();
            }
        }
        ImGui::End();
    }
// تعريف الدالة الأصلية
		  





int32_t (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);
int32_t onInputEvent(struct android_app *app, AInputEvent *inputEvent)
{
    if (initImGui)
    {
        if (AKeyEvent_getAction(inputEvent) == AKEY_EVENT_ACTION_DOWN)
        {
            int32_t key_val = AKeyEvent_getKeyCode(inputEvent);
            if (key_val == AKEYCODE_VOLUME_UP)
            {
                VR = !VR;
                return 0;
            }
        }
        ImGui_ImplAndroid_HandleInputEvent(inputEvent, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});
    }
    return VR ? 0 : orig_onInputEvent(app, inputEvent);
}






void *anogs_thread(void *) {
LOGI(OBFUSCATE("MODE BUY @zakrovich"));
        do {
              sleep(1);
   } while (!isLibraryLoaded("libanogs.so"));
       #if defined(__aarch64__)

 //Add your bypass  
       
      
   LOGI(OBFUSCATE("Done"));
 

#endif
 return NULL;
 }



void FixGameCrash() {
        system("rm -rf /data/data/com.pubg.imobile/files/");
        
        system("rm -rf /data/data/com.pubg.imobile/files/obblib");
        system("touch /data/data/com.pubg.imobile/files/obblib");
        system("chmod 000 /data/data/com.pubg.imobile/files/obblib");
        
        system("rm -rf /data/data/com.pubg.imobile/files/xlog");
        system("touch /data/data/com.pubg.imobile/files/xlog");
        system("chmod 000 /data/data/com.pubg.imobile/files/xlog");
        
        system("rm -rf /data/data/com.pubg.imobile/app_bugly");
        system("touch /data/data/com.pubg.imobile/app_bugly");
        system("chmod 000 /data/data/com.pubg.imobile/app_bugly");
        
        system("rm -rf /data/data/com.pubg.imobile/app_crashrecord");
        system("touch /data/data/com.pubg.imobile/app_crashrecord");
        system("chmod 000 /data/data/com.pubg.imobile/app_crashrecord");
        
        system("rm -rf /data/data/com.pubg.imobile/app_crashSight");
        system("touch /data/data/com.pubg.imobile/app_crashSight");
        system("chmod 000 /data/data/com.pubg.imobile/app_crashSight");
  
  system("rm -rf /data/data/com.pubg.imobile/files/ano_tmp");
        system("touch /data/data/com.pubg.imobile/files/ano_tmp");
        system("chmod 000 /data/data/com.pubg.imobile/files/ano_tmp");
  }

void banfixer() {
        system("rm -rf /data/data/com.pubg.imobile/shared_prefs");
        system("mkdir /data/data/com.pubg.imobile/shared_prefs");
        system("chmod 777 /data/data/com.pubg.imobile/shared_prefs");
        
        system("rm -rf /data/data/com.pubg.imobile/files");
        system("rm -rf /data/data/com.pubg.imobile/databases");
        system("rm -rf /data/data/com.pubg.imobile/files/login-identifier.txt");
        
        system("rm -rf /data/data/com.pubg.imobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
        system("rm -rf /data/data/com.pubg.imobile/files/UE4Game/ShadowTrackerExtra/ShadowTrackerExtra/Intermediate");
        
        system("rm -rf /data/data/com.pubg.imobile/files/TGPA");
        system("rm -rf /data/data/com.pubg.imobile/files/TGPA");
        
        system("rm -rf /data/data/com.pubg.imobile/files/ProgramBinaryCache");
        system("rm -rf /data/data/com.pubg.imobile/files/ProgramBinaryCache");
        
        system("chmod -R 000 /data/data/com.pubg.imobile/files/ano_tmp/ano.ano3.dat");

 }
 
//======================================================================================//
void* main_thread(void*) {
	//FixGameCrash();   // set Properly 
	//banfixer(); // set Properly
	
    Data::Cheat::UE4 = Tools::GetBaseAddress("libUE4.so");
    while (!Data::Cheat::UE4)
    {
        Data::Cheat::UE4 = Tools::GetBaseAddress("libUE4.so");
        sleep(1);
        
    }
    while (!Data::Cheat::App)
    {
        Data::Cheat::App = *(android_app**)(Data::Cheat::UE4 + GNativeAndroidApp_Offset);
        sleep(1);
    }
    FName::GNames = GetGNames();
    while (!FName::GNames) {
        FName::GNames = GetGNames();
        sleep(1);
    }
    UObject::GUObjectArray = (FUObjectArray*)(Data::Cheat::UE4 + GUObject_Offset);
    shadowhook_init(SHADOWHOOK_MODE_UNIQUE, 0);
    PostrenderDraw();
    shadowhook_hook_func_addr((void *)(Data::Cheat::UE4 + ProcessEvent_Offset), (void *)hkProcessEvent, (void **)&oProcessEvent);
    orig_onInputEvent = decltype(orig_onInputEvent)(Data::Cheat::App->onInputEvent);
    Data::Cheat::App->onInputEvent = onInputEvent;
shadowhook_hook_sym_name("libEGL.so", "eglSwapBuffers", (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers);
    return 0;
}


    
	
__attribute__((constructor)) void _init()
{
    pthread_t t;
    pthread_create(&t, 0, main_thread, 0);
	    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_destroy(&attr);
    pthread_create(&t, NULL, anogs_thread, NULL);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_androidx_multidex_MultiDexApplication_SIGNATUR(
        JNIEnv *env,
        jclass clazz,
        jint code,
        jboolean flag) 
        {
    if (code == 0x456){
        return JNI_TRUE;
    } else {
        return JNI_FALSE;
        }
}

