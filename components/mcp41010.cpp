#include "mcp41010.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mcp41010 {

static const char *const TAG = "mcp41010";

void MCP41010::setup() {
  this->spi_setup();  // ✅ Correction : utiliser spi_setup()
}

void MCP41010::set_value(uint8_t value) {
  uint16_t command = (0x11 << 8) | (value & 0xFF);

  this->enable();  // ✅ Active CS
  this->write_byte((command >> 8) & 0xFF);
  this->write_byte(command & 0xFF);
  this->disable();  // ✅ Désactive CS

  ESP_LOGD(TAG, "MCP41010 set to %d", value);
}

}  // namespace mcp41010
}  // namespace esphome
