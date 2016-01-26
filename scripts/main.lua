local playerMod = require("rebubox.scripts.player")
local worldMod = require("rebubox.scripts.game.world.gameworld")
local cameraMod = require("rebubox.scripts.game.camera")
local graphics = require("rebubox.scripts.api.graphics")
local blocks = require("rebubox.scripts.game.world.gameblocks")

local world = worldMod.World:new{}
world:setSize(30, 30)

for i=1, 30, 2 do
  world:setFieldAt(i, i, blocks.gameblockId.stone)
  world:setFieldAt(i, i, blocks.gameblockId.stone)
  world:setFieldAt(i, 1, blocks.gameblockId.stone)
  world:setFieldAt(1, i, blocks.gameblockId.stone)
  world:setFieldAt(i, 30, blocks.gameblockId.stone)
  world:setFieldAt(30, i, blocks.gameblockId.stone)
end

for i=2, 30, 2 do
  world:setFieldAt(i, i, blocks.gameblockId.grass)
  world:setFieldAt(i, 1, blocks.gameblockId.grass)
  world:setFieldAt(1, i, blocks.gameblockId.grass)
  world:setFieldAt(i, 30, blocks.gameblockId.grass)
  world:setFieldAt(30, i, blocks.gameblockId.grass)
end


local player = playerMod.Player:new{
  x = 0,
  y = 0
}

local view = {
  width = 48, 
  height = 12
}

local camera = cameraMod.create(world, player, view)

function update()
  player:update()
end

function debug_clear()
  for x = 0, view.width do
    for y = 0, view.height do
      graphics.draw_at(x, y, ' ', 0, 0)
    end
  end
end

function draw()
  debug_clear()
  --world:draw()
  camera:draw()
  --player:draw()
end