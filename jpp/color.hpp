#pragma once

#include <cstdint>

namespace jpp {

// rgba
struct alignas(uint32_t) Color {
  public: // fields:
    uint8_t r, g, b, a;
};

} // namespace jpp
