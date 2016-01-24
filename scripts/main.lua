local graphics = require("rebubox.scripts.api.graphics")

function update()
  
end

function draw()
  graphics.draw_at(0, 0, '@', graphics.color.yellow, graphics.color.dark_red)
end