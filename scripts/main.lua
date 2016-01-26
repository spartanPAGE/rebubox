local playerModule = require("rebubox.scripts.player")
local worldModule = require("rebubox.scripts.game.world.gameworld")
local graphics = require("rebubox.scripts.api.graphics")

local world = worldModule.World:new{}
world:setSize(48, 12)

local player = playerModule.Player:new{}

function update()
  player:update()
end

function draw()
  world:draw()
  player:draw()
end