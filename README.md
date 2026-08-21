<h1 align="center">
  pubgmsrc
</h1>

<p align="center">
  <b>PUBG Mobile v4.5</b><br>
  by <a href="https://github.com/ibrdot">ibrdot</a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/version-4.5-purple?style=for-the-badge" />
  <img src="https://img.shields.io/badge/platform-Android-green?style=for-the-badge&logo=android" />
  <img src="https://img.shields.io/badge/language-C%2B%2B-blue?style=for-the-badge&logo=cplusplus" />
  <img src="https://img.shields.io/badge/author-ibrdot-red?style=for-the-badge&logo=github" />
</p>

---

## 👤 Author

| | |
|---|---|
| **GitHub** | [github.com/ibrdot](https://github.com/ibrdot) |
| **Repo** | [github.com/ibrdot/pubgmsrc](https://github.com/ibrdot/pubgmsrc) |
| **Credit** | [t.me/ibrdevelopershub](https://t.me/ibrdevelopershub) |

---

## 📁 Project Structure

```
app/src/main/jni/
├── Main.cpp               # Entry point — ImGui render loop
├── KeyAuth.hpp            # Authentication
├── Offset.h               # Game offsets
├── SDK.hpp                # Game SDK
└── WOLTAJ/
    ├── Main/
    │   ├── Main.h         # Menu logic
    │   └── ESP/
    │       ├── Draw.cpp   # ESP rendering
    │       ├── Draw.h     # Info panel, UI
    │       └── Setting.h  # Global variables
    ├── hook.cpp           # Hooks + Anti-cheat bypass
    ├── Helper/            # Includes, fonts, textures
    ├── Hook/              # Hook macros & utilities
    └── KittyMemory/       # Memory patching
```

---

## ⚙️ Features

- 🎯 **Aimbot** — Smooth, FOV-based, configurable
- 👁️ **ESP** — Player box, bones, health, distance, name
- 💀 **No Recoil** — Multiple modes
- ⚡ **Speed Hack** — Fast run, fast para
- 🛡️ **Anti-Ban** — Offline + Online 10-year ban fix
- 🔒 **Anti-Cheat Bypass** — ptrace, kill, dlopen, syscall hooks
- 💥 **Crash Fixer** — Safe crash patches (PUBGM + BGMI)
- 🔧 **Memory Hacks** — Fast shoot, magic bullet, etc.
- 🎮 **Volume Key / Button** support

---

## 🔧 Build Requirements

- Android NDK r21+
- Android Studio / Gradle
- ABI: `arm64-v8a`

---

## 🚀 Build Steps

```bash
# Clone the repo
git clone https://github.com/ibrdot/pubgmsrc.git

# Open in Android Studio and build
# OR use Gradle directly:
./gradlew assembleRelease
```

---

## 🛡️ Anti-Cheat Bypass Hooks

```cpp
hptrace      → blocks ptrace detection
hkill        → blocks self-kill signals (9,3,6,15)
h__system_property_get → spoofs ro.debuggable=0, ro.secure=1
hdlopen      → blocks Frida/Xposed lib loading
hpopen       → blocks su/magisk/busybox commands
hopen        → redirects /proc/self/maps to /dev/null
hsyscall     → blocks ptrace(26), kill(129), clone(220)
```

---

## 📌 Supported Versions

| Game | Version |
|------|---------|
| PUBG Mobile | 4.5.x |

---

## ⚠️ Disclaimer

> This project is for **educational and research purposes only**.  
> The author is not responsible for any misuse.  
> Use at your own risk.

---

<p align="center">
  Made with ❤️ by <a href="https://github.com/ibrdot">ibrdot</a>
</p>
