local playerModule = {}

local actorModule = require("rebubox.scripts.core.actors.actor")
local graphics = require("rebubox.scripts.api.graphics")
local input = require("rebubox.scripts.api.input")

local field = require("rebubox.scripts.game.world.field")

playerModule.Player = actorModule.Actor:new{
  graphic = field.createField('@', graphics.color.yellow, graphics.color.dark_red)
}

function playerModule.Player:handleInput()
  local actions = {
    w = function() self.y = self.y - 1 end,
    s = function() self.y = self.y + 1 end,
    a = function() self.x = self.x - 1 end,
    d = function() self.x = self.x + 1 end
  }

  str = input.get_buffer()
  str:gsub(".", function(c)
    local func = actions[c]
    if func then 
      func() 
    end;
  end)
end

function playerModule.Player:update()
  self:handleInput()
end

function playerModule.Player:draw()
  local x, y = self:getPosition()
  graphics.draw_at(x, y, self.graphic.representation, self.graphic.fgcol, self.graphic.bgcol)
end

return playerModule