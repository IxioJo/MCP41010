import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import spi
from esphome.const import CONF_ID

DEPENDENCIES = ["spi"]

mcp41010_ns = cg.esphome_ns.namespace("mcp41010")
MCP41010 = mcp41010_ns.class_("MCP41010", cg.Component, spi.SPIDevice)

CONFIG_SCHEMA = ( cv.Schema({    cv.GenerateID(): cv.declare_id(MCP41010),})
    .extend(cv.COMPONENT_SCHEMA)
    .extend(spi.spi_device_schema(cs_pin_required=True))

)

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await spi.register_spi_device(var, config)
