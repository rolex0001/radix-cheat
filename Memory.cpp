#pragma once
#include "Memory.hpp"
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <algorithm>

// Returns first PID found from process name
uint32_t Memory::getProcessId(const std::string& processName)
{
  HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  PROCESSENTRY32 entry;
  entry.dwSize = sizeof(entry);
  do
  {
    if (!strcmp(entry.szExeFile, processName.c_str()))
      return entry.th32ProcessID;
  } while (Process32Next(snapshot, &entry));
  CloseHandle(snapshot);
  return 0;
}

bool qdaaxet::sydmnqwaxaxgi(double uuynvxnnj, bool fcyxltiipkbuk, string gzheeynxjbnjen, bool fmkji, bool awbwfefb, bool bzppgjkjgmgmle, bool dmsrfoonoatz) {
int rlgueqzckce = 7030;
if (7030 == 7030) {
int poghvtrmmg;
for (poghvtrmmg=99; poghvtrmmg > 0; poghvtrmmg--) {
continue;
} 
}
if (7030 != 7030) {
int vwtinicxre;
for (vwtinicxre=97; vwtinicxre > 0; vwtinicxre--) {
continue;
} 
}
return false;
}

void yvebcoo::namzcoobcbiggmhatddiymms(double bxnsdvhtymwpt, int dprncrhonkdpm, string tyorbgxzi, bool foovt, string dxkbpqaa, string nxnptbpgjkutqhc, int xcyoktafx, bool xmebammceffzb, string kvdridkvejopxyk) {
bool wkhkb = true;
if (true != true) {
int xuaaxkdqfh;
for (xuaaxkdqfh=2; xuaaxkdqfh > 0; xuaaxkdqfh--) {
continue;
} 
}
if (true == true) {
int jlehte;
for (jlehte=82; jlehte > 0; jlehte--) {
continue;
} 
}
if (true != true) {
int yklzd;
for (yklzd=100; yklzd > 0; yklzd--) {
continue;
} 
}

}


// Attach memory manager to process
bool Memory::attachToProcess(const std::string& processName)
{
  PID = getProcessId(processName);

  // Simply open a handle to target
  hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);

  return hProcess;
}

// Finds base address of module name
uint32_t Memory::getModule(const char * moduleName)
{
  HANDLE module = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, PID);
  MODULEENTRY32 moduleEntry;
  moduleEntry.dwSize = sizeof(moduleEntry);

  do
  {
    if (!strcmp(moduleEntry.szModule, moduleName))
    {
      CloseHandle(module);
      return (uint32_t)moduleEntry.modBaseAddr;
    }
  } while (Module32Next(module, &moduleEntry));
  CloseHandle(module);
  moduleEntry.modBaseAddr = 0;
  return (uint32_t)moduleEntry.modBaseAddr;
}

Memory::Memory()
{
  this->hProcess = 0;
  this->PID = 0;

  if (!attachToProcess(TARGET_PROCESS))
    return;

  this->clientDll = getModule(CLIENT_DLL_NAME);
  this->engineDll = getModule(ENGINE_DLL_NAME);
}

Memory::~Memory()
{
  CloseHandle(this->hProcess);
}
