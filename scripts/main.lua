--[[local helloModule = require("rebubox.scripts.hello")

helloModule.greet()
print(type('a'))
]]--

function update()
  
end

function draw()
  rebubox_draw_at(0, 0, '@', 4, 12)
end