#include "esphome/core/component.h"
#include "esphome/components/spi/spi.h"

namespace esphome {
namespace mcp41010 {

class MCP41010 : public Component, public spi::SPIDevice<spi::BIT_ORDER_MSB_FIRST, spi::CLOCK_POLARITY_LOW, spi::CLOCK_PHASE_LEADING, spi::DATA_RATE_1MHZ> {
 public:
  void setup() override;
  void set_value(uint8_t value);
};

}  // namespace mcp41010
}  // namespace esphome
