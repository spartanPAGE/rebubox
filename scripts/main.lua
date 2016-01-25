local playerModule = require("rebubox.scripts.player")
local worldModule = require("rebubox.scripts.game.world.gameworld")

local world = worldModule.World:new{}
world:setSize(10, 10)

local player = playerModule.Player:new{}

function update()
  player:update()
end

function draw()
  world:draw()
  player:draw()
end