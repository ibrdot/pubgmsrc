// one 1 real  owner of this logic  :- @SHIZUUWASOP
#pragma once

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

namespace llvm {
namespace sys {

class Signals {
public:
    static void PrintStackTraceOnErrorSignal() {
        struct sigaction sa;
        sa.sa_handler = SignalHandler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;

        sigaction(SIGSEGV, &sa, nullptr);  // Segmentation Fault
        sigaction(SIGILL, &sa, nullptr);   // Illegal Instruction
        sigaction(SIGFPE, &sa, nullptr);   // Floating Point Exception
        sigaction(SIGABRT, &sa, nullptr);  // Abort signal
    }

private:
    static void SignalHandler(int sig) {
        const char* signal_name = SignalName(sig);
        fprintf(stderr, "\n[ShizuuWasOP] Crashed due to signal: %s (%d)\n", signal_name, sig);
        _exit(1);
    }

    static const char* SignalName(int sig) {
        switch (sig) {
            case SIGSEGV: return "SIGSEGV (Segmentation Fault)";
            case SIGILL:  return "SIGILL (Illegal Instruction)";
            case SIGFPE:  return "SIGFPE (Floating Point Exception)";
            case SIGABRT: return "SIGABRT (Abort)";
            default:      return "Unknown Signal";
        }
    }
};

} // namespace sys
} // namespace llvm

