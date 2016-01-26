local cameraModule = {}

local graphics = require("rebubox.scripts.api.graphics")
local blocks = require("rebubox.scripts.game.world.gameblocks")

cameraModule.Camera = {
  focusedWorld = {},
  focusedCoordinates = {},
  view = {}
}

function cameraModule.Camera:new(object)
  object = object or {}
  setmetatable(object, self)
  self.__index = self
  return object
end

function cameraModule.create(focusedWorld, focusedCoordinates, view)
  local result = cameraModule.Camera:new{}
  result.focusedWorld = focusedWorld
  result.focusedCoordinates = focusedCoordinates
  result.view = view
  return result
end

function cameraModule.Camera:focusCoordinates(coordinates)
  self.focusedCoordinates = coordinates
end

function cameraModule.Camera:focusWorld(world)
  self.focusedWorld = world
end

function cameraModule.Camera:setView(view)
  self.view = view
end

function cameraModule.Camera:draw()
  local halvedWidth = self.view.width/2
  local halvedHeight = self.view.height/2

  local xBegin = self.focusedCoordinates.x - halvedWidth
  local yBegin = self.focusedCoordinates.y - halvedHeight

  local xEnd = self.focusedCoordinates.x + halvedWidth + 1
  local yEnd = self.focusedCoordinates.y + halvedHeight + 1

  for x = xBegin, xEnd do
    local mapX = x-xBegin
    for y = yBegin, yEnd do
      local mapY = y-yBegin
      
      if mapX >= 0 and mapY >= 0 and mapX < graphics.console_width and mapY < graphics.console_height then
        local idx = self.focusedWorld:fieldAt(x, y) or blocks.gameblockId.void
        local block = blocks.gameblocks[idx]
        graphics.draw_at(mapX, mapY, block.representation, block.fgcol, block.bgcol)
      end
    end
  end
end

return cameraModule