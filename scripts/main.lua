local playerModule = require("rebubox.scripts.player")

local player = playerModule.Player:new{}

function update()
  player:update()
end

function draw()
  player:draw()
end