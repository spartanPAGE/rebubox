local gameblocksModule = {}

local field = require("rebubox.scripts.game.world.field")
local graphics = require("rebubox.scripts.api.graphics")

gameblocksModule.gameblockId = {
  void = 1,
  empty = 2,
  grass = 3,
  stone = 4
}

gameblocksModule.gameblocks = {
  --void
  field.create(' ', graphics.color.black, graphics.color.black),
  --empty
  field.create(' ', graphics.color.cyan, graphics.color.cyan),
  --grass
  field.create('#', graphics.color.green, graphics.color.dark_green),
  --stone
  field.create('#', graphics.color.gray, graphics.color.dark_gray)
}

return gameblocksModule