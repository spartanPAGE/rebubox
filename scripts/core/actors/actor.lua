local actorsModule = {}

actorsModule.Actor = {
  x = 0, 
  y = 0
}

function actorsModule.Actor:new(object)
  object = object or {}
  setmetatable(object, self)
  self.__index = self
  return object
end

function actorsModule.Actor:update()
end

function actorsModule.Actor:draw()
end

function actorsModule.Actor:getPosition()
  return self.x, self.y
end

function actorsModule.Actor:setPositon(x, y)
  self.x, self.y = x, y
end

return actorsModule