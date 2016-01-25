local fieldModule = {}

fieldModule.Field = {
  representation = 'c',
  fgcol = 0,
  bgcol = 0
}

function fieldModule.Field:new(object)
  object = object or {}
  setmetatable(object, self)
  self.__index = self
  return object
end

function fieldModule.createField(repr, fg, bg)
  local result = fieldModule.Field:new()
  result.representation = repr
  result.fgcol = fg
  result.bgcol = bg
  return result
end

function fieldModule.Field:getRepresentation()
  return self.representation
end

function fieldModule.Field:getFgColor()
  return self.fgcol
end

function fieldModule.Field:getBgColor()
  return self.bgcol
end

return fieldModule