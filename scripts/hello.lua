local this_module = {}

function this_module.greet()
  print("Hello from the hello.lua!")
  print("By the way, ")
  rebubox_greet()
end

return this_module