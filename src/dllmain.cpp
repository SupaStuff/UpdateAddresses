// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

#include <format>
#include <iostream>

#include "plugin/AddressFacade.h"

using plugin::AddressFacade;
using std::cout;

AddressFacade facade;

void sanityCheck() {
  if (!facade.isGood()) {
    facade.search();

    cout << std::format(
        "{} was updated. You don't have to do anything,\n"
        "\tbut you can send the updated file to the maintainers if you like.\n",
        facade.getOutputName());
  } else {
    cout << "All good!\n";
  }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
  switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
      sanityCheck();
      break;
    }
    case DLL_PROCESS_DETACH: {
      break;
    }
    default:
      break;
  }
  return TRUE;
}