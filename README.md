<div align="center">

```
██████╗ ██╗   ██╗██████╗  ██████╗ ███╗   ███╗███████╗██████╗  ██████╗
██╔══██╗██║   ██║██╔══██╗██╔════╝ ████╗ ████║██╔════╝██╔══██╗██╔════╝
██████╔╝██║   ██║██████╔╝██║  ███╗██╔████╔██║███████╗██████╔╝██║
██╔═══╝ ██║   ██║██╔══██╗██║   ██║██║╚██╔╝██║╚════██║██╔══██╗██║
██║     ╚██████╔╝██████╔╝╚██████╔╝██║ ╚═╝ ██║███████║██║  ██║╚██████╗
╚═╝      ╚═════╝ ╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝
```

<h1>🎯 pubgmsrc</h1>

<p><strong>PUBG Mobile Source Code — Version 4.5</strong></p>

[![Author](https://img.shields.io/badge/Author-ibrdot-ff6b6b?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ibrdot)
[![Version](https://img.shields.io/badge/Version-4.5.0-6c5ce7?style=for-the-badge&logo=android&logoColor=white)](https://github.com/ibrdot/pubgmsrc)
[![Language](https://img.shields.io/badge/C++-00b4d8?style=for-the-badge&logo=cplusplus&logoColor=white)](https://github.com/ibrdot/pubgmsrc)
[![Platform](https://img.shields.io/badge/Android-arm64-00b894?style=for-the-badge&logo=android&logoColor=white)](https://github.com/ibrdot/pubgmsrc)
[![Stars](https://img.shields.io/github/stars/ibrdot/pubgmsrc?style=for-the-badge&color=ffd700)](https://github.com/ibrdot/pubgmsrc)

<br/>

> *"Built from scratch. Owned by ibrdot."*

</div>

---

<div align="center">

## 🔗 Links

[![GitHub](https://img.shields.io/badge/GitHub-ibrdot-181717?style=for-the-badge&logo=github)](https://github.com/ibrdot)
[![Telegram](https://img.shields.io/badge/Telegram-ibrdevelopershub-2CA5E0?style=for-the-badge&logo=telegram)](https://t.me/ibrdevelopershub)
[![Source](https://img.shields.io/badge/Source-pubgmsrc-6c5ce7?style=for-the-badge&logo=github)](https://github.com/ibrdot/pubgmsrc)

</div>

---

## 📖 About

> **pubgmsrc** is an open-source PUBG Mobile modification source code for version **4.5**  
> Written in **C++** using **ImGui** for the overlay menu and **KittyMemory** for memory patching.  
> Includes full anti-cheat bypass, ESP, aimbot, ban fix patches and much more.

---

## ✨ Features

<table>
<tr>
<td>

### 🎯 Combat
- ✅ Aimbot (Smooth + Silent)
- ✅ No Recoil (Multi-mode)
- ✅ Magic Bullet
- ✅ Fast Shoot
- ✅ Rapid Fire
- ✅ No Spread

</td>
<td>

### 👁️ Visuals
- ✅ Player ESP (Box, Corner, Bone)
- ✅ Health Bar
- ✅ Distance
- ✅ Name Tag
- ✅ Item ESP
- ✅ Vehicle ESP

</td>
<td>

### 🛡️ Protection
- ✅ Anti-Ban (10 Year Fix)
- ✅ Anti-Cheat Bypass
- ✅ ptrace Block
- ✅ Frida/Xposed Block
- ✅ Crash Fixer
- ✅ Termination Fix

</td>
</tr>
<tr>
<td>

### ⚡ Movement
- ✅ Speed Hack
- ✅ Fast Run
- ✅ Fast Para
- ✅ Car Fly
- ✅ God View
- ✅ Teleport

</td>
<td>

### 🔧 Misc
- ✅ Volume Key Support
- ✅ Button Mode
- ✅ Memory Hacks
- ✅ Skin Changer
- ✅ Scope FOV
- ✅ Config Save/Load

</td>
<td>

### 🔒 Bypass
- ✅ ptrace Hook
- ✅ kill() Block
- ✅ dlopen Filter
- ✅ popen Filter
- ✅ Syscall Block
- ✅ Prop Spoof

</td>
</tr>
</table>

---

## 📁 Project Structure

```
📦 pubgmsrc
 ┣ 📂 app/src/main/jni/
 ┃ ┣ 📄 Main.cpp              ← ImGui render loop entry point
 ┃ ┣ 📄 KeyAuth.hpp           ← Authentication system
 ┃ ┣ 📄 Offset.h              ← Game memory offsets
 ┃ ┣ 📄 SDK.hpp               ← PUBG Mobile SDK structs
 ┃ ┗ 📂 WOLTAJ/
 ┃    ┣ 📂 Main/
 ┃    ┃  ┣ 📄 Main.h          ← Menu draw logic
 ┃    ┃  ┗ 📂 ESP/
 ┃    ┃     ┣ 📄 Draw.cpp     ← ESP & watermark overlay
 ┃    ┃     ┣ 📄 Draw.h       ← Info panel & game status
 ┃    ┃     ┗ 📄 Setting.h    ← Global config variables
 ┃    ┣ 📄 hook.cpp           ← All hooks + ban/crash fixes
 ┃    ┣ 📂 Helper/            ← Fonts, textures, headers
 ┃    ┣ 📂 Hook/              ← Hook macros & utilities
 ┃    ┣ 📂 KittyMemory/       ← Memory patch engine
 ┃    ┗ 📂 SDK/               ← Extended SDK classes
 ┗ 📄 README.md
```

---

## 🛡️ Anti-Cheat Bypass Details

```cpp
// ── Hooks registered at runtime ──────────────────────────────
hptrace               → Blocks ptrace() anti-debug calls
hkill                 → Blocks self-kill signals (SIGKILL/SIGTERM)
h__system_property_get→ Spoofs: ro.debuggable=0, ro.secure=1
hdlopen               → Blocks Frida / Xposed library injection
hpopen                → Blocks su, magisk, busybox detection
hopen                 → Redirects /proc/self/maps → /dev/null
hsyscall              → Kills ptrace(26), kill(129), clone(220)

// ── Ban Fix Patches ───────────────────────────────────────────
OFFLINE 10yr ban fix  → 0x3E6C44 ~ 0x3E6C84
ONLINE  10yr ban fix  → 0x375D0C ~ 0x375D70
Termination Fix       → 0x4C9FF0 / 0x4B36F8 / 0x4F7D84
Crash Safe Fix        → 0x514D10 / 0x514D18 / 0x514D20
```

---

## 🔧 Requirements

| Tool | Version |
|------|---------|
| Android NDK | r21+ |
| Android Studio | Any |
| ABI | arm64-v8a |
| Min SDK | 21 |
| Target | PUBG Mobile 4.5.x |

---

## 🚀 Build

```bash
# 1. Clone
git clone https://github.com/ibrdot/pubgmsrc.git
cd pubgmsrc

# 2. Build with Gradle
./gradlew assembleRelease

# 3. APK Output:
# app/build/outputs/apk/release/app-release.apk
```

---

## 📌 Supported

| Game | Version | Status |
|------|---------|--------|
| PUBG Mobile | 4.5.x | ✅ Supported |

---

## ⚠️ Disclaimer

```
This source code is released for EDUCATIONAL and RESEARCH purposes only.
The author (ibrdot) holds no responsibility for any misuse of this code.
Use entirely at your own risk.
```

---

<div align="center">

### 🌟 Star this repo if it helped you!

[![Star History](https://img.shields.io/github/stars/ibrdot/pubgmsrc?style=social)](https://github.com/ibrdot/pubgmsrc)

<br/>

**Made with ❤️ by [ibrdot](https://github.com/ibrdot)**

`© 2026 ibrdot — github.com/ibrdot`

</div>
