#pragma once

#include <types/address.h>

#include <string_view>
#include <vector>

#include "../model/Addresses.h"
#include "../model/Metadata.h"
#include "../model/UpdateAddresses.h"

namespace plugin {
  using model::Addresses;
  using model::Metadata;
  using model::UpdateAddresses;
  using std::string_view;
  using std::vector;
  using stuff::types::Pointer;

  class AddressFacade {
    Pointer exeBase;
    int divider;
    UpdateAddresses config;
    Metadata metadata;
    Addresses addresses;
    vector<string_view> keys;

    void handleFoundAddress(unsigned int idx, Pointer address);

   public:
    AddressFacade();
    bool isGood();
    void search();
    bool foundAllAddresses();
    const Addresses& getNewAddreses();
    string_view getOutputName();
  };
}  // namespace plugin
