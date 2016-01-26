local worldModule = {}

local fieldModule = require("rebubox.scripts.game.world.field")
local blocks = require("rebubox.scripts.game.world.gameblocks")

worldModule.World = {
  width = 0,
  height = 0,
  blockIds = {}
}

function worldModule.World:new(object)
  object = object or {}
  setmetatable(object, self)
  self.__index = self
  return object
end

function worldModule.World:translateToIndex(x, y)
  return x * self.height + y
end

function worldModule.World:fieldAt(x, y)
  return self.blockIds[self:translateToIndex(x, y)]
end

function worldModule.World:setFieldAt(x, y, value)
  self.blockIds[self:translateToIndex(x, y)] = value
end

function worldModule.World:setSize(w, h)
  self.width = w
  self.height = h

  for x = 1, w do
    for y = 1, h do
      self:setFieldAt(x, y, blocks.gameblockId.empty)
    end
  end
end

--[[function worldModule.World:draw()
  for x = 1, self.width do
    for y = 1, self.height do
      local field = self:fieldAt(x, y)
      graphics.draw_at(x-1, y-1, field.representation, field.fgcol, field.bgcol)
    end
  end
end]]

return worldModule